//prog_uchar        IDE versión anterior, generada por EVE editor  V1.17
//unsigned char     IDE nuevas versiones
//http://forum.arduino.cc/index.php?topic=261093.0

#include <GD23Z.h>

#define RAM_STM32A 0

static const PROGMEM prog_uchar STM32a[] = {
  #include "STM32a.h"
};

int minX = 135, minY = 15;
//int maxX = 480 - minX, maxY = 272 - minY;  //FT80X
int maxX = 800 - minX, maxY = 480 - minY;    //FT81X

int startX = maxX / 2, startY = maxY / 2;
int deltaX = 2, deltaY = 2;
 
void setup()
{
//  EEPROM.begin(512); // Use only for ESP8266 and ESP32 calibration screen
   GD.begin();
   EntornoMP();
}

void EntornoMP()
{
  GD.cmd_inflate(RAM_STM32A);
  GD.copy(STM32a, sizeof(STM32a));
  GD.BitmapHandle(0);
  GD.BitmapSource(0);
  GD.BitmapLayout(ARGB1555, 960, 175);
  GD.BitmapSize(NEAREST, BORDER, BORDER, 480, 175);
}

void loop()
{
 GD.ClearColorRGB(0, 0, 0);
 GD.Clear();

 GD.SaveContext();
  GD.Begin(BITMAPS);
  GD.Vertex2ii(160, 152, 0, 0);
 GD.RestoreContext();
 
 GD.ColorRGB(0x00,0xff,0x00);  GD.cmd_text(startX, startY, 31, OPT_CENTER, "FT81X en linea");
 
 startX = startX + deltaX;   startY = startY + deltaY;
   if (startX >= maxX)
       deltaX = -deltaX;
   if (startX <= minX)
       deltaX = abs(deltaX);
   if (startY >= maxY)
       deltaY = -deltaY;
   if (startY <= minY)
       deltaY = abs(deltaY);
 GD.swap();
}
