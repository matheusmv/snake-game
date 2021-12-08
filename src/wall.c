#include "wall.h"

void draw_wall(Game *game, const int screen_width, const int screen_height, const int wall_thickness)
{
        ColorRGBA gray = get_color(GRAY);
        SDL_SetRenderDrawColor(game->renderer, gray.R, gray.G, gray.B, gray.A);

        SDL_Rect block = {
                .x = 0,
                .y = 0,
                .w = wall_thickness,
                .h = screen_height
        };

        // left wall
        SDL_RenderFillRect(game->renderer, &block);

        // right wall
        block.x = screen_width - wall_thickness;
        SDL_RenderFillRect(game->renderer, &block);

        // top wall
        block.x = 0;
        block.w = screen_width;
        block.h = wall_thickness;
        SDL_RenderFillRect(game->renderer, &block);

        // bottom wall
        block.y = screen_height - wall_thickness;
        SDL_RenderFillRect(game->renderer, &block);
}
