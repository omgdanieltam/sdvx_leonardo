# sdvx_leonardo
Arduino Leonardo code to make a Sound Voltex Controller

#INTRODUCTION
Sound Voltex is a rhythm game created by Konami. Since it is an arcade game, there are no official controllers and no offical way to play at home. There is a similation of this game called K-Shoot. Since we would want to play the game as if it was an arcade game, we will need to create a controller to play the game. This is to create a Sound Voltex controller using an Arduino Leonardo. It will take 7 buttons and 2 rotary encoders. Using this, we will maps the controls so that it will act as a keyboard and mouse plugged into the computer. Then, we can use this to play Sound Voltex/K-Shoot.

#WIRING
How to correctly hook up the wires. When hooking up the wires for buttons, there should be two wires. One should go to the arudino board as listed below, the other should go to ground. The encoders should have three wires, two to the arduino, and one to ground.

Button A -> Digital 4

Button B -> Digital 5

Button C -> Digital 6

Button D -> Ditital 7

Button FX-L -> Digital 8

Button FX-R -> Digital 9

Button Start -> Digital 10

Rotary Encoder 1 -> Digital 0 and Digital 1

Rotary Encoder 2 -> Digital 2 and Digital 3

#MAPPING
How the keys are mapped in format Button : Keyboard letter

Button A : "a"

Button B : "b"

Button C : "c"

Button D : "d"

Button FX-L : "z"

Button FX-R : "x"

Button Start : "n"

Encoder 1 : Mouse Y-Axis

Encoder 2 : Mouse X-Axis

#HOW IT WORKS
During intialization, we set the pins for the buttons to output HIGH. Since one wire is hooked to ground, when the button is pushed it should cause the pin to go to ground. If we read the pin at this time, it should read LOW and thus we know that the button is pushed down. Once we know the button is pushed down, we output a keyboard press through the arduino to the apporiate letter. Once the button is released, we can also release the keyboard press.

The encoders will read it's location at every cycle. We then determine if this is more or less than previous and move the mouse x/y axis apporiately. Since we are careful not to exceed the arduino's integer number, we set a max number of 255 and a minimum number of -255. If it exceeds this, we set the integer back to 0.

#SOURCES
http://forum.arduino.cc/index.php/topic,72276.0.html -- Pushbuttons

www.circuitsathome.com/mcu/reading-rotary-encoder-on-arduino -- Encoders; library needed for encoders
