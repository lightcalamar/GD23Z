#include <GD23Z.h>

void setup()
{
//  EEPROM.begin(512); // Use only for ESP8266 and ESP32 calibration screen
 GD.begin();
}

void loop() {
  GD.ClearColorRGB(0xff0000);
  GD.Clear();

   GD.ColorRGB(0x00ff00);
   GD.LineWidth(1 * 16);
   GD.Begin(RECTS);
   GD.Vertex2f(0 * 16, 0* 16);
   GD.Vertex2f((GD.w-1) * 16, (GD.h-1) * 16);
   
   GD.ColorRGB(0x000000);
   GD.Vertex2f(1 * 16, 1* 16);
   GD.Vertex2f((GD.w-2) * 16, (GD.h-2) * 16);

  GD.swap();
}
