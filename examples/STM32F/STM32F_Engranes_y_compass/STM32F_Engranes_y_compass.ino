#include <GD23Z.h>

File archivo1, archivo2, archivo3, archivo4;
SdFat Sd2(2);
const uint8_t SD2_CS = PA11;   // STM32F767 chip select for sd2
//const uint8_t SD2_CS = PB12;   // STM32F103 chip select for sd2

int PX=100, PY=100;
//int Centro=320/2;   //AE1.png, 320x320 px, Centro=320/2, engranes 
int Centro=240/2;   //AE1.png, 240x240 px, Centro=240/2,   compass
float AnguloG1=0, AnguloG2=0;
int Centro2=252/2;   //Pn1.png, 252x252 px, Centro=240/2,   aguja-brújula

float avance1, rapidez1=-1.0;
float avance2, rapidez2=1.0;

void setup()
{
  Sd2.begin(SD2_CS, SD_SCK_MHZ(18));
  GD.begin();

  //archivo1 = Sd2.open("AE1.png");  //engranes()
  archivo1 = Sd2.open("CMP1.png");  //compass
    GD.BitmapHandle(0);
    GD.cmd_loadimage(0, 0);
    GD.loadSDIO(archivo1);

  archivo2 = Sd2.open("HM2.png");  //HM1.png
    GD.BitmapHandle(1);
    GD.cmd_loadimage(-1, 0);
    GD.loadSDIO(archivo2);

  archivo3 = Sd2.open("Bru1.png");  //dial brújula
    GD.BitmapHandle(2);
    GD.cmd_loadimage(-1, 0);
    GD.loadSDIO(archivo3);

  archivo4 = Sd2.open("Pn1.png");  //aguja brújula
    GD.BitmapHandle(3);
    GD.cmd_loadimage(-1, 0);
    GD.loadSDIO(archivo4);    
}

void loop()
{
  //engranes();
  compass1();
}

float Direccion;


void compass1()
{
  GD.ClearColorRGB(0x202020);
  GD.Clear();

  GD.SaveContext();
//    STM32();
  GD.RestoreContext();

  GD.SaveContext();
  GD.ColorA(20);
  GD.Begin(BITMAPS);
    GD.Vertex2ii(0, 0, 0);
    GD.Vertex2ii(65, 45, 1);
    
  GD.End();
  GD.RestoreContext();
  
  
  
  GD.SaveContext();
  GD.Begin(BITMAPS);
    avance1=avance1 + rapidez1;                               //GD.printNfloat(500, 20, avance1, 1, 31);

    if(avance1<=-360){rapidez1=1.0;}
    if(avance1>=0){rapidez1=-1.0;}
                                                              //GD.printNfloat(565, 20, rapidez1, 1, 29);
    Direccion = rapidez1*(360*rapidez1 + rapidez1*avance1);   GD.printNfloat(400, 20, Direccion, 1, 31);
    rotate_Center(DEGREES(AnguloG1+avance1), Centro);
    GD.cmd_setmatrix();
    GD.Vertex2ii(0+PX, 0+PY, 0);
    GD.cmd_loadidentity();
  GD.End();
  GD.RestoreContext();

  GD.SaveContext();
   GD.Begin(BITMAPS);
    GD.Vertex2ii(65+PX, 45+PY, 1);
    GD.Vertex2ii(250+PX, 0+PY, 2);
  GD.RestoreContext();

  GD.SaveContext();
  GD.Begin(BITMAPS);
    avance2=avance2 + rapidez2;                       //   GD.printNfloat(500, 20, avance1, 1, 31);
    if(avance2<=-360){rapidez2=1.0;}
    if(avance2>=0){rapidez2=-1.0;}
                                                    //     GD.printNfloat(565, 20, rapidez1, 1, 29);
    rotate_Center(DEGREES(AnguloG2+avance2), Centro2);
    GD.cmd_setmatrix();
    GD.Vertex2ii(0+PX+248, +PY, 3);
    GD.cmd_loadidentity();
  GD.End();
  GD.RestoreContext();  

  
  
  GD.swap();
}


void engranes()
{
  GD.Clear();

  GD.ColorA(20);
  GD.SaveContext();
  GD.Begin(BITMAPS);
    avance1=avance1 + rapidez1;                          GD.printNfloat(500, 20, avance1, 1, 31);
    if(avance1<=-360){rapidez1=2.5;}
    if(avance1>=0){rapidez1=-2.5;}
                                                         GD.printNfloat(565, 20, rapidez1, 1, 29);
    rotate_Center(DEGREES(AnguloG1+avance1), Centro);
    GD.cmd_setmatrix();
    GD.Vertex2ii(380, 70);
    GD.cmd_loadidentity();
  GD.End();
  GD.RestoreContext();

  GD.SaveContext();
  GD.Begin(BITMAPS);
    avance2=avance2 + rapidez2;                          GD.printNfloat(200, 20, avance2, 1, 31);
    if(avance2>=360){rapidez2=-2.5;}
    if(avance2<=0){rapidez2=2.5;}
                                                         GD.printNfloat(265, 20, rapidez2, 1, 29);
    rotate_Center(DEGREES(AnguloG2+avance2), Centro);
    GD.cmd_setmatrix();
    GD.Vertex2ii(90, 70);
    GD.cmd_loadidentity();
  GD.End();
  GD.RestoreContext();
  
  GD.ColorA(255);
  
  GD.swap(); 
}


static void rotate_Center(float a, int CXY)
{
  GD.cmd_translate(F16(CXY),F16(CXY));
  GD.cmd_rotate(a);
  GD.cmd_translate(F16(-CXY), F16(-CXY));
}
