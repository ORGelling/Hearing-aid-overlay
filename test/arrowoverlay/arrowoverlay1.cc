#include "arrowoverlay.ih"

    // by 

ArrowOverlay::ArrowOverlay(const OverlayConfig& config)
: 
    cfg(config),
    cx(cfg.window_width / 2),
    cy(cfg.window_height / 2),
    radius(min(cfg.window_width / 2, cfg.window_height / 2) - cfg.margin),
    window(0),
    renderer(0)
{
    // Initialize compass angles (N, NE, ..., NW)
    for (std::size_t i = 0; i < cfg.compass_arrow_count; ++i)
        arrow_angles.push_back(-OverlayValues::pi / 2 
                    + i * (2 * OverlayValues::pi / cfg.compass_arrow_count));
}
