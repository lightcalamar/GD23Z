void espera()
{
  GD.ClearColorRGB(0x000025); //fondo de pantalla
  GD.Clear();
    GD.ColorA(255);  
    GD.cmd_text(GD.w/2, GD.h/2, 26,   OPT_CENTERX, "Procesando entorno visual...");    
  GD.swap();
}
