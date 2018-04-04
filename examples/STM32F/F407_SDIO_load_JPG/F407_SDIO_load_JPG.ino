#include <GD23Z.h>

File archivo1;
SdFat SD;

void setup()
{
  GD.begin();
  SD.begin();
  archivo1 = SD.open("tree.jpg");
  GD.cmd_loadimage(0, 0);
  GD.loadSDIO(archivo1);
}

void loop()
{
   GD.Clear();
    GD.Begin(BITMAPS);
    GD.ColorA(255);
    GD.Vertex2ii(0, 0);
    GD.ColorRGB(255, 255, 255);
  GD.swap(); 
}
