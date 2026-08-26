# 📊 Priorização MoSCoW — Carrinho Robô 4WD

A técnica MoSCoW foi utilizada para definir a prioridade das funcionalidades do projeto.

As funcionalidades foram divididas em:

- **Must Have:** obrigatórias para funcionamento do projeto;
- **Should Have:** importantes, mas não essenciais para o primeiro protótipo;
- **Could Have:** melhorias desejáveis;
- **Won't Have:** funcionalidades que não fazem parte do escopo atual.

---

# 🔴 Must Have

Funcionalidades essenciais para que o projeto possa ser considerado funcional.

| Funcionalidade | Justificativa |
|---|---|
| Chassi 4WD | Estrutura principal do carrinho |
| Quatro motores DC | Responsáveis pela movimentação |
| Ponte H | Permite controlar os motores |
| Sistema de alimentação | Necessário para funcionamento do circuito |
| Leitura do joystick/botões | Permite receber os comandos do usuário |
| Comunicação Arduino Mega → ESP32 | Permite transmitir os comandos do controle |
| Comunicação sem fio | Permite controlar o carrinho remotamente |
| ESP32 receptor no carrinho | Recebe os comandos enviados pelo controle |
| Movimento para frente | Movimento básico do carrinho |
| Curva para esquerda | Controle de direção |
| Curva para direita | Controle de direção |
| Parada/Freio | Segurança e controle do carrinho |
| Integração hardware + software | Necessária para o funcionamento completo |

---

# 🟠 Should Have

Funcionalidades importantes que aumentam a segurança e qualidade do produto.

| Funcionalidade | Justificativa |
|---|---|
| Movimento para trás | Aumenta a capacidade de manobra |
| Sensor HC-SR04/proximidade | Permite detectar obstáculos |
| Parada automática | Evita colisões |
| LEDs traseiros de freio | Sinalização visual durante a frenagem |
| Failsafe de comunicação | Para o carrinho caso o sinal seja perdido |
| Controle de velocidade utilizando PWM | Melhora a dirigibilidade |
| Organização do cabeamento | Aumenta a segurança e confiabilidade |
| Testes de integração | Garante que os módulos funcionam juntos |
| Documentação técnica | Facilita manutenção e apresentação |

---

# 🟡 Could Have

Funcionalidades interessantes caso exista tempo disponível após a conclusão das funções principais.

| Funcionalidade | Benefício |
|---|---|
| Controle proporcional de velocidade pelo joystick | Movimento mais suave |
| Diferentes níveis de velocidade | Melhor experiência de controle |
| Buzina com buzzer | Feedback sonoro |
| LEDs dianteiros | Simulação de faróis |
| Indicador de conexão | Mostra se controle e carrinho estão conectados |
| Indicador de bateria | Facilita monitoramento |
| Carenagem personalizada | Melhora aparência e proteção |
| Peças adicionais impressas em 3D | Melhora organização dos componentes |
| Telemetria do sensor | Permite visualizar distância de obstáculos |

---

# ⚪ Won't Have — Nesta Versão

Funcionalidades que estão fora do escopo atual do projeto.

| Funcionalidade | Motivo |
|---|---|
| Direção autônoma completa | Complexidade acima do escopo |
| GPS | Não necessário para o objetivo atual |
| Câmera com transmissão de vídeo | Não necessária para o MVP |
| Inteligência Artificial | Fora do escopo principal |
| Reconhecimento de objetos | Exigiria hardware e software adicionais |
| Aplicativo mobile | Controle físico já atende ao projeto |
| Mapeamento de ambiente | Complexidade acima do necessário |
| Navegação autônoma | Poderá ser considerada em versões futuras |

---

# 🎯 Ordem de Prioridade

```text
1. Movimentação
        ↓
2. Controle
        ↓
3. Comunicação sem fio
        ↓
4. Integração
        ↓
5. Segurança
        ↓
6. Sensores e LEDs
        ↓
7. Melhorias opcionais
```

O desenvolvimento deverá priorizar primeiro todas as funcionalidades **Must Have**, seguido pelas **Should Have**.
