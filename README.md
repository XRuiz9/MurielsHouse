# Muriel's House

Muriel's House is a piece that imagines what it would look like if the dancing mannequins and cardboard cutouts from Kevin McCallister's clever trick lived an actual life of their own. All that is visible to the viewer is Muriel's silhouette, but that doesn't stop her from living her own life independent of outsider interaction.

## Install It Yourself!

In order to replicate this device you'll need the following:

- A device with Arduino IDE and Processing installed on it
- An ESP32 Development Board and USB to Micro-USB cable
- Two servo motors
- Two LEDs
- A switch, a button, and a photosensitive resistor
- A bread board and a number of wires
- A bluetooth speaker
- Cardboard, hot glue, felt, popsicle sticks, felt, black paper, fairy lights

### The Code

First what you'll want to do is clone this git repository. Then, with your ESP32 plugged into your laptop via Micro-USB, you'll want to open the ESPCode.ino and upload it to your ESP32.

The motors and sensors can go wherever you'd like in your enclosure, but pay special attention to what pins they go to in the code. Some things to take note of:
- Both LEDs go from pin to ground (so they can be turned on and off by the pin)
- Both the button and switch go from pin to ground (so switching/pressing them will return 0s)
- The ESPCode.ino file handles the LEDs and motors
- The TinyHouse.pde file handles all the audio

### The Enclosure

Unless you decide to create an enclosure identical to mine, the sensors, buttons, and motors can go anywhere you like. It is best to first plan a general guide of where you want things to go before you begin, but you'll find that things may have to move around during development.

#### Muriel and the Door
Muriel and the door are both controlled with a servo motor. Muriel is a cutout adhered to a popsicle stick that is attached to the motors arm, while the door is a part of the whole house enclosure, but the cardboard has been scored so that it opens with ease. Additionally, a cut paperclip connects the motors arm to the door, along with lots of hot glue.

