void screen() {

   do {
   GD.ClearColorRGB(0x000025);
   GD.Clear();
   GD.ColorRGB(0xffffff);
//   GD.SaveContext();
    GD.Begin(BITMAPS);

    GD.Vertex2ii(5, 10, T1_HANDLE);
    GD.Vertex2ii(140, 10, T2_HANDLE);
    GD.Vertex2ii(310, 10, T3_HANDLE);
    
    GD.SaveContext(); 
    GD.VertexTranslateX(16 * 400); GD.Vertex2ii(80, 10, T4_HANDLE);    
    GD.VertexTranslateX(16 * 400); GD.Vertex2ii(240, 10, T5_HANDLE); 
    GD.VertexTranslateX(16 * 400); GD.Vertex2ii(80, 240, T9_HANDLE);   
    GD.VertexTranslateX(16 * 400); GD.Vertex2ii(240, 240, T0_HANDLE);  
          
    GD.RestoreContext();
   
    GD.Vertex2ii(5, 240, T6_HANDLE);
    GD.Vertex2ii(140, 240, T7_HANDLE);
    GD.Vertex2ii(310, 240, T8_HANDLE);

              
        


   
    GD.swap();
 } while(1);
}

