#include "input.h"
#include "screen.h"

void
handle_input(Game *game)
{
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                        finish_rendering(&game->screen, EXIT_SUCCESS);
                        break;
                case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                                finish_rendering(&game->screen, EXIT_SUCCESS);

                        if (event.key.keysym.sym == SDLK_UP
                            || event.key.keysym.sym == SDLK_DOWN
                            || event.key.keysym.sym == SDLK_LEFT
                            || event.key.keysym.sym == SDLK_RIGHT)
                                change_direction(game, event.key.keysym.sym);
                        break;
                default:
                        break;
                }
        }
}

void
change_direction(Game *game, SDL_Keycode new_direction)
{
        bool going_up = game->snake.dy == -CELL_HEIGHT;
        bool going_down = game->snake.dy == CELL_HEIGHT;
        bool going_left = game->snake.dx == -CELL_WIDTH;
        bool going_right = game->snake.dx == CELL_WIDTH;

        /* change the direction to up when the snake is not going down */
        if (new_direction == SDLK_UP && !going_down) {
                game->snake.dx = 0;
                game->snake.dy = -CELL_HEIGHT;
        }

        /* change the direction to down when the snake is not going up */
        if (new_direction == SDLK_DOWN && !going_up) {
                game->snake.dx = 0;
                game->snake.dy = CELL_HEIGHT;
        }

        /* change the direction to left when the snake is not going right */
        if (new_direction == SDLK_LEFT && !going_right) {
                game->snake.dx = -CELL_WIDTH;
                game->snake.dy = 0;
        }

        /* change the direction to right when the snake is not going left */
        if (new_direction == SDLK_RIGHT && !going_left) {
                game->snake.dx = CELL_WIDTH;
                game->snake.dy = 0;
        }
}
