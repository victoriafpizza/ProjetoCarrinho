# 🚀 MVP — Carrinho Robô 4WD

## 1. Objetivo

O objetivo do projeto é desenvolver um carrinho robótico 4WD controlado remotamente, capaz de receber comandos do usuário através de um controle com joystick, transmitir esses comandos sem fio e executar movimentos através de quatro motores DC.

O sistema também deverá possuir recursos adicionais, como sensor de proximidade e LEDs traseiros de sinalização.

---

# 🟢 MVP — Produto Minimamente Viável

O projeto será considerado minimamente funcional quando for possível controlar o carrinho remotamente e executar seus movimentos principais de maneira estável.

## Requisitos mínimos

Para atingir o MVP, o sistema deverá possuir:

- Chassi 4WD montado;
- Quatro motores DC funcionando;
- Ponte H conectada aos motores;
- Sistema de alimentação funcional;
- Controle utilizando Arduino Mega 2560 e Joystick Shield;
- Comunicação entre o controle e o carrinho utilizando ESP32;
- Comunicação sem fio entre os módulos;
- Comando para movimentar o carrinho para frente;
- Comando para virar para a esquerda;
- Comando para virar para a direita;
- Comando de parada/freio;
- Integração entre hardware e software;
- Testes básicos de movimentação.

## Fluxo esperado do MVP

```text
Joystick / Botões
        ↓
Arduino Mega 2560
        ↓
ESP32 Transmissor
        ↓
Comunicação ESP-NOW
        ↓
ESP32 Receptor no Carrinho
        ↓
Ponte H
        ↓
4 Motores DC
```

## Critério de conclusão do MVP

O MVP será considerado concluído quando um integrante conseguir utilizar o controle para comandar o carrinho a distância e executar, de maneira confiável:

1. Frente;
2. Esquerda;
3. Direita;
4. Parada/Freio.

O carrinho deverá responder aos comandos sem necessidade de conexão física com o controle.

---

# 🏁 Produto Final

Após o MVP, serão implementadas funcionalidades adicionais para concluir o projeto.

O produto será considerado totalmente concluído quando possuir:

- Controle remoto funcionando de forma estável;
- Comunicação ESP-NOW confiável;
- Quatro motores funcionando corretamente;
- Movimentação para frente;
- Movimentação para trás;
- Curvas para esquerda;
- Curvas para direita;
- Sistema de parada/freio;
- LEDs traseiros acionados durante a frenagem;
- Sensor de proximidade funcionando;
- Detecção de obstáculos;
- Parada automática ao detectar um obstáculo;
- Sistema de segurança em caso de perda da comunicação;
- Controle adequado da velocidade dos motores;
- Organização definitiva dos componentes no chassi;
- Cabeamento organizado e seguro;
- Estrutura física finalizada;
- Código organizado e documentado;
- Testes de integração concluídos;
- Documentação do projeto atualizada no GitHub.

---

# 📊 Etapas do Projeto

| Etapa | Resultado esperado |
|---|---|
| Protótipo inicial | Componentes eletrônicos funcionando individualmente |
| Integração | Controle consegue enviar comandos ao carrinho |
| MVP | Carrinho executa frente, esquerda, direita e parada remotamente |
| Evolução | Sensor, LEDs, controle de velocidade e segurança adicionados |
| Produto Final | Sistema completamente integrado, testado e documentado |

---

# ✅ Definição de Pronto

O projeto será considerado finalizado quando todas as funcionalidades classificadas como **Must Have** e **Should Have** estiverem implementadas, integradas e testadas, permitindo uma demonstração completa do carrinho.
