int TextoPX=145, TextoPY=140;

void MP()
{
  while(1)
  {
  GD.ClearColorRGB(20,0,20);
  GD.Clear();

  GD.SaveContext();
  title.draw(PGX+155, 40);
  GD.ColorRGB(255,255,0);  yaxisH.draw(PGX-25, PGY+150, DEGREES(270));
  GD.ColorRGB(0,255,255);  yaxisT.draw(PGX+RectWidthM+25, PGY+150, DEGREES(270));
  GD.ColorRGB(255,255,255);  xaxis.draw(PGX+160, PGY+345);
  GD.RestoreContext();

  unsigned long currentMillisDHT = millis();        
  if(currentMillisDHT - previousMillisDHT > intervalDHT)
  {
    previousMillisDHT = currentMillisDHT;  
    LecturaDTH11();
    HM = h;  //humedad
    TC = t;  //Temperatura Celcius
    TF = f;  //Temperaura Fahrenheit
  }
  
  GD.ColorRGB(255,255,00);  GD.printNfloat(TextoPX, TextoPY, h, 1, 31);  GD.cmd_text(TextoPX+30, TextoPY, 31, 0, " %");
  GD.ColorRGB(00,255,255);  GD.printNfloat(TextoPX, TextoPY+55, t, 1, 31);  GD.cmd_text(TextoPX+30, TextoPY+55, 31, 0, " C");

    GD.ColorA(90); 
    GD.ColorRGB(0x00ff00);  
    GD.LineWidth(1 * 16);
    GD.Begin(LINES);
       McVL(PGX, PGY);
       McHL(PGX, PGY);
    GD.ColorA(255); //color solido 

  //Baseactual2ML(PGX, -202+PGY);
  BaseactualH(PGX, PGY);
  BaseactualT(PGX, PGY);
  
  GD.swap();
  }
}
