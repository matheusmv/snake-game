#include "color.h"

static ColorRGBA color_table[] = {
        [GRAY]  = {.code = GRAY, .R = 210, .G = 209, .B = 205, .A = 255},
        [GREEN] = {.code = GREEN, .R = 0, .G = 128, .B = 0, .A = 255},
        [BLACK] = {.code = BLACK, .R = 0, .G = 0, .B = 0, .A = 255},
        [RED]   = {.code = RED, .R = 255, .G = 0, .B = 0, .A = 255},
};

ColorRGBA
get_color(Color color)
{
        return color_table[color];
}
