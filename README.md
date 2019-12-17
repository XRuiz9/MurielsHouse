# Muriel's House

Muriel's House is a piece that imagines what it would look like if the dancing mannequins and cardboard cutouts from Kevin McCallister's clever trick lived an actual life of their own. All that is visible to the viewer is Muriel's silhouette, but that doesn't stop her from living her own life independent of outsider interaction.

![Muriel's House](https://github.com/XRuiz9/TinyHouse/blob/master/promo.png)

## Install It Yourself!

In order to replicate this device you'll need the following:

- A device with Arduino IDE and Processing installed on it
- An ESP32 Development Board and USB to Micro-USB cable
- Two servo motors
- Two LEDs
- A switch, a button, and a photosensitive resistor
- A bread board and a number of wires
- A bluetooth speaker
- Cardboard, hot glue, felt, popsicle sticks, felt, black paper, fairy lights, paint

### The Code

First what you'll want to do is clone this git repository. Then, with your ESP32 plugged into your laptop via Micro-USB, you'll want to open the ESPCode.ino and upload it to your ESP32.

The motors and sensors can go wherever you'd like in your enclosure, but pay special attention to what pins they go to in the code. Some things to take note of:
- Both LEDs go from pin to ground (so they can be turned on and off by the pin)
- Both the button and switch go from pin to ground (so switching/pressing them will return 0s)
- The ESPCode.ino file handles the LEDs and motors
- The TinyHouse.pde file handles all the audio, all of which is including in TinyHouse's data folder

### The Enclosure

Unless you decide to create an enclosure identical to mine, the sensors, buttons, and motors can go anywhere you like. It is best to first plan a general guide of where you want things to go before you begin, but you'll find that things may have to move around during development.

The house is split into two floors:
The first floor contains the speaker, the button (doorbell), the switch (power switch), the downstairs LED, and a hole for the Micro-USB cable.

![First Floor](https://github.com/XRuiz9/MurielsHouse/blob/master/first.png)

The second floor contains the motor for Muriel's silhouette, the upstairs LED, the breadboard and ESP32, and holes for wires from the first floor to come up through (and a space for the motor which lies midway between the first and second floors).

![Second Floor](https://github.com/XRuiz9/MurielsHouse/blob/master/second.png)

The roof is also detachable, and the only thing connected to it is the photo-sensitive resistor as that is the only place where light actually comes into the house.

![Roof](https://github.com/XRuiz9/MurielsHouse/blob/master/roof.png)

#### Muriel and the Door
Muriel and the door are both controlled with a servo motor. Muriel is a cutout adhered to a popsicle stick that is attached to the motors arm, while the door is a part of the whole house enclosure, but the cardboard has been scored so that it opens with ease. Additionally, a cut paperclip connects the motors arm to the door, along with lots of hot glue.

![Motors](https://github.com/XRuiz9/TinyHouse/blob/master/motors.png)

#### The LEDs
The LEDs are placed wherever they hit the windows right. Surprisingly, LEDs are quite directional with their lighting so pointing it at certain things looks almost like a spotlight. All you have to do is make sure that spotlight is hitting the windows the way you like it, especially if a silhouette is passing in front of it. Rooms where there are LEDs are painted white so that the light reflects better. The material covering the windows is a semi-transparent plastic that I found from a craft store. It is opaque enough to obscure the inner mechanics, but transparent enough to maintain the shadow of the sihouette.

#### The Doorbell and Power Switch
The doorbell is a simple button that is just glued on the inside of the box. A small screw acts as the actual doorbell that the user presses. The small hole was punctures through the box and the power switch was pushed through. The switch came with washers and bolts that could then be used to tighten the switch and secure it's position.

Once all the mechanisms are in place it's just a matter of decorating it the way you want. Starry night sky enclosure that is featured in the demo video above is not necessary and was created solely as a pretty way to demonstrate the way the lights turn on/off during the "night/day."

### Power Considerations:
This entire piece is powered with one ESP32 plugged into a laptop. No external power sources were used. 
This piece could also run on a Raspberry Pi but you run the risk of slower processing, especially since there are a lot of audio files that triggered throughout the piece. Additionally you'd have to connect the speaker to the Raspberry Pi via bluetooth or aux cord.
