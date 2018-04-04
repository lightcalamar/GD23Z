//# include <EEPROM.h>
//# include <SPI.h>
# include <GD23Z.h>

static uint16_t valu  = 0;
#define TAG_TOGGLE    202   

static uint16_t verano  = 0;
#define TAG_TOGGLE_1    203   

static uint16_t salva  = 0;
#define TAG_TOGGLE_2    204   

static uint16_t fade  = 0;
#define TAG_TOGGLE_3    205 

static uint16_t desper  = 0;
#define TAG_TOGGLE_4    206  

void setup() {
GD.begin();
menu();
}

void loop() { }

void menu() {
 do {

  GD.get_inputs(); 
  GD.ClearColorRGB(0x000015);
  GD.Clear();
     
  GD.ColorRGB(0xffffff); 
  GD.Tag(1);
  GD.cmd_fgcolor(0xff0000);
  GD.cmd_button(20, 410, 100, 50, 30, OPT_FLAT, "Salir"); GD.Tag(255); 
    if (GD.inputs.tag==1) {delay(150); // yout function
} 

// ------------------------------------------------------------
  GD.cmd_text(40,  80, 30, 0, "Horario Verano ?");
  GD.cmd_text(40, 130, 30, 0, "Salvapantalla ?"); 
  GD.cmd_text(40, 180, 30, 0, "Activar Fade ?");  
  GD.cmd_text(40, 230, 30, 0, "Despertador ?");   

  switch (GD.inputs.track_tag & 0xff) {
  case TAG_TOGGLE_1:
  verano = GD.inputs.track_val ;  // your function
  }

  GD.Tag(TAG_TOGGLE_1);
  GD.cmd_toggle(400, 95, 50, 29, 0, verano, "No" "\xff" "Yes");
  GD.cmd_track( 400, 95, 50, 29, TAG_TOGGLE_1);    

// -----------------------------------------------------------
  switch (GD.inputs.track_tag & 0xff) {
  case TAG_TOGGLE_2:
  salva = GD.inputs.track_val ;  // yout function
  }

  GD.Tag(TAG_TOGGLE_2);
  GD.cmd_toggle(400, 145, 50, 29, 0, salva, "No" "\xff" "Yes");
  GD.cmd_track( 400, 145, 50, 29, TAG_TOGGLE_2);    

// -----------------------------------------------------------
  switch (GD.inputs.track_tag & 0xff) {
  case TAG_TOGGLE_3:
  fade = GD.inputs.track_val ; // yout function
  }

  GD.Tag(TAG_TOGGLE_3);
  GD.cmd_toggle(400, 195, 50, 29, 0, fade, "No" "\xff" "Yes");
  GD.cmd_track( 400, 195, 50, 29, TAG_TOGGLE_3);    

// -----------------------------------------------------------
  switch (GD.inputs.track_tag & 0xff) {
  case TAG_TOGGLE_4:
  desper = GD.inputs.track_val ; // yout function
  }

  GD.Tag(TAG_TOGGLE_4);
  GD.cmd_toggle(400, 245, 50, 29, 0, desper, "No" "\xff" "Si");
  GD.cmd_track( 400, 245, 50, 29, TAG_TOGGLE_4);
      
     GD.swap(); 
  } while(1);
}
