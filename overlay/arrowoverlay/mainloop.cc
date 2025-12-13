#include "arrowoverlay.ih"

    // by 

void ArrowOverlay::mainLoop()
{
    bool running = true;
    SDL_Event e;
    while (running) 
    {
        while (SDL_PollEvent(&e)) 
        {
            if (e.type == SDL_QUIT)
                running = false;
            
            if (e.type == SDL_KEYDOWN) 
            {
                if (e.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
            }
        }
        
        renderFrame();
        SDL_Delay(16); // ~60 FPS           // look into further
    }
}
