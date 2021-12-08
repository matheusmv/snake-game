#include "game.h"
#include "input.h"
#include "wall.h"
#include "snake.h"
#include "food.h"

Game game = {
        .running = true,
        .dx = CELL_WIDTH,
        .dy = 0,
        .food = {.w = CELL_WIDTH, .h = CELL_HEIGHT}
};

int main(void)
{
        initialize(&game);

        spawn_snake(&game);
        spawn_food(&game);

        while (game.running) {
                ColorRGBA black = get_color(BLACK);

                SDL_SetRenderDrawColor(game.renderer, black.R, black.G, black.B, black.A);
                SDL_RenderClear(game.renderer);

                handle_input(&game);

                move_snake(&game);

                draw_food(&game);
                draw_snake(&game);
                draw_wall(&game);

                SDL_RenderPresent(game.renderer);

                SDL_Delay(100);
        }

        terminate(&game, EXIT_SUCCESS);
}
