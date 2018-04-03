#include <GD23Z.h>

Dirsearch ds;

char *pickfile(char *ext)
{
  GD.Clear();
  ds.begin();
  for (byte i = 0; ds.get(ext); i++) {
    int x = (i % 3) * 160;
    int y = (i / 3) * 68;
    GD.Tag(i + 1);
    GD.cmd_button(x, y, 150, 60, 27, OPT_FLAT, ds.name);
  }
  GD.swap();

  do {
    GD.get_inputs();
  } while (!GD.inputs.tag);

  ds.begin();
  for (byte i = 0; i <= (GD.inputs.tag - 1); i++)
    ds.get(ext);
  return ds.name;
}

void setup()
{
  EEPROM.begin(512); // Use only for ESP8266 and ESP32 calibration screen
  GD.begin();
}

void loop()
{
  char *avi = pickfile("avi");

  GD.Clear();
  GD.cmd_text(GD.w / 2, GD.h / 2 - 30, 31, OPT_CENTER, "playing");
  GD.cmd_text(GD.w / 2, GD.h / 2 + 30, 31, OPT_CENTER, avi);
  GD.swap();

  MoviePlayer mp;
  mp.begin(avi);
  mp.play();
}
