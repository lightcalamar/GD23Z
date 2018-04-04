#include <GD23Z.h>

File archivo1;
//SdFatSdio SD;
SdFat SD(2);  const uint8_t SD_CS = PA11;   // F767


#define SHARE(X)  do {GD.__end(); (X); GD.resume();} while (0)                  
#define FONT 26
int SepY=20;                                                                 
                                                                                
void setup()                                                                    
{                                                                               
  GD.begin();
  //SD.begin();
  SD.begin(SD_CS, SD_SCK_MHZ(36));

  archivo1 = SD.open("Fn1.jpg");
  GD.cmd_loadimage(0, 0);
  GD.loadSDIO(archivo1);
}                                                                               
                                                                                
void loop()                                                                      
{                                                                               
  File dir, entry;                                                              
  GD.Clear();
  GD.SaveContext();
    GD.Begin(BITMAPS);
    GD.ColorA(50);
    GD.Vertex2ii(0, 0);
    GD.End();
  GD.RestoreContext();
                                                                   
  SHARE(dir = SD.open("/"));                                                    
  for (int y = 0; y < 480; y += SepY) {                                          
    SHARE(entry = dir.openNextFile());                                          
    if (!entry)                                                                 
      break;                                                                    
    GD.cmd_text(0, y, FONT, 0,  entry.name());
    if (entry.isDirectory())                                                    
      GD.cmd_text(300, y, FONT, OPT_RIGHTX, "<dir>");                           
    else                                                                        
      GD.cmd_number(300, y, FONT, OPT_RIGHTX, entry.size());                    
    SHARE(entry.close());                                                       
  }                                                                             
  SHARE(dir.close());  

  GD.printNfloat(700, 100, SD.card()->cardSize()*512E-9, 2, 28);
  GD.cmd_text(750, 100, 28, 0, "Gb");
                                                          
  GD.swap();                                                                    
}
