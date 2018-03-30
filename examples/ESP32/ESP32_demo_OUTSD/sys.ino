void lineas() {

  GD.Begin(LINES);
  GD.SaveContext();
  GD.Vertex2ii(0, 0, 20, 0);          //  SUPERIOR IQUIERDA
  GD.Vertex2ii(500, 0, 20, 0);
  GD.RestoreContext();
    
  GD.SaveContext();                   //  SUPERIOR DERECHA
  GD.VertexTranslateX(16 * 495); GD.Vertex2ii(20, 0, 20, 0);
  GD.VertexTranslateX(16 * 320); GD.Vertex2ii(478, 0, 20, 0);     
  GD.RestoreContext();

  GD.SaveContext();
  GD.Vertex2ii(0, 478, 20, 0);        // LINEA INFERIOR DE LA PANTALLA
  GD.Vertex2ii(500, 478, 20, 0);      // IZQUIERDA
  
                                      // DERECHA
  GD.VertexTranslateX(16 * 498); GD.Vertex2ii(20, 478, 20, 0);
  GD.VertexTranslateX(16 * 320); GD.Vertex2ii(478, 478, 20, 0);     
  GD.RestoreContext();                
  
  GD.SaveContext();
  GD.Vertex2ii(0, 480, 20, 0);        // 1" LINEA LATERAL IZQUIERDA
  GD.Vertex2ii(0, 0, 20, 0);
  GD.RestoreContext(); 
                                      // 4" LINEA LATERAL DERECHA
  GD.SaveContext();
  GD.VertexTranslateX(16*318); GD.Vertex2ii(480, 0, 20, 0);     
  GD.VertexTranslateX(8*636);  GD.Vertex2ii(480, 480, 20, 0);                    
  GD.RestoreContext();    
  
  GD.SaveContext();                  // 3" LINEA LATERAL DERECHA
  GD.VertexTranslateX(16*335); GD.Vertex2ii(180, 0, 20, 0);     
  GD.VertexTranslateX(8*635);  GD.Vertex2ii(200, 480, 20, 0);                    
  GD.RestoreContext();
  
  GD.SaveContext();                  // 2" LINEA LATERAL DERECHA
  GD.Vertex2ii(500, 0, 20, 0);     
  GD.Vertex2ii(500, 480, 20, 0);                      
  GD.RestoreContext(); 
  GD.End();
}


void espera() {
 
  GD.ClearColorRGB(0x000000); //fondo de pantalla
  GD.Clear();

  GD.SaveContext();
//  GD.ColorRGB(YELLOW);
  GD.cmd_text(300, 345, 30, 0, "Espere por favor...");
  GD.RestoreContext();

  GD.ColorRGB(0x00ff00);
  GD.cmd_spinner(420, 225, 3, 1);  
//  GD.cmd_gradient(0, 0, BLACK, 480, 480, 0x000015);   // 0x071907
//  GD.ColorA(200);  
//  GD.cmd_text(GD.w/2, GD.h/2, 30,   OPT_CENTERX, "Procesando espere por favor..."); 
  GD.swap();
}
