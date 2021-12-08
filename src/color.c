#include "color.h"

struct map {
        Color key;
        ColorRGBA value;
};

static struct map color_table[] = {
        {GRAY, {.code = GRAY, .R = 210, .G = 209, .B = 205, .A = 255}},
};

ColorRGBA get_color(Color color)
{
        return color_table[color].value;
}
