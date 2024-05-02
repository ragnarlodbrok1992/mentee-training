#include "CCircle.h"

CCircle::CCircle(SDL_Renderer *&renderer, Circle obj, Color col)
{
    SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, SDL_ALPHA_OPAQUE);
    DrawFilledCircle(renderer, obj.centerX, obj.centerY, obj.radius);
}

void CCircle::DrawCircleLines(SDL_Renderer *&renderer, int centerX, int centerY, int x, int y)
{
    SDL_RenderDrawLine(renderer, centerX + x, centerY + y, centerX - x, centerY + y);
    SDL_RenderDrawLine(renderer, centerX + x, centerY - y, centerX - x, centerY - y);
    SDL_RenderDrawLine(renderer, centerX + y, centerY + x, centerX - y, centerY + x);
    SDL_RenderDrawLine(renderer, centerX + y, centerY - x, centerX - y, centerY - x);
}

void CCircle::DrawFilledCircle(SDL_Renderer *&renderer, int centerX, int centerY, int radius)
{
    int x = 0, y = radius;
    int d = 3 - 2 * radius;
    DrawCircleLines(renderer, centerX, centerY, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        DrawCircleLines(renderer, centerX, centerY, x, y);
    }
}
