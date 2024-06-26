#ifndef __UTILS_H
#define __UTILS_H		


#include "main.h"
typedef int8_t s8;

void cv_resize_u8(u8* in_array, int height, int width, u8* out_array, int out_height, int out_width);
void cv_resize_s8(s8* in_array, int height, int width, s8* out_array, int out_height, int out_width);

#endif