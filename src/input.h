#ifndef _INPUT_H
#define _INPUT_H

#include "game.h"

void handle_input(Game *game);
void change_direction(Game *game, SDL_KeyCode new_direction);

#endif
