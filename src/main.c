#include "game.h"
#include "input.h"
#include "wall.h"

/* window */

#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 400

/* game wall */

#define WALL_THICKNESS  20

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

                draw_wall(&game, SCREEN_WIDTH, SCREEN_HEIGHT, WALL_THICKNESS);

                SDL_RenderPresent(game.renderer);

                SDL_Delay(100);
        }

        terminate(&game, EXIT_SUCCESS);
}
