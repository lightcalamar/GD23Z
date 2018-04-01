// de -30 a 210 grados
void MarcasDial(uint16_t RadioBase, uint16_t XBase, uint16_t YBase, uint16_t LargoMarcas, uint16_t EspesorMarcas)
{
//Carátula del gauge personalizado   
//Base del Dial o Gauge
  GD.ColorA(180);
   GD.ColorRGB(0xff,0xff,0x00);
   GD.PointSize((RadioBase+5) * 16);
   GD.Begin(POINTS);   
   GD.Vertex2f(XBase * 16, YBase * 16);
   GD.End();
//Base del Dial o Gauge

//Submarcas
  float X1, Y1, X2, Y2;
  float pi=3.1415926535897932384626433832795;
//Gauge o arco XD
  GD.ColorA(255);
  GD.ColorRGB(0x00,0x00,0x00);

  for (int Angulo = -30; Angulo<=210; Angulo= Angulo + ((210+30)/10)){  // Gauge Discontinuo, bajo horizonte de -20 a 200 grados XD
  GD.LineWidth(EspesorMarcas * 16);
    GD.Begin(LINES);
        X1 = (RadioBase-LargoMarcas)* cos(Angulo*pi/180);
        Y1 = (RadioBase-LargoMarcas)* sin(Angulo*pi/180);

        X2 = (RadioBase)* cos(Angulo*pi/180);
        Y2 = (RadioBase)* sin(Angulo*pi/180);

  GD.Vertex2f((XBase - X1) * 16, (YBase - Y1) * 16);   //starting coordinates
  GD.Vertex2f((XBase - X2) * 16, (YBase - Y2) * 16);  //ending coordinates  
  GD.End();//end lines primitive
       }
//Submarcas
}
