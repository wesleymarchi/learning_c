// --- Ponte H ---
// Define os pinos conectados aos motores através da ponte H (L298N ou similar)
#define IN1 5     // Entrada 1 do motor da esquerda
#define IN2 4     // Entrada 2 do motor da esquerda
#define ENA 9     // PWM para controle de velocidade do motor da esquerda
#define IN3 3     // Entrada 1 do motor da direita
#define IN4 2     // Entrada 2 do motor da direita
#define ENB 10    // PWM para controle de velocidade do motor da direita

// --- Sensor Ultrassônico ---
// Define os pinos para o sensor de distância (HC-SR04)
#define TRIG 7    // Pino de disparo do sinal ultrassônico
#define ECHO 6    // Pino de recepção do sinal refletido

// --- Sensores IR ---
// Define os pinos dos sensores infravermelhos para detectar a linha branca do limite da arena
#define IR_ESQ A0 // Sensor IR do lado esquerdo
#define IR_DIR A1 // Sensor IR do lado direito

// --- Funções de controle de movimento ---

// Para o robô (desativa ambos os motores)
void parar() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}

// Move o robô para frente
void frente() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);   // Motor esquerdo gira para frente
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);   // Motor direito gira para frente
}

// Move o robô para trás
void tras() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);   // Motor esquerdo gira para trás
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);   // Motor direito gira para trás
}

// Gira o robô para a esquerda (motor direito para frente, motor esquerdo para trás)
void girarEsquerda() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

// Gira o robô para a direita (motor esquerdo para frente, motor direito para trás)
void girarDireita() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

// --- Função para medir distância com o sensor ultrassônico HC-SR04 ---
long medirDistancia() {
  digitalWrite(TRIG, LOW); delayMicroseconds(2);         // Limpa o pulso de trigger
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);       // Envia pulso de 10us
  digitalWrite(TRIG, LOW);                               // Finaliza pulso
  long duracao = pulseIn(ECHO, HIGH);                    // Mede tempo até o eco voltar
  return duracao / 58;                                   // Converte tempo em distância (cm)
}

void setup() {
  // Define os pinos dos motores como saída
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT); pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT); pinMode(ENB, OUTPUT);

  // Define velocidade inicial dos motores (valor entre 0 e 255)
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  // Define os pinos do sensor ultrassônico
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Define os sensores IR como entrada
  pinMode(IR_ESQ, INPUT);
  pinMode(IR_DIR, INPUT);

  // Inicializa a comunicação serial (opcional para debug)
  Serial.begin(9600);
}

void loop() {
  // Lê os sensores infravermelhos
  int linhaEsq = analogRead(IR_ESQ);   // Valor entre 0 e 1023
  int linhaDir = analogRead(IR_DIR);

  // Lê a distância ao obstáculo à frente
  long distancia = medirDistancia();

  // --- Lógica de decisão do robô sumô ---

  // Se qualquer sensor IR detectar a linha branca do limite da arena
  if (linhaEsq < 500 || linhaDir < 500) {
    tras(); delay(300);                  // Recuar por segurança

    // Decide para que lado girar para voltar ao centro
    if (linhaEsq < 500)
      girarDireita();                    // Linha detectada do lado esquerdo → girar para direita
    else
      girarEsquerda();                   // Linha detectada do lado direito → girar para esquerda

    delay(400);                          // Tempo de giro
  }

  // Se detecta oponente à frente em até 25 cm
  else if (distancia > 0 && distancia < 25) {
    frente();                            // Avança para empurrar o oponente
  }

  // Caso contrário, gira à procura do oponente
  else {
    girarDireita();                      // Comportamento de busca girando
  }

  delay(50);                             // Pequena pausa entre as decisões
}
