#ifndef _GAME_H
#define _GAME_H

#include "libs.h"

typedef struct {
        SDL_Renderer *renderer;
        SDL_Window *window;
        int running;
} Game;

void initialize(Game *game, const int screen_width, const int screen_height);
void terminate(Game *game, int exit_code);

#endif
