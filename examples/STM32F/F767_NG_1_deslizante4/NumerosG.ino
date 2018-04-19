void NumerosXXX(int Numero, int XNG, int YNG)
{
  int C = Numero/100;
   //GD.cmd_number(100, 100, 31, OPT_RIGHTX | OPT_SIGNED, C);
   NG(XNG+(90*0), YNG, C);
  
  int D = (Numero - C*100)/10;
   //GD.cmd_number(100, 150, 31, OPT_RIGHTX | OPT_SIGNED, D);
   NG(XNG+(90*1), YNG, D);
   
  int U = Numero - C*100 - D*10;
   //GD.cmd_number(100, 200, 31, OPT_RIGHTX | OPT_SIGNED, U);
   //NG(XNG+(90*2), YNG, U);
}

void NG(int PX, int PY, int Numero)
{
  GD.Vertex2ii(PX, PY, Numero);
}
