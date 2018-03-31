#include <GD23Z.h>

File archivo;
//SdFatSdio SD;
SdFatSdioEX SD;

void setup()
{
  GD.begin();
  SD.begin();
  
  archivo = SD.open("tree.jpg");
  GD.cmd_loadimage(0, 0);
  GD.loadSDIO(archivo);
}

void loop()
{
  GD.ClearColorRGB(0x202020);
  GD.Clear();
   GD.Begin(BITMAPS);
   GD.Vertex2ii(0, 0);
   GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");
  GD.swap();
}
