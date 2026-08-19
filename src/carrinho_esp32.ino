/*
 ============================================================
 CARRINHO ROBÔ 4WD
 ESP32 + L298N + 4 MOTORES + HC-SR04 + 2 LEDS
 ============================================================

 COMANDOS:

 F = Frente
 D = Direita
 E = Esquerda
 B = Freio
 P = Parar

 SEGURANÇA:

 - Failsafe de comunicação
 - Sensor frontal
 - Freio prioritário
 - LEDs de freio
 ============================================================
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

// ============================================================
// CONFIGURAÇÕES
// ============================================================

#define CANAL_ESPNOW 6

const int VELOCIDADE_FRENTE = 200;
const int VELOCIDADE_CURVA  = 180;

const int DISTANCIA_SEGURANCA = 15;

const unsigned long TIMEOUT_COMUNICACAO = 350;

// ============================================================
// L298N
// ============================================================

// MOTOR ESQUERDO
const int ENA = 25;
const int IN1 = 26;
const int IN2 = 27;

// MOTOR DIREITO
const int ENB = 14;
const int IN3 = 32;
const int IN4 = 33;

// ============================================================
// LEDS TRASEIROS
// ============================================================

const int LED_FREIO_1 = 18;
const int LED_FREIO_2 = 19;

// ============================================================
// HC-SR04
// ============================================================

const int TRIG = 23;
const int ECHO = 22;

// ============================================================
// INVERSÃO DOS MOTORES
// ============================================================

/*
 Se algum lado girar invertido,
 basta alterar false -> true.
*/

bool inverterMotorEsquerdo = false;
bool inverterMotorDireito = false;

// ============================================================
// PACOTE
// ============================================================

struct PacoteControle {

  uint32_t assinatura;

  uint32_t sequencia;

  char comando;
};

volatile PacoteControle pacoteRecebido;

volatile bool novoPacote = false;

portMUX_TYPE mux =
    portMUX_INITIALIZER_UNLOCKED;

unsigned long ultimoPacote = 0;

char comandoAtual = 'P';

// ============================================================
// SETUP
// ============================================================

void setup() {

  iniciarSerial();

  configurarMotores();

  configurarLeds();

  configurarSensor();

  iniciarWiFi();

  iniciarESPNow();

  pararCarrinho();
}

// ============================================================
// LOOP
// ============================================================

void loop() {

  verificarPacoteRecebido();

  verificarFailsafe();

  executarComando();

  delay(5);
}

// ============================================================
// SERIAL
// ============================================================

void iniciarSerial() {

  Serial.begin(115200);

  delay(500);

  Serial.println();
  Serial.println("===============================");
  Serial.println("CARRINHO ESP32 INICIADO");
  Serial.println("===============================");
}

// ============================================================
// CONFIGURA MOTORES
// ============================================================

void configurarMotores() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  /*
   PWM dos enables.

   Arduino ESP32 Core 3.x:
   ledcAttach(pin, frequência, resolução)
  */

  ledcAttach(
    ENA,
    1000,
    8
  );

  ledcAttach(
    ENB,
    1000,
    8
  );
}

// ============================================================
// CONFIGURA LEDS
// ============================================================

void configurarLeds() {

  pinMode(
    LED_FREIO_1,
    OUTPUT
  );

  pinMode(
    LED_FREIO_2,
    OUTPUT
  );

  desligarLedsFreio();
}

// ============================================================
// CONFIGURA SENSOR
// ============================================================

void configurarSensor() {

  pinMode(
    TRIG,
    OUTPUT
  );

  pinMode(
    ECHO,
    INPUT
  );

  digitalWrite(
    TRIG,
    LOW
  );
}

// ============================================================
// WIFI
// ============================================================

void iniciarWiFi() {

  WiFi.mode(WIFI_STA);

  WiFi.setChannel(
    CANAL_ESPNOW
  );

  delay(100);

  Serial.print(
    "MAC ESP32 RX: "
  );

  Serial.println(
    WiFi.macAddress()
  );
}

// ============================================================
// ESP-NOW
// ============================================================

void iniciarESPNow() {

  if (esp_now_init() != ESP_OK) {

    Serial.println(
      "ERRO iniciando ESP-NOW!"
    );

    while (true) {
      delay(1000);
    }
  }

  esp_now_register_recv_cb(
    receberDadosESPNow
  );

  Serial.println(
    "ESP-NOW pronto."
  );
}

// ============================================================
// CALLBACK ESP-NOW
// ============================================================

void receberDadosESPNow(
  const esp_now_recv_info_t *info,
  const uint8_t *dados,
  int tamanho
) {

  if (tamanho != sizeof(PacoteControle)) {
    return;
  }

  PacoteControle recebido;

  memcpy(
    &recebido,
    dados,
    sizeof(recebido)
  );

  if (recebido.assinatura != 0x524F424F) {
    return;
  }

  portENTER_CRITICAL(&mux);

  pacoteRecebido =
      recebido;

  novoPacote =
      true;

  portEXIT_CRITICAL(&mux);
}

// ============================================================
// TRATA PACOTE
// ============================================================

void verificarPacoteRecebido() {

  if (!novoPacote) {
    return;
  }

  PacoteControle copia;

  portENTER_CRITICAL(&mux);

  copia =
      pacoteRecebido;

  novoPacote =
      false;

  portEXIT_CRITICAL(&mux);

  comandoAtual =
      copia.comando;

  ultimoPacote =
      millis();

  Serial.print("RX -> ");

  Serial.println(
    comandoAtual
  );
}

// ============================================================
// EXECUTA COMANDO
// ============================================================

void executarComando() {

  switch (comandoAtual) {

    case 'F':

      andarFrente();

      break;

    case 'D':

      virarDireita();

      break;

    case 'E':

      virarEsquerda();

      break;

    case 'B':

      frearCarrinho();

      break;

    case 'P':

    default:

      pararCarrinho();

      break;
  }
}

// ============================================================
// ANDAR PARA FRENTE
// ============================================================

void andarFrente() {

  desligarLedsFreio();

  if (obstaculoNaFrente()) {

    frearPorObstaculo();

    return;
  }

  controlarMotorEsquerdo(
    VELOCIDADE_FRENTE
  );

  controlarMotorDireito(
    VELOCIDADE_FRENTE
  );
}

// ============================================================
// VIRAR PARA DIREITA
// ============================================================

void virarDireita() {

  desligarLedsFreio();

  /*
    Carrinho diferencial:

    Para virar DIREITA:
    lado ESQUERDO movimenta
    lado DIREITO para.
  */

  controlarMotorEsquerdo(
    VELOCIDADE_CURVA
  );

  controlarMotorDireito(
    0
  );
}

// ============================================================
// VIRAR PARA ESQUERDA
// ============================================================

void virarEsquerda() {

  desligarLedsFreio();

  controlarMotorEsquerdo(
    0
  );

  controlarMotorDireito(
    VELOCIDADE_CURVA
  );
}

// ============================================================
// FREIO
// ============================================================

void frearCarrinho() {

  ligarLedsFreio();

  frearMotorEsquerdo();

  frearMotorDireito();
}

// ============================================================
// FREIO POR OBSTÁCULO
// ============================================================

void frearPorObstaculo() {

  ligarLedsFreio();

  frearMotorEsquerdo();

  frearMotorDireito();

  Serial.println(
    "OBSTACULO DETECTADO!"
  );
}

// ============================================================
// PARAR SEM FREIO
// ============================================================

void pararCarrinho() {

  desligarLedsFreio();

  ledcWrite(
    ENA,
    0
  );

  ledcWrite(
    ENB,
    0
  );

  digitalWrite(
    IN1,
    LOW
  );

  digitalWrite(
    IN2,
    LOW
  );

  digitalWrite(
    IN3,
    LOW
  );

  digitalWrite(
    IN4,
    LOW
  );
}

// ============================================================
// MOTOR ESQUERDO
// ============================================================

void controlarMotorEsquerdo(
  int velocidade
) {

  velocidade =
      constrain(
        velocidade,
        0,
        255
      );

  if (velocidade == 0) {

    ledcWrite(
      ENA,
      0
    );

    return;
  }

  if (!inverterMotorEsquerdo) {

    digitalWrite(
      IN1,
      HIGH
    );

    digitalWrite(
      IN2,
      LOW
    );

  } else {

    digitalWrite(
      IN1,
      LOW
    );

    digitalWrite(
      IN2,
      HIGH
    );
  }

  ledcWrite(
    ENA,
    velocidade
  );
}

// ============================================================
// MOTOR DIREITO
// ============================================================

void controlarMotorDireito(
  int velocidade
) {

  velocidade =
      constrain(
        velocidade,
        0,
        255
      );

  if (velocidade == 0) {

    ledcWrite(
      ENB,
      0
    );

    return;
  }

  if (!inverterMotorDireito) {

    digitalWrite(
      IN3,
      HIGH
    );

    digitalWrite(
      IN4,
      LOW
    );

  } else {

    digitalWrite(
      IN3,
      LOW
    );

    digitalWrite(
      IN4,
      HIGH
    );
  }

  ledcWrite(
    ENB,
    velocidade
  );
}

// ============================================================
// FREIO MOTOR ESQUERDO
// ============================================================

void frearMotorEsquerdo() {

  ledcWrite(
    ENA,
    255
  );

  digitalWrite(
    IN1,
    HIGH
  );

  digitalWrite(
    IN2,
    HIGH
  );
}

// ============================================================
// FREIO MOTOR DIREITO
// ============================================================

void frearMotorDireito() {

  ledcWrite(
    ENB,
    255
  );

  digitalWrite(
    IN3,
    HIGH
  );

  digitalWrite(
    IN4,
    HIGH
  );
}

// ============================================================
// LIGA LEDS DE FREIO
// ============================================================

void ligarLedsFreio() {

  digitalWrite(
    LED_FREIO_1,
    HIGH
  );

  digitalWrite(
    LED_FREIO_2,
    HIGH
  );
}

// ============================================================
// DESLIGA LEDS DE FREIO
// ============================================================

void desligarLedsFreio() {

  digitalWrite(
    LED_FREIO_1,
    LOW
  );

  digitalWrite(
    LED_FREIO_2,
    LOW
  );
}

// ============================================================
// SENSOR
// ============================================================

float medirDistancia() {

  digitalWrite(
    TRIG,
    LOW
  );

  delayMicroseconds(2);

  digitalWrite(
    TRIG,
    HIGH
  );

  delayMicroseconds(10);

  digitalWrite(
    TRIG,
    LOW
  );

  unsigned long duracao =
      pulseIn(
        ECHO,
        HIGH,
        25000
      );

  if (duracao == 0) {

    return 999;
  }

  float distancia =
      duracao * 0.0343 / 2.0;

  return distancia;
}

// ============================================================
// VERIFICA OBSTÁCULO
// ============================================================

bool obstaculoNaFrente() {

  float distancia =
      medirDistancia();

  Serial.print(
    "Distancia: "
  );

  Serial.print(
    distancia
  );

  Serial.println(
    " cm"
  );

  return (
    distancia <
    DISTANCIA_SEGURANCA
  );
}

// ============================================================
// FAILSAFE
// ============================================================

void verificarFailsafe() {

  if (
    millis() - ultimoPacote >
    TIMEOUT_COMUNICACAO
  ) {

    if (comandoAtual != 'P') {

      Serial.println(
        "COMUNICACAO PERDIDA!"
      );
    }

    comandoAtual = 'P';
  }
}