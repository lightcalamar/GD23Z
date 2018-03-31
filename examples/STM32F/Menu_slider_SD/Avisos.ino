void espera()
{
  GD.ClearColorRGB(0x000025); //fondo de pantalla
  GD.Clear();
   GD.ColorA(255);  
   GD.cmd_text(GD.w / 2, GD.h / 2, 27, OPT_CENTERX, "Procesando entorno visual...");   
   GD.cmd_number((GD.w / 2)-(GD.w / 20), (GD.h / 2)+(GD.h / 20), 27, 0, GD.w);
   GD.cmd_number((GD.w / 2)+(GD.w / 80), (GD.h / 2)+(GD.h / 20), 27, 0, GD.h);   
   GD.cmd_text(GD.w / 2, (GD.h / 2)+(GD.h / 20), 27, OPT_CENTERX, "x");       
  GD.swap(); 
}
