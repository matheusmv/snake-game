#include "collision.h"
#include "color.h"
#include "food.h"
#include "snake.h"
#include "screen.h"

void
spawn_snake(Game *game)
{
        /* make all snake parts empty */
        for (size_t i = 0; i < sizeof(game->snake.body) / sizeof(game->snake.body[0]); i++) {
                game->snake.body[i].x = 0;
                game->snake.body[i].y = 0;
                game->snake.body[i].w = 0;
                game->snake.body[i].h = 0;
        }

        /* the first element in the snake array is the head */
        game->snake.body[0].x = SNAKE_START_X;
        game->snake.body[0].y = SNAKE_START_Y;
        game->snake.body[0].w = CELL_WIDTH;
        game->snake.body[0].h = CELL_HEIGHT;

        /* create 4 more snake elements for the body */
        for (int i = 1; i < 5; i++) {
                game->snake.body[i] = game->snake.body[0];
                game->snake.body[i].x = game->snake.body[0].x - (CELL_WIDTH * i);
        }
}

void
draw_snake(Game *game)
{
        ColorRGBA green = get_color(GREEN);
        ColorRGBA red = get_color(RED);
        ColorRGBA black = get_color(BLACK);

        if (game->status == GAME_OVER) {
                SDL_SetRenderDrawColor(game->screen.renderer, red.R, red.G, red.B, red.A);
        } else {
                SDL_SetRenderDrawColor(game->screen.renderer, green.R, green.G, green.B, green.A);
        }

        SDL_RenderFillRect(game->screen.renderer, &game->snake.body[0]);

        for (size_t i = 1; i < sizeof(game->snake.body) / sizeof(game->snake.body[0]); i++) {
                if (game->snake.body[i].w == 0)
                        break;

                if (game->status == GAME_OVER) {
                        /* draw red cell */
                        SDL_SetRenderDrawColor(game->screen.renderer, red.R, red.G, red.B, red.A);
                } else {
                        /* draw green cell */
                        SDL_SetRenderDrawColor(game->screen.renderer, green.R, green.G, green.B, green.A);
                }

                SDL_RenderFillRect(game->screen.renderer, &game->snake.body[i]);

                /* create a black border around each snake body cell */
                SDL_SetRenderDrawColor(game->screen.renderer, black.R, black.G, black.B, black.A);
                SDL_RenderDrawRect(game->screen.renderer, &game->snake.body[i]);
        }
}

void
move_snake(Game *game)
{
        if (game->status == GAME_OVER)
                return;

        for (size_t i = sizeof(game->snake.body) / sizeof(game->snake.body[0]) - 1; i > 0; i--)
                game->snake.body[i] = game->snake.body[i - 1];

        game->snake.body[0].x = game->snake.body[1].x + game->snake.dx;
        game->snake.body[0].y = game->snake.body[1].y + game->snake.dy;
        game->snake.body[0].w = CELL_WIDTH;
        game->snake.body[0].h = CELL_HEIGHT;

        if (game->food.cell.x == game->snake.body[0].x
            && game->food.cell.y == game->snake.body[0].y) {
                spawn_food(game);
                game->score++;
                display_score(game);
        } else {
                for (size_t i = 5; i < sizeof(game->snake.body) / sizeof(game->snake.body[0]); i++) {
                        if (game->snake.body[i].w == 0) {
                                game->snake.body[i - 1].x = 0;
                                game->snake.body[i - 1].y = 0;
                                game->snake.body[i - 1].w = 0;
                                game->snake.body[i - 1].h = 0;
                                break;
                        }
                }
        }

        handle_collision(game);
}
