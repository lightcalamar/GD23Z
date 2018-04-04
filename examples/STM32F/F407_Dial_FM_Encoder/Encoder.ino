int mul;

void LeeEncoder()
{
  int actual = digitalRead(a);
  if(actual == 0) {
    //delay(15);
    actual = digitalRead(a);
  }
 
  if(anterior == 1 && actual == 0)
  {
    int valor_b = digitalRead(b);
    if(valor_b == 1){contador++;  mul=1; }// Si B = 1, aumentamos el contador
    else {contador--; mul=-1;} // Si B = 0, reducimos el contador
   Dial= Dial+2.5*mul;

   //if (Dial<=-12.0){Dial=-12.0;}
   if (Dial<=-50.0){Dial=-50.0;}  //50=(88-86)/0.04    limite inferior 86   MHz
   //if (Dial>=500){Dial=500;}
   if (Dial>=550){Dial=550;}   //550= (110-88)/0.04,   limite superior 110  MHz
   
  }
  
  anterior = actual;  
}

