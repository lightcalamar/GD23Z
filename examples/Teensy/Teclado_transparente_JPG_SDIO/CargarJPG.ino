void ImagenJPG(int Fondo)
{
  start = millis();       
  archivo = SD.open(FondoJPG[Fondo]);  
  GD.cmd_loadimage(0, 0);
  //GD.loadSdFat(archivo); 
  GD.loadSDIO(archivo); 
  archivo.close();
}
