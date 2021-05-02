# sdvx_leonardo
Arduino Leonardo code to make a Sound Voltex Controller

## INTRODUCTION

Sound Voltex is a rhythm game created by Konami. Since it is an arcade game,
there are no official controllers and no offical way to play at home. Luckily
for us, there is a simulator called K-Shoot Mania. Since we would like to
recreate the arcade experience, we will need to create a controller to play the
game. This project should help you to create a Sound Voltex controller using an
Arduino Leonardo. It takes 7 buttons and 2 rotary encoders and maps them to
keyboard and mouse inputs. This allows us to play Sound Voltex/K-Shoot with our
homebrew controllers.

## WIRING

Here's how to correctly hook up the wires. Firstly, each button needs two
wires. One should go to a digital pin as listed below, and the other should go
to the ground. The encoders should have three wires, two to the digital pins
and one to the ground.

Button A -> Digital 4

Button B -> Digital 5

Button C -> Digital 6

Button D -> Ditital 7

Button FX-L -> Digital 8

Button FX-R -> Digital 9

Button Start -> Digital 10

Rotary Encoder 1 -> Digital 0 and Digital 1

Rotary Encoder 2 -> Digital 2 and Digital 3

## MAPPING

The buttons are mapped to alphanumeric keys, while the encoders are mapped to
mouse inputs. You may want to change your FX key bindings if you primarily use
a Japanese keyboard.

Button A : "d"

Button B : "f"

Button C : "j"

Button D : "k"

Button FX-L : "c"

Button FX-R : "m"

Button Start : "1"

Encoder 1 : Mouse Y-Axis

Encoder 2 : Mouse X-Axis

## HOW IT WORKS

During intialization, we set the pins for the buttons to output HIGH. Since one
wire is hooked to ground, when the button is pushed it should cause the pin to
go to ground. If we read the pin at this time, it should read LOW and thus we
know that the button is pushed down. Once we know the button is pushed down, we
output a keyboard press through the arduino to the apporiate letter. Once the
button is released, we can also release the keyboard press.

The encoders will read its location at every cycle. We then determine if this
is more or less than previous and move the mouse x/y axis accordingly. We also
set a boundary of -128 <= reading <= 127 and reset the value once they go
beyond this limit.

## SOURCES

http://forum.arduino.cc/index.php/topic,72276.0.html -- Pushbuttons

www.circuitsathome.com/mcu/reading-rotary-encoder-on-arduino -- Encoders;
library needed for encoders
