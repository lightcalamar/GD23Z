void McVL(int XGTML, int YGTM)
{
    for (int k=0; k<=NDH; k++) //numero de divisores horizontales 14
     {    
  GD.Vertex2f((XGTML+(k*PitchX)) * 16, YGTM* 16);  //starting coordinates
  GD.Vertex2f((XGTML+(k*PitchX)) * 16, (YGTM+RectHeightM) * 16);  //ending coordinates
     }  
}

void McHL(int XGTML, int YGTM)
{
    for (int k=0; k<=NDV; k++) //numero de divisores verticales 7
     {    
  GD.Vertex2f((XGTML) * 16, (YGTM+(k*PitchY))* 16);  //starting coordinates
  GD.Vertex2f((XGTML+RectWidthM) * 16, (YGTM+(k*PitchY)) * 16);  //ending coordinates, 140, modifica largo de la grafica
     }     
}
