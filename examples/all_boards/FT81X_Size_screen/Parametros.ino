extern "C" char* sbrk(int incr);
float freeRam() {
  char top;
  return &top - reinterpret_cast<char*>(sbrk(0));
}


