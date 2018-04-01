#include <GD23Z.h>

#include "money.h"
#include "Icons2.h"
#include "Ricon1.h"
#include "H1ico.h"
#include "Radio1.h"
#include "Radio2.h"

char GrupoJPG1[9][15]={"T36a.jpg","T36b.jpg","DX16.jpg","Fn1.jpg","DX2.jpg","DX9.jpg","Fpez1.jpg","DX12.jpg","DX6.jpg"};  //800x480
//char GrupoJPG1[16][15]={"c100.jpg", "cope.jpg", "catin.jpg","europa.jpg","los40.jpg","m80.jpg","maxfm.jpg","melofm.jpg","ondac.jpg","rac1.jpg","radio5.jpg","rmarca.jpg","rne1.jpg","rockfm.jpg","rt.jpg","ser.jpg"};  //64x64
int IDJPG=0;

//Fondo de pantalla
File Filefondoarchivo;
SdFat Sd2(2);
const uint8_t SD2_CS = PA11;   // chip select for sd2
//Fondo de pantalla

//                        0            1             2            3    //IDAsset
char ChAsset[6][11]={"money.gd2", "Icons2.gd2", "Ricon1.gd2", "H1ico.gd2", "Radio1.gd2", "Radio2.gd2"};  File FileAsset;
int NumAssets;          //10            14          14            8             10           9
int IDAsset;

long previousMillis0=0, interval0=2500;
unsigned long start, Test;

void CargaGrupoJPG1(int IDJPG)
{
  start = millis(); 
  String StrAsset(ChAsset[IDAsset]);
  FileAsset = Sd2.open(StrAsset);

  if (IDAsset==0){LOAD_ASSETS0(); NumAssets=10;}
  if (IDAsset==1){LOAD_ASSETS1(); NumAssets=14;}
  if (IDAsset==2){LOAD_ASSETS2(); NumAssets=14;}
  if (IDAsset==3){LOAD_ASSETS3(); NumAssets=8;}
  if (IDAsset==4){LOAD_ASSETS4(); NumAssets=10;}
  if (IDAsset==5){LOAD_ASSETS5(); NumAssets=9;}
  
  
  GD.BitmapHandle(15);
  GD.cmd_loadimage(ASSETS_END, 0);
  Filefondoarchivo = Sd2.open(GrupoJPG1[IDJPG]);
  GD.loadSDIO(Filefondoarchivo);

  Test = millis() - start;
}
