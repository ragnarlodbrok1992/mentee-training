#include "CAnimate.h"
#include "Constant.h"

using namespace Constant;

CAnimate::CAnimate(SDL_Rect *srcRect, int moveX, int moveY)
{
    this->moveX = moveX;
    this->moveY = moveY;
    shape = srcRect;
}

CAnimate::~CAnimate()
{
}

void CAnimate::Start()
{
    if (shape->x <= 0 + abs(moveX) || shape->x >= SCREEN_WIDTH - shape->w - abs(moveX))
    {
        this->moveX = -moveX;
        // fillRed = color.getRandom();
        // fillGreen = color.getRandom();
        // fillBlue = color.getRandom();
    };
    if (shape->y <= 0 + abs(moveY) || shape->y >= SCREEN_HEIGHT - shape->h - abs(moveY))
    {
        this->moveY = -moveY;
        // fillRed = color.getRandom();
        // fillGreen = color.getRandom();
        // fillBlue = color.getRandom();
    };

    shape->x += this->moveX;
    shape->y += this->moveY;
}
