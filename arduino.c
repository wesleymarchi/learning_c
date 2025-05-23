// --- Ponte H ---
#define IN1 6
#define IN2 7
#define ENA 10
#define IN3 8
#define IN4 9
#define ENB 5

// --- Sensor Ultrassônico ---
#define TRIG 7
#define ECHO 6

// --- Sensores IR ---
#define IR_ESQ A0
#define IR_DIR A1

// --- Controle de movimento ---

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);  // Máxima potência
  analogWrite(ENB, 255);
}

void tras() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);  // Máxima potência
  analogWrite(ENB, 255);
}

void girarEsquerda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 180);  // Potência média para giro
  analogWrite(ENB, 180);
}

void girarDireita() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 180);  // Potência média para giro
  analogWrite(ENB, 180);
}

// --- Função para medir distância com HC-SR04 ---
long medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duracao = pulseIn(ECHO, HIGH);
  return duracao / 58;
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

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
