#include "overlayconfig.ih"

    // by 

OverlayConfig::OverlayConfig(int length, double angle, size_t count)
:
    arrow_head_length(length),
    arrow_head_angle(OverlayValues::pi / angle),
    compass_arrow_count(count)
{}
