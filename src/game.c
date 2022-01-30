#include "color.h"
#include "food.h"
#include "game.h"
#include "input.h"
#include "screen.h"
#include "snake.h"
#include "wall.h"

static void
init_game_loop(Game *game)
{
        ColorRGBA black = get_color(BLACK);

        while (game->status == PLAYING) {
                SDL_SetRenderDrawColor(game->screen.renderer, black.R, black.G, black.B, black.A);
                SDL_RenderClear(game->screen.renderer);

                handle_input(game);

                move_snake(game);

                draw_food(game);

                draw_snake(game);

                draw_wall(game);

                SDL_RenderPresent(game->screen.renderer);
                SDL_Delay(100);
        }
}

void
start_game(Game *game)
{
        *game = (Game) {
                .status = PLAYING,
                .snake = {.dx = CELL_WIDTH, .dy = 0},
                .food = {.cell.w = CELL_WIDTH, .cell.h = CELL_HEIGHT}
        };

        // init screen
        start_rendering(&game->screen);

        // init snake
        spawn_snake(game);

        // init food
        spawn_food(game);

        // start rendering
        init_game_loop(game);

        // clear buffers
        finish_rendering(&game->screen, EXIT_SUCCESS);
}
