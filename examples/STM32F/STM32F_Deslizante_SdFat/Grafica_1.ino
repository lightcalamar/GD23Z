void insertadatos1()
{
  unsigned long currentMillis1 = millis();
  if(currentMillis1 - previousMillis1 > interval1)
  {
    previousMillis1 = currentMillis1;
    for (j=0; j<maxlecturas-1; j++)
      {
        lectura1[j]=lectura1[j+1];
      }      
    LecturaMSGEQ71();
    lectura1[maxlecturas-1] = Valor1;
  } 
}

void Baseactual1()  // Gráfico lineal
{
   GD.ColorRGB(0x00,0xff,0x00);
   GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturas; j++)
     {    
        GD.Vertex2f(((j*separacion)+XGT+separacion/2) * 16, (YGT+RectHeight-(lectura1[j])) * 16);
     }

    lectura1[maxlecturas-1] = Valor1;
    //sprintf(TX,"%03d", lectura1[maxlecturas-1]); GD.cmd_text(34, 110, 16, 0, TX);
    //sprintf(TX,"%04d", Lectura1); GD.cmd_text(25, 136, 16, 0, TX);
    j=0;
    insertadatos1();
}

void LecturaMSGEQ71()
{
  Lectura1=leftS[1];  //solo el canal seleccionado
  //Lectura1=1023;
  //Lectura1=1000;
  //Lectura1=(leftS[0]+leftS[1]+leftS[2]+leftS[3]+leftS[4]+leftS[5]+leftS[6])/7;  //promedio
  Valor1=Lectura1/(valormaximoY/RectHeight);  //ajuste para que el gráfico quede dentro del marco  
}
