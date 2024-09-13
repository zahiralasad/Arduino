String command;
#define ledPin 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //Serial.println("Hello");
  if (Serial.available()){
    command = Serial.readStringUntil('\n')
    command.trim();
    if (command.equals('on')){
      digitalWrite(ledPin, HIGH);
    }else{
      digitalWrite(ledPin, Low);

    }
  }
  delay(1000);
  // put your main code here, to run repeatedly:

}
