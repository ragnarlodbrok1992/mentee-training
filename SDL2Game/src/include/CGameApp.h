#ifndef GAME_APP_CLASS_H
#define GAME_APP_CLASS_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Constant.h"

using namespace std;
using namespace Constant;

class CGameApp
{
public:
    // Constructor
    CGameApp(const char *title);
    // Destructor
    ~CGameApp();
    // Retrieve the renderer
    SDL_Renderer *GetRenderer() const;
    bool GetRunning();
    void SetRunning(bool running);
    TTF_Font *GetFont();
    void SetFont(string filePath);

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    TTF_Font *font = nullptr;
    bool running = true;
};

#endif
