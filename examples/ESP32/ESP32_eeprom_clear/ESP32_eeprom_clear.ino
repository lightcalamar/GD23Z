/*
 * EEPROM Clear
 *
 * Sets all of the bytes of the EEPROM to 0.
 * This example code is in the public domain.
 * 
 * Modified by @lightcalamar for screen FTDI
 * RESET EEPROM for calibration ESP32 and ESP8266 screen FT81x
 * Date: April, 1 2018
 */

#include <EEPROM.h>
#include <GD23Z.h>

int i =0;

void setup()
{

  GD.begin();

  
  EEPROM.begin(512);
  // write a 0 to all 512 bytes of the EEPROM
  for (int i = 0; i < 512; i++)
    EEPROM.write(i, 0);

  // turn the LED on when we're done
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  EEPROM.end();
  clear_eeprom();
}

void loop() { }


void clear_eeprom()
{
  do {
  GD.ClearColorRGB(0x0000ff);
  GD.Clear();
  GD.ColorRGB(0xffffff);
  GD.get_inputs(); 
   
  GD.Tag(2);
  GD.cmd_fgcolor(0xff0000);
  GD.cmd_button(290, 220, 250, 120, 30, 0, "Reset EEPROM"); GD.Tag(255);

  if (GD.inputs.tag == 2) {delay(140);
    
    reset1();
    
      }
    GD.swap();
  } while(1);
  
}

void reset1(){

    do {
    GD.Clear();
    GD.cmd_text(220, 200, 31, 0, "Reset CALIBRATION");
     GD.swap();
    } while(1);
   
}

