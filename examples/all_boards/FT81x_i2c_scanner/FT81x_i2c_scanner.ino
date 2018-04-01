#include <Wire.h>
#include <SPI.h>
#include <GD23Z.h>

void setup()
{
  GD.begin();
  Searching();
}
void loop() {}

char ID[50];
int Sep=0;

void Searching()
{
  byte error, address;
  int nDevices;

  GD.ClearColorRGB(0x000040);
   GD.Clear();

    GD.ColorRGB(0xffffff);  GD.cmd_text(GD.w/2, 10, 31, OPT_CENTERX, "I2C Scanner");
    GD.ColorRGB(0x00ffff);  GD.cmd_text(GD.w/2, 80, 29, OPT_CENTERX, "Scanning...");

 
  nDevices = 0;
  for (address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    Wire.write(0);
    error = Wire.endTransmission();

    if (error == 0)
    {
      GD.ColorRGB(0xffffff); GD.cmd_text(160, 150, 29, OPT_CENTERX, "I2C device found at address:");
      if (address << 16) sprintf(ID,"0x%02x", address); GD.ColorRGB(0x00ff00); GD.cmd_text(350, 150+(Sep*35), 29, 0, ID); Sep=Sep+1;
      nDevices++;
    }
    else if (error == 4)
    {
      //Report adress with 0 devices
    }
  }

  if (nDevices == 0)
  {
    GD.ColorRGB(0xff0000); GD.cmd_text(55, 150, 29, 0, "No I2C devices found...");
    GD.ColorRGB(0xffffff); GD.cmd_text(55, 190, 29, 0, "Did you configure the chip select for your device?");
    GD.ColorRGB(0xffffff); GD.cmd_text(55, 230, 29, 0, "Please check your hardware.");
    GD.ColorRGB(0xffffff); GD.cmd_text(55, 270, 29, 0, "Restart your MCU for a new search.");
  }
  else
    
  GD.ColorRGB(0x00ff00);  GD.cmd_text(495, 80, 29, OPT_CENTERX, "Done");


  
  GD.swap();
}

