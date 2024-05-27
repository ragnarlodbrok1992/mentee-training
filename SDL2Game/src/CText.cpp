#include "CText.h"

CText::CText(SDL_Renderer *&renderer, TTF_Font *font, string text)
{
	SDL_Color fg = {255, 255, 255};
	SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), fg);
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

CText::~CText()
{
	SDL_DestroyTexture(this->texture);
}

void CText::Render(SDL_Renderer *&renderer, SDL_Rect *rectangle)
{
	SDL_RenderCopy(renderer, this->texture, NULL, rectangle);
}

int CText::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
	return SDL_SetTextureColorMod(this->texture, r, g, b);
}
