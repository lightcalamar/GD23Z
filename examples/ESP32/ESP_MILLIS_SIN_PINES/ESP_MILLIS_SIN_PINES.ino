#include <EEPROM.h>
#include <SPI.h>
#include <GD23Z.h>


long previousMillis = 0, interval = 2000UL;  // 2 segundos
int Control = 0;

void setup() {
  
  Serial.begin(115200);
  EEPROM.begin(512);
  GD.begin();
  MP();
}
void loop() { }

void MP()
{
 while(1) {
  Identificador();

  GD.ClearColorRGB(0x000055);
  GD.Clear();
  GD.cmd_number(215, 110, 31, OPT_RIGHTX, Control);
  GD.swap();  
 }
}

void Identificador() {
  
unsigned long currentMillis = millis();        
  if(currentMillis - previousMillis > interval) {
   previousMillis = currentMillis;  
   Control = Control + 1;
   Serial.println(Control);
    
  if(Control >= 2){Control = 0;
   Serial.println(Control); }
   }
}
