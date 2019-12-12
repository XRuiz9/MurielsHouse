#include <ESP32Servo.h>

#define button 0
#define flip 27
#define light1 15
#define light2 ??
#define doorPin 18
#define silPin ?? 
#define lightSen ??

Servo door, sil;
int one = 140;
int two = 45;
int pos;

void setup() {
  
  //Serial + Sensors
  Serial.begin(115200);
  pinMode(button, INPUT);
  pinMode(flip, INPUT);

  //Light
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  
  //Servo
  pos = one;
  door.setPeriodHertz(50);
  door.attach(doorPin);
  sil.setPeriodHertz(50);
  sil.attach(silPin);
  
}

void loop() {
  
  // Check sensors
  String out = "";
  int buttRead = analogRead(button);
  int flipRead = analogRead(flip);
  out = out + String(buttRead) + "," + String(flipRead);
  Serial.println(out);

  if (buttRead == 0) {
//    play ding dong
    delay(2000)
    sil.write(two);
//    play walk down stairs
//    play slippers on floor
    delay(9000);
    door.write(two);
//    play open door
    delay(5000);
    door.write(one);
//    play close door
  }

  // Switch lights off
  if (flipRead == 0) {
    digitalWrite(light1, LOW);
    //digitalWrite(light2, LOW);
    //play oh my
  }
}
