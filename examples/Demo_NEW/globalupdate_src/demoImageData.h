/*
	demoImageData.h
  DEMO set of Image Data
*/

// Load Global Update Images
#if(SCRN == 340)
#include "image_data/3.40/image_340_456X392_BW.c"
#define frameSize	22344
#define BW_monoBuffer (uint8_t *)&image_340_456X392_BW_mono
#define BW_0x00Buffer (uint8_t *)&image_340_456X392_BW_0x00
#elif(SCRN == 581)
#include "image_data/5.81/image_581_720x256_BW.c"
#include "image_data/5.81/image_581_720x256_BWR.c"
#define frameSize	23040
#define BW_monoBuffer (uint8_t *)&image_581_720x256_BW_mono
#define BW_0x00Buffer (uint8_t *)&image_581_720x256_BW_0x00
#define BWR_blackBuffer (uint8_t *)&image_581_720x256_BWR_blackBuffer
#define BWR_redBuffer (uint8_t *)&image_581_720x256_BWR_redBuffer
#else
#include "image_data/7.40/image_740_800x480_BW.c"
#include "image_data/7.40/image_740_800x480_BWR.c"
#define frameSize	48000
#define BW_monoBuffer (uint8_t *)&image_740_800x480_BW_mono
#define BW_0x00Buffer (uint8_t *)&image_740_800x480_BW_0x00
#define BWR_blackBuffer (uint8_t *)&image_740_800x480_BWR_blackBuffer
#define BWR_redBuffer (uint8_t *)&image_740_800x480_BWR_redBuffer
#endif