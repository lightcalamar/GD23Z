void setup()
{
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);
 // GD.self_calibrate();  
  espera();
  LOAD_ASSETS();  
  GD.BitmapHandle(8);
  GD.cmd_loadimage(ASSETS_END, 0);
  GD.load("B002.jpg"); 

  MP();
}

void loop(){}
