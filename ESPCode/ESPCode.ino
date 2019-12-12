#include <ESP32Servo.h>

#define button 0
#define flip 27
#define lightSen 33

#define light1 15
#define light2 4

#define doorPin 17
#define silPin 19


Servo door, sil;
int one = 140;
int two = 45;
int pos;

void setup() {
  
  //Serial + Sensors
  Serial.begin(115200);
  pinMode(button, INPUT);
  pinMode(flip, INPUT);
  pinMode(lightSen, INPUT);

  //Light
  pinMode(light1, OUTPUT);
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
  pinMode(light2, OUTPUT);
  
  
  //Servo
  pos = one;
  door.setPeriodHertz(50);
  door.attach(doorPin);
  door.write(one);
  sil.setPeriodHertz(50);
  sil.attach(silPin);
  sil.write(one);
  delay(1000);
}

void loop() {
  
  // Check sensors
  String out = "";
  int buttRead = analogRead(button);
  int flipRead = analogRead(flip);
  int lightRead = analogRead(lightSen);
//  out = out + String(lightRead) + "," + String(flipRead);
//  out = out + String(lightRead) + "," + String(buttRead) + "," + String(flipRead);
//  Serial.println(out);

  //Dark out
  if (lightRead > 1000) {
    digitalWrite(light1, HIGH);
    digitalWrite(light2, HIGH);
    flipSwitch(flipRead, true);
    doorbell(buttRead);
  } 
  //Light out 
  else {
    digitalWrite(light1, LOW);
    digitalWrite(light2, LOW);  
    flipSwitch(flipRead, false);
    doorbell(buttRead);
  }
}

void flipSwitch(int val, bool darkOut) {
  // Switch lights off
  if (darkOut) {
    if (val == 0) {
      int curr = digitalRead(light1);

      if (curr == HIGH) {
        digitalWrite(light1, LOW);
        digitalWrite(light2, LOW);
      } else {
        digitalWrite(light1, HIGH);
        digitalWrite(light2, HIGH);
      }

      //play oh my
    }
  }
}

void doorbell(int val) {
    if (val == 0) {
//  play ding dong
    delay(2000);
    silhouette();
//  play walk down stairs
//  play slippers on floor
    delay(9000);
    door.write(two);
//  play open door
    delay(5000);
    door.write(one);
    delay(9000);
    silhouette();
//  play close door
  }

}

void silhouette() {
  int curr = sil.read();
  Serial.println(curr);
  if (137 < curr) {
    while (curr > two) {
      curr -= 1;
      sil.write(curr);
      delay(15);
    }
  } else if (curr < 47) {
    Serial.println("hi");
    while (curr < one) {
      curr += 1;
      sil.write(curr);
      delay(15);
    }
  }
}
