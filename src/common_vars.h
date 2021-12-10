#ifndef _COMMON_VARS_H
#define _COMMON_VARS_H

/* window */

#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 400

/* wall */

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

#endif
