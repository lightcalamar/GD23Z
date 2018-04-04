void insertadatos2()
{
  unsigned long currentMillis2 = millis();        
  if(currentMillis2 - previousMillis2 > interval2)
  {
    previousMillis2 = currentMillis2;       
    for (j=0; j<maxlecturas-1; j++)
      {
        lectura2[j]=lectura2[j+1];   // genera la base de datos previa, recorriendo un dato hacia atrás
      }      
    LecturaMSGEQ72();  //Toma la lectura actual del sensor
    lectura2[maxlecturas-1] = Valor2;       //base de maxlecturas puntos
  } 
}

void Baseactual2()  // Gráfico lineal
{
   GD.ColorRGB(0xFF,0xff,0x00);
   GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturas; j++)
     {    
        GD.Vertex2f(((j*separacion)+XGT+separacion/2) * 16, (YGT+RectHeight-(lectura2[j])) * 16);
     }

    lectura2[maxlecturas-1] = Valor2;  
    //sprintf(TX,"%03d", lectura2[maxlecturas-1]); GD.cmd_text(34, 110, 16, 0, TX);  //Presenta el valor graficado
    //sprintf(TX,"%04d", Lectura2); GD.cmd_text(25, 136, 16, 0, TX);
    j=0;  //al salir deja j=0 para empezar la matriz en (0,0)
    insertadatos2();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}

void LecturaMSGEQ72()
{
  if(leftS[2]>0){
  Lectura2=leftS[2];}  //solo el canal seleccionado
  //Lectura2=0;
  //Lectura2=1024;
  //Lectura2=(leftS[0]+leftS[1]+leftS[2]+leftS[3]+leftS[4]+leftS[5]+leftS[6])/7;  //promedio
  Valor2=Lectura2/(valormaximoY/RectHeight);  //ajuste para que el gráfico quede dentro del marco  
}

//Lista de valores en la base 2
void Arraydatos2()
{
  for (j=0; j<=12; j++)  //Puedes usar cualquier intervalo entre 0 y maxlecturas   XD XD, solo muestra del 0-4 
    {  
      GD.ColorRGB(255,255,0);
      sprintf(TX,"%02d", j);  GD.cmd_text(xTextoT, (yTextoT+15*j), 16, 0, TX);   sprintf(TX,"%04d", (lectura2[j])*valormaximoY/RectHeight); GD.cmd_text(xTextoT+25, (yTextoT+15*j), 16, 0, TX);   
    }
}


void insertadatosMR()  //En Baseactual()  ---->    convertida en función XD
{
// Esta función debe recorrer los datos hacia atrás y luego insertará el dato actual al final de la lista
//  La base nueva corresponde a la base previa -1 dato
  unsigned long currentMillisMR = millis();        
  if(currentMillisMR - previousMillisMR > intervalMR)
  {
    // save the last time 
    previousMillisMR = currentMillisMR;       
  
    for (j=0; j<maxlecturasM-1; j++)
      {
        lecturaMR[j]=lecturaMR[j+1];   // genera la base de datos previa, recorriendo un dato hacia atrás
      }      
    LecturaMSGEQ7MR();  //Toma la lectura actual del sensor
    lecturaMR[maxlecturasM-1] = ValorMR;       //base de maxlecturas puntos
  } //usa millis en lugar de delay XD XD XD para actualizar la gráficaT
}


void Baseactual2MR(int XGTMR, int YbaseM)  // lineas
{
//lee la base de datos actual  

//Gráfica lineal      
     GD.ColorRGB(0xFF,0xff,0x00);
     GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturasM; j++)
     {    
        GD.Vertex2f(((j*separacionM)+XGTMR+2) * 16, (272+(YbaseM)-(lecturaMR[j])) * 16);
     }

    lecturaMR[maxlecturasM-1] = ValorMR;  
    //sprintf(TX,"%02d", lectura[maxlecturas-1]); GD.cmd_text(41, 110, 16, 0, TX);  //Presenta lectura actual
    //sprintf(TX,"%04d", Lectura); GD.cmd_text(25, 136, 16, 0, TX);      GD.cmd_text(402, 10, 16, OPT_CENTER, "Quad-MSGEQ7");       
     j=0;  //al salir deja j=0 para empezar la matriz en (0,0)
     insertadatosMR();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}

void LecturaMSGEQ7MR()
{
 // readMSGEQ7();
  LecturaMR=rightS[2];  //solo el canal seleccionado
//  Lectura=(rightS[0]+rightS[1]+rightS[2]+rightS[3]+rightS[4]+rightS[5]+rightS[6])/7;  //promedio
  ValorMR=LecturaMR/15;  //ajuste para que el gráfico quede dentro de la ventana
}


void insertadatosML()  //En Baseactual()  ---->    convertida en función XD
{
// Esta función debe recorrer los datos hacia atrás y luego insertará el dato actual al final de la lista
//  La base nueva corresponde a la base previa -1 dato
  unsigned long currentMillisML = millis();        
  if(currentMillisML - previousMillisML > intervalML)
  {
    // save the last time 
    previousMillisML = currentMillisML;       
  
    for (j=0; j<maxlecturasM-1; j++)
      {
        lecturaML[j]=lecturaML[j+1];   // genera la base de datos previa, recorriendo un dato hacia atrás
      }      
    LecturaMSGEQ7ML();  //Toma la lectura actual del sensor
    lecturaML[maxlecturasM-1] = ValorML;       //base de maxlecturas puntos
  } //usa millis en lugar de delay XD XD XD para actualizar la gráficaT
}


void Baseactual2ML(int XGTML, int YbaseM)  // lineas
{
//lee la base de datos actual  

//Gráfica lineal      
     GD.ColorRGB(0xFF,0xff,0x00);
     GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturasM; j++)
     {    
        GD.Vertex2f(((j*separacionM)+XGTML+2) * 16, (272+(YbaseM)-(lecturaML[j])) * 16);
     }

    lecturaML[maxlecturasM-1] = ValorML;
    //sprintf(TX,"%02d", lectura[maxlecturas-1]); GD.cmd_text(41, 110, 16, 0, TX);  //Presenta lectura actual
    //sprintf(TX,"%04d", Lectura); GD.cmd_text(25, 136, 16, 0, TX);      GD.cmd_text(402, 10, 16, OPT_CENTER, "Quad-MSGEQ7");       
     j=0;  //al salir deja j=0 para empezar la matriz en (0,0)
     insertadatosML();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}

void LecturaMSGEQ7ML()
{
 // readMSGEQ7();
  LecturaML=leftS[2];  //solo el canal seleccionado
//  Lectura=(leftS[0]+leftS[1]+leftS[2]+leftS[3]+leftS[4]+leftS[5]+leftS[6])/7;  //promedio
  ValorML=LecturaML/15;  //ajuste para que el gráfico quede dentro de la ventana
}
