int XPo0=0, XPo1=180, XPo2=190, XPo3=XPo1, XPo4=XPo0;
int YPo0=0, YPo1=YPo0, YPo2=25, YPo3=50, YPo4=YPo3;
int DeltaPoY=60;
int XtxT=XPo0+30, YtxT=YPo0+2, DeltaYTxT=60;

int YSpectrum=175, Espesor=40, sep=5, sepC=10;
int XL = (800 - (14*Espesor + 12*sep + sepC))/2;


void Spectrum1()
{
  while(1)
  {
    readMSGEQ7();
    GD.Clear(1, 1, 1);
    GD.get_inputs();

    GD.SaveContext();
    // barrasVSegmentadas(xi, yi, segmentos, largoX, sepX, sepY)
    barrasVSegmentadasL(XL, 155, 7, 33, 10, 8);
    barrasVSegmentadasR(XL+sepC+7*Espesor+7*sep, 155, 7, 33, 10, 8);
    GD.RestoreContext();
    
    GD.SaveContext();
    GD.Begin(BITMAPS);
    int datoI0 = map(leftS[0], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+0*Espesor+0*sep,   YSpectrum, datoI0, 0);
    int datoI1 = map(leftS[1], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+1*Espesor+1*sep,  YSpectrum, datoI1, 0);
    int datoI2 = map(leftS[2], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+2*Espesor+2*sep,  YSpectrum, datoI2, 0);
    int datoI3 = map(leftS[3], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+3*Espesor+3*sep,  YSpectrum, datoI3, 0);
    int datoI4 = map(leftS[4], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+4*Espesor+4*sep, YSpectrum, datoI4, 0);
    int datoI5 = map(leftS[5], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+5*Espesor+5*sep, YSpectrum, datoI5, 0);
    int datoI6 = map(leftS[6], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+6*Espesor+6*sep, YSpectrum, datoI6, 0);

    int datoD0 = map(rightS[0], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+sepC+7*Espesor+7*sep, YSpectrum, datoD0, 0);
    int datoD1 = map(rightS[1], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+sepC+8*Espesor+8*sep, YSpectrum, datoD1, 0);
    int datoD2 = map(rightS[2], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+sepC+9*Espesor+9*sep, YSpectrum, datoD2, 0);

    GD.SaveContext();
    GD.VertexTranslateX((XL+sepC+10*Espesor+10*sep)*16);

    int datoD3 = map(rightS[3], 0, 1023, 0, 15);
    GD.Vertex2ii(0*Espesor+0*sep, YSpectrum, datoD3, 0);
    int datoD4 = map(rightS[4], 0, 1023, 0, 15);
    
    GD.Vertex2ii(1*Espesor+1*sep, YSpectrum, datoD4, 0);
    int datoD5 = map(rightS[5], 0, 1023, 0, 15);
    GD.Vertex2ii(2*Espesor+2*sep, YSpectrum, datoD5, 0);
    int datoD6 = map(rightS[6], 0, 1023, 0, 15);
    GD.Vertex2ii(3*Espesor+3*sep, YSpectrum, datoD6, 0);
    GD.RestoreContext();
   
           
   GD.SaveContext();
   GD.ColorA(100);
   Poly po;
   GD.ColorRGB(0x008B4B);
   GD.Tag(1);  po.begin();  po.v(16*(XPo0),16*(YPo0+DeltaPoY*7));   po.v(16*(XPo1),16*(YPo1+DeltaPoY*7));   po.v(16*(XPo2),16*(YPo2+DeltaPoY*7));   po.v(16*(XPo3),16*(YPo3+DeltaPoY*7));   po.v(16*(XPo4),16*(YPo4+DeltaPoY*7));   po.draw();  GD.Tag(255);
   GD.RestoreContext();
   if (GD.inputs.tag==1)
    { 
      delay(105);   
      PIx=0; velP=VX; AvanceC=1;   Analizador(); 
    }

   //GD.Tag(224);  GD.cmd_button(5, 100, 120, 40, 26, 0,  "Analizador");        GD.Tag(255);
   //if (GD.inputs.tag==224)
   //  {
   //   delay(105);   
   //   PIx=0; velP=VX; AvanceC=1;   Analizador();        
   //  }
    
   Cortina();
   GD.swap();
  }  
}

int TipoL=0;
int TipoR=0;

void Spectrum()
{
  GAsset2 = SD.open(STRAsset2);
  LOAD_ASSETS2();
  while(1)
  {
    readMSGEQ7();
    GD.Clear(1, 1, 1);
    GD.get_inputs();
    
    GD.SaveContext();
    GD.Begin(BITMAPS);
    int datoI0 = map(leftS[0], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+0*Espesor+0*sep,   YSpectrum, datoI0, 0);
    int datoI1 = map(leftS[1], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+1*Espesor+1*sep,  YSpectrum, datoI1, 0);
    int datoI2 = map(leftS[2], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+2*Espesor+2*sep,  YSpectrum, datoI2, 0);
    int datoI3 = map(leftS[3], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+3*Espesor+3*sep,  YSpectrum, datoI3, 0);
    int datoI4 = map(leftS[4], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+4*Espesor+4*sep, YSpectrum, datoI4, 0);
    int datoI5 = map(leftS[5], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+5*Espesor+5*sep, YSpectrum, datoI5, 0);
    int datoI6 = map(leftS[6], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+6*Espesor+6*sep, YSpectrum, datoI6, 0);

    int datoD0 = map(rightS[0], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+sepC+7*Espesor+7*sep, YSpectrum, datoD0, 0);
    int datoD1 = map(rightS[1], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+sepC+8*Espesor+8*sep, YSpectrum, datoD1, 0);
    int datoD2 = map(rightS[2], 0, 1023, 0, 15);
    GD.Vertex2ii(XL+sepC+9*Espesor+9*sep, YSpectrum, datoD2, 0);

    GD.SaveContext();
    GD.VertexTranslateX((XL+sepC+10*Espesor+10*sep)*16);

    int datoD3 = map(rightS[3], 0, 1023, 0, 15);
    GD.Vertex2ii(0*Espesor+0*sep, YSpectrum, datoD3, 0);
    int datoD4 = map(rightS[4], 0, 1023, 0, 15);
    
    GD.Vertex2ii(1*Espesor+1*sep, YSpectrum, datoD4, 0);
    int datoD5 = map(rightS[5], 0, 1023, 0, 15);
    GD.Vertex2ii(2*Espesor+2*sep, YSpectrum, datoD5, 0);
    int datoD6 = map(rightS[6], 0, 1023, 0, 15);
    GD.Vertex2ii(3*Espesor+3*sep, YSpectrum, datoD6, 0);
    GD.RestoreContext();

    GD.Tag(10);
    if(TipoL==0){
    GD.SaveContext();
    // barrasVSegmentadas(xi, yi, segmentos, largoX, sepX, sepY)
    barrasVSegmentadasL(XL, 115, 7, 33, 10, 8);
    GD.RestoreContext();
    }

    if(TipoL==1){
    GD.SaveContext();
    GD.ColorA(40); 
    GD.ColorRGB(0x00ff00);  
    GD.LineWidth(1 * 16);
    GD.Begin(LINES);
       McVL(80+XL, 50);
       McHL(80+XL, 50);
    GD.ColorA(255); //color solido 
    
    Baseactual2ML(80+XL, -152);                          //  Gráfica lineal Izquierda

    GD.End();
    GD.RestoreContext();
    }
   GD.Tag(255);
   
   if (GD.inputs.tag==10)
    { 
      delay(85);   
      TipoL=TipoL+1;
      if(TipoL>=2){TipoL=0;} 
    }

    GD.Tag(11);
    if(TipoR==0){
    GD.SaveContext();
    // barrasVSegmentadas(xi, yi, segmentos, largoX, sepX, sepY)
    barrasVSegmentadasR(XL+sepC+7*Espesor+7*sep, 115, 7, 33, 10, 8);
    GD.RestoreContext();
    }

    if(TipoR==1){
    GD.SaveContext();
    GD.ColorA(40); 
    GD.ColorRGB(0x00ff00);  
    GD.LineWidth(1 * 16);
    GD.Begin(LINES);
       McVR(80+XL+sepC+7*Espesor+7*sep, 50);
       McHR(80+XL+sepC+7*Espesor+7*sep, 50);
    GD.ColorA(255); //color solido 
    
    Baseactual2MR(80+XL+sepC+7*Espesor+7*sep, -152);     //  Gráfica lineal derecha
    GD.End();
    GD.RestoreContext();
    }
   GD.Tag(255);
   
   if (GD.inputs.tag==11)
    { 
      delay(85);   
      TipoR=TipoR+1;
      if(TipoR>=2){TipoR=0;} 
    }

           
   GD.SaveContext();
   GD.ColorA(100);
   Poly po;
   GD.ColorRGB(0x008B4B);
   GD.Tag(1);  po.begin();  po.v(16*(XPo0),16*(YPo0+DeltaPoY*7));   po.v(16*(XPo1),16*(YPo1+DeltaPoY*7));   po.v(16*(XPo2),16*(YPo2+DeltaPoY*7));   po.v(16*(XPo3),16*(YPo3+DeltaPoY*7));   po.v(16*(XPo4),16*(YPo4+DeltaPoY*7));   po.draw();  GD.Tag(255);
   GD.RestoreContext();
   if (GD.inputs.tag==1)
    { 
      delay(105);   
      PIx=0; velP=VX; AvanceC=1;   Analizador(); 
    }

   //GD.Tag(224);  GD.cmd_button(5, 100, 120, 40, 26, 0,  "Analizador");        GD.Tag(255);
   //if (GD.inputs.tag==224)
   //  {
   //   delay(105);   
   //   PIx=0; velP=VX; AvanceC=1;   Analizador();        
   //  }
    
   Cortina();
   GD.swap();
  }  
}

// Diseño de marco para gráfica
int RectWidthM = 178, RectHeightM = 70;

void McVR(int XGTMR, int YGTM)
{
    for (int k=0; k<15; k++)
     {    
  GD.Vertex2f((XGTMR+(k*10)) * 16, YGTM* 16);  //starting coordinates
  GD.Vertex2f((XGTMR+(k*10)) * 16, (YGTM+RectHeightM) * 16);  //ending coordinates
     }  
}

void McHR(int XGTMR, int YGTM)
{
    for (int k=0; k<8; k++)
     {    
  GD.Vertex2f((XGTMR) * 16, (YGTM+(k*10))* 16);  //starting coordinates
  GD.Vertex2f((XGTMR+140) * 16, (YGTM+(k*10)) * 16);  //ending coordinates
     }     
}

void McVL(int XGTML, int YGTM)
{
    for (int k=0; k<15; k++)
     {    
  GD.Vertex2f((XGTML+(k*10)) * 16, YGTM* 16);  //starting coordinates
  GD.Vertex2f((XGTML+(k*10)) * 16, (YGTM+RectHeightM) * 16);  //ending coordinates
     }  
}

void McHL(int XGTML, int YGTM)
{
    for (int k=0; k<8; k++)
     {    
  GD.Vertex2f((XGTML) * 16, (YGTM+(k*10))* 16);  //starting coordinates
  GD.Vertex2f((XGTML+140) * 16, (YGTM+(k*10)) * 16);  //ending coordinates
     }     
}

// Diseño de marco para gráfica
