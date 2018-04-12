#include <GD23Z.h>

Bitmap title, xaxis, yaxis, YCyg;

void setup()
{
  GD.begin();

  title.fromtext(30, "This is the Chart Title");
  xaxis.fromtext(27, "This is the X axis title");
  yaxis.fromtext(27, "This is the Y axis title");
  YCyg.fromtext(30, "This is the Y axis title");
}

void loop()
{
  GD.ClearColorRGB(0xffffff);
  GD.Clear();

  GD.ColorRGB(0x000000);
  title.draw(240, 30);
  yaxis.draw( 20, 136, DEGREES(270));
  yaxis.draw( 500, 150, DEGREES(300));
  yaxis.draw( 600, 200, DEGREES(360));
  GD.SaveContext();
  GD.ColorRGB(0x00ff00);  YCyg.draw( 500, 300, DEGREES(300));
  GD.ColorRGB(0xff0000);  YCyg.draw( 500, 300, DEGREES(200));
  GD.RestoreContext();
  xaxis.draw(240, 250);

  GD.Begin(LINE_STRIP);
  GD.LineWidth(24);
  for (int x = 50; x < 440; x += 20) {
    int y = 255 - (x / 2 + random(20));
    GD.Vertex2ii(x, y);
  }
  GD.swap();
}
