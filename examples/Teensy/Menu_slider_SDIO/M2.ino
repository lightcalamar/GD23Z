void M2()
{
  while(1)    
  {
   GD.ClearColorRGB(0x505000); 
   GD.Clear();
   GD.ColorRGB(0xFFFFFF);
   GD.cmd_text(GD.w/2, 30, 31, OPT_CENTER, "M2");
   GD.get_inputs();
   
    GD.cmd_fgcolor(0x000050); 
    GD.ColorRGB(0xffffff); 
    GD.Tag(100);  GD.cmd_button(GD.w/2, 400, 120, 60, 29, 0,  "MP");  GD.Tag(255);

    if (GD.inputs.tag==100){
        MP();    
      }    

   GD.swap(); 
  }
}
