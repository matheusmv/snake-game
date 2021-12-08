#include "game.h"
#include "input.h"
#include "wall.h"
#include "snake.h"

Game game = {
        .running = true,
        .dx = CELL_WIDTH,
        .dy = 0
};

int main(void)
{
        initialize(&game);

        spawn_snake(&game);

        while (game.running) {
                ColorRGBA black = get_color(BLACK);

                SDL_SetRenderDrawColor(game.renderer, black.R, black.G, black.B, black.A);
                SDL_RenderClear(game.renderer);

                handle_input(&game);

                draw_wall(&game);
                draw_snake(&game);
                move_snake(&game);

                SDL_RenderPresent(game.renderer);

                SDL_Delay(100);
        }

        terminate(&game, EXIT_SUCCESS);
}
