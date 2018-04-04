void insertadatosH()  //En Baseactual()  ---->    convertida en función XD
{
  unsigned long currentMillisH = millis();        
  if(currentMillisH - previousMillisH > intervalH)
  {
    previousMillisH = currentMillisH;       
  
    for (jH=0; jH<maxlecturasM-1; jH++)
      {
        lecturaHumedad[jH]=lecturaHumedad[jH+1];
      }      
    LecturaHumedad();

    lecturaHumedad[maxlecturasM-1] = ValorH;       //base de maxlecturas puntos
  }
}

void BaseactualH(int XGTML, int YbaseM)  // lineas
{
   GD.ColorRGB(0xFF,0xff,0x00);
   GD.Begin(LINE_STRIP);
    for (jH=0; jH<maxlecturasM; jH++)
     {    
        GD.Vertex2f(((jH*separacionM)+XGTML+2) * 16, (RectHeightM+(YbaseM)-(lecturaHumedad[jH])) * 16); //272
     }

    lecturaHumedad[maxlecturasM-1] = ValorH;
     jH=0;  //al salir deja j=0 para empezar la matriz en (0,0)
     insertadatosH();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}

void LecturaHumedad()
{
  //LecturaH=random(0,100);  //Humedad aleatoria
  LecturaH=h;  //Humedad
  ValorH=LecturaH*EscalaY;  //ajuste para que el gráfico quede dentro de la ventana
}

