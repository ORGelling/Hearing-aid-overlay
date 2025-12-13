#include "overlayconfig.ih"

    // by 

OverlayConfig::OverlayConfig(int length, size_t angle)
:
    arrow_head_length(length),
    arrow_head_angle(OverlayValues::pi / angle)
{}
