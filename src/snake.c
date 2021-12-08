#include "snake.h"

void spawn_snake(Game *game)
{
        /* make all snake parts empty */
        for (int i = 0; i < sizeof(game->snake) / sizeof(game->snake[0]); i++) {
                game->snake[i].x = 0;
                game->snake[i].y = 0;
                game->snake[i].w = 0;
                game->snake[i].h = 0;
        }

        /* the first element in the snake array is the head */
        game->snake[0].x = SNAKE_START_X;
        game->snake[0].y = SNAKE_START_Y;
        game->snake[0].w = CELL_WIDTH;
        game->snake[0].h = CELL_HEIGHT;

        /* create 4 more snake elements for the body */
        for (int i = 1; i < 5; i++) {
                game->snake[i] = game->snake[0];
                game->snake[i].x = game->snake[0].x - (CELL_WIDTH * i);
        }
}

void draw_snake(Game *game)
{
        ColorRGBA green = get_color(GREEN);
        ColorRGBA black = get_color(BLACK);

        SDL_SetRenderDrawColor(game->renderer, green.R, green.G, green.B, green.A);
        SDL_RenderFillRect(game->renderer, &game->snake[0]);

        for (int i = 1; i < sizeof(game->snake) / sizeof(game->snake[0]); i++) {
                if (game->snake[i].w == 0)
                        break;

                /* draw green cell */
                SDL_SetRenderDrawColor(game->renderer, green.R, green.G, green.B, green.A);
                SDL_RenderFillRect(game->renderer, &game->snake[i]);

                /* create a black border around each snake body cell */
                SDL_SetRenderDrawColor(game->renderer, black.R, black.G, black.B, black.A);
                SDL_RenderDrawRect(game->renderer, &game->snake[i]);
        }
}

void move_snake(Game *game)
{
        for (int i = sizeof(game->snake) / sizeof(game->snake[0]) - 1; i >= 0; i--)
                game->snake[i] = game->snake[i - 1];

        game->snake[0].x = game->snake[1].x + game->dx;
        game->snake[0].y = game->snake[1].y + game->dy;
        game->snake[0].w = CELL_WIDTH;
        game->snake[0].h = CELL_HEIGHT;

        for (int i = 5; i < sizeof(game->snake) / sizeof(game->snake[0]); i++) {
                if (game->snake[i].w == 0) {
                        game->snake[i - 1].x = 0;
                        game->snake[i - 1].y = 0;
                        game->snake[i - 1].w = 0;
                        game->snake[i - 1].h = 0;
                        break;
                }
        }
}
