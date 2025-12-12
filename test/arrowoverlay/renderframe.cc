#include "arrowoverlay.ih"

    // by 

void ArrowOverlay::renderFrame()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200);
    SDL_RenderClear(renderer);

    for (std::size_t i = 0; i < arrow_angles.size(); ++i)
        drawArrow(i, arrow_angles[i]);
    
    SDL_RenderPresent(renderer);
}
