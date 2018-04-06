
#include <GD23Z.h>
#include "barras.h"    //Asset2



//Cortina
int PIx=0, VX=-10, velP=VX, AvanceC=1;
//Cortina

// MSGEQ7 spectrum analyser 
//600 = 100 x 2 x 3
  int XGT=140, YGT=245;   //Posición (X,Y) inicial del marco
  float escala = 2;  
  const int Divisor=3;
  const int maxlecturas = 100; 
//600 = 100 x 2 x 3  
  
int separacion=Divisor*escala;   //separación entre dos puntos de la gráfica

long previousMillis0 = 0, previousMillis1 = 0, previousMillis2 = 0, previousMillis3 = 0, previousMillis4 = 0, previousMillis5 = 0, previousMillis6 = 0;
long interval0 = 0, interval1 = 0, interval2 = 0, interval3 = 0, interval4 = 0, interval5 = 0, interval6 = 0;

int strobe = 27; //5  FT843   2  FT801/FT813 Riverdi    25 T36
int res =    25;  //6  FT843   3  FT801/FT813 Riverdi    26 T36

int leftS[7], rightS[7]; 
int band;
//char TX[50];
 int Lectura0, Lectura1, Lectura2, Lectura3, Lectura4, Lectura5, Lectura6;        // activar variable para las lecturas directas de la banda del MSGEQ7 seleccionada
 int Valor0, Valor1, Valor2, Valor3, Valor4, Valor5, Valor6;          // ajuste de lectura para que quede dentro del marco de la gráfica
  
  int valormaximoY=1024;  //máximo valor de las lecturas
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
int segmentos = 14;
// MSGEQ7 ssegmentado

// MSGEQ7 spectrum analyser 

//Panel principal

int Xbase=0, Avance=0, Velocidad=5;

//Panel principal

//Mini-Analizador lineal
int separacionM=4;
const int maxlecturasM = 35;  //Número de puntos almacenados para graficar

//Mini-Analizador lineal Derecho
int LecturaMR;        // activar variable para las lecturas directas de la banda del MSGEQ7 seleccionada
int ValorMR;          // ajuste de lectura para que quede dentro del marco de la gráfica
int lecturaMR[maxlecturasM];  // base de datos actual
long previousMillisMR = 0;   
long intervalMR = 0;  

//Mini-Analizador lineal Izquierdo
int LecturaML;        // activar variable para las lecturas directas de la banda del MSGEQ7 seleccionada
int ValorML;          // ajuste de lectura para que quede dentro del marco de la gráfica
int lecturaML[maxlecturasM];  // base de datos actual
long previousMillisML = 0;   
long intervalML = 0;  


void setup()
{
  pinMode(res, OUTPUT); 
  pinMode(strobe, OUTPUT); 
  digitalWrite(res,LOW); 
  digitalWrite(strobe,HIGH);  
  lineabaseMSGEQ7();  //linea base en 0
  
  GD.begin();
  //PIx=0; velP=-5; AvanceC=1;   
  Spectrum();
//  Analizador(); 
  
}
void loop() { }
