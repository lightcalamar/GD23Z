#include <GD23Z.h>
#include "num.h"

//Grupo de assets
char Asset[] = "num.gd2"; File GAsset;  String STRAsset(Asset); //numeros grandes

//SdFatSdio SD;
//SdFat SD(2);  const uint8_t SD_CS = PA11;   //F767ZI    SPI2
SdFat SD(3);  const uint8_t SD_CS = PB11;   

void setup() {

  SD.begin(SD_CS, SD_SCK_MHZ(36));
  GD.begin();
  GAsset = SD.open(STRAsset);
  LOAD_ASSETS();

/*
  GD.BitmapHandle(ONE1_HANDLE);
  GD.BitmapLayout(ARGB4, 2*  200, 300);

  GD.BitmapHandle(ONE2_HANDLE);
  GD.BitmapLayout(ARGB4, 2*  200, 300);

  GD.BitmapHandle(ONE3_HANDLE);
  GD.BitmapLayout(ARGB4, 2*  200, 300);
*/

  GD.BitmapHandle(T1_HANDLE);
  GD.BitmapLayout(ARGB2,  150, 200);

  GD.BitmapHandle(T2_HANDLE);
  GD.BitmapLayout(ARGB2, 150, 200);

  GD.BitmapHandle(T3_HANDLE);
  GD.BitmapLayout(ARGB2,  150, 200);
  
  GD.BitmapHandle(T4_HANDLE);
  GD.BitmapLayout(ARGB2,  150, 200);  

  GD.BitmapHandle(T5_HANDLE);
  GD.BitmapLayout(ARGB2,  150, 200);

  GD.BitmapHandle(T6_HANDLE);
  GD.BitmapLayout(ARGB2,  150, 200);    

  GD.BitmapHandle(T7_HANDLE);
  GD.BitmapLayout(ARGB2,  150, 200);

  GD.BitmapHandle(T8_HANDLE);
  GD.BitmapLayout(ARGB2,  150, 200);

  GD.BitmapHandle(T9_HANDLE);
  GD.BitmapLayout(ARGB2,  150, 200);      

  GD.BitmapHandle(T0_HANDLE);
  GD.BitmapLayout(ARGB2,  150, 200);  
  screen();
}

void loop() { }
