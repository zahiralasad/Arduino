String command;
String test;
#define ledPin 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equals("on")) {
      digitalWrite(ledPin, HIGH);
      return 1;
    } else if (command.equals("off")) {
      digitalWrite(ledPin, LOW);
      return 0;
    } else if (command.equals("blink")) {
      for (int i=0; i<5; i++){
        digitalWrite(2, HIGH);
        delay(500);
        digitalWrite(2, LOW);
        delay(500);
      }
      return 2;
    }
  }
  delay(1000);
}
