
// yb @lightcalamar

#include <GD23Z.h>
#include "digit.h"

//#define SensorPin PA12 

int SensorPin = PA1;
int valorAnalogico = analogRead(SensorPin);

uint16_t sintab[] = {
  0, 402, 804, 1206, 1607, 2009, 2410, 2811, 3211, 3611, 4011, 4409, 4807, 5205, 5601, 5997, 6392, 
  6786, 7179, 7571, 7961, 8351, 8739, 9126, 9511, 9895, 10278, 10659, 11038, 11416, 11792, 12166, 12539,
  12909, 13278, 13645, 14009, 14372, 14732, 15090, 15446, 15799, 16150, 16499, 16845, 17189, 17530, 17868,
  18204, 18537, 18867, 19194, 19519, 19840, 20159, 20474, 20787, 21096, 21402, 21705, 22004, 22301, 22594, 
  22883, 23169, 23452, 23731, 24006, 24278, 24546, 24811, 25072, 25329, 25582, 25831, 26077, 26318, 26556, 26789, 
  27019, 27244, 27466, 27683, 27896, 28105, 28309, 28510, 28706, 28897, 29085, 29268, 29446, 29621, 29790, 29955, 
  30116, 30272, 30424, 30571, 30713, 30851, 30984, 31113, 31236, 31356, 31470, 31580, 31684, 31785, 31880, 31970, 
  32056, 32137, 32213, 32284, 32350, 32412, 32468, 32520, 32567, 32609, 32646, 32678, 32705, 32727, 32744, 32757, 
  32764, 32767, 32764};

int16_t qsin(uint16_t a) {
  uint8_t f;
  int16_t s0, s1;

  if (a & 32768)
    return -qsin(a & 32767);
  if (a & 16384)
  a = 32768 - a;
  f = a & 127;
  s0 = sintab[a >> 7];
  s1 = sintab[(a >> 7) + 1];
  return (s0 + ((int32_t)f * (s1 - s0) >> 7));
}


int16_t qcos(uint16_t a) {
  return (qsin(a + 16384));
}

static int32_t ox;
static uint8_t noofch = 0;

/// =========================================================================  //
//              AQUI LOS PARAMETROS DE LA CAJA NEGRA DEL VU-METER
/// =========================================================================  //
static void polarxy(int32_t r, uint16_t th, int32_t *x, int32_t *y) {
  *x = (16 * (480 / (2 * noofch)) + (((long)r * qsin(th)) >> 11) + 16 * ox);
  *y = (16 * 300 - (((long)r * qcos(th)) >> 11));
}
/// =========================================================================  //

void vertex(int32_t x, int32_t y) {
  GD.Vertex2f(x, y);
}

static void polar(int32_t r, uint16_t th) {
  int32_t x, y;
  polarxy(r, th, &x, &y);
  vertex(x, y);
}

uint16_t da(int32_t i) {
  return (i - 45) * 32768L / 360;
}

static void cs(uint8_t i) {
  switch (i)   {
   case  0: GD.ColorRGB(200, 255, 200); break;
   case 60: GD.ColorRGB(255, 255,   0); break;
   case 80: GD.ColorRGB(255,   0,   0); break;
  }
}

void Gauges() {
  
  uint16_t w, h, n, val = 0, a, th, size_d, tval, lastXPos = 0;
  int32_t rval, tgt;
  uint8_t i, bi, z;
  int32_t x, y, tx, ty, o, dt;
  w = 220; h = 135;                               // DIMENSION DE LAS CAJAS NEGRAS
	noofch = 2;
	dt = 10;

  GD.cmd_dlstart();  
  GD.cmd_memset(0, 0, 10 * 1024);	
  GD.finish();
  
  GD.cmd_inflate(0);
  GD.copy(digits, sizeof(digits) );

  GD.cmd_dlstart();  							
  GD.ClearColorRGB(55 ,55, 55);
  GD.Clear(1, 1, 1);
  GD.ClearColorRGB(0, 0, 0);
      y = 10;
       for(z = 0;z < (480 / w); z++)
      {
          ox = 240 * z;  
            GD.ScissorXY(ox + dt, y);
              GD.ScissorSize(w, h);
   
  GD.Clear(1, 1, 1);			
  GD.Begin(LINES);
  GD.LineWidth(10);
  for (bi = 0; bi < 81; bi += 10) 
   {
     cs(bi);
  for ( i = 2; i < 10; i += 2) 
     {
       a = da(bi + i);
       polar(220, a);
       polar(240, a);
     }
   }
    
  GD.LineWidth(16);
  for (i = 0; i < 91; i += 10)
   {
     cs(i);
     a = da(i);
     polar(220, a);
     polar(250, a);
   }
   
  GD.ColorRGB(255, 255, 255);
  for (i = 0; i < 91; i += 10)
   {
     a = da(i);
     polarxy(260, a, &tx, &ty);
     GD.cmd_number(tx >> 4, ty >> 4, 26, OPT_CENTER, i);
   }
    ox = (480 / (2 * noofch))+(z * (480 /2 ));
   
  if(z == 1)GD.cmd_text(ox, h -20, 28, OPT_CENTERX, "RIGHT"); 
  if(z == 0)GD.cmd_text(ox, h -20, 28, OPT_CENTERX, "LEFT");
  }
  
  GD.finish();
  
  uint16_t dloffset;
    dloffset =  GD.rd16(REG_CMD_DL); 
       GD.cmd_memcpy(100000L, RAM_DL, dloffset);
         y = 10 + 120 + 20;
           rval = 0, tgt = 4500;
  do  {
  GD.cmd_dlstart();  
  GD.cmd_append(100000L, dloffset);	
  for(z = 0; z < (480 / w); z++)   {
     ox = (480 / 2) * z;

/* 
	int d = (tgt - rval) / 8;
	rval += d;
   
  tgt = analogRead(SensorPin);
	val = rval;
	
	if (random(20) == 0)
	tgt = random(9000L);
	val = rval;
*/
 

  int d = (tgt - rval) / 16;
  rval += d;
  for (int w = 0; w < 18; w++) {
  }
  
  tgt = (analogRead(SensorPin) * w * 1.656) ;
  val = rval / 5;
   
/*
/////////////////////////////////////////////////////////
  int d = (tgt - rval) / 8;
  rval += d;

  for (int w = 0; w < 18; w++) {
  }
   
//  tgt = ( (analogRead(SensorPin) -90 ) * w * 1.58) ;
  tgt = (valorAnalogico * w * 1.58) ;  
  val = rval / 5;
//////////////////////////////////////////////////////////////////
*/
     
  GD.ScissorXY(ox + dt, 10);
  GD.ScissorSize(w, 420);
  
  GD.ColorRGB(255,255,255);
  GD.Begin(LINES);
  GD.LineWidth(10);
  th = (val - 4500L) * 32768L / 36000L;
  
  for (o = -5; o < 6; o++)  {
    polar(170, th + (o << 5));
    polar(235, th); }
   
  GD.cmd_fgcolor(0xff0000);
  GD.cmd_button(10, 155, 225, 110, 30, 0,  "VU-Meter L");
  GD.cmd_button(250, 155, 220, 110, 30, 0, "Vu-Meter R");
   
  GD.ScissorXY(ox+dt, y);

  GD.ScissorSize(w, (uint16_t)(0 * 0.36));
  GD.Clear(1 ,1 ,1);
  GD.ColorRGB(0, 255 ,0);                                 // 255,0,0
  GD.cmd_number(ox + dt + 10, 160, 13, 2, val / 100);	
  GD.cmd_text(ox + dt + 96, 160, 13, 0, ".");
  GD.cmd_number(ox + dt + 106, 160, 13, 2, val % 100);           
    }
    
  GD.End();
  GD.finish();
   GD.swap();
  }
 while(1);
}

void setup() {
  
  GD.begin();
 	Gauges();  
}

void loop() { }  // NO HCE FALTA NINGUNA
