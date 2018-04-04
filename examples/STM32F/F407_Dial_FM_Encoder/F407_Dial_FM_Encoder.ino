#include <GD23Z.h>

#include "Dial.h"

SdFatSdio SD;


//Grupo 1 de assets
char Asset1[] = "Dial.gd2";  File DialFM;
String STRAsset1(Asset1);
//Grupo 1 de assets

// Pines de lectura del encoder
int a = PD15;  //CLK
int b = PD14;  //DT

// Valores de medida
int anterior = 1;
int contador;
char texto[10];

void setup() {
  // Inicializamos la lectura del encoder
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  
  SD.begin();
  GD.begin();

  MP();
}

void loop() {}

float PDX=50, BasePDX=95, PDY=100;

float Dial=0;

void MP()
{
  DialFM = SD.open(STRAsset1);
  LOAD_ASSETS1();
  
  while(1)
  {
   LeeEncoder();
   GD.get_inputs();
   GD.ClearColorRGB(75, 0, 25);
   GD.Clear();
   GD.SaveContext(); 
    GD.Begin(BITMAPS);
     GD.Vertex2ii(50, PDY, 1);
     GD.Vertex2ii(50+350, PDY, 2);
    GD.End();
   GD.RestoreContext();

  GD.SaveContext();
    GD.Begin(LINES);
    GD.LineWidth(70);
    GD.ColorRGB(0xff0000);  GD.Vertex2f(16*(PDX+BasePDX+Dial+5), 16*120);   GD.Vertex2f(16*(PDX+BasePDX+Dial+5), 16*150);
  GD.RestoreContext();

    GD.SaveContext();
    GD.ColorRGB(0,0xaa,0);  GD.Tag(104);  GD.cmd_button(350, 250, 70, 35, 26, 0, "<");  GD.Tag(255);
    if (GD.inputs.tag==104)
     {
       delay(75);
       Dial= Dial-2.5;
       //if (Dial<=-12.5){Dial=-12.5;} //12.5=(88-87.5)/0.04  limite inferior 87.5 MHz
       if (Dial<=-50.0){Dial=-50.0;}  //50=(88-86)/0.04       limite inferior 86   MHz
     }    
    GD.ColorRGB(0,0xaa,0);  GD.Tag(105);  GD.cmd_button(500, 250, 70, 35, 26, 0, ">");  GD.Tag(255);
    if (GD.inputs.tag==105)
     {
       delay(75);
       Dial= Dial+2.5;
       //if (Dial>=550){Dial=550;}  //88+500*0.04=108 MHz max
       if (Dial>=550){Dial=550;}   //550= (110-88)/0.04, 110 MHz max
     }

  GD.ColorRGB(0,0xaa,0);  GD.Tag(106);  GD.cmd_button(100, 250, 100, 35, 30, 0, "97.7");  GD.Tag(255);
   if (GD.inputs.tag==106)
     {
       delay(75);
       Dial= (97.7-88)/0.04;
     }

  GD.ColorRGB(0,0xaa,0);  GD.Tag(107);  GD.cmd_button(100, 310, 100, 35, 30, 0, "101.3");  GD.Tag(255);
   if (GD.inputs.tag==107)
     {
       delay(75);
       Dial= (101.3-88)/0.04;
     }     
  GD.RestoreContext();
  
  GD.cmd_romfont(15,34);
  GD.printNfloat(550, -15, 88+(Dial*0.04), 1, 15);  GD.cmd_text(650, 53, 31, OPT_CENTER, "MHz");
  //GD.printNfloat(550, 0, 88+(Dial*0.04), 1, 31);  GD.cmd_text(650, 53, 31, OPT_CENTER, "MHz");
  GD.swap();
  }
}
