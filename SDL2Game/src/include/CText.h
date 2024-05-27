#ifndef TEXT_CLASS_H
#define TEXT_CLASS_H
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

using namespace std;

class CText
{
public:
    // Constructor
    CText(SDL_Renderer *&renderer, TTF_Font *font, string text);
    // Destructor
    ~CText();
    void Render(SDL_Renderer *&renderer, SDL_Rect *rectangle);
    int SetColor(Uint8 r, Uint8 g, Uint8 b);

private:
    SDL_Texture *texture;
};

#endif
