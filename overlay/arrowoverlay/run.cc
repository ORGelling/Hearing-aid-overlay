#include "arrowoverlay.ih"

    // by 

bool ArrowOverlay::run() 
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
        return false;

    initialiseWindow();                         // initialises screen size and arrow locations
    
    d_window = SDL_CreateWindow("Compass Overlay",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        d_cfg.window_width, d_cfg.window_height, SDL_WINDOW_SHOWN);
    
    if (!d_window) 
        return false;

    d_renderer = SDL_CreateRenderer(d_window, -1, SDL_RENDERER_ACCELERATED);

    configureWindow();                          // sets transparency and topmost

    if (!d_renderer) 
    {
        SDL_DestroyWindow(d_window);
        return false;
    }

    mainLoop();
    
    SDL_DestroyRenderer(d_renderer);
    SDL_DestroyWindow(d_window);
    SDL_Quit();
    return true;
}
