import processing.serial.*;
import ddf.minim.*;
import ddf.minim.ugens.*;

Minim minim;
AudioOutput out;
//Sampler dingDong, stairsU, stairsD, doorO, doorC;
Sampler dingDong, stairsD, stairsU, fDoor, powerDown, cooking, music, tv, bathroom;

Serial myPort;

boolean power = false;
boolean darkOut;

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
  while (myPort.available() > 0) {
    float ind = random(0, 3000);
    println(ind);
    String inMsg = myPort.readString();
    //println(inMsg);
    String[] input = split(inMsg, ",");
    //printArray(input);
    
    if (int(input[1]) == 0) {
      if (!power) {
        powerDown.trigger();
        power = true;
      }
    } else {
      power = false;
    }
    
    if (int(input[2]) == 0) {
      dingDong.trigger();
      delay(3000);
      stairsD.trigger();
      delay(8000);
      fDoor.trigger();
      delay(5000);
      stairsU.trigger();
    }
    
    if ((0 <= ind) && (ind <= 5)) {
      cooking.trigger();
      delay(48000);
    }
    if ((6 <= ind) && (ind <= 9)) {
      bathroom.trigger();
      delay(23000);
    }
    if ((10 <= ind) && (ind <= 15)) {
      tv.trigger();
      delay(53000);
    }
    if ((16 <= ind) && (ind <= 20)) {
      music.trigger();
      delay(69000);
    }
  }
}
