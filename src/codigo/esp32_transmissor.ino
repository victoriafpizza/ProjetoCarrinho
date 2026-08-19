/*
 =========================================================
 ESP32 TRANSMISSOR
 Recebe comando do Arduino Mega via UART
 e transmite via ESP-NOW
 =========================================================
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

// =========================================================
// CONFIGURAÇÃO
// =========================================================

#define CANAL_ESPNOW 6

// UART usada para conversar com Mega
#define RX_MEGA 26
#define TX_MEGA 27

HardwareSerial SerialMega(1);

// Broadcast ESP-NOW
uint8_t enderecoBroadcast[] = {
    0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF};

// =========================================================
// ESTRUTURA DO PACOTE
// =========================================================

struct PacoteControle
{

    uint32_t assinatura;

    uint32_t sequencia;

    char comando;
};

PacoteControle pacote;

uint32_t contadorPacotes = 0;

// =========================================================
// SETUP
// =========================================================

void setup()
{

    iniciarSerial();

    iniciarComunicacaoMega();

    iniciarWiFi();

    iniciarESPNow();

    adicionarPeerBroadcast();
}

// =========================================================
// LOOP
// =========================================================

void loop()
{

    lerComandoMega();

    delay(1);
}

// =========================================================
// SERIAL DEBUG
// =========================================================

void iniciarSerial()
{

    Serial.begin(115200);

    delay(500);

    Serial.println();
    Serial.println("==============================");
    Serial.println("ESP32 TRANSMISSOR");
    Serial.println("==============================");
}

// =========================================================
// SERIAL MEGA -> ESP32
// =========================================================

void iniciarComunicacaoMega()
{

    SerialMega.begin(
        115200,
        SERIAL_8N1,
        RX_MEGA,
        TX_MEGA);

    Serial.println("UART Mega iniciada.");
}

// =========================================================
// WIFI
// =========================================================

void iniciarWiFi()
{

    WiFi.mode(WIFI_STA);

    WiFi.setChannel(CANAL_ESPNOW);

    delay(100);

    Serial.print("MAC ESP32 TX: ");
    Serial.println(WiFi.macAddress());
}

// =========================================================
// ESP-NOW
// =========================================================

void iniciarESPNow()
{

    if (esp_now_init() != ESP_OK)
    {

        Serial.println("ERRO iniciando ESP-NOW!");

        while (true)
        {
            delay(1000);
        }
    }

    Serial.println("ESP-NOW iniciado.");
}

// =========================================================
// ADICIONA BROADCAST
// =========================================================

void adicionarPeerBroadcast()
{

    esp_now_peer_info_t peerInfo = {};

    memcpy(
        peerInfo.peer_addr,
        enderecoBroadcast,
        6);

    peerInfo.channel = CANAL_ESPNOW;

    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {

        Serial.println(
            "Erro adicionando broadcast peer.");
    }
    else
    {

        Serial.println(
            "Broadcast peer adicionado.");
    }
}

// =========================================================
// LÊ COMANDO DO MEGA
// =========================================================

void lerComandoMega()
{

    if (!SerialMega.available())
    {
        return;
    }

    char comando =
        SerialMega.read();

    if (!comandoValido(comando))
    {
        return;
    }

    enviarComandoESPNow(comando);
}

// =========================================================
// VALIDA COMANDO
// =========================================================

bool comandoValido(char comando)
{

    return (
        comando == 'F' ||
        comando == 'D' ||
        comando == 'E' ||
        comando == 'B' ||
        comando == 'P');
}

// =========================================================
// ENVIA VIA ESP-NOW
// =========================================================

void enviarComandoESPNow(char comando)
{

    pacote.assinatura = 0x524F424F; // "ROBO"

    pacote.sequencia =
        contadorPacotes++;

    pacote.comando =
        comando;

    esp_err_t resultado =
        esp_now_send(
            enderecoBroadcast,
            (uint8_t *)&pacote,
            sizeof(pacote));

    Serial.print("TX -> ");

    Serial.print(comando);

    Serial.print(" | ");

    if (resultado == ESP_OK)
    {

        Serial.println("OK");
    }
    else
    {

        Serial.println("ERRO");
    }
}