#include "CGameApp.h"

CGameApp::CGameApp(const char *title)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Error initializing video subsystem: " << SDL_GetError() << endl;
    }

    if (TTF_Init() < 0)
    {
        cout << "Error initializing SDL_ttf: " << TTF_GetError() << endl;
    }

    // Initialize the video subsystem
    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_OPENGL);

    if (NULL == window)
    {
        std::cout << "Cloud not create window: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (NULL == renderer)
    {
        std::cout << "Cloud not create renderer: " << SDL_GetError() << std::endl;
    }

    this->font = TTF_OpenFont("./src/font/consolas.ttf", 24);

    if (NULL == this->font)
    {
        cout << "Error loading font: " << TTF_GetError() << endl;
    }
}

CGameApp::~CGameApp()
{
    TTF_CloseFont(this->font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer *CGameApp::GetRenderer() const
{
    return renderer;
}

bool CGameApp::GetRunning()
{
    return this->running;
}

void CGameApp::SetRunning(bool running)
{
    this->running = running;
}

TTF_Font *CGameApp::GetFont()
{
    return this->font;
}

void CGameApp::SetFont(string filePath)
{
    this->font = TTF_OpenFont(filePath.c_str(), 24);
}
