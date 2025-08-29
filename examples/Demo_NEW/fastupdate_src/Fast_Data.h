/*
	Fast_Data.h
  User set of Image Data
*/


#if(SCRN == 340)
#include "fp_data/images340.h"
#define FastPic_1 (uint8_t *) & image_340_456X392_BW_mono
#define FastPic_2 (uint8_t *) & image_340_456X392_BW_product2
#define FastPic_b (uint8_t *) & img_black
#define FastPic_w (uint8_t *) & img_white
#elif(SCRN == 581)
#include "fp_data/images581.h"
#define FastPic_1 (uint8_t *) & image_581_720x256_BW_mono
#define FastPic_2 (uint8_t *) & image_581_720x256_BW_product
#define FastPic_b (uint8_t *) & img_black
#define FastPic_w (uint8_t *) & img_white
#else
#include "fp_data/image_740_800x480_BW.c"
#include "fp_data/image_740_800x480_BWR.c"
#define FastPic_1 (uint8_t *)&image_740_800x480_BW_mono
#define FastPic_2 (uint8_t *)&image_740_800x480_BWR_blackBuffer
#define FastPic_w (uint8_t *)&image_740_800x480_BW_0x00
#define FastPic_b (uint8_t *) &image_740_800x480_BW_0xff
#endif