#if defined(__arm__)
extern "C" char* sbrk(int incr);
static int FreeStack() {
  char top = 't';
  return &top - reinterpret_cast<char*>(sbrk(0));
}
#endif

char TXP[50];

void Parametros()
{
  ram = FreeStack();
  GD.SaveContext();
  GD.ColorRGB(0x00ff00); 
   sprintf(TXP,"F_CPU: %d MHz", (F_CPU/1000000));  GD.cmd_text(5, 0, 26, 0, TXP);
   //sprintf(TXP,"F_RAM:  %d Kb", (ram/1024));  GD.cmd_text(5, 15, 26, 0, TXP);
   //sprintf(TXP,"U_RAM:  %d Kb", ((262144-ram)/1024));  GD.cmd_text(5, 30, 26, 0, TXP);  //T36
   //sprintf(TXP,"U_RAM:  %d Kb", ((131072-ram)/1024));  GD.cmd_text(5, 30, 26, 0, TXP);  //F429
   
  GD.RestoreContext();
}
