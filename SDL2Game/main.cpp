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

    SDL_Event event;
    SDL_KeyCode key;
    SDL_Renderer *gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (NULL == gRenderer)
    {
        std::cout << "Cloud not create renderer: " << SDL_GetError() << std::endl;
        return 1;
    }

    bool running = true;

    while (running) // One cycle frame
    {
        // Check the close event and keypress
        if (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                running = false;
            }
            if (SDL_KEYUP == event.type)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_DOWN:
                    std::cout << "Go down" << std::endl;
                    break;
                case SDLK_UP:
                    std::cout << "Go up" << std::endl;
                    break;
                case SDLK_RIGHT:
                    std::cout << "Go right" << std::endl;
                    break;
                case SDLK_LEFT:
                    std::cout << "Go left" << std::endl;
                    break;
                case SDLK_ESCAPE:
                    running = false;
                    break;
                default:
                    std::cout << "Key was pressed: " << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
                    break;
                }
            }
        }

        // Clear screen to black
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(gRenderer);

        // Draw red rect
        SDL_Rect fillRect = {WIDTH / 4, HEIGHT / 4, WIDTH / 2, HEIGHT / 2};
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(gRenderer, &fillRect);

        // Draw to the screen
        SDL_RenderPresent(gRenderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
