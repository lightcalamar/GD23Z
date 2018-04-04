#include <GD23Z.h>  


#define TAG_SLIDER    201
byte brightness = 90;       // 90 brightness PWM Backlight


void brillo() {        // function brightness
   
  do {    
  GD.ClearColorRGB(0x000015);
  GD.Clear(); 

 // GD.SaveContext();
 // lineas();
//  GD.RestoreContext(); 

  GD.ColorRGB(0xffff00);
  GD.cmd_text(185, 150, 31, 0,  "Control screen FT81x");

  GD.Tag(1);
  GD.cmd_fgcolor(0x000000); 
  GD.ColorRGB(0xffffff);
  GD.cmd_romfont(1, 32);
  GD.cmd_button(20, 20, 760, 70, 1, 0, "Control brightness FT81x"); GD.Tag(255);
     if (GD.inputs.tag==1) {
       delay(175);  }
         
  GD.SaveContext(); 
  GD.Tag(TAG_SLIDER);
  GD.cmd_fgcolor(0xffff00);                     
  GD.ColorRGB(0x0000ff); 
  GD.cmd_bgcolor(0x000000);      
  GD.cmd_slider(150, 270, 450, 15, 0, brightness, 128);
  GD.cmd_track( 150, 270, 450, 15, TAG_SLIDER);

  GD.get_inputs();
  switch (GD.inputs.track_tag & 0xff) {
  case TAG_SLIDER:
  brightness = GD.inputs.track_val * 128L / 65535;
  GD.wr(REG_PWM_DUTY,(brightness));
  break;
  }
  
  GD.RestoreContext();

  GD.SaveContext(); 
  GD.ColorRGB(0xffffff);   
  GD.cmd_romfont(1, 34);
  GD.cmd_number(GD.w /2 - 50, 370, 1, 0, brightness); 
  GD.RestoreContext();

  GD.swap();
 } while(1);
} 


void lineas() {
  
  GD.Begin(LINES);
  GD.SaveContext();
  GD.Vertex2ii(0, 0, 20, 0);         // LINEA SUPERIOR DE LA PANTALLA
  GD.Vertex2ii(319, 0, 20, 0);
  GD.VertexTranslateX(16*320); GD.Vertex2ii(480, 0, 20, 0);
  GD.VertexTranslateX(16*320); GD.Vertex2ii(0, 0, 20, 0);
  GD.RestoreContext();

  GD.SaveContext();
  GD.Vertex2ii(0, 478, 20, 0);        // LINEA INFERIOR DE LA PANTALLA
  GD.Vertex2ii(478, 478, 20, 0);
  GD.VertexTranslateX(16*480); GD.Vertex2ii(0, 478, 20, 0);
  GD.VertexTranslateX(16*320); GD.Vertex2ii(478, 478, 20, 0);     
  GD.RestoreContext();
  
  GD.SaveContext();
  GD.Vertex2ii(0, 480, 20, 0);        // LINEA LATERAL IZQUIERDA
  GD.Vertex2ii(0, 0, 20, 0);
  GD.RestoreContext(); 
                                      // LINEA LATERAL DERECHA
  GD.SaveContext();
  GD.VertexTranslateX(16 * 318); GD.Vertex2ii(480, 0, 20, 0);     
  GD.VertexTranslateX( 8 * 636);  GD.Vertex2ii(480, 480, 20, 0);                    
  GD.RestoreContext();           
  GD.End(); 
}

void setup() {

 GD.begin();
 brillo();
}

void loop() { }

