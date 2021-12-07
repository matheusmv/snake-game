#include <stdio.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 400

void initialize(void);
void terminate(int exit_code);
void handle_input(void);

typedef struct __game {
        SDL_Renderer *renderer;
        SDL_Window *window;
        int running;
} Game;

Game game = {
        .running = 1
};

int main(void)
{
        initialize();

        while (game.running) {
                SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
                SDL_RenderClear(game.renderer);

                handle_input();

                SDL_RenderPresent(game.renderer);

                SDL_Delay(100);
        }

        terminate(EXIT_SUCCESS);
}

void initialize(void)
{
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                fprintf(stderr, "error: failed to initialize SDL: %s\n", SDL_GetError());
                terminate(EXIT_FAILURE);
        }

        game.window = SDL_CreateWindow(
                "Score: 0",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
        );

        if (!game.window) {
                fprintf(stderr, "error: failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
                terminate(EXIT_FAILURE);
        }

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED);

        if (!game.renderer) {
                fprintf(stderr, "error: failed to create renderer: %s\n", SDL_GetError());
                terminate(EXIT_FAILURE);
        }
}

void terminate(int exit_code)
{
        if (game.renderer) {
                SDL_DestroyRenderer(game.renderer);
        }

        if (game.window) {
                SDL_DestroyWindow(game.window);
        }

        SDL_Quit();

        exit(exit_code);
}

void handle_input(void)
{
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                        terminate(EXIT_SUCCESS);
                        break;
                case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                                terminate(EXIT_SUCCESS);
                        break;
                default:
                        break;
                }
        }
}
