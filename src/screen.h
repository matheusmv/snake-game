#ifndef _SCREEN_H
#define _SCREEN_H

#include "common_libs.h"
#include "common_structs.h"
#include "common_vars.h"

void start_rendering(Screen *screen);
void finish_rendering(Screen *screen, int exit_code);
void display_score(Game *game);

#endif
