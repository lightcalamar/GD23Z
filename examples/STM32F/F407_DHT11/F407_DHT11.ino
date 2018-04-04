#include <Wire.h>
#include <GD23Z.h>

#include "DHT.h"

#define DHTPIN     PC2     
#define DHTTYPE    DHT11 

DHT dht(DHTPIN, DHTTYPE);

Bitmap title, xaxis, yaxisH, yaxisT;

float h, t, f;
int HM, TC, TF;
long previousMillisDHT = 0, previousMillisSec = 0; 
long intervalDHT = 1000;

int PGX=320, PGY=80;

//Parámetros del plano y gráfica lineal
int separacionM=4;            //distancia en pixeles entre puntos de la gráfica
const int maxlecturasM = 80;  //Número de puntos almacenados para graficar
float NDV = 10;               //número de divisores verticales del plano
float PitchX=32, PitchY=32;   //tamaño de cada celda en el plano

float NDH = maxlecturasM*separacionM/PitchX;  //número de divisores horizontales
float EscalaY=PitchY*NDV/100;

// Diseño de marco para gráfica
int RectWidthM = NDH*PitchX, RectHeightM = NDV*PitchY; //afecta altura del marco, base 70
//Parámetros del plano y gráfica lineal

//Humedad
float LecturaH;        // activar variable para las lecturas directas de la banda del MSGEQ7 seleccionada
float ValorH;          // ajuste de lectura para que quede dentro del marco de la gráfica
int lecturaHumedad[maxlecturasM];  // base de datos actual
long previousMillisH = 0, intervalH = 20;  
int jH;
//Humedad

//Temperatura
float LecturaT;        // activar variable para las lecturas directas de la banda del MSGEQ7 seleccionada
float ValorT;          // ajuste de lectura para que quede dentro del marco de la gráfica
int lecturaTemperatura[maxlecturasM];  // base de datos actual
long previousMillisT = 0, intervalT = 1000;  
int jT;
//Temperatura


