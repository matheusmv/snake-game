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
        ColorRGBA red = get_color(RED);
        ColorRGBA black = get_color(BLACK);

        if (game->game_over) {
                SDL_SetRenderDrawColor(game->renderer, red.R, red.G, red.B, red.A);
        } else {
                SDL_SetRenderDrawColor(game->renderer, green.R, green.G, green.B, green.A);
        }

        SDL_RenderFillRect(game->renderer, &game->snake[0]);

        for (int i = 1; i < sizeof(game->snake) / sizeof(game->snake[0]); i++) {
                if (game->snake[i].w == 0)
                        break;

                if (game->game_over) {
                        /* draw red cell */
                        SDL_SetRenderDrawColor(game->renderer, red.R, red.G, red.B, red.A);
                } else {
                        /* draw green cell */
                        SDL_SetRenderDrawColor(game->renderer, green.R, green.G, green.B, green.A);
                }

                SDL_RenderFillRect(game->renderer, &game->snake[i]);

                /* create a black border around each snake body cell */
                SDL_SetRenderDrawColor(game->renderer, black.R, black.G, black.B, black.A);
                SDL_RenderDrawRect(game->renderer, &game->snake[i]);
        }
}

void move_snake(Game *game)
{
        if (game->game_over)
                return;

        for (int i = sizeof(game->snake) / sizeof(game->snake[0]) - 1; i >= 0; i--)
                game->snake[i] = game->snake[i - 1];

        game->snake[0].x = game->snake[1].x + game->dx;
        game->snake[0].y = game->snake[1].y + game->dy;
        game->snake[0].w = CELL_WIDTH;
        game->snake[0].h = CELL_HEIGHT;

        if (game->food.x == game->snake[0].x && game->food.y == game->snake[0].y) {
                spawn_food(game);
                game->score++;
                display_score(game);
        } else {
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

        handle_collisions(game);
}

void handle_collisions(Game *game)
{
        for (int i = 1; i < sizeof(game->snake) / sizeof(game->snake[0]); i++) {
                /* exit loop when at the end of the active elements of the snake body */
                if (game->snake[i].w == 0)
                        break;

                /* check the head has not run into active body elements */
                if (game->snake[0].x == game->snake[i].x && game->snake[0].y == game->snake[i].y) {
                        game->game_over = true;
                        return;
                }
        }

        /* hit left wall? */
        if (game->snake[0].x < WALL_THICKNESS) {
                game->game_over = true;
                return;
        }

        /* hit right wall? */
        if (game->snake[0].x > SCREEN_WIDTH - WALL_THICKNESS - CELL_WIDTH) {
                game->game_over = true;
                return;
        }

        /* hit top wall? */
        if (game->snake[0].y < WALL_THICKNESS) {
                game->game_over = true;
                return;
        }

        /* hit bottoom wall? */
        if (game->snake[0].y > SCREEN_HEIGHT - WALL_THICKNESS - CELL_HEIGHT) {
                game->game_over = true;
                return;
        }
}
