#include "input.h"

void handle_input(Game *game)
{
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                        terminate(game, EXIT_SUCCESS);
                        break;
                case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                                terminate(game, EXIT_SUCCESS);
                        break;
                default:
                        break;
                }
        }
}
