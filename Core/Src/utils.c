#include "utils.h"

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