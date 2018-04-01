void setup()
{
  pinMode(res, OUTPUT); 
  pinMode(strobe, OUTPUT); 
  digitalWrite(res,LOW); 
  digitalWrite(strobe,HIGH);  
  GD.begin();
  lineabaseMSGEQ7();  //linea base en 0
  
  Sd2.begin(SD2_CS, SD_SCK_MHZ(18));
  GD.begin();

  MP();
  
}
void loop(){}
