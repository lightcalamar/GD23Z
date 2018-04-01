#include <GD23Z.h>

//Fondo de pantalla
File archivo1, archivo2;
SdFat Sd2(2);

const uint8_t SD2_CS = PA11;   // STM32F767 chip select for sd2
//const uint8_t SD2_CS = PB12;   // STM32F103 chip select for sd2
//Fondo de pantalla

void setup()
{
  
  GD.begin();
  Sd2.begin(SD2_CS, SD_SCK_MHZ(18));
  // load image 1
  archivo1 = Sd2.open("Fn1.jpg");
  
  
  
  GD.BitmapHandle(0);
  GD.cmd_loadimage(0, 0);
  GD.loadSDIO(archivo1);

  // load image 2
  archivo2 = Sd2.open("Rad1.png");
  
  GD.BitmapHandle(1);
  GD.cmd_loadimage(-1, 0);
  GD.loadSDIO(archivo2);
}



void loop()

{
  //solido();
  transparente();
  //simpleJPG();
}


void solido()
{
  GD.Clear();
  GD.Begin(BITMAPS);
  GD.Vertex2ii(0, 0, 0); //image 1, fondo de pantalla

  int x = random (0,200);
  int y = random (0,200);
  delay(150);
    GD.Vertex2ii(0, 0, 1); //image 2, imagen superpuesta
    GD.Vertex2ii(x, y, 1); //image 2, imagen superpuesta

  GD.swap(); 
}


void transparente()
{
  GD.Clear();
  GD.Begin(BITMAPS);
    GD.ColorA(255);
  GD.Vertex2ii(0, 0, 0); //image 1, fondo de pantalla

  GD.ColorA(85);
    GD.Vertex2ii(100, 100, 1); //image 2, imagen superpuesta
  GD.swap(); 
}

void simpleJPG()
{
  GD.Clear();
  GD.Begin(BITMAPS);
    GD.Vertex2ii(0, 0, 0); //image 1, fondo de pantalla

  GD.swap(); 
}

