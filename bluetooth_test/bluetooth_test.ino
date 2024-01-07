void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int data;
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {

    data = Serial.read();
    Serial.print(data);
    Serial.print("  ");
  }
  if (Serial.available()) {
    data = Serial.read();
    Serial.print(data);
    Serial.print("  ");
  }
  if (Serial.available()) {
    data = Serial.read();
    Serial.println(data);
  }
  
}
