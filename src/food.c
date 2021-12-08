#include "food.h"

void spawn_food(Game *game)
{
        game->food.x = (rand() % (((SCREEN_WIDTH - CELL_WIDTH - WALL_THICKNESS) / CELL_WIDTH) + 1) * CELL_WIDTH);
        game->food.y = (rand() % (((SCREEN_HEIGHT - CELL_HEIGHT - WALL_THICKNESS) / CELL_HEIGHT) + 1) * CELL_HEIGHT);

        if (game->food.x < WALL_THICKNESS)
                game->food.x = WALL_THICKNESS;

        if (game->food.y < WALL_THICKNESS)
                game->food.y = WALL_THICKNESS;

        for (int i = 0; i < sizeof(game->snake) / sizeof(game->snake[0]); i++) {
                if (game->snake[i].w == 0)
                        break;

                if (game->snake[i].x == game->food.x && game->snake[i].y == game->food.y) {
                        spawn_food(game);
                        break;
                }
        }
}

void draw_food(Game *game)
{
        ColorRGBA red = get_color(RED);

        SDL_SetRenderDrawColor(game->renderer, red.R, red.G, red.B, red.A);
        SDL_RenderFillRect(game->renderer, &game->food);
}
