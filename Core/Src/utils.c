#include "utils.h"
#include <string.h>

int is_in_array(int x, int y, int height, int width) {    
    return (x >= 0 && x < width && y >= 0 && y < height);    
}

void cv_resize_u8(u8* in_array, int height, int width, u8* out_array, int out_height, int out_width) {    
    double h_ratio = (double)(height - 1) / (out_height - 1);
    double w_ratio = (double)(width - 1) / (out_width - 1);

    for (int i = 0; i < out_height; i++) {        
        for (int j = 0; j < out_width; j++) {
            double x = j * w_ratio;
            double y = i * h_ratio;
            int x1 = (int)x;
            int y1 = (int)y;
            int x2 = x1 + 1;
            int y2 = y1 + 1;

            if (x2 >= width) x2 = width - 1;
            if (y2 >= height) y2 = height - 1;

            double x_diff = x - x1;
            double y_diff = y - y1;

            for (int c = 0; c < 3; c++) {
                if (is_in_array(x1, y1, height, width) && is_in_array(x2, y2, height, width)) {
                    u8 f11 = in_array[(y1 * width + x1) * 3 + c];
                    u8 f21 = in_array[(y1 * width + x2) * 3 + c];
                    u8 f12 = in_array[(y2 * width + x1) * 3 + c];
                    u8 f22 = in_array[(y2 * width + x2) * 3 + c];

                    out_array[(i * out_width + j) * 3 + c] = (u8)(
                        f11 * (1 - x_diff) * (1 - y_diff) +
                        f21 * x_diff * (1 - y_diff) +
                        f12 * (1 - x_diff) * y_diff +
                        f22 * x_diff * y_diff
                    );
                }
            }
        }
    }
}



void cv_resize_s8_CHW(s8* in_array, int height, int width, s8* out_array, int out_height, int out_width) {    
    double h_ratio = (double)(height - 1) / (out_height - 1);
    double w_ratio = (double)(width - 1) / (out_width - 1);

    for (int i = 0; i < out_height; i++) {        
        for (int j = 0; j < out_width; j++) {
            double x = j * w_ratio;
            double y = i * h_ratio;
            int x1 = (int)x;
            int y1 = (int)y;
            int x2 = x1 + 1;
            int y2 = y1 + 1;

            if (x2 >= width) x2 = width - 1;
            if (y2 >= height) y2 = height - 1;

            double x_diff = x - x1;
            double y_diff = y - y1;
            for (int c = 0; c < 3; c++) {
                s8 f11 = in_array[(y1 * width + x1) * 3 + c];
                s8 f21 = in_array[(y1 * width + x2) * 3 + c];
                s8 f12 = in_array[(y2 * width + x1) * 3 + c];
                s8 f22 = in_array[(y2 * width + x2) * 3 + c];

                out_array[(c * out_height + i) * out_width + j] = (s8)(
                    f11 * (1 - x_diff) * (1 - y_diff) +
                    f21 * x_diff * (1 - y_diff) +
                    f12 * (1 - x_diff) * y_diff +
                    f22 * x_diff * y_diff
                );
            }
        }
    }
}

void cv_resize_s8(s8* in_array, int height, int width, s8* out_array, int out_height, int out_width) {    
    double h_ratio = (double)(height - 1) / (out_height - 1);
    double w_ratio = (double)(width - 1) / (out_width - 1);

    for (int i = 0; i < out_height; i++) {        
        for (int j = 0; j < out_width; j++) {
            double x = j * w_ratio;
            double y = i * h_ratio;
            int x1 = (int)x;
            int y1 = (int)y;
            int x2 = x1 + 1;
            int y2 = y1 + 1;

            if (x2 >= width) x2 = width - 1;
            if (y2 >= height) y2 = height - 1;

            double x_diff = x - x1;
            double y_diff = y - y1;

            for (int c = 0; c < 3; c++) {
                if (is_in_array(x1, y1, height, width) && is_in_array(x2, y2, height, width)) {
                    s8 f11 = in_array[(y1 * width + x1) * 3 + c];
                    s8 f21 = in_array[(y1 * width + x2) * 3 + c];
                    s8 f12 = in_array[(y2 * width + x1) * 3 + c];
                    s8 f22 = in_array[(y2 * width + x2) * 3 + c];

                    out_array[(i * out_width + j) * 3 + c] = (s8)(
                        f11 * (1 - x_diff) * (1 - y_diff) +
                        f21 * x_diff * (1 - y_diff) +
                        f12 * (1 - x_diff) * y_diff +
                        f22 * x_diff * y_diff
                    );
                }
            }
        }
    }
}

#include "math.h"

//-------以下是HSV颜色空间和RGB颜色空间相互转换接口------------
/**
 * @brief HSV颜色空间
*/
typedef struct {
    float h;    // 色调H(hue)  0~360° {R(0°),G(120°),B(240°)}
    float s;    // 饱和度S(saturation)  0~1.0
    float v;    // 明度V(value)  0~1.0  
}color_hsv_t;

typedef struct {
    unsigned char r;    // 0-255
    unsigned char g;    // 0-255
    unsigned char b;    // 0-255
    unsigned int color; // 0x000000 ~ 0xffffff
}color_rgb_t;


/**
 * @brief   RGB颜色空间 转  HSV颜色空间 
 * @param   rgb:RGB颜色空间参数
 * @param   hsv:HSV颜色空间参数
 * @return  none
*/
void rgb2hsv(color_rgb_t *rgb, color_hsv_t *hsv);

/**
 * @brief   HSV颜色空间 转 RGB颜色空间
 * @param   hsv:HSV颜色空间参数
 * @param   rgb:RGB颜色空间参数
 * @return  none
*/
void hsv2rgb(color_hsv_t *hsv, color_rgb_t *rgb);

/**
 * @brief   调节HSV颜色空间 H值(0.0~360.0)
 * @param   hsv:HSV颜色空间参数
 * @param   h_offset:调节参数 增加>0.0，减小<0.0
 * @return  none
*/
void hsv_adjust_h(color_hsv_t *hsv, float h_offset);

/**
 * @brief   调节HSV颜色空间 S值(0.0~1.0)
 * @param   hsv:HSV颜色空间参数
 * @param   s_offset:调节参数 增加>0.0，减小<0.0
 * @return  none
*/
void hsv_adjust_s(color_hsv_t *hsv, float s_offset);

/**
 * @brief   调节HSV颜色空间 V值(0.0~1.0)
 * @param   hsv:HSV颜色空间参数
 * @param   v_offset:调节参数 增加>0.0，减小<0.0
 * @return  none
*/
void hsv_adjust_v(color_hsv_t *hsv, float v_offset);



// 以下是HSV颜色空间和RGB颜色空间相互转换接口
/*********************************************************************************************
红：    
    R   255         H:0
    G   0           S:100
    B   0           V:100    
绿：
    R   0           H:120   
    G   255         S:100
    B   0           V:100    
蓝：
    R   0           H:240   
    G   0           S:100
    B   255         V:100    
*********************************************************************************************/

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max3(a,b,c) (((a) > (b) ? (a) : (b)) > (c) ? ((a) > (b) ? (a) : (b)) : (c))
#define min3(a,b,c) (((a) < (b) ? (a) : (b)) < (c) ? ((a) < (b) ? (a) : (b)) : (c))


/*********************************************************************************************
RGB转化到HSV的算法:
    max=max(R,G,B)；
    min=min(R,G,B)；
    V=max(R,G,B)；
    S=(max-min)/max；
    if (R = max) H =(G-B)/(max-min)* 60；
    if (G = max) H = 120+(B-R)/(max-min)* 60；
    if (B = max) H = 240 +(R-G)/(max-min)* 60；
    if (H < 0) H = H + 360；
***********************************************************************************************/

/**
 * @brief   RGB颜色空间 转  HSV颜色空间 
 * @param   rgb:RGB颜色空间参数
 * @param   hsv:HSV颜色空间参数
 * @note    The R,G,B values are divided by 255 to change the range from 0..255 to 0..1:
 * @return  none
*/
void rgb2hsv(color_rgb_t *rgb, color_hsv_t *hsv)
{
    float max, min, delta=0;
    float r = (float)((float)((int)rgb->r)/255);
    float g = (float)((float)((int)rgb->g)/255);
    float b = (float)((float)((int)rgb->b)/255);

    max = max3(r, g, b);
    min = min3(r, g, b);
    delta = (max - min);

    //printf("r:%f, g:%f, b:%f\n", r, g, b);

    if (delta == 0) {
        hsv->h = 0;
    } else {
        if (r == max) {
            hsv->h = ((g-b)/delta)*60; 
        } else if (g == max) {
            hsv->h = 120+(((b-r)/delta)*60); 
        } else if (b == max) {
            hsv->h = 240 + (((r-g)/delta)*60);
        }

        if (hsv->h < 0) {
            hsv->h += 360;
        }
    }

    if (max == 0) {
        hsv->s = 0;
    } else {
        hsv->s = (float)(delta/max);
    }

    hsv->v = max;

    rgb->color = (unsigned int)(((rgb->r&0xff)<<16) | ((rgb->g&0xff)<<8) | (rgb->b&0xff));
}


/*************************************************************************
HSV转化到RGB的算法:
    if (s = 0)
    R=G=B=V;
    else
    H /= 60;
    i = INTEGER(H);
    f = H - i;
    a = V * ( 1 - s );
    b = V * ( 1 - s * f );
    c = V * ( 1 - s * (1 - f ) );
    switch(i)
    case 0: R = V; G = c; B = a;
    case 1: R = b; G = v; B = a;
    case 2: R = a; G = v; B = c;
    case 3: R = a; G = b; B = v;
    case 4: R = c; G = a; B = v;
    case 5: R = v; G = a; B = b;
*******************************************************************************/

/**
 * @brief   HSV颜色空间 转 RGB颜色空间
 * @param   hsv:HSV颜色空间参数
 * @param   rgb:RGB颜色空间参数
 * @note    When 0 ≤ H < 360, 0 ≤ S ≤ 1 and 0 ≤ V ≤ 1:
 * @return  none
*/
void hsv2rgb(color_hsv_t *hsv, color_rgb_t *rgb)
{
    int i;
    float f,a,b,c;

    float h = hsv->h;
    float s = hsv->s;
    float v = hsv->v;
	if (h >= 360) {
		h = 0;
	}
	
    if (s == 0) {
        rgb->r = (unsigned char)((int)(v*255));
        rgb->g = (unsigned char)((int)(v*255));
        rgb->b = (unsigned char)((int)(v*255));
    } else {
        h /= 60.0;  // sector 0 to 5, h_max=360 360/60=6[0,1,2,3,4,5]
        i = (int)floor(h); // floor(h)
        f = h-i; // factorial path of h
        a = v * (1-s);
        b = v * (1-s*f);
        c = v * (1-s*(1-f));
        switch(i) {
            case 0:
                rgb->r = (unsigned char)((int)(v*255)); //v*255
                rgb->g = (unsigned char)((int)(c*255)); //c*255;
                rgb->b = (unsigned char)((int)(a*255)); //a*255;
                break;
            case 1:
                rgb->r = (unsigned char)((int)(b*255)); //b*255;
                rgb->g = (unsigned char)((int)(v*255)); //v*255;
                rgb->b = (unsigned char)((int)(a*255)); //a*255;
                break;
            case 2:
                rgb->r = (unsigned char)((int)(a*255)); //a*255;
                rgb->g = (unsigned char)((int)(v*255)); //v*255;
                rgb->b = (unsigned char)((int)(c*255)); //c*255;
                break;
            case 3:
                rgb->r = (unsigned char)((int)(a*255));//a*255;
                rgb->g = (unsigned char)((int)(b*255));//b*255;
                rgb->b = (unsigned char)((int)(v*255));//v*255;
                break;
            case 4:
                rgb->r = (unsigned char)((int)(c*255)); //c*255;
                rgb->g = (unsigned char)((int)(a*255)); //a*255;
                rgb->b = (unsigned char)((int)(v*255)); //v*255;
                break;
            default:
                rgb->r = (unsigned char)((int)(v*255)); //v*255;
                rgb->g = (unsigned char)((int)(a*255)); //a*255;
                rgb->b = (unsigned char)((int)(b*255)); //b*255;
                break;
        }

    }

    rgb->color = (unsigned int)(((rgb->r&0xff)<<16) | ((rgb->g&0xff)<<8) | (rgb->b&0xff));
}

/**
 * @brief   调节HSV颜色空间 H值(0.0~360.0)
 * @param   hsv:HSV颜色空间参数
 * @param   h_offset:调节参数 增加>0.0，减小<0.0
 * @return  none
*/
void hsv_adjust_h(color_hsv_t *hsv, float h_offset)
{
    hsv->h += h_offset;
    if (hsv->h >= 360) {
        hsv->h = 360;
    } else if (hsv->h<=0) {
        hsv->h = 0;
    }
}


/**
 * @brief   调节HSV颜色空间 S值(0.0~1.0)
 * @param   hsv:HSV颜色空间参数
 * @param   s_offset:调节参数 增加>0.0，减小<0.0
 * @return  none
*/
void hsv_adjust_s(color_hsv_t *hsv, float s_offset)
{
    hsv->s += s_offset;
    if (hsv->s >= 1.0) {
        hsv->s = 1.0;
    } else if (hsv->s <= 0) {
        hsv->s = 0;
    }
}


/**
 * @brief   调节HSV颜色空间 V值(0.0~1.0)
 * @param   hsv:HSV颜色空间参数
 * @param   v_offset:调节参数 增加>0.0，减小<0.0
 * @return  none
*/
void hsv_adjust_v(color_hsv_t *hsv, float v_offset)
{
    hsv->v += v_offset;
    if (hsv->v >= 1.0) {
        hsv->v = 1.0;
    } else if (hsv->v<=0) {
        hsv->v = 0;
    }
}

void rgb2hsv_u8(uint8_t* img, int h, int w,float* img_out){
    color_hsv_t hsv;
    color_rgb_t rgb;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            rgb.r = img[i*w*3 + j*3];
            rgb.g = img[i*w*3 + j*3 + 1];
            rgb.b = img[i*w*3 + j*3 + 2];
            rgb2hsv(&rgb, &hsv);
            img_out[i*w*3 + j*3] = hsv.h;
            img_out[i*w*3 + j*3 + 1] = hsv.s;
            img_out[i*w*3 + j*3 + 2] = hsv.v;
        }
    }
}

void hsv2rgb_u8(float* img, int h, int w,uint8_t* img_out){
    color_hsv_t hsv;
    color_rgb_t rgb;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            hsv.h = img[i*w*3 + j*3];
            hsv.s = img[i*w*3 + j*3 + 1];
            hsv.v = img[i*w*3 + j*3 + 2];
            hsv2rgb(&hsv, &rgb);
            img_out[i*w*3 + j*3] = rgb.r;
            img_out[i*w*3 + j*3 + 1] = rgb.g;
            img_out[i*w*3 + j*3 + 2] = rgb.b;
        }
    }
}

// 计算直方图
void calculateHistogram(int *hist, unsigned char *image, int width, int height) {
    for(int i = 0; i < 256; i++) {
        hist[i] = 0;
    }
    for(int i = 0; i < width * height; i++) {
        hist[image[i]]++;
    }
}

// 计算累计分布函数
void calculateCDF(int *hist, float *cdf, int totalPixels) {
    cdf[0] = (float)hist[0] / totalPixels;
    for(int i = 1; i < 256; i++) {
        cdf[i] = cdf[i - 1] + (float)hist[i] / totalPixels;
    }
}

// 应用直方图均衡化
void histogramEqualization(unsigned char *image, float *cdf, int width, int height) {
    for(int i = 0; i < width * height; i++) {
        image[i] = (unsigned char)(255 * cdf[image[i]]);
    }
}

int hist[256] = {0};
float cdf[256] = {0};
void cv_enhanceImageUsingHSV(uint8_t *img, int height, int width,float *hsv_img, uint8_t* img_out) {
    int i;
    
    rgb2hsv_u8(img, height, width, hsv_img);

    // 步骤2: 计算直方图
    
    for (i = 0; i < height * width; i++) {
        unsigned char v_value = (unsigned char)(hsv_img[i*3 + 2] * 255); // 提取V值并量化至0-255
        hist[v_value]++;
    }

    // // 步骤3: 计算累计分布函数
    
    calculateCDF(hist, cdf, height * width);

    // 步骤4: 应用直方图均衡
    for (i = 0; i < height * width; i++) {
        unsigned char v_value = (unsigned char)(hsv_img[i*3 + 2] * 255);
        unsigned char equalized_v = (unsigned char)(255 * cdf[v_value]);
        hsv_img[i*3 + 2] = (float)equalized_v / 255.0; // 更新V值，转换回0.0-1.0范围
    }

    hsv2rgb_u8(hsv_img, height, width, img_out);
}


// int8到uint8的转换
// void cv_S82U8(int8_t* src, uint8_t* dest, int height, int width) {
//     int num_pixels = width * height * 3; // 三通道图像
//     for (int i = 0; i < num_pixels; i++) {
//         dest[i] = (uint8_t)(src[i] + 128);
//     }
// }

// uint8到int8的转换
void cv_U82S8(uint8_t* src, int8_t* dest, int height, int width) {
    int num_pixels = width * height * 3; // 三通道图像
    for (int i = 0; i < num_pixels; i++) {
        dest[i] = (int8_t)(src[i] - 128);
    }
}
