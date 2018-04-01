//#define LOAD_ASSETS2()  GD.safeload("AV3SD.gd2");
#define LOAD_ASSETS2()  GD.safeloadSDIO(AV3);
#define AV1A_HANDLE 0
#define AV1A_WIDTH 510
#define AV1A_HEIGHT 480
#define AV1A_CELLS 1
#define AV1B_HANDLE 1
#define AV1B_WIDTH 290
#define AV1B_HEIGHT 480
#define AV1B_CELLS 1
#define DHT_HANDLE 2
#define DHT_WIDTH 100
#define DHT_HEIGHT 74
#define DHT_CELLS 1
#define DS3231_HANDLE 3
#define DS3231_WIDTH 100
#define DS3231_HEIGHT 100
#define DS3231_CELLS 1
#define FT8XX_HANDLE 4
#define FT8XX_WIDTH 200
#define FT8XX_HEIGHT 130
#define FT8XX_CELLS 1
#define STM32_HANDLE 5
#define STM32_WIDTH 275
#define STM32_HEIGHT 100
#define STM32_CELLS 1
#define ASSETS2_END 909800UL
static const shape_t AV1A_SHAPE = {0, 510, 480, 0};
static const shape_t AV1B_SHAPE = {1, 290, 480, 0};
static const shape_t DHT_SHAPE = {2, 100, 74, 0};
static const shape_t DS3231_SHAPE = {3, 100, 100, 0};
static const shape_t FT8XX_SHAPE = {4, 200, 130, 0};
static const shape_t STM32_SHAPE = {5, 275, 100, 0};
