void insertadatos4()
{
// Esta función debe recorrer los datos hacia atrás y luego insertará el dato actual al final de la lista
//  La base nueva corresponde a la base previa -1 dato
  unsigned long currentMillis4 = millis();
  if(currentMillis4 - previousMillis4 > interval4)
  {
    // save the last time 
    previousMillis4 = currentMillis4;
  
    for (j=0; j<maxlecturas-1; j++)
      {
        lectura4[j]=lectura4[j+1];   // genera la base de datos previa, recorriendo un dato hacia atrás
      }      
    LecturaMSGEQ74();  //Toma la lectura actual del sensor
    lectura4[maxlecturas-1] = Valor4;       //base de maxlecturas puntos
  } 
}


void Baseactual4()  // Gráfico lineal
{
   GD.ColorRGB(0x00,0xff,0xff);
   GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturas; j++)
     {    
        GD.Vertex2f(((j*separacion)+XGT+separacion/2) * 16, (YGT+RectHeight-(lectura4[j])) * 16);
     }

    lectura4[maxlecturas-1] = Valor4;
    //sprintf(TX,"%03d", lectura4[maxlecturas-1]); GD.cmd_text(34, 110, 16, 0, TX);  //Presenta el valor graficado
    //sprintf(TX,"%04d", Lectura4); GD.cmd_text(25, 136, 16, 0, TX);
    j=0;  //al salir deja j=0 para empezar la matriz en (0,0)
    insertadatos4();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}

void LecturaMSGEQ74()
{
  Lectura4=leftS[4];  //solo el canal seleccionado
  //Lectura4=1023;
  //Lectura4=1000;
  //Lectura4=(leftS[0]+leftS[1]+leftS[2]+leftS[3]+leftS[4]+leftS[5]+leftS[6])/7;  //promedio
  Valor4=Lectura4/(valormaximoY/RectHeight);  //ajuste para que el gráfico quede dentro del marco  
}
