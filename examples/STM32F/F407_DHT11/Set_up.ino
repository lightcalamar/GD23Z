void setup() 
{
  dht.begin();  LecturaDTH11();
   GD.begin();

  title.fromtext(30, "Sensor DHT11");
  xaxis.fromtext(28, "Intervalo de lectura");
  yaxisH.fromtext(28, "Humedad relativa (%)");
  yaxisT.fromtext(28, "Temperatura (Celcius)");

   MP();
}

void loop(){}
