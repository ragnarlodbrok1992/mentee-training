#ifndef ANIMATE_CLASS_H
#define ANIMATE_CLASS_H
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

// TODO: Learn more about Motion (integration methods, interpolation, etc.)

class CAnimate
{
public:
    // Constructor
    CAnimate(SDL_Rect *srcRect, int moveX, int moveY);
    // Destructor
    ~CAnimate();
    void Start();

private:
    int moveX = 2;
    int moveY = 2;
    SDL_Rect *shape;
    void Init();
};

#endif
