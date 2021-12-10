#include "screen.h"

void start_rendering(Screen *screen)
{
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                char *err_msg = "error: failed to initialize SDL: %s\n";
                fprintf(stderr, err_msg, SDL_GetError());
                finish_rendering(screen, EXIT_FAILURE);
        }

        screen->window = SDL_CreateWindow(
                "Score: 0",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
        );

        if (!screen->window) {
                char *err_msg = "error: failed to open %d x %d window: %s\n";
                fprintf(stderr, err_msg, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
                finish_rendering(screen, EXIT_FAILURE);
        }

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        screen->renderer = SDL_CreateRenderer(screen->window, -1, SDL_RENDERER_ACCELERATED);

        if (!screen->renderer) {
                char *err_msg = "error: failed to create renderer: %s\n";
                fprintf(stderr, err_msg, SDL_GetError());
                finish_rendering(screen, EXIT_FAILURE);
        }
}

void finish_rendering(Screen *screen, int exit_code)
{
        if (screen->renderer)
                SDL_DestroyRenderer(screen->renderer);

        if (screen->window)
                SDL_DestroyWindow(screen->window);

        SDL_Quit();

        exit(exit_code);
}

void display_score(Game *game)
{
        char buffer[20];
        snprintf(buffer, 20, "Score: %ld", game->score);
        SDL_SetWindowTitle(game->screen.window, buffer);
}
