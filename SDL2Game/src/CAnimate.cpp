#include "CAnimate.h"
#include "Constant.h"

using namespace Constant;

/** TODO:
 * - allow to anime different object not only srcRect
 * - move color logic to a different class
 *
 * @brief Construct a new CAnimate::CAnimate object
 * @param srcRect - object that will be moved
 * @param moveX - the amount of pixels move in X axis
 * @param moveY - the amount of pixels move in Y axis
 */

CAnimate::CAnimate(SDL_Rect *srcRect, int moveX, int moveY)
{
    this->moveX = moveX;
    this->moveY = moveY;
    this->shape = srcRect;
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

    this->shape->x += this->moveX;
    this->shape->y += this->moveY;
}
