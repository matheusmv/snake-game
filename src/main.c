#include "game.h"
#include "input.h"

#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 400

Game game = {
        .running = 1
};

int main(void)
{
        initialize(&game, SCREEN_WIDTH, SCREEN_HEIGHT);

        while (game.running) {
                SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
                SDL_RenderClear(game.renderer);

                handle_input(&game);

                SDL_RenderPresent(game.renderer);

                SDL_Delay(100);
        }

        terminate(&game, EXIT_SUCCESS);
}
