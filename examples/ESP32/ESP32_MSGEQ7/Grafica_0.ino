void insertadatos0()
{
  unsigned long currentMillis0 = millis();
  if(currentMillis0 - previousMillis0 > interval0)
  {
    previousMillis0 = currentMillis0;
    for (j=0; j<maxlecturas-1; j++)
      {
        lectura0[j]=lectura0[j+1];
      }      
    LecturaMSGEQ70();
    lectura0[maxlecturas-1] = Valor0;
  } 
}

void Baseactual0()  // Gráfico lineal
{
   //GD.ColorRGB(0x50,0x50,0x50);
   GD.ColorRGB(0,0xaa,0);
   GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturas; j++)
     {    
        GD.Vertex2f(((j*separacion)+XGT+separacion/2) * 16, (YGT+RectHeight-(lectura0[j])) * 16);
     }

    lectura0[maxlecturas-1] = Valor0;
    //sprintf(TX,"%03d", lectura0[maxlecturas-1]); GD.cmd_text(34, 110, 16, 0, TX);
    //sprintf(TX,"%04d", Lectura0); GD.cmd_text(25, 136, 16, 0, TX);
    j=0;
    insertadatos0();
}

void LecturaMSGEQ70()
{
  Lectura0=leftS[0];  //solo el canal seleccionado
  //Lectura0=1023;
  //Lectura0=1000;
  //Lectura0=(leftS[0]+leftS[1]+leftS[2]+leftS[3]+leftS[4]+leftS[5]+leftS[6])/7;  //promedio
  Valor0=Lectura0/(valormaximoY/RectHeight);  //ajuste para que el gráfico quede dentro del marco  
}
