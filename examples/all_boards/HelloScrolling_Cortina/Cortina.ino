void Cortina()
{
 if(velP<1){PIx=PIx+velP;  if(PIx<=-405){velP=0;}}
 if(velP>1){PIx=PIx+velP;  if(PIx>=0){velP=0;}}

 GD.SaveContext();
   GD.ColorRGB(0x000011);   GD.LineWidth(1 * 16);
   GD.Begin(RECTS);
    GD.Vertex2f((-5) * 16, 0* 16);  GD.Vertex2f((((GD.w-1)/2)+PIx) * 16, (GD.h-1) * 16);
    GD.Vertex2f(((GD.w/2)-PIx) * 16, 0* 16);  GD.Vertex2f((((GD.w-1)/1)+5) * 16, (GD.h-1) * 16);
 GD.RestoreContext();
}

