#ifndef _SNAKE_H
#define _SNAKE_H

#include "game.h"
#include "color.h"

void spawn_snake(Game *game);
void draw_snake(Game *game);
void move_snake(Game *game);
void handle_collisions(Game *game);

#endif
