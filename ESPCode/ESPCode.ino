#include <ESP32Servo.h>

#define button 0
#define flip 27
#define lightSen 33

#define lightBr 15
#define lightDs 4

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
  pinMode(lightBr, OUTPUT);
  digitalWrite(lightBr, HIGH);
  pinMode(light2, OUTPUT);
  digitalWrite(light2, LOW);
  
  
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
  
  String out;
  int buttRead = analogRead(button);
  int flipRead = analogRead(flip);
  int lightRead = analogRead(lightSen);
  int ind = random(0, 3000);
  
  out = String(lightRead) + "," + String(flipRead) + "," + String(buttRead) + "," + String(ind);
  Serial.print(out);
  
  //Dark out
  if (lightRead > 2000) {
    digitalWrite(lightBr, HIGH);
    digitalWrite(lightDs, HIGH);
    flipSwitch(flipRead, true);
    doorbell(buttRead);
  } 
  
  //Light out 
  else {
    digitalWrite(lightBr, LOW);
    digitalWrite(lightDs, LOW);  
    flipSwitch(flipRead, false);
    doorbell(buttRead);
  }
  delay(200);
}

//Handles switching lights on and off
void flipSwitch(int val, bool darkOut) {
  // Switch lights off
  if (darkOut) {
    if (val == 0) {
      int currBr = digitalRead(lightBr);
      int currDs = digitalRead(lightDs);

      //If either lights are on, turn them off
      if ((currBr == HIGH) || (currDs == HIGH)) {
        digitalWrite(lightBr, LOW);
        digitalWrite(lightDs, LOW);
      } else {
        digitalWrite(lightBr, HIGH);
        digitalWrite(lightDs, HIGH);
      }
    }
  }
}

//Handles doorbell sequence
void doorbell(int val) {
    if (val == 0) {
      //Ding dong
      delay(2000);
      silhouette();
      //Walk down stairs
      //Slippers on floor
      delay(7500);
      door.write(two);
      //Open and close door
      delay(5000);
      door.write(one);
      //Walk back up stairs
      delay(9500);
      silhouette();
  }
}

//Handles movement of silhouette
void silhouette() {
  int curr = sil.read();

  if (137 < curr) {
    while (curr > two) {
      curr -= 1;
      sil.write(curr);
      delay(15);
    }
  } else if (curr < 47) {

    while (curr < one) {
      curr += 1;
      sil.write(curr);
      delay(15);
    }
  }
}
