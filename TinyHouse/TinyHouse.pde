import processing.serial.*;
import ddf.minim.*;
import ddf.minim.ugens.*;

Minim minim;
AudioOutput out;
Sampler dingDong, stairsU, stairsD, doorO, doorC;

Serial myPort;

void setup() {
  size(800, 480);
  
  myPort = new Serial(this, Serial.list()[11], 115200);
  
  //Load sounds
  out = minim.getLineOut();
  dingDong = new Sampler("DingDong.wav", 4, minim);
  dingDong.patch(out);
  stairsU = new Sampler("StairsU.wav", 4, minim);
  stairsU.patch(out);
  stairsD = new Sampler("StairsD.wav", 4, minim);
  stairsD.patch(out):
  doorO = new Sampler("DoorO.wav", 4, minim);
  doorO.patch(out);
  doorC = new Sampler("DoorC.wav", 4, minim);
  doorC.patch(out);
}

void draw() {
  while (myPort.available() > 0) {
    String inMsg = myPort.readString();
    String[] input = split(inMsg, ",");
    
    //If it's light out
    if (int(input[0]) > 3000){
      
    }
    if (int(input[0]) == 0) {
      dingDong.trigger();
      delay(3000);
      stairsD.trigger();
      delay(8000);
      doorO.trigger();
      delay(5000);
      doorC.trigger();
    }
    
    if (int(input[1]) == 0) {
      //ohMy.trigger();
    }
  }
}
