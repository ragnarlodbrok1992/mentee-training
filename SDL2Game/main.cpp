#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int arg, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow(
        "SDL Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WIDTH, HEIGHT,
        SDL_WINDOW_OPENGL);

    if (NULL == window)
    {
        std::cout << "Cloud not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event widnowEvent;

    while (true)
    {
        if (SDL_PollEvent(&widnowEvent))
        {
            if (SDL_QUIT == widnowEvent.type)
            {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
