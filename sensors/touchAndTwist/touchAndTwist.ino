#include <ESP32Servo.h>

#define button 0
#define flip 27
#define light1 15

Servo door;
int one = 140;
int two = 45;
int pos;
int servoPin = 18;

void setup() {
  
  //Serial + Sensors
  Serial.begin(115200);
  pinMode(button, INPUT);
  pinMode(flip, INPUT);

  //Light
  pinMode(light1, OUTPUT);
  
  //Servo
  pos = one;
  door.setPeriodHertz(50);
  door.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  String out = "";
  int reading = analogRead(button);
  int reading2 = analogRead(flip);

  if (reading2 == 0) {
    digitalWrite(light1, LOW);
    delay(1000);
    digitalWrite(light1, HIGH);
    delay(1000);
  }
  
  out = out + String(reading) + "/" + String(reading2);
  Serial.println(out);

  door.write(two);
  delay(100);
}
