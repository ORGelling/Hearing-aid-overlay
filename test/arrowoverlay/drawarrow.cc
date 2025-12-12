#include "arrowoverlay.ih"

    // by 

void ArrowOverlay::drawArrow(std::size_t size, double angle) {
    double ca = std::cos(angle), sa = std::sin(angle);
    int ex = cx + int(radius * ca);
    int ey = cy + int(radius * sa);

    SDL_SetRenderDrawColor(renderer, 200, Uint8(55 * size), 
                                            Uint8(255 - 30 * size), 255);

//  SDL_RenderDrawLine(
//      renderer,
//      cx + int((radius - cfg.arrow_length) * ca),
//      cy + int((radius - cfg.arrow_length) * sa),
//      ex, ey
//  );

    for (double ha : {angle + OverlayValues::pi - cfg.arrow_head_angle, 
                        angle + OverlayValues::pi + cfg.arrow_head_angle}) 
    {
        double ch = std::cos(ha), sh = std::sin(ha);
        SDL_RenderDrawLine(
            renderer,
            ex, ey,
            int(ex + cfg.arrow_head_length * ch),
            int(ey + cfg.arrow_head_length * sh)
        );
    }
}
