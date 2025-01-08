/*
	Fast_Data.h
  User set of Image Data
*/

// 5.81"

#include "fp_data/images581.h"

#if(SCRN == 581)
#define FastPic_1 (uint8_t *) & image_581_720x256_BW_mono
#define FastPic_2 (uint8_t *) & image_581_720x256_BW_product
#define FastPic_b (uint8_t *) & img_black
#define FastPic_w (uint8_t *) & img_white
#else
#define FastPic_1 (uint8_t *)&image_740_800x480_BW_mono
#define FastPic_2 (uint8_t *)&image_740_800x480_BWR_blackBuffer
#define FastPic_w (uint8_t *)&image_740_800x480_BW_0x00
#define FastPic_b (uint8_t *) &image_740_800x480_BW_0xff
#endif