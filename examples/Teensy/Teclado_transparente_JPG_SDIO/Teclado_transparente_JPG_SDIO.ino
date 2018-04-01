#include <GD23Z.h>  

# define PAINT_ALPHA() GD.BlendFunc(ONE, ONE_MINUS_SRC_ALPHA)
# define CLEAR_ALPHA() GD.BlendFunc(ZERO, ONE_MINUS_SRC_ALPHA)

int picked;
int Floor;
int sz = 35; // button size in pixels
int delta=sz;

//                         0         1         2         3         4         5           6             7            8
char FondoJPG[10][15]={"Fn1.jpg","Imag1.jpg","Ab2.jpg","Ab3.jpg","Ab4.jpg","Ab5.jpg", "Fly.jpg","Fondo003.jpeg","Fondo010.jpg" };
int BaseJPG = 8;

unsigned long start;

File archivo;
SdFatSdioEX SD;  //T36

//SdFat SD(3);  const uint8_t SD_CS = PA15;   // F429ZI-DISCO y Core7XXI  SPI3
//SdFat SD(2);  const uint8_t SD_CS = PB12;   // F103 y F407   SPI2

void setup() {
  Serial.begin(9600);
  SD.begin();
  
  //SD.begin(SD_CS, SD_SCK_MHZ(FreqSPI2));
  GD.begin();
   // GD.cmd_setrotate(0);
   // GD.self_calibrate();  
  tecladotransp();
}

void loop(){}

void tecladotransp()
{
  ImagenJPG(0);

  while(1)
  {
    GD.Clear();
    GD.get_inputs();
    GD.ColorMask(1, 1, 1, 0);
    GD.Begin(BITMAPS);
    
    GD.ColorA(150);
      GD.Vertex2ii(0, 0);
    GD.ColorA(255);

    GD.SaveContext();
      GD.cmd_romfont(1,34);  
      GD.ColorRGB(0xffffff);  GD.cmd_number(750, 430, 1, OPT_CENTER, Floor);
    GD.RestoreContext();

    GD.ColorMask(0, 0, 0, 1);

    int espacio = 4.444*sz;
    
    int x0 = 200, x1 = x0+espacio, x2 = x0+espacio*2;
    int y0 = 60, y1 = y0+espacio, y2 = y0+espacio*2;
    
    button(x0, y0, 1);  button(x1, y0, 2);  button(x2, y0, 3);
    button(x0, y1, 4);  button(x1, y1, 5);  button(x2, y1, 6);
    button(x0, y2, 7);  button(x1, y2, 8);  button(x2, y2, 9);

    GD.ColorMask(1, 1, 1, 1);
      GD.ColorRGB(0x00ff00);
    GD.BlendFunc(DST_ALPHA, ONE_MINUS_DST_ALPHA);

    GD.Begin(RECTS);
    GD.Vertex2f(0*16, 0*16); GD.Vertex2f(800*16, 480*16);  

    GD.SaveContext();
      CLEAR_ALPHA();
      GD.ColorA(0);
      GD.Tag(1); GD.Vertex2f((x0-delta)*16, (y0-delta)*16); GD.Vertex2f((x0+delta)*16, (y0+delta)*16); GD.Tag(255);
      GD.Tag(2); GD.Vertex2f((x1-delta)*16, (y0-delta)*16); GD.Vertex2f((x1+delta)*16, (y0+delta)*16); GD.Tag(255);
      GD.Tag(3); GD.Vertex2f((x2-delta)*16, (y0-delta)*16); GD.Vertex2f((x2+delta)*16, (y0+delta)*16); GD.Tag(255);

      GD.Tag(4); GD.Vertex2f((x0-delta)*16, (y1-delta)*16); GD.Vertex2f((x0+delta)*16, (y1+delta)*16); GD.Tag(255);
      GD.Tag(5); GD.Vertex2f((x1-delta)*16, (y1-delta)*16); GD.Vertex2f((x1+delta)*16, (y1+delta)*16); GD.Tag(255);
      GD.Tag(6); GD.Vertex2f((x2-delta)*16, (y1-delta)*16); GD.Vertex2f((x2+delta)*16, (y1+delta)*16); GD.Tag(255);

      GD.Tag(7); GD.Vertex2f((x0-delta)*16, (y2-delta)*16); GD.Vertex2f((x0+delta)*16, (y2+delta)*16); GD.Tag(255);
      GD.Tag(8); GD.Vertex2f((x1-delta)*16, (y2-delta)*16); GD.Vertex2f((x1+delta)*16, (y2+delta)*16); GD.Tag(255);
      GD.Tag(9); GD.Vertex2f((x2-delta)*16, (y2-delta)*16); GD.Vertex2f((x2+delta)*16, (y2+delta)*16); GD.Tag(255);
      GD.ColorA(255);
    GD.RestoreContext();

    picked = GD.inputs.tag;   
     if ((picked>=1) && (picked<=9)) 
         { 
           delay(135);
           
           if (picked>BaseJPG){picked=0;}          
           ImagenJPG(picked);
           
           Serial.println(picked);
           Floor = picked;
         }     
    GD.swap();
  }
}  

static void button(int x, int y, byte label)
{
  PAINT_ALPHA();
  GD.Begin(RECTS);
  GD.LineWidth(16 * 20);  GD.Vertex2f((x - sz)*16, (y - sz)*16);  GD.Vertex2f((x + sz)*16, (y + sz)*16);
  CLEAR_ALPHA();
  GD.ColorA(255);  //0=color solido, 255=100% transparente
  GD.LineWidth(16 * 15);  GD.Vertex2f((x - sz)*16, (y - sz)*16); GD.Vertex2f((x + sz)*16, (y + sz)*16);
  GD.ColorA(0xff);
  PAINT_ALPHA();
  GD.cmd_number(x, y, 31, OPT_CENTER, label);
}
