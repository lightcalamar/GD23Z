void Elipse(int X00, int Y00, int r0, int a0, int b0, float t)
{
  Ex0=X00+a0*cos(t);
  Ey0=Y00+b0*sin(t);

  GD.SaveContext();
  GD.ColorRGB(255,0,0);
   GD.Begin(POINTS);
   GD.PointSize(16*r0);
   GD.Vertex2f(Ex0*16, Ey0*16);
  GD.RestoreContext();
}

