#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

class CTexture
{
public:
    // Constructor
    CTexture(SDL_Renderer *&renderer, string filePath);
    // Destructor
    ~CTexture();
    void Render(SDL_Renderer *&renderer, SDL_Rect *rectangle);
    void SetColor(Uint8 r, Uint8 g, Uint8 b);

private:
    SDL_Texture *texture;
};

#endif
