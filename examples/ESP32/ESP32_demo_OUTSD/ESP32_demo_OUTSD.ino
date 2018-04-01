// #include <EEPROM.h>
// by @lightcalamar
// 28-03-2018

#include <GD23Z.h>

#include "logos.h"
#include"esp32.h"


// Cortina
int PIx = 0, VX = -20, velP = VX, AvanceC = 1;
// Cortina

void setup()
{
  Serial.begin(115200);
  Serial.println("Inicializando graphicos controlador FT81x...");

  EEPROM.begin(512); // Use only for ESP8266 and ESP32 calibration screen

  GD.begin();
//  GD.self_calibrate();

  screen1();  
}

void screen0() {
  
  LOAD_ASSETS0();
  do {
  GD.ClearColorRGB(0x000020);
  GD.Clear();
  GD.get_inputs();  

  GD.SaveContext();
  lineas();
  GD.RestoreContext();
    
  GD.Begin(BITMAPS);
  GD.Vertex2ii(0, 0, LOG1_HANDLE);
  GD.SaveContext();
  GD.VertexTranslateX(16 * 510); GD.Vertex2ii(0, 0, LOG2_HANDLE);
  GD.RestoreContext();

  GD.Tag(3);
  GD.cmd_fgcolor(0x000000); 
  GD.cmd_button(620, 380, 140, 50, 30, 0, "Screen 0"); GD.Tag(255);
  if (GD.inputs.tag == 3) {espera(); delay(830); PIx = 0, velP = VX, AvanceC = 1, screen1();}
           Cortina();
       GD.swap();
  } while(1);   
}

void screen1() {

  LOAD_ASSETS1();
  do {
  GD.ClearColorRGB(0x000000);
  GD.Clear();
  GD.get_inputs(); 

//  GD.SaveContext();
//  lineas();
//  GD.RestoreContext();
    
  GD.Begin(BITMAPS);
//  GD.Vertex2ii(0, 0, LOG1_HANDLE);
//  GD.SaveContext();
//  GD.VertexTranslateX(16 * 150); 
  GD.Vertex2ii(10, 150, ESP32_HANDLE);
//  GD.RestoreContext();
  GD.Tag(2);
  GD.cmd_fgcolor(0xff8000);
  GD.cmd_button(620, 380, 140, 50, 30, 0, "Screen 1"); GD.Tag(255);
  if (GD.inputs.tag == 2) {espera(); delay(830); PIx = 0, velP = VX, AvanceC = 1, screen0();}
  
         Cortina();
       GD.swap();    
  } while(1);   
}

void loop() {  } // no hace falta

