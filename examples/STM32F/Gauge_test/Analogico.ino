// Aguja analógica + seguidor o gauge, de -20 a 200 grados
void Analogico(uint16_t RadioBase, uint16_t XBase, uint16_t YBase, uint16_t LargoAguja, uint16_t Addaguja, uint16_t EspesorAguja, uint16_t Separador, double Variable, uint16_t RangoEscala, uint16_t SizeTxt, uint16_t XTxt, uint16_t YTxt, uint16_t  R, uint16_t  G, uint16_t  B, uint16_t  pivote)
{
 RadioBase = RadioBase - 10;  //Da la separación respecto a las marcas secundarias
  
  float X1, Y1, X2, Y2, Tetha;
  float pi=3.1415926535897932384626433832795;
  Tetha = map(Variable, 0, RangoEscala, -30, 210);       //elimina el limite horizontal de los 180 grados XD  

//Gauge o arco XD
  GD.ColorA(200);
  GD.ColorRGB(R,G,B);
   for (int Angulo = -30; Angulo<=(Tetha-3); Angulo= Angulo + Separador){  // Gauge Continuo desde la horizontal, 3 grados antes de la aguja
    GD.LineWidth(1 * 16); //Espesor de las lineas que forman el gauge solido que acompaña a la aguja
    GD.Begin(LINES);
          X1 = (RadioBase-LargoAguja)* cos(Angulo*pi/180);
          Y1 = (RadioBase-LargoAguja)* sin(Angulo*pi/180);

          X2 = (RadioBase)* cos(Angulo*pi/180);
          Y2 = (RadioBase)* sin(Angulo*pi/180);
        GD.Vertex2f((XBase - X1) * 16, (YBase - Y1) * 16);   //starting coordinates
        GD.Vertex2f((XBase - X2) * 16, (YBase - Y2) * 16);  //ending coordinates  
       }
//Gauge o arco XD

      GD.ColorA(255); 
      GD.ColorRGB(0xffffff); GD.printNfloat(XBase-RadioBase+(Addaguja/4), YBase+RadioBase/2, 0, 0, 29);
      GD.ColorRGB(0xffffff); GD.printNfloat(XBase+24, 0, RangoEscala/2, 0, 29);
      GD.ColorRGB(0xffffff); GD.printNfloat(XBase+RadioBase+(Addaguja/2), YBase+RadioBase/2, RangoEscala, 0, 29);

//Pivote
  GD.ColorA(150);
  GD.ColorRGB(0x00,0x00,0xff);
  GD.PointSize(pivote * 16);
  GD.Begin(POINTS);   
  GD.Vertex2f(XBase * 16, YBase * 16);
//Pivote



//Aguja del Dial
        X1 = (RadioBase-LargoAguja-Addaguja)* cos(Tetha*pi/180);
        Y1 = (RadioBase-LargoAguja-Addaguja)* sin(Tetha*pi/180);

        X2 = (RadioBase)* cos(Tetha*pi/180);
        Y2 = (RadioBase)* sin(Tetha*pi/180);
  GD.ColorA(255);
  GD.ColorRGB(0xFF,0x00,0x00);
  GD.LineWidth(EspesorAguja);
    GD.Begin(LINES);
  GD.Vertex2f((XBase - X1) * 16, (YBase - Y1) * 16);   //starting coordinates
  GD.Vertex2f((XBase - X2) * 16, (YBase - Y2) * 16);  //ending coordinates
}
// Aguja analógica + seguidor o gauge
