#include "game.h"
#include "input.h"
#include "wall.h"
#include "snake.h"

Game game = {
        .running = 1
};

int main(void)
{
        initialize(&game);

        spawn_snake(&game);

        while (game.running) {
                SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
                SDL_RenderClear(game.renderer);

                handle_input(&game);

                draw_wall(&game);
                draw_snake(&game);

                SDL_RenderPresent(game.renderer);

                SDL_Delay(100);
        }

        terminate(&game, EXIT_SUCCESS);
}
