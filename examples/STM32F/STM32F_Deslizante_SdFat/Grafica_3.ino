void insertadatos3()
{
  unsigned long currentMillis3 = millis();
  if(currentMillis3 - previousMillis3 > interval3)
  {
    previousMillis3 = currentMillis3;
    for (j=0; j<maxlecturas-1; j++)
      {
        lectura3[j]=lectura3[j+1];
      }      
    LecturaMSGEQ73();
    lectura3[maxlecturas-1] = Valor3;
  } 
}

void Baseactual3()  // Gráfico lineal
{
   GD.ColorRGB(0xff,0x00,0xff);
   GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturas; j++)
     {    
        GD.Vertex2f(((j*separacion)+XGT+separacion/2) * 16, (YGT+RectHeight-(lectura3[j])) * 16);
     }

    lectura3[maxlecturas-1] = Valor3;
    //sprintf(TX,"%03d", lectura3[maxlecturas-1]); GD.cmd_text(34, 110, 16, 0, TX);
    //sprintf(TX,"%04d", Lectura3); GD.cmd_text(25, 136, 16, 0, TX);
    j=0;
    insertadatos3();
}

void LecturaMSGEQ73()
{
  Lectura3=leftS[3];  //solo el canal seleccionado
  //Lectura3=1023;
  //Lectura3=1000;
  //Lectura3=(leftS[0]+leftS[1]+leftS[2]+leftS[3]+leftS[4]+leftS[5]+leftS[6])/7;  //promedio
  Valor3=Lectura3/(valormaximoY/RectHeight);  //ajuste para que el gráfico quede dentro del marco  
}
