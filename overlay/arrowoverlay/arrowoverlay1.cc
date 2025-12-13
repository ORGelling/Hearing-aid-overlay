#include "arrowoverlay.ih"

    // by 

ArrowOverlay::ArrowOverlay(OverlayConfig const &config)
: 
    d_cfg(config),
    d_cx(d_cfg.window_width / 2),
    d_cy(d_cfg.window_height / 2),
    d_rx(0),
    d_ry(0),
    d_radius(min(d_cfg.window_width / 2, 
                 d_cfg.window_height / 2) - d_cfg.margin),
    d_window(0),
    d_renderer(0)
{
    // Initialize compass angles (N, NE, ..., NW)
    for (size_t idx = 0; idx < d_cfg.compass_arrow_count; ++idx)
    {
        d_arrow_angles.push_back(-OverlayValues::pi / 2 
                + idx * (2 * OverlayValues::pi / d_cfg.compass_arrow_count));
    }
}
