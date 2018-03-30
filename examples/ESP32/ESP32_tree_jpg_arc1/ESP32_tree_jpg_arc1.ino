#include <GD23Z.h>

#define RAM_TREE 0

//static const PROGMEM prog_uchar tree[] = {
static const unsigned char PROGMEM tree[] = {   
  
  #include "tree.h"
};

void arc(int x, int y, int la, int ra, int s, int t,int c)
{  
  GD.Begin(POINTS);
  GD.PointSize(t);
  GD.ColorRGB(c);                // select the color
       
  for(int i=la;i<ra;i+=1)
   { 
     int xi,yi;
     GD.polar(xi,yi,s,i*180);          // calculates xy co-ordinates of arc point.
     GD.Vertex2f((x+xi)*16,(y+yi)*16);      
   }
}

void setup()
{
  EEPROM.begin(512); // Use only for ESP8266 and ESP32 calibration screen
  GD.begin();
  GD.cmd_inflate(RAM_TREE);
  GD.copy(tree, sizeof(tree));
  GD.BitmapHandle(0);
  GD.BitmapSource(0);
  GD.BitmapLayout(ARGB1555, 960, 272);
  GD.BitmapSize(NEAREST, BORDER, BORDER, 480, 272);
}

void loop()
{
  //GD.Clear(1, 1, 1);
  
  GD.SaveContext();
  // GD.ColorA(70);
   GD.Begin(BITMAPS);
   GD.Vertex2ii(0, 0, 0, 0);
   GD.End();
  GD.RestoreContext();

    arc(150,100,135,225,80,100,0xFF6420);  
    arc(150,100,135,225,60,60,0xFF6420);
    arc(150,100,135,225,40,30,0xFF6420);
    arc(150,100,135,225,20,10,0xFF6420);
  
  GD.swap();
}
