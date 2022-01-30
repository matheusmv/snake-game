#include "collision.h"

void 
handle_collision(Game *game)
{
        for (size_t i = 1; i < sizeof(game->snake.body) / sizeof(game->snake.body[0]); i++) {
                /* exit loop when at the end of the active elements of the snake body */
                if (game->snake.body[i].w == 0)
                        break;

                /* check the head has not run into active body elements */
                if (game->snake.body[0].x == game->snake.body[i].x
                    && game->snake.body[0].y == game->snake.body[i].y) {
                        game->status = GAME_OVER;
                        return;
                }
        }

        /* hit left wall? */
        if (game->snake.body[0].x < WALL_THICKNESS) {
                game->status = GAME_OVER;
                return;
        }

        /* hit right wall? */
        if (game->snake.body[0].x > SCREEN_WIDTH - WALL_THICKNESS - CELL_WIDTH) {
                game->status = GAME_OVER;
                return;
        }

        /* hit top wall? */
        if (game->snake.body[0].y < WALL_THICKNESS) {
                game->status = GAME_OVER;
                return;
        }

        /* hit bottom wall? */
        if (game->snake.body[0].y > SCREEN_HEIGHT - WALL_THICKNESS - CELL_HEIGHT) {
                game->status = GAME_OVER;
                return;
        }
}
