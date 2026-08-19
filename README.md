# 🤖 Carrinho Robô 4WD com Arduino Mega 2560 e ESP32

Projeto de um **carrinho robô 4WD controlado remotamente**, desenvolvido utilizando **Arduino Mega 2560**, **ESP32 com Joystick Shield**, sensores e motores DC.

O objetivo do projeto é desenvolver um robô móvel capaz de receber comandos de movimentação remotamente, controlar quatro motores e identificar obstáculos através de um sensor de proximidade.

---

## 🎯 Objetivo do Projeto

Desenvolver um carrinho robótico capaz de:

- Movimentar-se para frente e para trás;
- Realizar curvas para esquerda e direita;
- Receber comandos através de um joystick;
- Comunicar o controle ESP32 com o Arduino Mega;
- Detectar obstáculos utilizando um sensor de proximidade;
- Controlar quatro motores DC através de uma Ponte H;
- Utilizar LEDs como sinalização visual do robô;
- Implementar uma estrutura física utilizando um chassi 4WD de acrílico.

---

## 🧰 Componentes Utilizados

| Componente | Quantidade | Função |
|---|---:|---|
| Arduino Mega 2560 | 1 | Controlador principal do carrinho |
| ESP32 | 1 | Comunicação e controle remoto |
| Joystick Shield | 1 | Controle da movimentação |
| Sensor de proximidade | 1 | Detecção de obstáculos |
| Ponte H | 1 | Controle dos motores DC |
| Motores DC | 4 | Movimentação do robô |
| Rodas | 4 | Locomoção |
| LEDs vermelhos | 2 | Sinalização |
| Resistores | 2+ | Proteção dos LEDs e circuito |
| Mini Protoboard | 1 | Organização das conexões |
| Suporte para pilhas | 1 | Alimentação do sistema |
| Fios Jumper | Diversos | Conexões elétricas |
| Chassi 4WD de acrílico | 1 | Estrutura física do robô |

---

## 🏎️ Chassi

O projeto utiliza um **chassi 4WD de acrílico**, contendo quatro motores independentes e quatro rodas.

Modelo utilizado:

**Kit Chassi 4WD com 4 motores e rodas para montagem de robôs**

O kit possui:

- Base dupla em acrílico;
- 4 motores DC;
- Caixa de redução;
- 4 rodas com pneus;
- Suporte para pilhas;
- Parafusos e espaçadores para montagem.

🔗 Produto de referência:

https://www.roboticaeducacional.art.br/kit-4wd-chassi-para-montagem-de-robo

---

## 🧠 Arquitetura do Projeto

O sistema será dividido em dois módulos principais:

### 🎮 Controle Remoto

O controle será responsável por receber os comandos do usuário.

Componentes:

- ESP32;
- Joystick Shield.

O ESP32 interpreta a posição do joystick e envia comandos para o carrinho.

Exemplos de comandos:

```text
FRENTE
TRÁS
ESQUERDA
DIREITA
PARAR
