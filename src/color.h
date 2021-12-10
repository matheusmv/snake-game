#ifndef _COLOR_H
#define _COLOR_H

#include "common_libs.h"

typedef enum color { GRAY, GREEN, BLACK, RED } Color;

typedef struct colorRGBA {
        Color code;
        uint8_t R, G, B, A;
} ColorRGBA;

ColorRGBA get_color(Color color);

#endif
