#ifndef GAME_APP_CLASS_H
#define GAME_APP_CLASS_H
#include <iostream>
#include <SDL2/SDL.h>
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

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool running = true;
};

#endif
