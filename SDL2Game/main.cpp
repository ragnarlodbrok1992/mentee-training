#include <iostream>
#include <SDL2/SDL.h>
#include "CRnd.h"
#include "CTexture.h"
#include "CCircle.h"

SDL_Window *window;
SDL_Renderer *gRenderer;

/**
 * @brief TODO:
 * - [] Generate circle shapes that will use the same movement as DVD Logo.
 * - [] Add a counter that will display numbers at the top of the screen.
 * - [] Handle the collision and update the counter.
 */

const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

void coordinates(SDL_Rect shape)
{
    printf("X:%d Y:%d\n", shape.x, shape.y);
};

int main(int arg, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "SDL Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_OPENGL);

    if (NULL == window)
    {
        std::cout << "Cloud not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (NULL == gRenderer)
    {
        std::cout << "Cloud not create renderer: " << SDL_GetError() << std::endl;
        return 1;
    }

    bool running = true;

    const int rectWidth = 50;
    const int rectHeight = 50;

    CRnd posX, posY, color;
    CTexture DvDLogo(gRenderer, "./src/images/DVD-Logo-w.bmp");

    // Set rect to random initial position
    SDL_Rect srcRect =
        {
            posX.getRandom(0, SCREEN_WIDTH - rectWidth),   // x from left to right
            posY.getRandom(0, SCREEN_HEIGHT - rectHeight), // y from top to bottom
            rectWidth,                                     // width
            rectHeight,                                    // height
        };

    int moveX = 2;
    int moveY = 2;
    Uint8 fillRed = 0;
    Uint8 fillGreen = 0;
    Uint8 fillBlue = 255;

    while (running) // One cycle frame
    {

        SDL_Event event;
        // Check the close event and keypress
        if (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                running = false;
            }
            if (SDL_KEYDOWN == event.type)
            {
                // TODO: Remember to optimize arrow motion keypresses
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    running = false;
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

        // TODO: Learn more about Motion (integration methods, interpolation, etc.)

        if (srcRect.x <= 0 + abs(moveX) || srcRect.x >= SCREEN_WIDTH - rectWidth - abs(moveX))
        {
            moveX = -moveX;
            fillRed = color.getRandom();
            fillGreen = color.getRandom();
            fillBlue = color.getRandom();
        };
        if (srcRect.y <= 0 + abs(moveY) || srcRect.y >= SCREEN_HEIGHT - rectHeight - abs(moveY))
        {
            moveY = -moveY;
            fillRed = color.getRandom();
            fillGreen = color.getRandom();
            fillBlue = color.getRandom();
        };

        srcRect.x += moveX;
        srcRect.y += moveY;

        coordinates(srcRect);

        CCircle Point1(gRenderer, {100, 150, 25}, {255, 0, 0});
        CCircle Point2(gRenderer, {400, 450, 25}, {0, 0, 255});

        SDL_Delay(5);
        // Draw to the screen
        SDL_RenderPresent(gRenderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
