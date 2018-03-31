#include <GD23Z.h>

File archivo;
//SdFatSdio SD;
SdFatSdioEX SD;

unsigned long start;

int TT=0;

void setup()
{
  GD.begin();
  SD.begin();
}

char nombre[32];

void loop(){
  start = millis(); 
  archivo = SD.open("6oBaa.jpg");      
  GD.cmd_loadimage(0, 0);
  GD.loadSDIO(archivo);
  CargaJPG();  delay(TT);

  start = millis();  
  archivo = SD.open("6oBba.jpg");        
  GD.cmd_loadimage(0, 0);
  GD.loadSDIO(archivo);
  CargaJPG();  delay(TT);

  start = millis();    
  archivo = SD.open("6oFb.jpg");      
  GD.cmd_loadimage(0, 0);
  GD.loadSDIO(archivo);
  CargaJPG();  delay(TT);

  start = millis();  
  archivo = SD.open("6oGb.jpg");        
  GD.cmd_loadimage(0, 0);
  GD.loadSDIO(archivo);
  CargaJPG();  delay(TT);

  start = millis();     
  archivo = SD.open("6oHaa.jpg");     
  GD.cmd_loadimage(0, 0);
  GD.loadSDIO(archivo);
  CargaJPG();  delay(TT);
}

void CargaJPG()
{
   GD.Clear();
   GD.Begin(BITMAPS);  
   GD.Vertex2ii(0, 0); 
    GD.ColorRGB(255,0,0);  GD.cmd_number(30,260,21,OPT_CENTER|OPT_SIGNED,millis() - start);
   GD.swap();
}
