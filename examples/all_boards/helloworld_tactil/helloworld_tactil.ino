#include <GD23Z.h>

int Mensaje=0;

void setup()
{
//   EEPROM.begin(512); // Use only for ESP8266 and ESP32 calibration screen
  GD.begin();
  //GD.self_calibrate();
}

void loop()
{
  GD.ClearColorRGB(0x550000);
  GD.Clear();
   GD.get_inputs();
   
  GD.cmd_text(GD.w / 2, (GD.h / 2)-50, 31, OPT_CENTER, "Hello world");

  GD.Tag(1);    GD.cmd_button(GD.w/2-(100/2), 110, 100, 50, 31, 0,  "Try");  GD.Tag(255);  
    if (GD.inputs.tag==1){
       delay(145);
       Mensaje=Mensaje+1;  
       if(Mensaje>=2){Mensaje=0;}
      }
    
    if(Mensaje==1){GD.ColorRGB(0x00ff00);  GD.cmd_text(GD.w/2, 190, 28, OPT_CENTER, "Tactil OK");}

  
  GD.swap();
}
