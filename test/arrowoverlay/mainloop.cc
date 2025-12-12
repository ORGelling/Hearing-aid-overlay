#include "arrowoverlay.ih"

    // by 

void ArrowOverlay::mainLoop()
{
    bool running = true;
    SDL_Event e;
    while (running) 
    {
        //handleEvents(running, e);
        while (SDL_PollEvent(&e)) 
        {
            if (e.type == SDL_QUIT)
                running = false;
        }
        
        renderFrame();
        SDL_Delay(16); // ~60 FPS           // look into further
    }
}
