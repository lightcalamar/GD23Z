//#define PDNPin 8

void setup()
{
 // Serial.begin(9600);
  SD.begin();

  // pinMode(PDNPin, OUTPUT);
  // digitalWrite(PDNPin, HIGH);  
  // delay(20);
  // digitalWrite(PDNPin, LOW);
  // delay(20);
  // digitalWrite(PDNPin, HIGH);
  // delay(20);
  //GD.wr(REG_PWM_DUTY, 0);
  GD.begin();
  
  //GD.cmd_setrotate(0);
  //GD.self_calibrate();  
  
  espera();
  CargaGrupoJPG1(IDJPG);
//  LOAD_ASSETS();  
//  GD.BitmapHandle(8);
//  GD.cmd_loadimage(ASSETS_END, 0);
//  GD.load("Fn1.jpg"); 

  MP();
}

void loop(){}

unsigned long start, Test;

void CargaGrupoJPG1(int IDJPG)
{
  start = millis(); 
  String StrAsset(ChAsset[IDAsset]);
  FileAsset = SD.open(StrAsset);

  if (IDAsset==0){LOAD_ASSETS0(); NumAssets=10;}
  if (IDAsset==1){LOAD_ASSETS1(); NumAssets=14;}
  if (IDAsset==2){LOAD_ASSETS2(); NumAssets=14;}
  if (IDAsset==3){LOAD_ASSETS3(); NumAssets=8;}
  if (IDAsset==4){LOAD_ASSETS4(); NumAssets=10;}
  if (IDAsset==5){LOAD_ASSETS5(); NumAssets=9;}
  
  Filefondoarchivo = SD.open(GrupoJPG1[IDJPG]);
  GD.BitmapHandle(15);
  GD.cmd_loadimage(ASSETS_END, 0);
  GD.loadSDIO(Filefondoarchivo);

  Test = millis() - start;
}
