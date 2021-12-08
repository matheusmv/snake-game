#ifndef _COLOR_H
#define _COLOR_H

typedef enum color { GRAY } Color;

typedef struct colorRGBA {
    Color code;
    int R;
    int G;
    int B;
    int A;
} ColorRGBA;

ColorRGBA get_color(Color color);

#endif