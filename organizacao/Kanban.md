# 🗂️ Kanban — Carrinho Robô 4WD

O Kanban será utilizado para acompanhar o andamento das tarefas do projeto.

O fluxo utilizado será:

```text
BACKLOG → TO DO → IN PROGRESS → REVIEW / TEST → DONE
```

Caso uma tarefa dependa de outra atividade que ainda não foi concluída, deverá receber a marcação:

> 🚫 **BLOQUEADA**

---

# 📥 Backlog

Funcionalidades que serão desenvolvidas após a conclusão das atividades essenciais.

| ID | Tarefa | Responsável |
|---|---|---|
| B05 | Implementar failsafe | Gabriel |
| B10 | Organização final do cabeamento | Lourenzo |
| B15 | Integrar sensor de proximidade | Vitor Hugo |
| B17 | Desenvolver suportes/carenagem em CAD | Victoria |
| B18 | Implementar LEDs de freio | Victoria |
| B22 | Testar alcance da comunicação | Todos |
| B23 | Testar detecção de obstáculos | Todos |
| B25 | Validar produto final | Todos |

---

# 📌 To Do

Tarefas necessárias para construir o primeiro MVP.

| ID | Tarefa | Responsável |
|---|---|---|
| B01 | Definir protocolo de comandos | Gabriel |
| B02 | Programar ESP32 receptor | Gabriel |
| B06 | Montar chassi 4WD | Lourenzo |
| B07 | Instalar motores | Lourenzo |
| B08 | Instalar Ponte H | Lourenzo |
| B09 | Configurar alimentação | Lourenzo |
| B11 | Configurar Mega + Joystick | Vitor Hugo |
| B12 | Programar leitura do joystick | Vitor Hugo |
| B13 | Comunicação Mega → ESP32 | Vitor Hugo |
| B14 | Configurar ESP-NOW transmissor | Vitor Hugo |
| B16 | Definir layout dos componentes | Victoria |
| B19 | Atualizar documentação | Victoria |

---

# 🚧 In Progress

Mover para esta coluna quando algum integrante iniciar efetivamente uma tarefa.

| ID | Tarefa | Responsável |
|---|---|---|
| — | Nenhuma tarefa registrada atualmente | — |

---

# 🧪 Review / Test

Tarefas implementadas que ainda precisam de validação.

| ID | Tarefa | Responsável |
|---|---|---|
| — | Nenhuma tarefa registrada atualmente | — |

---

# ✅ Done

Tarefas completamente implementadas e validadas.

| ID | Tarefa | Responsável |
|---|---|---|
| — | Nenhuma tarefa registrada atualmente | — |

---

# 🎯 Primeiro Sprint — Objetivo: MVP

O primeiro ciclo do projeto deverá priorizar:

### Controle

- [ ] Configurar Arduino Mega;
- [ ] Configurar Joystick Shield;
- [ ] Ler comandos do usuário;
- [ ] Enviar comandos para o ESP32.

### Comunicação

- [ ] Configurar ESP32 transmissor;
- [ ] Configurar ESP32 receptor;
- [ ] Implementar ESP-NOW;
- [ ] Testar envio e recebimento de comandos.

### Carrinho

- [ ] Montar chassi;
- [ ] Instalar quatro motores;
- [ ] Instalar Ponte H;
- [ ] Implementar alimentação;
- [ ] Programar controle dos motores.

### Integração

- [ ] Integrar controle e carrinho;
- [ ] Implementar movimento para frente;
- [ ] Implementar curva para esquerda;
- [ ] Implementar curva para direita;
- [ ] Implementar parada/freio;
- [ ] Realizar teste completo do MVP.

---

# 🏁 Segundo Sprint — Finalização

Após atingir o MVP:

- [ ] Implementar movimento para trás;
- [ ] Implementar sensor de proximidade;
- [ ] Implementar parada automática;
- [ ] Implementar LEDs de freio;
- [ ] Implementar failsafe;
- [ ] Ajustar velocidade dos motores;
- [ ] Organizar cabeamento;
- [ ] Finalizar estrutura física;
- [ ] Realizar testes finais;
- [ ] Corrigir bugs;
- [ ] Atualizar documentação;
- [ ] Preparar demonstração.

---

# 📏 Regras do Kanban

1. Cada tarefa deverá possuir um responsável;
2. Uma tarefa só entra em **In Progress** quando realmente começar;
3. Tarefas implementadas devem passar por **Review / Test**;
4. Somente tarefas testadas podem entrar em **Done**;
5. Dependências não concluídas devem gerar a marcação **Bloqueada**;
6. Problemas encontrados nos testes devem voltar para **In Progress**;
7. As tarefas do MVP possuem prioridade sobre funcionalidades adicionais.
