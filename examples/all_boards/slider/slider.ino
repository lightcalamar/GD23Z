#include <GD23Z.h>

//http://gameduino2.proboards.com/thread/226/slider

#define SliderRojo  201
#define SliderVerde 202
#define SliderAzul  203
int ValorR=125, ValorG=125, ValorB=125, PX=350, PXS=100, PYS=35;

uint16_t RectWidth=100, RectHeight=50;

void setup() {
  Serial.begin(115200);
  GD.begin();
  //GD.self_calibrate();
}

void loop() {
  GD.ClearColorRGB(0x103000);
  GD.Clear();
  GD.get_inputs();  

  //Draw clock
 // GD.cmd_clock(50,50,50,OPT_FLAT,12,33,45,0);

GD.SaveContext();
	GD.ColorRGB(ValorR, 0, 0);//set the color of the rectangle to red
	GD.LineWidth(1 * 16);//set the line width to 1 pixels - corner are 1 pixel radius
	GD.Begin(RECTS);//begin lines primitive	
	GD.Vertex2f(PX*16,  10*16);	                                //top left coordinates
	GD.Vertex2f((PX + RectWidth)*16,  (10 + RectHeight)*16);	//bottom right coordinates

	GD.ColorRGB(0, ValorG, 0);//set the color of the rectangle to green
	GD.Begin(RECTS);//begin lines primitive	
	GD.Vertex2f(PX*16,  (10+10+RectHeight)*16);	                //top left coordinates
	GD.Vertex2f((PX + RectWidth)*16,  (10*2 + RectHeight*2)*16);	//bottom right coordinates

	GD.ColorRGB(0, 0, ValorB);//set the color of the rectangle to blue
	GD.Begin(RECTS);//begin lines primitive	
	GD.Vertex2f(PX*16,  (10+10+RectHeight+10+RectHeight)*16);       //top left coordinates
	GD.Vertex2f((PX + RectWidth)*16,  (10*3 + RectHeight*3)*16);	//bottom right coordinates

	GD.ColorRGB(ValorR, ValorG, ValorB);//set the color of the rectangle to MIX
	GD.Begin(RECTS);//begin lines primitive	
	GD.Vertex2f(PX*16,  (10+10+RectHeight+10+RectHeight+10+RectHeight)*16);       //top left coordinates
	GD.Vertex2f((PX + RectWidth)*16,  (10*4 + RectHeight*4)*16);	//bottom right coordinates
	GD.End();
GD.RestoreContext();

GD.ColorRGB(0xffffff);   GD.cmd_number(PX, 10, 28, OPT_RIGHTX | OPT_SIGNED, ValorR);  
GD.ColorRGB(0xffffff);   GD.cmd_number(PX, 10+10+50, 28, OPT_RIGHTX | OPT_SIGNED, ValorG);  
GD.ColorRGB(0xffffff);   GD.cmd_number(PX, 10+10+10+100, 28, OPT_RIGHTX | OPT_SIGNED, ValorB);  

//Draw Slider color Rojo
  GD.Tag(SliderRojo);
  GD.cmd_fgcolor(0xFF0000);  
  GD.cmd_slider(PXS,PYS,200,10,OPT_FLAT,ValorR,255);
  //            x,   y,  largo, espesor, tag a seguir 
  GD.cmd_track( PXS,PYS,200,10,SliderRojo);


  switch (GD.inputs.track_tag & 0xff) {
  case SliderRojo:
    ValorR = GD.inputs.track_val * 255L / 65535;
    Serial.println(ValorR);
    break;
   }
//Draw Slider color Rojo


//Draw Slider color Verde
  GD.Tag(SliderVerde);
  GD.cmd_fgcolor(0x00FF00);
  GD.cmd_slider(PXS,95,200,10,OPT_FLAT,ValorG,255);
  //            x,   y,  largo, espesor, tag a seguir 
  GD.cmd_track( PXS,95,200,10,SliderVerde);


  switch (GD.inputs.track_tag & 0xff) {
  case SliderVerde:
    ValorG = GD.inputs.track_val * 255L / 65535;
    Serial.println(ValorG);
    break;
   }
//Draw Slider color Verde

//Draw Slider color Azul
  GD.Tag(SliderAzul);
//  GD.cmd_fgcolor(0x008A4B);
  GD.cmd_fgcolor(0x0000FF);
  GD.cmd_slider(PXS,155,200,10,OPT_FLAT,ValorB,255);
  //            x,   y,  largo, espesor, tag a seguir 
  GD.cmd_track( PXS,155,200,10,SliderAzul);


  switch (GD.inputs.track_tag & 0xff) {
  case SliderAzul:
    ValorB = GD.inputs.track_val * 255L / 65535;
    Serial.println(ValorB);
    break;
   }
//Draw Slider color Azul

  GD.swap();
}

