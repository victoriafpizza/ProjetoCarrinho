# 📋 Product Backlog — Carrinho Robô 4WD

## 👥 Integrantes

- **Gabriel Machado**
- **Lourenzo Ramos**
- **Vitor Hugo Rodrigues**
- **Victoria Franceschini**

A divisão das atividades foi feita procurando equilibrar software, eletrônica, mecânica, integração e documentação entre os integrantes.

---

# 👨‍💻 Gabriel Machado

Responsável principalmente pelo software do carrinho, ESP32 receptor e integração dos comandos.

| ID | Tarefa | Prioridade |
|---|---|---|
| B01 | Definir protocolo de comandos do carrinho | Alta |
| B02 | Programar ESP32 receptor | Alta |
| B03 | Implementar recebimento de comandos via ESP-NOW | Alta |
| B04 | Criar funções de movimentação do carrinho | Alta |
| B05 | Implementar lógica de failsafe para perda de comunicação | Média |

### Entregas

- Código do ESP32 receptor;
- Interpretação dos comandos;
- Funções frente, trás, esquerda, direita e parar;
- Comunicação integrada ao sistema;
- Sistema de segurança em perda de sinal.

---

# 🔧 Lourenzo Ramos

Responsável principalmente pela montagem física, motores, Ponte H e alimentação.

| ID | Tarefa | Prioridade |
|---|---|---|
| B06 | Montar o chassi 4WD | Alta |
| B07 | Instalar os quatro motores DC | Alta |
| B08 | Conectar motores à Ponte H | Alta |
| B09 | Implementar sistema de alimentação | Alta |
| B10 | Organizar e revisar o cabeamento | Média |

### Entregas

- Chassi montado;
- Motores instalados;
- Ponte H funcionando;
- Alimentação segura;
- Cabeamento organizado.

---

# 🎮 Vitor Hugo Rodrigues

Responsável pelo controle remoto, leitura do joystick e transmissão dos comandos.

| ID | Tarefa | Prioridade |
|---|---|---|
| B11 | Configurar Arduino Mega e Joystick Shield | Alta |
| B12 | Programar leitura do joystick e botões | Alta |
| B13 | Implementar comunicação Arduino Mega → ESP32 | Alta |
| B14 | Programar ESP32 transmissor utilizando ESP-NOW | Alta |
| B15 | Integrar e testar sensor de proximidade | Média |

### Entregas

- Controle físico funcionando;
- Leitura correta dos comandos;
- Transmissão dos comandos para o carrinho;
- Comunicação sem fio;
- Sensor de proximidade integrado.

---

# 🎨 Victoria Franceschini

Responsável pelo layout físico, LEDs, estrutura e documentação.

| ID | Tarefa | Prioridade |
|---|---|---|
| B16 | Definir posicionamento dos componentes no chassi | Alta |
| B17 | Desenvolver suportes/carenagem em CAD, caso necessário | Média |
| B18 | Instalar e programar LEDs traseiros de freio | Média |
| B19 | Atualizar documentação e diagramas do projeto | Média |
| B20 | Organizar apresentação e demonstração final | Média |

### Entregas

- Layout dos componentes;
- Modelagem CAD;
- Sistema de LEDs;
- Documentação;
- Material de apresentação.

---

# 🤝 Tarefas do Grupo

Algumas atividades deverão ser realizadas em conjunto pelos quatro integrantes.

| ID | Tarefa | Responsáveis |
|---|---|---|
| B21 | Teste completo do MVP | Todos |
| B22 | Teste de alcance da comunicação | Todos |
| B23 | Teste de obstáculos | Todos |
| B24 | Correção de bugs encontrados na integração | Todos |
| B25 | Validação do produto final | Todos |

---

# 📊 Distribuição

| Integrante | Área principal |
|---|---|
| Gabriel Machado | Software / ESP32 receptor / Integração |
| Lourenzo Ramos | Hardware / Motores / Alimentação |
| Vitor Hugo Rodrigues | Controle / Joystick / Comunicação |
| Victoria Franceschini | CAD / LEDs / Documentação |

---

# 🎯 Prioridade de Desenvolvimento

O desenvolvimento deverá seguir aproximadamente esta sequência:

1. Montagem do chassi;
2. Instalação dos motores;
3. Ponte H;
4. Alimentação;
5. Controle com joystick;
6. Comunicação Mega → ESP32;
7. ESP-NOW;
8. ESP32 receptor;
9. Movimentação;
10. Integração;
11. Teste do MVP;
12. Sensor de proximidade;
13. LEDs;
14. Failsafe;
15. Melhorias;
16. Testes finais;
17. Documentação e apresentação.
