void insertadatos2()
{
  unsigned long currentMillis2 = millis();        
  if(currentMillis2 - previousMillis2 > interval2)
  {
    previousMillis2 = currentMillis2;       
    for (j=0; j<maxlecturas-1; j++)
      {
        lectura2[j]=lectura2[j+1];   // genera la base de datos previa, recorriendo un dato hacia atrás
      }      
    LecturaMSGEQ72();  //Toma la lectura actual del sensor
    lectura2[maxlecturas-1] = Valor2;       //base de maxlecturas puntos
  } 
}

void Baseactual2()  // Gráfico lineal
{
   GD.ColorRGB(0xFF,0xff,0x00);
   GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturas; j++)
     {    
        GD.Vertex2f(((j*separacion)+XGT+separacion/2) * 16, (YGT+RectHeight-(lectura2[j])) * 16);
     }

    lectura2[maxlecturas-1] = Valor2;  
    //sprintf(TX,"%03d", lectura2[maxlecturas-1]); GD.cmd_text(34, 110, 16, 0, TX);  //Presenta el valor graficado
    //sprintf(TX,"%04d", Lectura2); GD.cmd_text(25, 136, 16, 0, TX);
    j=0;  //al salir deja j=0 para empezar la matriz en (0,0)
    insertadatos2();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}

void LecturaMSGEQ72()
{
  Lectura2=leftS[2];  //solo el canal seleccionado
  //Lectura2=1023;
  //Lectura2=1000;
  //Lectura2=(leftS[0]+leftS[1]+leftS[2]+leftS[3]+leftS[4]+leftS[5]+leftS[6])/7;  //promedio
  Valor2=Lectura2/(valormaximoY/RectHeight);  //ajuste para que el gráfico quede dentro del marco  
}

//Lista de valores en la base 2
void Arraydatos2()
{
  for (j=0; j<=12; j++)  //Puedes usar cualquier intervalo entre 0 y maxlecturas   XD XD, solo muestra del 0-4 
    {  
      GD.ColorRGB(255,255,0);
      sprintf(TX,"%02d", j);  GD.cmd_text(xTextoT, (yTextoT+15*j), 16, 0, TX);   sprintf(TX,"%04d", (lectura2[j])*valormaximoY/RectHeight); GD.cmd_text(xTextoT+25, (yTextoT+15*j), 16, 0, TX);   
    }
}
