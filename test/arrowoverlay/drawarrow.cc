#include "arrowoverlay.ih"

    // by 

void ArrowOverlay::drawArrow(std::size_t size, double angle) 
{
    double ca = cos(angle);
    double sa = sin(angle);
    
//  int ex = d_cx + static_cast<int>(d_radius * ca);
//  int ey = d_cy + static_cast<int>(d_radius * sa);

    int ex = d_cx + static_cast<int>(d_rx * ca);
    int ey = d_cy + static_cast<int>(d_ry * sa);

//  int sx = d_cx + static_cast<int>((d_rx - d_cfg.arrow_length) * ca);
//  int sy = d_cy + static_cast<int>((d_ry - d_cfg.arrow_length) * sa);
    
    SDL_SetRenderDrawColor(d_renderer, 200, Uint8(55 * size), 
                                            Uint8(255 - 30 * size), 255);
    
//  SDL_RenderDrawLine(d_renderer, sx, sy, ex, ey);     // ellips
//  SDL_RenderDrawLine(                                 // circle
//      d_renderer,
//      cx + int((d_radius - d_cfg.arrow_length) * ca),
//      cy + int((d_radius - d_cfg.arrow_length) * sa),
//      ex, ey
//  );

    for (double ha : {angle + OverlayValues::pi - d_cfg.arrow_head_angle, 
                      angle + OverlayValues::pi + d_cfg.arrow_head_angle}) 
    {
        double ch = cos(ha);
        double sh = sin(ha);
        SDL_RenderDrawLine(
            d_renderer,
            ex, ey,
            static_cast<int>(ex + d_cfg.arrow_head_length * ch),
            static_cast<int>(ey + d_cfg.arrow_head_length * sh)
        );
    }
}
