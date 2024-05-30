#include "CText.h"

CText::CText(SDL_Renderer *&renderer, TTF_Font *font, string text)
{
	this->color = {255, 255, 255};
	this->font = font;
	this->Create(renderer, text);
}

CText::~CText()
{
	SDL_DestroyTexture(this->texture);
}

void CText::Create(SDL_Renderer *&renderer, string text)
{
	this->surface = TTF_RenderText_Solid(this->font, text.c_str(), this->color);
	this->texture = SDL_CreateTextureFromSurface(renderer, this->surface);
	SDL_FreeSurface(this->surface);
}

void CText::Update(SDL_Renderer *&renderer, SDL_Rect *rectangle, string text)
{
	this->~CText();
	this->Create(renderer, text);
	this->Render(renderer, rectangle);
}

void CText::Render(SDL_Renderer *&renderer, SDL_Rect *rectangle)
{
	SDL_RenderCopy(renderer, this->texture, NULL, rectangle);
}

int CText::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
	return SDL_SetTextureColorMod(this->texture, r, g, b);
}
