#include <EEPROM.h>
#include <SPI.h>
#include <GD23Z.h>

void setup()
{
  EEPROM.begin(512);  //calibration on eeprom FOR esp8266
  GD.begin();
}

void loop()
{
  MoviePlayer mp;

  mp.begin("fun-1500.avi");
  mp.play();
}
