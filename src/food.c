#include "color.h"
#include "food.h"

void
spawn_food(Game *game)
{
        game->food.cell.x = (rand() % (((SCREEN_WIDTH - CELL_WIDTH - WALL_THICKNESS) / CELL_WIDTH) + 1) * CELL_WIDTH);
        game->food.cell.y = (rand() % (((SCREEN_HEIGHT - CELL_HEIGHT - WALL_THICKNESS) / CELL_HEIGHT) + 1) * CELL_HEIGHT);

        if (game->food.cell.x < WALL_THICKNESS)
                game->food.cell.x = WALL_THICKNESS;

        if (game->food.cell.y < WALL_THICKNESS)
                game->food.cell.y = WALL_THICKNESS;

        for (size_t i = 0; i < sizeof(game->snake.body) / sizeof(game->snake.body[0]); i++) {
                if (game->snake.body[i].w == 0)
                        break;

                if (game->snake.body[i].x == game->food.cell.x
                    && game->snake.body[i].y == game->food.cell.y) {
                        spawn_food(game);
                        break;
                }
        }
}

void
draw_food(Game *game)
{
        ColorRGBA red = get_color(RED);

        SDL_SetRenderDrawColor(game->screen.renderer, red.R, red.G, red.B, red.A);
        SDL_RenderFillRect(game->screen.renderer, &game->food.cell);
}
