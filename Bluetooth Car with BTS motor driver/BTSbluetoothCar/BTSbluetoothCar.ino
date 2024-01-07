#define L1 9   //Left Motor MB2
#define L2 10  //Left Motor MB1
#define R1 5   //Right Motor MA1
#define R2 6   //Right Motor MA2  //Right Motor Enable Pin EA
int speed = 100;
//*************************************************//

void setup() {
  Serial.begin(9600);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L1, OUTPUT);
}


char data;

void goForward() {
  speed = 100;
  analogWrite(R1, speed);
  digitalWrite(R2, LOW);
  digitalWrite(L1, LOW);
  analogWrite(L2, speed);
}
void goLeft(int n) {
  if (n == 1) {
    analogWrite(R1, speed);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  } else if (n == 2) {

    analogWrite(R1, speed);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    analogWrite(L2, speed - 40);
  }
}
void goRight(int n) {
  if (n == 1) {
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    analogWrite(L2, speed);
  } else if (n == 2) {

    analogWrite(R1, speed - 40);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    analogWrite(L2, speed);
  }
}

void goBackward() {
  digitalWrite(R1, LOW);
  analogWrite(R2, speed);
  analogWrite(L1, speed);
  digitalWrite(L2, LOW);
}

void goStop() {
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
}

void loop() {

  if (Serial.available()) {
    //sensorRead();
    data = Serial.read();
    Serial.println(data);
  }

  if (data == 'L') {
    goLeft(1);
  }

  else if (data == 'R') {
    goRight(1);
  } else if (data == 'G') {
    goLeft(2);
  } else if (data == 'I') {
    goRight(2);
  } else if (data == 'H') {
    goLeft(3);
  } else if (data == 'J') {
    goRight(3);
  } else if (data == 'F') {
    goForward();
  }

  else if (data == 'B') {
    goBackward();
  }

  if (data == 'S') {
    goStop();
  }
  //Serial.println("   Stop");
}