#include "arrowoverlay.ih"

    // by 

void ArrowOverlay::renderFrame()
{
    SDL_SetRenderDrawColor(d_renderer, 0, 0, 0, 0);
    SDL_RenderClear(d_renderer);
    
    for (std::size_t idx = 0; idx < d_arrow_angles.size(); ++idx)
        drawArrow(idx, d_arrow_angles[idx]);
    
    SDL_RenderPresent(d_renderer);
}
