void NumerosXXX(int Numero)
{
  int C = Numero/100;
   GD.cmd_number(100, 200, 31, OPT_RIGHTX | OPT_SIGNED, C);
   NG(260, 200, C);
  
  int D = (Numero - C*100)/10;
   GD.cmd_number(100, 250, 31, OPT_RIGHTX | OPT_SIGNED, D);
   NG(350, 200, D);
   
  int U = Numero - C*100 - D*10;
   GD.cmd_number(100, 300, 31, OPT_RIGHTX | OPT_SIGNED, U);
   NG(440, 200, U);
}

void NG(int PX, int PY, int Numero)
{
  GD.Vertex2ii(PX, PY, Numero);
}
