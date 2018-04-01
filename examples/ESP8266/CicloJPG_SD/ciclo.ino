void Ciclo()
{
  start = millis();       
  GD.cmd_loadimage(0, 0);
  GD.load("6oBaa.jpg");
  CargaJPG();  

  start = millis();       
  GD.cmd_loadimage(0, 0);
  GD.load("6oBba.jpg");
  CargaJPG();

  start = millis();       
  GD.cmd_loadimage(0, 0);
  GD.load("6oFb.jpg");
  CargaJPG();

  start = millis();       
  GD.cmd_loadimage(0, 0);
  GD.load("6oGb.jpg");
  CargaJPG();

  start = millis();       
  GD.cmd_loadimage(0, 0);
  GD.load("6oHaa.jpg");
  CargaJPG();
}  
