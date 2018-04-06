void insertadatos6()
{
// Esta función debe recorrer los datos hacia atrás y luego insertará el dato actual al final de la lista
//  La base nueva corresponde a la base previa -1 dato
  unsigned long currentMillis6 = millis();
  if(currentMillis6 - previousMillis6 > interval6)
  {
    // save the last time 
    previousMillis6 = currentMillis6;
  
    for (j=0; j<maxlecturas-1; j++)
      {
        lectura6[j]=lectura6[j+1];   // genera la base de datos previa, recorriendo un dato hacia atrás
      }      
    LecturaMSGEQ76();  //Toma la lectura actual del sensor
    lectura6[maxlecturas-1] = Valor6;       //base de maxlecturas puntos
  } 
}


void Baseactual6()  // Gráfico lineal
{
   GD.ColorRGB(0xFF,0xff,0xff);
   GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturas; j++)
     {    
        GD.Vertex2f(((j*separacion)+XGT+separacion/2) * 16, (YGT+RectHeight-(lectura6[j])) * 16);
     }

    lectura6[maxlecturas-1] = Valor6;
    //sprintf(TX,"%03d", lectura6[maxlecturas-1]); GD.cmd_text(34, 110, 16, 0, TX);  //Presenta el valor graficado
    //sprintf(TX,"%04d", Lectura6); GD.cmd_text(25, 136, 16, 0, TX);
    j=0;  //al salir deja j=0 para empezar la matriz en (0,0)
    insertadatos6();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}

void LecturaMSGEQ76()
{
  Lectura6=leftS[6];  //solo el canal seleccionado
  //Lectura6=1023;
  //Lectura6=1000;
  //Lectura6=(leftS[0]+leftS[1]+leftS[2]+leftS[3]+leftS[4]+leftS[5]+leftS[6])/7;  //promedio
  Valor6=Lectura6/(valormaximoY/RectHeight);  //ajuste para que el gráfico quede dentro del marco  
}
