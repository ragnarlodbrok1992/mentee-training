#ifndef CIRCLE_CLASS_H
#define CIRCLE_CLASS_H
#include <SDL2/SDL.h>

using namespace std;

struct Circle
{
    int centerX;
    int centerY;
    int radius;
};

struct Color
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
};

class CCircle
{
public:
    // Constructor
    CCircle(SDL_Renderer *&renderer, Circle obj, Color col);
    void Draw(SDL_Renderer *&renderer);

private:
    Circle circle;
    Color color;
    void DrawFilledCircle(SDL_Renderer *&renderer, int radius);
    void DrawCircleLines(SDL_Renderer *&renderer, int x, int y);
};

#endif
