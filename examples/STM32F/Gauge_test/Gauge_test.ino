#include <GD23Z.h>
#include "NG1.h"

File Filefondoarchivo;

//Grupo de assets
char Asset[] = "NG1.gd2"; File GAsset;  String STRAsset(Asset); //numeros grandes

SdFat SD(2);  const uint8_t SD_CS = PA11;   //F767ZI           SPI2
//SdFat SD(3); const uint8_t SD_CS = PA15;  //F429ZI, Core7XXI SPI3
//SdFat SD(2); const uint8_t SD_CS = PB12;  //F407, F103       SPI2

uint16_t RangoDial=800;
float V0, incremento, Delta1=RangoDial/100;
int Valor0;

//Desplazamiento de panel de control maestro  -central
int movMy = 50, movMybase = 50, velMy = -1; 

void setup()
{
  SD.begin(SD_CS, SD_SCK_MHZ(36));
  GD.begin();

  GAsset = SD.open(STRAsset);
  LOAD_ASSETS();
  GD.BitmapHandle(15);
  GD.cmd_loadimage(ASSETS_END, 0);
  Filefondoarchivo = SD.open("Dial1f.png");
  GD.loadSDIO(Filefondoarchivo); 
  Filefondoarchivo.close();
}

void loop()
{
  if(V0>=RangoDial){incremento=-Delta1;}  //Rango-escala
    if(V0<=0){incremento=Delta1;}  
   V0 = V0 +incremento;

  Valor0 = V0;
  
  GD.Clear();

  GD.SaveContext();
//Gauge central
//RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
  MarcasDial(250,400,280,5,3); 
   Analogico(250,400,280,20,50,100,12,V0,RangoDial,24,400,200, 0,0,0,165);   
//RadioBase, XBase, YBase, LargoSeguidor, largoAguja, EspesorAguja, SeparadorSeguidor, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, R, G, B, radio del pivote.    
  GD.RestoreContext();
//Gauge central   

  GD.printNfloat(100, 100, V0, 0, 31); 
   GD.cmd_number(100, 150, 31, OPT_RIGHTX | OPT_SIGNED, Valor0);
   NumerosXXX(Valor0);

  GD.SaveContext();
  GD.Begin(BITMAPS);
  GD.RestoreContext();

GD.SaveContext();
  GD.ColorA(5); arc(400,280,63,60+(V0*240/RangoDial),230,300,0x0000ff); GD.ColorA(255); 
  GD.ColorA(25); arc(400,280,63,60+(V0*240/RangoDial),240,70,0x0000ff);  GD.ColorA(255); 
  GD.ColorA(25); arc(400,280,63,60+(V0*240/RangoDial),220,70,0x0000ff);  GD.ColorA(255); 
GD.RestoreContext();  

GD.SaveContext();  
   Poly po;
    GD.ColorA(255);  GD.ColorRGB(0x000000);
    if (movMy==0){movMy = 0;}else{movMy = movMy + velMy;}
   po.begin();  po.v(16*(230),16*(480+movMy));    po.v(16*(570),16*(480+movMy));   po.v(16*(500),16*(410+movMy));    po.v(16*(300),16*(410+movMy));    po.draw();
GD.RestoreContext();  
   
  GD.swap();
}

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
