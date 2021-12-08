#ifndef _GAME_H
#define _GAME_H

#include "libs.h"

/* window */

#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 400

/* game wall */

#define WALL_THICKNESS  20

/* snake dimensions */

#define CELL_WIDTH 20
#define CELL_HEIGHT 20

/* initial position */

#define SNAKE_START_X 200
#define SNAKE_START_Y 200

/* max snake size */

#define CELL_COUNT ((SCREEN_WIDTH - WALL_THICKNESS * 2) * \
                        (SCREEN_HEIGHT - WALL_THICKNESS * 2)) / \
                        (CELL_WIDTH * CELL_HEIGHT)

typedef struct {
        SDL_Renderer *renderer;
        SDL_Window *window;
        int running;
        SDL_Rect snake[CELL_COUNT];
        int dx;
        int dy;
} Game;

void initialize(Game *game);
void terminate(Game *game, int exit_code);

#endif
