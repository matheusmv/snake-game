#include "color.h"
#include "wall.h"

void
draw_wall(Game *game)
{
        ColorRGBA gray = get_color(GRAY);
        SDL_SetRenderDrawColor(game->screen.renderer, gray.R, gray.G, gray.B, gray.A);

        SDL_Rect block = {
                .x = 0,
                .y = 0,
                .w = WALL_THICKNESS,
                .h = SCREEN_HEIGHT
        };

        /* left wall */
        SDL_RenderFillRect(game->screen.renderer, &block);

        /* right wall */
        block.x = SCREEN_WIDTH - WALL_THICKNESS;
        SDL_RenderFillRect(game->screen.renderer, &block);

        /* top wall */
        block.x = 0;
        block.w = SCREEN_WIDTH;
        block.h = WALL_THICKNESS;
        SDL_RenderFillRect(game->screen.renderer, &block);

        /* bottom wall */
        block.y = SCREEN_HEIGHT - WALL_THICKNESS;
        SDL_RenderFillRect(game->screen.renderer, &block);
}
