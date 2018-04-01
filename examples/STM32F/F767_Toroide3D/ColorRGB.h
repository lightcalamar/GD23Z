#ifndef _quickcg_h_included
#define _quickcg_h_included
#include <GD23Z.h>

#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm> //std::min and std::max
////////////////////////////////////////////////////////////////////////////////
//COLOR STRUCTS/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct ColorRGB8bit;
//a color with 3 components: r, g and b
struct ColorRGB
{
  int r;
  int g;
  int b;
//In the case of the ARM:
//
//uint8_t_t is unsigned char;
//int8_t is signed char;
//uint16_t is unsigned short;
//int16_t is short;
//uint32_t is unsigned int;
//int32_t is int.
  ColorRGB(uint8_t r, uint8_t g, uint8_t b);
  ColorRGB(const ColorRGB8bit& color);
  ColorRGB();
};

ColorRGB operator+(const ColorRGB& color, const ColorRGB& color2);
ColorRGB operator-(const ColorRGB& color, const ColorRGB& color2);
ColorRGB operator*(const ColorRGB& color, int a);
ColorRGB operator*(int a, const ColorRGB& color);
ColorRGB operator/(const ColorRGB& color, int a);
bool operator==(const ColorRGB& color, const ColorRGB& color2);
bool operator!=(const ColorRGB& color, const ColorRGB& color2);

static const ColorRGB RGB_Black    (  0,   0,   0);
static const ColorRGB RGB_Red      (255,   0,   0);
static const ColorRGB RGB_Green    (  0, 255,   0);
static const ColorRGB RGB_Blue     (  0,   0, 255);
static const ColorRGB RGB_Cyan     (  0, 255, 255);
static const ColorRGB RGB_Magenta  (255,   0, 255);
static const ColorRGB RGB_Yellow   (255, 255,   0);
static const ColorRGB RGB_White    (255, 255, 255);
static const ColorRGB RGB_Gray     (128, 128, 128);
static const ColorRGB RGB_Grey     (192, 192, 192);
static const ColorRGB RGB_Maroon   (128,   0,   0);
static const ColorRGB RGB_Darkgreen(  0, 128,   0);
static const ColorRGB RGB_Navy     (  0,   0, 128);
static const ColorRGB RGB_Teal     (  0, 128, 128);
static const ColorRGB RGB_Purple   (128,   0, 128);
static const ColorRGB RGB_Olive    (128, 128,   0);

//a color with 3 components: r, g and b
struct ColorRGB8bit
{
  uint8_t r;
  uint8_t g;
  uint8_t b;

  ColorRGB8bit(uint8_t r, uint8_t g, uint8_t b);
  ColorRGB8bit(const ColorRGB& color);
  ColorRGB8bit();
};

//a color with 3 components: h, s and l
struct ColorHSL
{
  int h;
  int s;
  int l;

  ColorHSL(uint8_t h, uint8_t s, uint8_t l);
  ColorHSL();
};

//a color with 3 components: h, s and v
struct ColorHSV
{
  int h;
  int s;
  int v;

  ColorHSV(uint8_t h, uint8_t s, uint8_t v);
  ColorHSV();
};

////////////////////////////////////////////////////////////////////////////////
//COLOR CONVERSIONS/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
ColorHSL RGBtoHSL(const ColorRGB& colorRGB);
ColorRGB HSLtoRGB(const ColorHSL& colorHSL);
ColorHSV RGBtoHSV(const ColorRGB& colorRGB);
ColorRGB HSVtoRGB(const ColorHSV& colorHSV);
uint32_t RGBtoINT(const ColorRGB& colorRGB);
uint16_t RGBtoINT2(const ColorRGB& colorRGB);
ColorRGB INTtoRGB(uint32_t colorINT);
#endif
