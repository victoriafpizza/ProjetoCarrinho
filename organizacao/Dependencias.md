# 🔗 Dependências do Projeto

Algumas atividades do projeto dependem da conclusão de outras tarefas.

O objetivo deste documento é identificar essas relações para evitar que uma tarefa seja iniciada sem que seus pré-requisitos estejam disponíveis.

---

# 📊 Dependências

| Tarefa | Depende de | Motivo |
|---|---|---|
| Instalação dos motores | Montagem do chassi | Os motores precisam ser fixados na estrutura |
| Conexão da Ponte H | Instalação dos motores | A Ponte H será conectada aos motores |
| Teste dos motores | Ponte H + alimentação | Os motores precisam receber alimentação e controle |
| Leitura do joystick | Configuração do Arduino Mega | O controle precisa estar funcionando |
| Comunicação Mega → ESP32 | Leitura do joystick | Os comandos precisam existir antes de serem transmitidos |
| ESP-NOW | Configuração dos ESP32 | Os dois dispositivos precisam estar configurados |
| ESP32 receptor | ESP-NOW | É necessário receber os pacotes enviados pelo controle |
| Funções de movimentação | Ponte H + motores | O software precisa controlar hardware funcional |
| Controle remoto completo | Joystick + ESP-NOW + receptor | Todas as etapas de comunicação devem estar integradas |
| LEDs de freio | Função de parada | Os LEDs serão acionados junto ao comando de freio |
| Detecção de obstáculos | Sensor instalado | O sensor precisa estar conectado e funcionando |
| Parada automática | Sensor + função de parada | Depende da leitura do obstáculo e da capacidade de frear |
| Failsafe | Comunicação funcionando | É necessário detectar quando os pacotes deixam de chegar |
| Teste do MVP | Movimentação + controle + comunicação | Todos os elementos principais precisam estar integrados |
| Teste final | MVP + funcionalidades Should Have | O produto precisa estar completo |
| Apresentação final | Testes + documentação | Deve representar o funcionamento real do projeto |

---

# 🔄 Fluxo Principal de Dependências

```text
Montagem do Chassi
        ↓
Instalação dos Motores
        ↓
Ponte H
        ↓
Alimentação
        ↓
Teste dos Motores
        ↓
Funções de Movimentação
```

Paralelamente:

```text
Arduino Mega + Joystick
        ↓
Leitura dos Comandos
        ↓
Arduino Mega → ESP32
        ↓
ESP-NOW Transmissor
        ↓
ESP-NOW Receptor
        ↓
Interpretação dos Comandos
```

Os dois fluxos se encontram em:

```text
Movimentação do Carrinho
            +
Controle Remoto
            ↓
      Integração Geral
            ↓
           MVP
```

---

# 🛡️ Funcionalidades Pós-MVP

Após o funcionamento do MVP:

```text
MVP
 │
 ├── Sensor de Proximidade
 │        ↓
 │   Detecção de Obstáculo
 │        ↓
 │   Parada Automática
 │
 ├── Parada/Freio
 │        ↓
 │   LEDs de Freio
 │
 └── Comunicação
          ↓
       Failsafe
```

---

# 🚨 Caminho Crítico

As tarefas consideradas parte do caminho crítico são:

1. Montagem do chassi;
2. Instalação dos motores;
3. Ponte H;
4. Alimentação;
5. Leitura do controle;
6. Comunicação entre os dispositivos;
7. ESP-NOW;
8. ESP32 receptor;
9. Controle dos motores;
10. Integração;
11. Teste do MVP.

Caso alguma dessas tarefas fique bloqueada, o MVP também será impactado.

---

# ⚠️ Regra para tarefas bloqueadas

Caso uma tarefa não possa continuar devido a uma dependência:

- A tarefa deverá ser marcada como **Bloqueada** no Kanban;
- O motivo deverá ser registrado;
- A equipe deverá priorizar a atividade que está causando o bloqueio.
