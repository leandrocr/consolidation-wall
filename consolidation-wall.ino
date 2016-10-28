int aa = 11;
int ab = 12;
int ac = 13;
int ba = 8;
int bb = 9;
int bc = 10;
int consolidationWallSlot = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(aa, OUTPUT);
  pinMode(ab, OUTPUT);
  pinMode(ac, OUTPUT);
  pinMode(ba, OUTPUT);
  pinMode(bb, OUTPUT);
  pinMode(bc, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    consolidationWallSlot = Serial.parseInt();

    turnOn(consolidationWallSlot);
  }

  delay(1000);
}

void turnOn(int ledNumber) {
  digitalWrite(aa, LOW);
  digitalWrite(ab, LOW);
  digitalWrite(ac, LOW);
  digitalWrite(ba, LOW);
  digitalWrite(bb, LOW);
  digitalWrite(bc, LOW);

  digitalWrite(ledNumber, HIGH);

  Serial.print(ledNumber);
}

