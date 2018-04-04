void insertadatos5()
{
  unsigned long currentMillis5 = millis();
  if(currentMillis5 - previousMillis5 > interval5)
  {
    previousMillis5 = currentMillis5;
    for (j=0; j<maxlecturas-1; j++)
      {
        lectura5[j]=lectura5[j+1];
      }      
    LecturaMSGEQ75();
    lectura5[maxlecturas-1] = Valor5;
  } 
}

void Baseactual5()  // Gráfico lineal
{
   GD.ColorRGB(0xff,0x00,0x00);
   GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturas; j++)
     {    
        GD.Vertex2f(((j*separacion)+XGT+separacion/2) * 16, (YGT+RectHeight-(lectura5[j])) * 16);
     }

    lectura5[maxlecturas-1] = Valor5;
    //sprintf(TX,"%03d", lectura5[maxlecturas-1]); GD.cmd_text(34, 110, 16, 0, TX);
    //sprintf(TX,"%04d", Lectura5); GD.cmd_text(25, 136, 16, 0, TX);
    j=0;
    insertadatos5();
}

void LecturaMSGEQ75()
{
  Lectura5=leftS[5];  //solo el canal seleccionado
  //Lectura5=1023;
  //Lectura5=1000;
  //Lectura5=(leftS[0]+leftS[1]+leftS[2]+leftS[3]+leftS[4]+leftS[5]+leftS[6])/7;  //promedio
  Valor5=Lectura5/(valormaximoY/RectHeight);  //ajuste para que el gráfico quede dentro del marco  
}
