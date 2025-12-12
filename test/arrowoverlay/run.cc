#include "arrowoverlay.ih"

    // by 

bool ArrowOverlay::run() 
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
        return false;

    window = SDL_CreateWindow("Compass Overlay",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        cfg.window_width, cfg.window_height, SDL_WINDOW_SHOWN);
    
    if (!window) 
        return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) 
    {
        SDL_DestroyWindow(window);
        return false;
    }

    mainLoop();
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return true;
}
