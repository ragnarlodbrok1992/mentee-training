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
    void Create(SDL_Renderer *&renderer, string text);
    void Update(SDL_Renderer *&renderer, SDL_Rect *rectangle, string text);
    void Render(SDL_Renderer *&renderer, SDL_Rect *rectangle);
    int SetColor(Uint8 r, Uint8 g, Uint8 b);

private:
    SDL_Texture *texture;
    SDL_Surface *surface;
    TTF_Font *font;
    SDL_Color color;
};

#endif
