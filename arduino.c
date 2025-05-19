// --- Ponte H ---
// Define os pinos conectados aos motores através da ponte H (L298N ou similar)
#define IN1 6     // Entrada 1 do motor da esquerda
#define IN2 7     // Entrada 2 do motor da esquerda
#define ENA 10    // PWM para controle de velocidade do motor da esquerda
#define IN3 8     // Entrada 1 do motor da direita
#define IN4 9     // Entrada 2 do motor da direita
#define ENB 5     // PWM para controle de velocidade do motor da direita

// --- Sensor Ultrassônico ---
// Define os pinos para o sensor de distância (HC-SR04)
#define TRIG 7    // Pino de disparo do sinal ultrassônico
#define ECHO 6    // Pino de recepção do sinal refletido

// --- Sensores IR ---
// Define os pinos dos sensores infravermelhos para detectar a linha branca do limite da arena
#define IR_ESQ A0 // Sensor IR do lado esquerdo
#define IR_DIR A1 // Sensor IR do lado direito

// --- Funções de controle de movimento ---

void parar() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}

void frente() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void tras() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void girarEsquerda() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void girarDireita() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

// --- Função para medir distância com o sensor ultrassônico HC-SR04 ---
long medirDistancia() {
  digitalWrite(TRIG, LOW); delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duracao = pulseIn(ECHO, HIGH);
  return duracao / 58;
}

void setup() {
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT); pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT); pinMode(ENB, OUTPUT);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(IR_ESQ, INPUT);
  pinMode(IR_DIR, INPUT);

  Serial.begin(9600);
}

void loop() {
  int linhaEsq = analogRead(IR_ESQ);
  int linhaDir = analogRead(IR_DIR);
  long distancia = medirDistancia();

  if (linhaEsq < 500 || linhaDir < 500) {
    tras(); delay(300);
    if (linhaEsq < 500)
      girarDireita();
    else
      girarEsquerda();
    delay(400);
  }
  else if (distancia > 0 && distancia < 25) {
    frente();
  }
  else {
    girarDireita();
  }

  delay(50);
}
