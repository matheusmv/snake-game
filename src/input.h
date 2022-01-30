#ifndef _INPUT_H
#define _INPUT_H

#include "common_libs.h"
#include "common_structs.h"
#include "common_vars.h"

void handle_input(Game *game);
void change_direction(Game *game, SDL_Keycode new_direction);

#endif
