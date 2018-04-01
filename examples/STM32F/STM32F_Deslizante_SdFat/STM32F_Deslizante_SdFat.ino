#include <GD23Z.h>

#include "AV3SD.h" //Asset2

SdFat Sd2(2);
//const uint8_t SD2_CS = PB12;   // F103 chip select for sd2
const uint8_t SD2_CS = PA11;   // F767 chip select for sd2

//Grupo 2 de assets
char Asset2[] = "AV3SD.gd2";  File AV3;
String STRAsset2(Asset2);
//Grupo 2 de assets

//Elipses

float Ex0, Ey0;
//float pi= 3.141516;
float t0, t1, t2;
float delta0 = 0.005;

//Elipses

// MSGEQ7 spectrum analyser 

int XGT=140, YGT=210;   //Posición (X,Y) inicial del marco

  float escala = 2.5;
  const int Divisor=2;
  //const int maxlecturas = 150;  //Número de puntos almacenados para graficar  max 185 por base, en un arreglo de 7 bases
  const int maxlecturas = 110;  //145 en Teensy 36
  int separacion=Divisor*escala;   //separación entre dos puntos de la gráfica


long previousMillis0 = 0, previousMillis1 = 0, previousMillis2 = 0, previousMillis3 = 0, previousMillis4 = 0, previousMillis5 = 0, previousMillis6 = 0;
long interval0 = 0, interval1 = 0, interval2 = 0, interval3 = 0, interval4 = 0, interval5 = 0, interval6 = 0;

int strobe = PF12; //5  FT843   2  FT801/FT813 Riverdi    25 T36
int res =    PF13;  //6  FT843   3  FT801/FT813 Riverdi    26 T36

int leftS[7]; 
int band;
char TX[50];
 int Lectura0, Lectura1, Lectura2, Lectura3, Lectura4, Lectura5, Lectura6;        // activar variable para las lecturas directas de la banda del MSGEQ7 seleccionada
 int Valor0, Valor1, Valor2, Valor3, Valor4, Valor5, Valor6;          // ajuste de lectura para que quede dentro del marco de la gráfica
  
  int valormaximoY=1000;  //máximo valor de las lecturas
  int claroXY = 10*escala;  

  int lectura0[maxlecturas], lectura1[maxlecturas], lectura2[maxlecturas], lectura3[maxlecturas], lectura4[maxlecturas], lectura5[maxlecturas], lectura6[maxlecturas];  // base de datos actual
  int k,j;

// Diseño de marco para gráfica
int RectWidth = (maxlecturas*separacion);
int RectHeight = 10*claroXY;
  
//Posición del listado de la base de datos
  int xTextoT = 20;
  int yTextoT = 252; 
//Posición del listado de la base de datos

// MSGEQ7 ssegmentado
int sepY = 10, sepX = 20, largoX = 30;
//int xi = 75, yi = 185; 
int segmentos = 14;
// MSGEQ7 ssegmentado

// MSGEQ7 spectrum analyser 

//Panel principal

int Xbase=0, Avance=0, Velocidad=5;
int CargaAssetNuevo =1; 

//Panel principal


