#ifndef _COMMON_STRUCTS_H
#define _COMMON_STRUCTS_H

#include "common_libs.h"
#include "common_vars.h"

typedef enum game_status {
        NOT_PLAYING,
        PLAYING,
        PAUSED,
        GAME_OVER
} Status;


typedef struct screen {
        SDL_Renderer    *renderer;
        SDL_Window      *window;
} Screen;


typedef struct snake {
        SDL_Rect        body[CELL_COUNT];
        int             dx, dy;
} Snake;


typedef struct food {
        SDL_Rect        cell;
} Food;


typedef struct game { 
        Screen          screen;
        Status          status;
        Snake           snake;
        Food            food;
        uint64_t        score;
} Game;

#endif
