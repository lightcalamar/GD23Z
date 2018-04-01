void FT8XXLOGO()
{
   GD.ColorA(75);
   GD.cmd_text(650, 260, 26, OPT_CENTER, "FT8XX TEAM");
       GD.SaveContext();
       GD.ColorRGB(255,255,0);
       GD.Begin(POINTS);
       GD.PointSize(20*16);
       GD.Vertex2f(650*16, 220*16);
       GD.RestoreContext();

       t0= t0+delta0; Elipse(650,220,4, 50,100, t0); 
       t1= t1+delta0; Elipse(650,220,8, 80,150, t1);
       t2= t2+delta0; Elipse(650,220,12, 110,200, t2);
       GD.End();
   GD.ColorA(255);
}
