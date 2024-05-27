#include <iostream>
#include <SDL2/SDL.h>
#include "CGameApp.h"
#include "CRnd.h"
#include "CTexture.h"
#include "CCircle.h"
#include "CAnimate.h"
#include "Constant.h"
#include "CText.h"

using namespace Constant;

/**
 * @brief TODO:
 * - [] Generate circle shapes that will use the same movement as DVD Logo.
 * - [] Add a counter that will display numbers at the top of the screen.
 * - [] Handle the collision and update the counter.
 */

void coordinates(SDL_Rect shape)
{
    printf("X:%d Y:%d\n", shape.x, shape.y);
};

int main(int arg, char *argv[])
{
    CGameApp app("DVD Screener");
    SDL_Renderer *gRenderer = app.GetRenderer();
    CRnd posX, posY;
    CTexture DvDLogo(gRenderer, "./src/images/DVD-Logo-w.bmp");
    TTF_Font *font = app.GetFont();

    const int rectWidth = 50;
    const int rectHeight = 50;
    // Set rect to random initial position
    SDL_Rect srcRect =
        {
            posX.GetRandom(0, SCREEN_WIDTH - rectWidth),   // x from left to right
            posY.GetRandom(0, SCREEN_HEIGHT - rectHeight), // y from top to bottom
            rectWidth,                                     // width
            rectHeight,                                    // height
        };

    SDL_Rect textRect =
        {
            posX.GetRandom(0, SCREEN_WIDTH - 50),  // x from left to right
            posY.GetRandom(0, SCREEN_HEIGHT - 20), // y from top to bottom
            50,                                    // width
            20,                                    // height
        };

    CAnimate rectangle(&srcRect, 2, 2);

    Uint8 fillRed = 0;
    Uint8 fillGreen = 0;
    Uint8 fillBlue = 255;

    Circle point1 = {100, 150, 25};
    Circle point2 = {400, 450, 25};
    CCircle Point1(gRenderer, point1, {255, 0, 0});
    CCircle Point2(gRenderer, point2, {0, 0, 255});

    CText Text(gRenderer, font, std::string("text"));

    while (app.GetRunning()) // One cycle frame
    {

        SDL_Event event;
        // Check the close event and keypress
        if (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                app.SetRunning(false);
            }
            if (SDL_KEYDOWN == event.type)
            {
                // TODO: Remember to optimize arrow motion keypresses
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    app.SetRunning(false);
                    break;
                }
            }
        }

        // Clear screen to one color
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(gRenderer);

        // Draw DVD logo
        DvDLogo.Render(gRenderer, &srcRect);
        DvDLogo.SetColor(fillRed, fillGreen, fillBlue);

        rectangle.Start();
        // coordinates(srcRect);

        Point1.Draw(gRenderer);
        Point2.Draw(gRenderer);

        Text.Render(gRenderer, &textRect);

        SDL_Delay(5);
        // Draw to the screen
        SDL_RenderPresent(gRenderer);
    }

    app.~CGameApp();
    return EXIT_SUCCESS;
}
