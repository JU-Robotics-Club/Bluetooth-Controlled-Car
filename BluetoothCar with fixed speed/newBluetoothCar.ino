#define L1 5     //Left Motor MB2
#define L2 6     //Left Motor MB1
#define R1 7     //Right Motor MA1
#define R2 8     //Right Motor MA2
#define enaL 9   //Left Motor Enable Pin EB
#define enaR 10  //Right Motor Enable Pin EA
int speed = 200;
//*************************************************//

void setup() {
  Serial.begin(9600);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(enaR, OUTPUT);  // anaa
  pinMode(enaL, OUTPUT);  //enab
}


char data;

// int sensorRead() {
//   //data = Serial.read();
// }

void setSpeed(int speed) {
  analogWrite(enaR, speed);
  analogWrite(enaL, speed);
}

void goForward() {
  setSpeed(200);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
}
void goLeft(int n) {
  if (n == 1) {
    setSpeed(200);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  } else if(n==2){
    analogWrite(enaR, speed);
    analogWrite(enaL, speed-100);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  }
}
void goRight(int n) {
  if (n == 1) {
    setSpeed(200);
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  } else if(n==2){
    analogWrite(enaR, speed-150);
    analogWrite(enaL, speed);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  }
}

void goBackward() {
  setSpeed(200);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(L1, HIGH);
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
  }
   else if (data == 'G') {
    goLeft(2);
  } 
   else if (data == 'I') {
    goRight(2);
  } 
   else if (data == 'H') {
    goLeft(3);
  } 
   else if (data == 'J') {
    goRight(3);
  }  else if (data == 'F') {
    goForward();
  }

  else if (data == 'B') {
    goBackward();
  }

  if (data == 'S') {
    goStop();
  }
}