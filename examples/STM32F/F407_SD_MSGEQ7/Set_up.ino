void setup()
{
  pinMode(res, OUTPUT); 
  pinMode(strobe, OUTPUT); 
  digitalWrite(res,LOW); 
  digitalWrite(strobe,HIGH);  
  lineabaseMSGEQ7();  //linea base en 0
  
  SD.begin(SD2_CS, SD_SCK_MHZ(18));
  GD.begin();
  //SD.begin();
GD.self_calibrate();
  //PIx=0; velP=-5; AvanceC=1;   
  Spectrum();
//  Analizador(); 
  
}
void loop(){}
