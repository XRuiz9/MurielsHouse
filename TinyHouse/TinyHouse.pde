import processing.serial.*;
import ddf.minim.*;
import ddf.minim.ugens.*;

Minim minim;
AudioOutput out;
Sampler dingDong, stairsD, stairsU, fDoor, powerDown, cooking, music, tv, bathroom;

Serial myPort;

boolean darkOut, cooked, danced, watched, flushed, busy, power = false;
int diff = 0;
long currT, startT;

void setup() {
  size(800, 480);
  myPort = new Serial(this, Serial.list()[33], 115200);
  
  //Load sounds
  minim = new Minim(this);
  out = minim.getLineOut();
  dingDong = new Sampler("DingDong.wav", 4, minim);
  dingDong.patch(out);
  stairsU = new Sampler("StairsU.wav", 4, minim);
  stairsU.patch(out);
  stairsD = new Sampler("StairsD.wav", 4, minim);
  stairsD.patch(out);
  fDoor = new Sampler("FDoor.wav", 4, minim);
  fDoor.patch(out);
  powerDown = new Sampler("PowerDown.wav", 4, minim);
  powerDown.patch(out);
  cooking = new Sampler("Cooking.wav", 4, minim);
  cooking.patch(out);
  music = new Sampler("Music.wav", 4, minim);
  music.patch(out);
  tv = new Sampler("Tv.wav", 4, minim);
  tv.patch(out);
  bathroom = new Sampler("Bathroom.wav", 4, minim);
  bathroom.patch(out);
}

void draw() {
  currT = millis()
  while (myPort.available() > 0) {
    if (diff != 0) {
      busy = true;
      if (currT - startT > diff) {
        diff = 0;
        busy = false;
      }
    }
    String inMsg = myPort.readString();
    String[] input = split(inMsg, ",");
    
    int flipRead = int(input[1]);
    int buttRead = int(input[2]);
    int ind = int(input[3]);
    
    println(ind);
    
    if (flipRead == 0) {
      if (!power) {
        powerDown.trigger();
        power = true;
      }
    } else {
      power = false;
    }
    
    if (buttRead == 0) {
      dingDong.trigger();
      if (!busy) {
        delay(3000);
        stairsD.trigger();
        delay(8000);
        fDoor.trigger();
        delay(5000);
        stairsU.trigger();
      }
    }
    
    if ((0 <= ind) && (ind <= 5) && (!cooked) && (!busy)) {
      cooking.trigger();
      diff = 48000;
      startT = millis();
      
      reset();
      cooked = true;
    }
    if ((6 <= ind) && (ind <= 9) && (!flushed) && (!busy)) {
      bathroom.trigger();
      diff = 23000;
      startT = millis();
  
      reset();
      flushed = true;
    }
    if ((10 <= ind) && (ind <= 15) && (!watched) && (!busy)) {
      tv.trigger();
      diff = 53000;
      startT = millis();

      reset();
      watched = true;
    }
    if ((16 <= ind) && (ind <= 20) && (!danced) && (!busy)) {
      music.trigger();
      delay(69000);
      
      reset();
      danced = true;
    }
  }
}

void reset() {
  cooked = false;
  danced = false;
  watched = false;
  flushed = false;
}
