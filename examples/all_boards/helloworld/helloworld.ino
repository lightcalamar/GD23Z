#include <GD23Z.h>

void setup()
{
//  EEPROM.begin(512); Only for ESP8266 and ESP32
  GD.begin(0);
}

void loop()
{
  GD.ClearColorRGB(0x000015);
  GD.Clear();
  GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");
  GD.swap();
}
