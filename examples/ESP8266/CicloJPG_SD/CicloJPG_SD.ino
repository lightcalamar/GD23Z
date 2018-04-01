#include <GD23Z.h>

unsigned long start;

void setup()
{
  GD.begin();
}

void loop(){
 Ciclo();
}

void CargaJPG()
{
   GD.Clear();
   GD.Begin(BITMAPS);  
   GD.Vertex2ii(0, 0); 
    GD.ColorRGB(255,0,0);  GD.cmd_number(30,260,21,OPT_CENTER|OPT_SIGNED,millis() - start);
   GD.swap();
}
