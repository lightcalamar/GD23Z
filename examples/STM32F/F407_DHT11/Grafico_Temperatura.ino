void insertadatosT()  //En Baseactual()  ---->    convertida en función XD
{
  unsigned long currentMillisT = millis();        
  if(currentMillisT - previousMillisT > intervalT)
  {
    previousMillisT = currentMillisT;       
  
    for (jT=0; jT<maxlecturasM-1; jT++)
      {
        lecturaTemperatura[jT]=lecturaTemperatura[jT+1];
      }      
    LecturaTemperatura();

    lecturaTemperatura[maxlecturasM-1] = ValorT;       //base de maxlecturas puntos
  }
}

void BaseactualT(int XGTML, int YbaseM)  // lineas
{
   GD.ColorRGB(0x00,0xff,0xff);
   GD.Begin(LINE_STRIP);
    for (jT=0; jT<maxlecturasM; jT++)
     {    
        GD.Vertex2f(((jT*separacionM)+XGTML+2) * 16, (RectHeightM+(YbaseM)-(lecturaTemperatura[jT])) * 16); //272
     }

    lecturaTemperatura[maxlecturasM-1] = ValorT;
     jT=0;  //al salir deja j=0 para empezar la matriz en (0,0)
     insertadatosT();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}

void LecturaTemperatura()
{
  //LecturaT=random(0,100);  //Temperatura aleatoria
  LecturaT=t;  //Temperatura
  ValorT=LecturaT*EscalaY;  //ajuste para que el gráfico quede dentro de la ventana
}
