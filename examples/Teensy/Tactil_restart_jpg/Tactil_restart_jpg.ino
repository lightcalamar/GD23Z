#include <EEPROM.h>
//#include <GD3USDIO.h>
//#include <GD3_SDIO.h>
#include <GD23Z.h>

Bitmap Background, SaidHello;

void setup()
{
  for ( unsigned int i = 0 ; i < EEPROM.length() ; i++ ){EEPROM.write(i, 0);}

  digitalWrite(13, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(13, LOW);

  GD.begin();
  Background.fromfile("selfie.jpg");
  SaidHello.fromtext(31, "Teensy 3.6@FT8XX");

  MP();
}

void loop(){}

int test;

void MP()
{

int ANG=0;
int minX = 0, minY = 0;
int maxX = GD.w - minX, maxY = GD.h - minY;
int startX = maxX / 2, startY = maxY / 2;
int deltaX = 2, deltaY = 2;

  while(1)
  {
   ANG = ANG + 1;
  if (ANG>=360){ANG=0;}

   startX = startX + deltaX;   startY = startY + deltaY;
   if (startX >= maxX)
       deltaX = -deltaX;
   if (startX <= minX)
       deltaX = abs(deltaX);
   if (startY >= maxY)
       deltaY = -deltaY;
   if (startY <= minY)
       deltaY = abs(deltaY);
  
  GD.ClearColorRGB(0x000055);
  GD.Clear();
  GD.get_inputs();

  GD.ColorA(144);
  Background.draw(GD.w / 2, GD.h / 2);
  GD.ColorA(255);

  if(test==1){GD.ColorRGB(0xffff00);  GD.cmd_text(GD.w/2, (GD.h/2)-65, 30, OPT_CENTER, "Calibration OK!");}
  
  GD.ColorRGB(0xffffff); SaidHello.draw(startX, startY, DEGREES(ANG));

  GD.Tag(1); GD.cmd_fgcolor(0x005000);  GD.cmd_button((GD.w/2)-(60/2), (GD.h/2)-20, 60, 40, 28, 0,  "Test");  GD.Tag(255);

  if (GD.inputs.tag==1)
  {
    delay(115);
    test=test+1;
    if (test==2){test=0;}
  }

  GD.swap();
  }
}
