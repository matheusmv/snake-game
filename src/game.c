#include "game.h"

void initialize(Game *game)
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
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
        );

        if (!game->window) {
                char *err_msg = "error: failed to open %d x %d window: %s\n";
                fprintf(stderr, err_msg, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
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

void display_score(Game *game)
{
        char buffer[20];
        snprintf(buffer, 20, "Score: %d", game->score);
        SDL_SetWindowTitle(game->window, buffer);
}
