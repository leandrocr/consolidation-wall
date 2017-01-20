int ba = 8;
int bb = 9;
int consolidationWallSlot = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(ba, OUTPUT);
  pinMode(bb, OUTPUT);
}

void loop() {
  
  
  if (Serial.available() > 0) {
    consolidationWallSlot = Serial.parseInt();

    if (consolidationWallSlot == 1) {
      consolidationWallSlot = 8;
    } else {
      consolidationWallSlot = 9;
    }
    

    turnOn(consolidationWallSlot);
  }

  delay(10);
}

void turnOn(int ledNumber) {
  digitalWrite(ba, LOW);
  digitalWrite(bb, LOW);

  digitalWrite(ledNumber, HIGH);

  
}

