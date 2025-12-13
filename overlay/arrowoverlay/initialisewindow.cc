#include "arrowoverlay.ih"

    // by 

void ArrowOverlay::initialiseWindow()
{
    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) 
        return;
    
    d_cfg.window_width = dm.w;
    d_cfg.window_height = dm.h;
    
    d_cx = dm.w / 2;
    d_cy = dm.h / 2;
    
    d_rx = d_cx - d_cfg.margin;
    d_ry = d_cy - d_cfg.margin;
    
    d_radius = min(d_cfg.window_width, 
                   d_cfg.window_height) / 2 - d_cfg.margin;
}
