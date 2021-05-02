/*
  By Daniel Tam (daniel@danieltam.net)
  modified by Henry Chen <chenx97@aosc.io>
  ============ NOTES ============
  This will create a SDVX Controller using an Arduino Leonardo.
  You will hook up one wire of the button to the Arduino pin and the other to Arduino's ground. When pushed, the button should go to high.
  You will need to download the encoder library and use it in your project for this to work (ww.circuitsathome.com/mcu/reading-rotary-encoder-on-arduino)
  ===============================
*/

// buttons
#include <Mouse.h>
#include <Keyboard.h>
#define BT_A 4
#define BT_B 5
#define BT_C 6
#define BT_D 7
#define FX_L 8
#define FX_R 9
#define BT_ST 10

// encoders
#include "Encoder.h"
Encoder enc1(0, 1);
Encoder enc2(2, 3);
int16_t knob1 = 0;
int16_t knob2 = 0;
int8_t old_knob1 = 0;
int8_t old_knob2 = 0;

void setup()
{
  // set pins to read, and output high
  // when the pins read low, we know that the buttons have been grounded (aka, pushed down)
  pinMode(BT_A, INPUT);
  pinMode(BT_B, INPUT);
  pinMode(BT_C, INPUT);
  pinMode(BT_D, INPUT);
  pinMode(FX_L, INPUT);
  pinMode(FX_R, INPUT);
  pinMode(BT_ST, INPUT);

  digitalWrite(BT_A, HIGH);
  digitalWrite(BT_B, HIGH);
  digitalWrite(BT_C, HIGH);
  digitalWrite(BT_D, HIGH);
  digitalWrite(FX_L, HIGH);
  digitalWrite(FX_R, HIGH);
  digitalWrite(BT_ST, HIGH);

  Mouse.begin();
  Keyboard.begin();
  Keyboard.releaseAll();
}

void loop()
{
  // read encoders
  knob1 = enc1.read();
  knob2 = enc2.read();

  update_knobs();

  // read the buttons for high, if it's low, output a keyboard press
  if (digitalRead(BT_A) == LOW)
  {
    Keyboard.press('d');
  }
  else
  {
    Keyboard.release('d');
  }

  if (digitalRead(BT_B) == LOW)
  {
    Keyboard.press('f');
  }
  else
  {
    Keyboard.release('f');
  }

  if (digitalRead(BT_C) == LOW)
  {
    Keyboard.press('j');
  }
  else
  {
    Keyboard.release('j');
  }

  if (digitalRead(BT_D) == LOW)
  {
    Keyboard.press('k');
  }
  else
  {
    Keyboard.release('k');
  }

  if (digitalRead(FX_L) == LOW)
  {
    Keyboard.press('c');
  }
  else
  {
    Keyboard.release('c');
  }

  if (digitalRead(FX_R) == LOW)
  {
    Keyboard.press('m');
  }
  else
  {
    Keyboard.release('m');
  }

  if (digitalRead(BT_ST) == LOW)
  {
    Keyboard.press('1');
  }
  else
  {
    Keyboard.release('1');
  }
}

void update_knobs()
{
  if (knob1 != old_knob1)
  {
    // if there's a difference in encoder movement from last pass, move the mouse
    if (knob1 < old_knob1)
    {
      Mouse.move(0, -5);
    }
    else
    {
      Mouse.move(0, 5);
    }

    // if overflown, then write back to the encoder
    if ((old_knob1 = knob1) != knob1)
    {
      enc1.write(old_knob1);
    }
  }
  if (knob2 != old_knob2)
  {
    if (knob2 > old_knob2)
    {
      Mouse.move(-5, 0);
    }
    else
    {
      Mouse.move(5, 0);
    }

    // if overflown, then write back to the encoder
    if ((old_knob2 = knob2) != knob2)
    {
      enc2.write(old_knob2);
    }
  }
}
