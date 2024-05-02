#include "CTexture.h"

CTexture::CTexture(SDL_Renderer *&renderer, string filePath)
{
    SDL_Surface *surface = SDL_LoadBMP(filePath.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

CTexture::~CTexture()
{
    SDL_DestroyTexture(texture);
}

void CTexture::Render(SDL_Renderer *&renderer, SDL_Rect *rectangle)
{
    SDL_RenderCopy(renderer, texture, NULL, rectangle);
}

void CTexture::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetTextureColorMod(texture, r, g, b);
}
