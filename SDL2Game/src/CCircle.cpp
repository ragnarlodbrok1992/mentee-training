#include "CCircle.h"

CCircle::CCircle(SDL_Renderer *&renderer, Circle obj, Color col)
{
    this->circle = obj;
    this->color = col;
}

void CCircle::Draw(SDL_Renderer *&renderer)
{
    SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, SDL_ALPHA_OPAQUE);
    DrawFilledCircle(renderer, this->circle.radius);
}

void CCircle::DrawCircleLines(SDL_Renderer *&renderer, int x, int y)
{
    SDL_RenderDrawLine(renderer, this->circle.centerX + x, this->circle.centerY + y, this->circle.centerX - x, this->circle.centerY + y);
    SDL_RenderDrawLine(renderer, this->circle.centerX + x, this->circle.centerY - y, this->circle.centerX - x, this->circle.centerY - y);
    SDL_RenderDrawLine(renderer, this->circle.centerX + y, this->circle.centerY + x, this->circle.centerX - y, this->circle.centerY + x);
    SDL_RenderDrawLine(renderer, this->circle.centerX + y, this->circle.centerY - x, this->circle.centerX - y, this->circle.centerY - x);
}

void CCircle::DrawFilledCircle(SDL_Renderer *&renderer, int radius)
{
    int x = 0, y = radius;
    int d = 3 - 2 * radius;
    DrawCircleLines(renderer, x, y);
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
        DrawCircleLines(renderer, x, y);
    }
}
