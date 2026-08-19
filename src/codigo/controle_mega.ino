/*
 =========================================================
 CONTROLE DO CARRINHO 4WD
 Arduino Mega 2560 + Funduino Joystick Shield V1.A
 =========================================================

 COMANDOS ENVIADOS:
 F = Frente
 D = Direita
 E = Esquerda
 B = Brake/Freio
 P = Parado

 Comunicação:
 Mega -> ESP32 transmissor
 Serial1 TX1 = pino 18
 =========================================================
*/

// -------------------------
// PINOS DO JOYSTICK SHIELD
// -------------------------

const int PIN_JOYSTICK_X = A0;
const int PIN_JOYSTICK_Y = A1;

const int BOTAO_FRENTE = 2;   // Botão A / UP
const int BOTAO_DIREITA = 3;  // Botão B
const int BOTAO_FREIO = 4;    // Botão C / DOWN
const int BOTAO_ESQUERDA = 5; // Botão D

// -------------------------
// CONFIGURAÇÕES DO JOYSTICK
// -------------------------

int centroJoystickX = 512;

const int ZONA_MORTA = 170;

const int INTERVALO_ENVIO = 50;

unsigned long ultimoEnvio = 0;

char ultimoComando = 'P';

// =========================================================
// SETUP
// =========================================================

void setup()
{

    iniciarSerial();

    configurarJoystick();

    configurarBotoes();

    calibrarJoystick();

    enviarComando('P');
}

// =========================================================
// LOOP
// =========================================================

void loop()
{

    lerControle();

    delay(10);
}

// =========================================================
// CONFIGURA SERIAL
// =========================================================

void iniciarSerial()
{

    // Comunicação com computador
    Serial.begin(115200);

    // Comunicação Mega -> ESP32 TX
    Serial1.begin(115200);

    Serial.println("=================================");
    Serial.println("CONTROLE DO CARRINHO INICIADO");
    Serial.println("=================================");
}

// =========================================================
// CONFIGURA JOYSTICK
// =========================================================

void configurarJoystick()
{

    pinMode(PIN_JOYSTICK_X, INPUT);
    pinMode(PIN_JOYSTICK_Y, INPUT);
}

// =========================================================
// CONFIGURA BOTOES
// =========================================================

void configurarBotoes()
{

    pinMode(BOTAO_FRENTE, INPUT_PULLUP);
    pinMode(BOTAO_FREIO, INPUT_PULLUP);
    pinMode(BOTAO_DIREITA, INPUT_PULLUP);
    pinMode(BOTAO_ESQUERDA, INPUT_PULLUP);
}

// =========================================================
// CALIBRA O CENTRO DO JOYSTICK
// =========================================================

void calibrarJoystick()
{

    Serial.println("Calibrando joystick...");
    Serial.println("Nao mova o joystick.");

    long somaX = 0;

    for (int i = 0; i < 100; i++)
    {

        somaX += analogRead(PIN_JOYSTICK_X);

        delay(5);
    }

    centroJoystickX = somaX / 100;

    Serial.print("Centro X = ");
    Serial.println(centroJoystickX);

    delay(500);
}

// =========================================================
// LEITURA PRINCIPAL DO CONTROLE
// =========================================================

void lerControle()
{

    bool frentePressionado =
        digitalRead(BOTAO_FRENTE) == LOW;

    bool freioPressionado =
        digitalRead(BOTAO_FREIO) == LOW;

    int joystickX =
        analogRead(PIN_JOYSTICK_X);

    // FREIO TEM PRIORIDADE MÁXIMA

    if (freioPressionado)
    {

        comandoFreio();
        return;
    }

    // JOYSTICK DIREITA

    if (joystickX >
        centroJoystickX + ZONA_MORTA)
    {

        comandoDireita();
        return;
    }

    // JOYSTICK ESQUERDA

    if (joystickX <
        centroJoystickX - ZONA_MORTA)
    {

        comandoEsquerda();
        return;
    }

    // BOTÃO DIANTEIRO

    if (frentePressionado)
    {

        comandoFrente();
        return;
    }

    comandoParado();
}

// =========================================================
// COMANDO FRENTE
// =========================================================

void comandoFrente()
{

    enviarComando('F');
}

// =========================================================
// COMANDO DIREITA
// =========================================================

void comandoDireita()
{

    enviarComando('D');
}

// =========================================================
// COMANDO ESQUERDA
// =========================================================

void comandoEsquerda()
{

    enviarComando('E');
}

// =========================================================
// COMANDO FREIO
// =========================================================

void comandoFreio()
{

    enviarComando('B');
}

// =========================================================
// COMANDO PARADO
// =========================================================

void comandoParado()
{

    enviarComando('P');
}

// =========================================================
// ENVIA COMANDO PARA ESP32
// =========================================================

void enviarComando(char comando)
{

    unsigned long agora = millis();

    /*
      O comando é enviado:
      - quando muda
      OU
      - a cada 50 ms

      Isso cria um heartbeat de segurança.
    */

    if (comando != ultimoComando ||
        agora - ultimoEnvio >= INTERVALO_ENVIO)
    {

        Serial1.println(comando);

        Serial.print("Comando: ");
        Serial.println(comando);

        ultimoComando = comando;

        ultimoEnvio = agora;
    }
}