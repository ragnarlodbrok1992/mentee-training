#include <iostream>
#include <SDL2/SDL.h>
#include <random>

const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

// TODO: exercise 1) dvd screensaver, bouncing rect & change colors
// TODO: exercise 2) dvd screensaver, add texture to rect
int randomize(int maxRange)
{
    std::random_device rd;                              // obtain a random number from hardware
    std::mt19937 gen(rd());                             // seed the generator
    std::uniform_int_distribution<> distr(0, maxRange); // define the range
    return distr(gen);                                  // generate numbers
};
void coordinates(SDL_Rect shape)
{
    printf("X:%d Y:%d\n", shape.x, shape.y);
};

int main(int arg, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
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

    SDL_Renderer *gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);

    if (NULL == gRenderer)
    {
        std::cout << "Cloud not create renderer: " << SDL_GetError() << std::endl;
        return 1;
    }

    bool running = true;

    int rectWidth = 50;
    int rectHeight = 50;

    // Set rect to random initial position
    SDL_Rect srcRect =
        {
            randomize(SCREEN_WIDTH - rectWidth),   // x from left to right
            randomize(SCREEN_HEIGHT - rectHeight), // y from top to bottom
            rectWidth,                             // width
            rectHeight,                            // height
        };

    int moveX = 1;
    int moveY = 1;
    int fillRed = 0;
    int fillGreen = 0;
    int fillBlue = 255;

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

        // Clear screen to black
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(gRenderer);

        // Draw red rect
        SDL_SetRenderDrawColor(gRenderer, fillRed, fillGreen, fillBlue, 0xFF);
        SDL_RenderFillRect(gRenderer, &srcRect);

        // TODO: Learn more about Motion (integration methods, interpolation, etc.)

        if (srcRect.x == 0 || srcRect.x == SCREEN_WIDTH - rectWidth)
        {
            moveX = -moveX;
            fillRed = randomize(255);
            fillGreen = randomize(255);
            fillBlue = randomize(255);
        };
        if (srcRect.y == 0 || srcRect.y == SCREEN_HEIGHT - rectHeight)
        {
            moveY = -moveY;
            fillRed = randomize(255);
            fillGreen = randomize(255);
            fillBlue = randomize(255);
        };

        srcRect.x += moveX;
        srcRect.y += moveY;

        coordinates(srcRect);

        SDL_Delay(50);

        // Draw to the screen
        SDL_RenderPresent(gRenderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
