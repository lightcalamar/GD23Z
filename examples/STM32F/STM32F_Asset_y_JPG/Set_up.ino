void setup() {
   Sd2.begin(SD2_CS, SD_SCK_MHZ(18));
  GD.begin();

  CargaGrupoJPG1(IDJPG);

  MP();
}

void loop() {}
