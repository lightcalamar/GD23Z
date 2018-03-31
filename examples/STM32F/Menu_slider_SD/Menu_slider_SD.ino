#include <GD23Z.h>

#define SliderRojo  201
#define SliderVerde 202
#define SliderAzul  203

int ValorR=125, ValorG=0, ValorB=125, PX=350, PXS=100, PYS=115;
uint16_t RectWidth=100, RectHeight=50;

int PixelesX=649, PixelesY=360, EspX=100;
float Valor1=0,  Valor2=0;
float xReloj = 600, yReloj =400, yValor=Valor2, xValor=Valor1;

//T36 SDIO
//SdFatSdioEX SD;
//T36 SDIO
//SdFat SD(2); const uint8_t SD_CS = PA15;    //F429ZI      SPI3

File archivo;

void setup()
{
// Serial.begin(9600);
// SD.begin(SD_CS, SD_SCK_MHZ(36));
// SD.begin();
 GD.begin();
 
  espera();
  //archivo = SD.open("Fn1.jpg");
  GD.cmd_loadimage(0, 0);
  //GD.loadSdFat(archivo); 
  //GD.loadSDIO(archivo); 
  GD.load("Fn1.jpg"); 
  //archivo.close(); 

  MP();
}

void loop(){}

void MP()
{
  while(1){
  GD.Clear();
  GD.SaveContext();
   GD.Begin(BITMAPS);  
   GD.Vertex2ii(0, 0); 
  GD.RestoreContext();
  
  GD.get_inputs();    

  GD.ColorA(0);
    slider2();
  GD.ColorA(255);

   GD.ColorRGB(0x00ff00);  
   GD.LineWidth(1 * 16);
   GD.Begin(LINES);
   GD.Vertex2f((0+xValor) * 16, 0* 16);  GD.Vertex2f((0+xValor)* 16,  480* 16);
   GD.Vertex2f((0+xValor) * 16, 1* 16);  GD.Vertex2f((0+150+xValor)* 16,  1* 16);
   GD.Vertex2f((EspX+50+xValor) * 16, 0* 16);  GD.Vertex2f((EspX+50+xValor)* 16,  480* 16);
   GD.Vertex2f((0+xValor) * 16, 479* 16);  GD.Vertex2f((0+150+xValor)* 16,  479* 16);
   
   GD.Vertex2f((0+xValor) * 16, (355-yValor)* 16);  GD.Vertex2f((0+150+xValor)* 16,  (355-yValor)* 16);
   GD.Vertex2f((0+xValor) * 16, (479-yValor)* 16);  GD.Vertex2f((0+150+xValor)* 16,  (479-yValor)* 16);
   GD.End();

   //GD.ColorRGB(0xffffff);   GD.cmd_number(120+xValor, 25, 28, OPT_RIGHTX | OPT_SIGNED, xValor);
   //GD.ColorRGB(0xffffff);   GD.cmd_number(120+xValor, 435-yValor, 28, OPT_RIGHTX | OPT_SIGNED, yValor);


  GD.ColorA(0);
  GD.Begin(RECTS);
   GD.Vertex2f(0* 16, (0)* 16);  GD.Vertex2f((0+xValor)* 16, (480)* 16);  //Mascara para evitar slider fuera de zona superior
   GD.Vertex2f((EspX+xValor)* 16, (0)* 16);  GD.Vertex2f((800)* 16, (480)* 16);  //Mascara para evitar slider fuera de zona superior
  GD.End();  
  GD.ColorA(255);


   GD.cmd_fgcolor(0x000050); 
   GD.ColorRGB(0xffffff);   GD.Tag(20);    GD.cmd_button(650+xValor, 20-yValor, 120, 60, 29, 0,  "M0"); GD.Tag(255);
   if (GD.inputs.tag==20){
       M0();    
      }

   GD.cmd_fgcolor(0x005000); 
   GD.ColorRGB(0xffffff);   GD.Tag(21);    GD.cmd_button(650+xValor, 400-yValor, 120, 60, 29, 0,  "M1"); GD.Tag(255);
   if (GD.inputs.tag==21){
       M1();    
      }

   GD.cmd_fgcolor(0x505000); 
   GD.ColorRGB(0x000000);   GD.Tag(22);    GD.cmd_button(650+xValor, 750-yValor, 120, 60, 29, 0,  "M2"); GD.Tag(255);
   if (GD.inputs.tag==22){
       M2();    
      }

   GD.cmd_fgcolor(0x000050); 
   GD.ColorRGB(0xffffff);   GD.Tag(24);    GD.cmd_button(-630+xValor, 20-yValor, 120, 60, 29, 0,  "M3"); GD.Tag(255);
   if (GD.inputs.tag==24){
       M3();    
      }

   GD.cmd_fgcolor(0x005000); 
   GD.ColorRGB(0xffffff);   GD.Tag(25);    GD.cmd_button(-630+xValor, 400-yValor, 120, 60, 29, 0,  "M4"); GD.Tag(255);
   if (GD.inputs.tag==25){
       M4();    
      }

   GD.cmd_fgcolor(0x505000); 
   GD.ColorRGB(0x000000);   GD.Tag(26);    GD.cmd_button(-630+xValor, 750-yValor, 120, 60, 29, 0,  "M5"); GD.Tag(255);
   if (GD.inputs.tag==26){
       M5();    
      }

  GD.swap();
  }
}

void Sliderbase()
{
  GD.Clear();
   GD.Begin(BITMAPS);  
   GD.Vertex2ii(0, 0); 
  GD.get_inputs();  

  if(xReloj>=850){xReloj=-150;}

//Draw clock
//  GD.ColorRGB(0x0000ff);  //color de las manecillas, sino se selecciona se dibujan en color blanco
 GD.cmd_bgcolor(0xff0000); //color de fondo
 GD.cmd_clock(xReloj,yReloj-yValor,50,OPT_FLAT,12,33,45,0);

  xReloj = xReloj+4;

//  slider1();
 GD.ColorA(100);  
  slider2();
 GD.ColorA(255);  

   
  GD.swap();
}

