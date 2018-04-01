#include <GD23Z.h>

File archivo;
SdFat SD(2);
const uint8_t SD_CS = PA11;   // chip select for sd2

void setup()
{
  SD.begin(SD_CS, SD_SCK_MHZ(18));
  GD.begin();
  archivo = SD.open("tree.jpg");  

  GD.cmd_loadimage(0, 0);
  GD.loadSDIO(archivo); 
}

void loop()
{
  GD.Clear();
  GD.Begin(BITMAPS);
  GD.Vertex2ii(0, 0);
  GD.swap();
}

