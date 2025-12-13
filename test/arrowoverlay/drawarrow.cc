#include "arrowoverlay.ih"

    // by 

void ArrowOverlay::drawArrow(std::size_t size, double angle) 
{
    double ca = cos(angle), sa = sin(angle);
    int ex = d_cx + int(d_radius * ca);
    int ey = d_cy + int(d_radius * sa);

    SDL_SetRenderDrawColor(d_renderer, 200, Uint8(55 * size), 
                                            Uint8(255 - 30 * size), 255);

//  SDL_RenderDrawLine(
//      d_renderer,
//      cx + int((d_radius - d_cfg.arrow_length) * ca),
//      cy + int((d_radius - d_cfg.arrow_length) * sa),
//      ex, ey
//  );

    for (double ha : {angle + OverlayValues::pi - d_cfg.arrow_head_angle, 
                        angle + OverlayValues::pi + d_cfg.arrow_head_angle}) 
    {
        double ch = cos(ha), sh = sin(ha);
        SDL_RenderDrawLine(
            d_renderer,
            ex, ey,
            int(ex + d_cfg.arrow_head_length * ch),
            int(ey + d_cfg.arrow_head_length * sh)
        );
    }
}
