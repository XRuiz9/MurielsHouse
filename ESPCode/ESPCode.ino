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
int diff = 0;

bool cooked, danced, watched, flushed, busy, dancing = false, ds = false, br = true;
long currT, busyT;

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
  if (!busy) {
    if (val == 0) {
      //Ding dong
      delay(2000);
      if (br) {
        silhouette();
        //Walk down stairs
        //Slippers on floor
        delay(7500);
      }
      door.write(two);
      //Open and close door
      delay(5000);
      door.write(one);
      //Walk back up stairs
      delay(9500);
      silhouette();
    }
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

//Handles Muriel's independent actions
void exist(int val, bool darkOut) {
  if ((0 <= val) && (val <= 5) && (!cooked) && (!busy)) {
    downstairs(darkOut);
    diff = 48000;
    busyT = millis();
    inBedroom(false);
    
    reset();
    cooked = true;
  }
  if ((6 <= val) && (val <= 9) && (!flushed) && (!busy)) {
    downstairs(darkOut);
    diff = 23000;
    busyT = millis();
    inBedroom(false);

    reset();
    flushed = true;
  }
  if ((10 <= val) && (val <= 15) && (!watched) && (!busy)) {
    downstairs(darkOut);
    diff = 53000;
    busyT = millis();
    inBedroom(false);

    reset();
    watched = true;
  }
  if ((16 <= val) && (val <= 20) && (!danced)) {
    dancing = true;
    busyT = millis();
    inBedroom(true);
    
    reset();
    danced = true;
  }
}

//Resets action variables 
void reset() {
  cooked = false;
  danced = false;
  watched = false;
  flushed = false;
}

//Turns out lights if downstairs
void downstairs(bool darkOut) {
  if (darkOut) {
    digitalWrite(lightBr, LOW);
    digitalWrite(lightDs, HIGH);  
  }
}

//Tracks what floor Muriel is on
void inBedroom(bool val) {
  br = val;
  ds = !val;
}

//Set up pins, sensors, and servos
void setup() {
  
  //Serial + Sensors
  Serial.begin(115200);
  pinMode(button, INPUT);
  pinMode(flip, INPUT);
  pinMode(lightSen, INPUT);

  //Light
  pinMode(lightBr, OUTPUT);
  digitalWrite(lightBr, HIGH);
  pinMode(lightDs, OUTPUT);
  digitalWrite(lightDs, LOW);
  
  
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
  currT = millis();

  if (dancing) {
    silhouette();
    if (currT - busyT > 68500) {
      dancing = false;
      sil.write(one);
    }  
  }

  if (diff != 0) {
    busy = true;
    if (currT - busyT > diff) {
      diff = 0;
      busy = false;
    }
  }
  
  String out;
  int buttRead = analogRead(button);
  int flipRead = analogRead(flip);
  int lightRead = analogRead(lightSen);
  int ind = random(0, 3000);
  
  out = String(lightRead) + "," + String(flipRead) + "," + String(buttRead) + "," + String(ind);
  Serial.print(out);
  
  //Dark out
  if (lightRead > 2500) {
    if (br) {
      digitalWrite(lightBr, HIGH);
    }
    if (ds) {
      digitalWrite(lightDs, HIGH);
    }
    flipSwitch(flipRead, true);
    exist(ind, true);
    doorbell(buttRead);
    
  } 
  
  //Light out 
  else {
    digitalWrite(lightBr, LOW);
    digitalWrite(lightDs, LOW);  
    flipSwitch(flipRead, false);
    exist(ind, false);
    doorbell(buttRead);
  }
  delay(200);
}
