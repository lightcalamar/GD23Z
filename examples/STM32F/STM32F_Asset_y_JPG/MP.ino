int IDciclo;

void MP() 
{
  while(1)
  {
  GD.Clear(); 
  //GD.wr(REG_PWM_DUTY, 15);
  GD.get_inputs(); 
  GD.Begin(BITMAPS);
  //GD.Tag(1);  GD.Vertex2ii(0, 0, 15);  GD.Tag(255); 
  
  //if (GD.inputs.tag==1)
  //     {
  //      IDJPG=IDJPG+1;
  //      if(IDJPG>=16){IDJPG=0;}
  //      CargaGrupoJPG1(IDJPG);
  //     }


  CargaGrupoJPG1(IDciclo);
  GD.Vertex2ii(0, 0, 15);
  IDciclo++;
  //if(IDciclo>=16){IDciclo=0;}
  if(IDciclo>=8){IDciclo=0;}
       
  GD.SaveContext();
    GD.ColorRGB(255,0,0);  GD.cmd_number(730,460,31,OPT_CENTER|OPT_SIGNED,Test);
    GD.cmd_text(775, 447, 21, OPT_CENTER, "ms");

    GD.ColorRGB(0,255,0);  
    GD.cmd_text(550, 50, 31, OPT_CENTER, "Grupo de assets:");
    GD.Tag(2);  GD.cmd_number(730,50,31,OPT_CENTER|OPT_SIGNED,IDAsset+1);  GD.Tag(255);
    

  if (GD.inputs.tag==2)
       {
        IDAsset=IDAsset+1;
        if(IDAsset>=6){IDAsset=0;}
        CargaGrupoJPG1(IDJPG);
       }


    
  GD.RestoreContext();

  //GD.ColorA(150);
  int x, y, PV;

  unsigned long currentMillis0 = millis();        
  if(currentMillis0 - previousMillis0 >= interval0)
  {
    previousMillis0 = currentMillis0;
       x = random(0,750); y = random(0,430);
       PV = random(0,NumAssets);
  }
   GD.VertexTranslateX(16*x);  GD.Vertex2ii(0, y, PV);

  
   GD.swap();
  }
}
