#define pin 25

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  String out = "";
  int reading = analogRead(pin);
  out = out + String(reading);
  Serial.println(out);
  delay(100);
}
