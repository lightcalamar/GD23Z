extern "C" char* sbrk(int incr);
float freeRam() {
  char top;
  return &top - reinterpret_cast<char*>(sbrk(0));
}

//char TX[50];
int RAM = 65536;   //F103ZET6
//int RAM = 131072;   //F407ZGT6

void STM32()
{
  GD.ColorRGB(0x00ff00); sprintf(TX,"F_CPU: %d MHz", (F_CPU/1000000));  GD.cmd_text(GD.w - 105, 0, 26, 0, TX);
 
  //float RAMFree = (freeRam()/1)*100/ST_RAM;   
  float RAMFree = (freeRam()/1)*100/RAM;   
  int RAMUsed= 100-RAMFree;
 
  GD.ColorRGB(0x00ff00); sprintf(TX,"RAM: %d/%d", RAMUsed,100);  GD.cmd_text(GD.w - 105, 20, 26, 0, TX);
}
