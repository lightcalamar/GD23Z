#include <GD23Z.h>

#include "H1ico.h"


float pi= 3.141592654;

int A[20];
int B[20];
int XX0[20], YY0[20], RadioR[20];
float EEX[20], EEY[20];
float TT[20];
float DeltaD[20];

//Menu circular
//parametros de centroide del menu circular
  int MCa= 250, MCb= 120, MCX= 250, MCY=190;
  float MCV = 0.025;  //0.025; 0.01;  -0.025;   velocidad y dirección de rotación
//parametros de centroide del menu circular  

//int DESPMCX= 100, DESPMCY= 70;
int DESPMCX= 100, DESPMCY= -180;

void MP()
{
//Puntoa  
  //    (i,  a,   b,  px,  py,  r, inicial, delta)
 // Parametros(1, 150, 200, 400, 240, 15, -pi, -0.01);  //elipse 1, punto
 // Parametros(2, 300, 140, 400, 240, 15, -pi, 0.05);   //elipse 2, punto
 // Parametros(3, 100, 100, 400, 240, 15, -pi, -0.05);  //elipse 3, punto
//Puntoa

//Menu circular
  //    (i,  a,   b,  px,  py,  r, inicial, delta)
  Parametros(4, MCa, MCb, MCX, MCY, 15, -pi, MCV);      //elipse 4 con dibujo
  Parametros(5, MCa, MCb, MCX, MCY, 15, -pi+0.9, MCV);  //elipse 5 con dibujo
  Parametros(6, MCa, MCb, MCX, MCY, 15, -pi+1.8, MCV);  //elipse 6 con dibujo    
  Parametros(7, MCa, MCb, MCX, MCY, 15, -pi+2.7, MCV);  //elipse 7 con dibujo
  Parametros(8, MCa, MCb, MCX, MCY, 15, -pi+3.6, MCV);  //elipse 7 con dibujo
  Parametros(9, MCa, MCb, MCX, MCY, 15, -pi+4.5, MCV);  //elipse 7 con dibujo
  Parametros(10, MCa, MCb, MCX, MCY, 15, -pi+5.4, MCV); //elipse 7 con dibujo
//Menu circular
  
  while(1)
  {
    GD.ClearColorRGB(0x000000);
    GD.Clear();
    GD.SaveContext();
    GD.Begin(BITMAPS);
    GD.ColorA(150);
      GD.Vertex2ii(0, 0, 8);
    GD.VertexTranslateX(16*DESPMCX);
    //GD.VertexTranslateY(16*DESPMCY);
    //GD.ColorA(255);
      //GD.Vertex2ii(0, 0, 0);
       EllipseD(10,0);
      //GD.Vertex2ii(120, 0, 1);
       EllipseD(9,1);
      //GD.Vertex2ii(240, 0, 2);
       EllipseD(8,2);
      //GD.Vertex2ii(360, 0, 3);
       EllipseD(7,3);
      //GD.Vertex2ii(0, 120, 3);
      //GD.Vertex2ii(120, 120, 2);
       EllipseD(6,4);
      //GD.Vertex2ii(240, 120, 1);
       EllipseD(5,6);      
      //GD.Vertex2ii(360, 120, 0);
       EllipseD(4,7);      
    GD.RestoreContext();

    GD.SaveContext();
     GD.VertexTranslateX(16*700);
     GD.Vertex2ii(0, 400, 0);
    GD.RestoreContext();     
 // ElipseCpuntos();
  
    GD.swap();
  }
}

