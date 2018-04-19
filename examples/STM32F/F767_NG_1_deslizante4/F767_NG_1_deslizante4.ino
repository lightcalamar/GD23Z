#include <GD23Z.h>
#include "NG1.h"

File Filefondoarchivo;

//Grupo de assets
char Asset[] = "NG1.gd2"; File GAsset;  String STRAsset(Asset); //numeros grandes

//SdFatSdio SD;
//SdFat SD(2);  const uint8_t SD_CS = PA11;   //F767ZI    SPI2
SdFat SD(3);  const uint8_t SD_CS = PB11;   //F767ZI    SPI3


//SdFat SD(3); const uint8_t SD_CS = PA15;  //F429ZI, Core7XXI SPI3
//SdFat SD(2); const uint8_t SD_CS = PB12;  //F407, F103       SPI2

int Valor0=0;

void setup() {
//  SD.begin();
  SD.begin(SD_CS, SD_SCK_MHZ(36));
  GD.begin();

  GAsset = SD.open(STRAsset);
  LOAD_ASSETS();
  GD.BitmapHandle(15);
  GD.cmd_loadimage(ASSETS_END, 0);
  Filefondoarchivo = SD.open("Dial1f.png");
  GD.loadSDIO(Filefondoarchivo); 
  Filefondoarchivo.close();

  GD.wr(REG_PWM_DUTY,(5)); 
}

int DeltaY=250, velY=10, AvanceU;

void loop() {
  GD.Clear();

   GD.SaveContext();
    GD.Begin(BITMAPS);
    GD.cmd_number(100, 20, 31, OPT_RIGHTX | OPT_SIGNED, Valor0);
    NumerosXXX(Valor0, 320, 100+50);

    if((AvanceU+1)>=10){GD.Vertex2ii(320+(90*2), DeltaY-150, 0);}else{
    GD.Vertex2ii(320+(90*2), DeltaY-150, AvanceU+1);}
    
    GD.Vertex2ii(320+(90*2), DeltaY, AvanceU);
    
    DeltaY = DeltaY + velY;
    if(DeltaY >=290){DeltaY=140; 
       AvanceU=AvanceU+1;  Valor0=Valor0+1;  
       
       //if(Valor0==60){Valor0=0;}
       if(Valor0==1000){Valor0=0;}
       
       if(AvanceU>=10){AvanceU=0;}
       }
  GD.RestoreContext();

  GD.SaveContext();
   GD.Begin(RECTS);
      GD.ColorRGB(0,0,0);
      GD.Vertex2f(100*16, 0*16);  GD.Vertex2f(700*16, 150*16);
      GD.Vertex2f(100*16, 310*16);  GD.Vertex2f(700*16, 450*16);
  GD.RestoreContext();
  GD.swap();
}
