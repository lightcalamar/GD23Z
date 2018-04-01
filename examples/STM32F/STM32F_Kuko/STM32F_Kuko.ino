#include <GD23Z.h>

#include "Kuku.h"    //Asset0

SdFat Sd2(2);
const uint8_t SD2_CS = PA11;   // STM32F767 chip select for sd2
//const uint8_t SD2_CS = PB12;   // STM32F103 chip select for sd2

//Grupo 0 de assets
char Asset0[] = "Kuku.gd2";  File Kuku0;
String STRAsset0(Asset0);
//Grupo 0 de assets

//Péndulo
int Centro=250/2;   //pendulo 3.png, 250x250 px, Centro=250/2
float AnguloG=0;  //péndulo vertical
float avance, rapidez=1.5;
//Péndulo

#define DS3231_I2C_ADDRESS 0x68
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year; 
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}

void setup()
{
  Wire.begin();
  
  Sd2.begin(SD2_CS, SD_SCK_MHZ(18));
  GD.begin();

  Kuku0 = Sd2.open(STRAsset0);
  LOAD_ASSETS0();  
}

void BaseX()
{
  GD.Clear();
  GD.Begin(BITMAPS);
    GD.Vertex2ii(0, 0, 0);    //cuco
    GD.Vertex2ii(0, 100, 1);  //reloj
    GD.Vertex2ii(0, 200, 2);  //péndulo
  GD.swap();
}

float dato;

void loop()
{
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,&year); 
  GD.ClearColorRGB(0x202020);
  GD.Clear();

   GD.cmd_text((GD.w / 2)+75, GD.h / 2, 31, OPT_CENTER, "MCU: STM32Fx");

  GD.SaveContext();
  GD.Begin(BITMAPS);
    avance = 1 + dato;
    dato = dato + rapidez;
    if((AnguloG+avance)>=15){rapidez=-1.5;}
    if((AnguloG+avance)<=-15){rapidez=1.5;}
    rotate_Center(DEGREES(AnguloG+avance), Centro);
    GD.cmd_setmatrix();
    GD.Vertex2ii(32, 125, 2);
    GD.cmd_loadidentity();
  GD.End();
  GD.RestoreContext();
  //GD.printNfloat(400, 315, dato/10, 1, 29);

  GD.SaveContext();
   GD.Begin(BITMAPS);
   GD.Vertex2ii(50, 50, 1);
  GD.RestoreContext();   

  GD.cmd_clock(151,184,30,OPT_NOTICKS,hour,minute,second,0);


  GD.swap();
}

static void rotate_Center(float a, int CXY)
{
  GD.cmd_translate(F16(CXY),F16(CXY));
  GD.cmd_rotate(a);
  GD.cmd_translate(F16(-CXY), F16(-CXY));
}
