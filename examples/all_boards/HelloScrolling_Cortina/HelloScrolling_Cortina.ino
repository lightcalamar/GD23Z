//prog_uchar        IDE versi�n anterior, generada por EVE editor  V1.17
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

//Cortina
int PIx=0, velP=-5, Avance=1, Retorno;
//Cortina
 
void setup() {
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
 GD.get_inputs();
 

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


//Cortina

 if (GD.inputs.tag==1)
    { 
      delay(105);  
      Avance=Avance+1;
      if(Avance==1){velP=-5;}
      if(Avance==2){velP=5;  Avance=0;}
    }

 Cortina();

 GD.Tag(1);   
  //GD.cmd_number(750, 350, 31, OPT_RIGHTX | OPT_SIGNED, PIx); 
  //GD.cmd_number(750, 390, 31, OPT_RIGHTX | OPT_SIGNED, Avance); 
  //GD.cmd_number(750, 430, 31, OPT_RIGHTX | OPT_SIGNED, velP);

  GD.ColorA(40);
   GD.ColorRGB(0xffff00);   GD.LineWidth(1 * 16);
   GD.Begin(RECTS);
   GD.Vertex2f(640*16, 340*16); GD.Vertex2f(800*16,480*16);
  GD.ColorA(255);
 GD.Tag(255); 

//Cortina
 
 GD.swap();
}
