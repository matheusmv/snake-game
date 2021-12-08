#include "game.h"

void initialize(Game *game, const int screen_width, const int screen_height)
{
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                char *err_msg = "error: failed to initialize SDL: %s\n";
                fprintf(stderr, err_msg, SDL_GetError());
                terminate(game, EXIT_FAILURE);
        }

        game->window = SDL_CreateWindow(
                "Score: 0",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                screen_width,
                screen_height,
                SDL_WINDOW_SHOWN
        );

        if (!game->window) {
                char *err_msg = "error: failed to open %d x %d window: %s\n";
                fprintf(stderr, err_msg, screen_width, screen_height, SDL_GetError());
                terminate(game, EXIT_FAILURE);
        }

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

        if (!game->renderer) {
                char *err_msg = "error: failed to create renderer: %s\n";
                fprintf(stderr, err_msg, SDL_GetError());
                terminate(game, EXIT_FAILURE);
        }
}

void terminate(Game *game, int exit_code)
{
        if (game->renderer) {
                SDL_DestroyRenderer(game->renderer);
        }

        if (game->window) {
                SDL_DestroyWindow(game->window);
        }

        SDL_Quit();

        exit(exit_code);
}
