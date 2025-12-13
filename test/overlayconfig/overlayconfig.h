#ifndef INCLUDED_OVERLAYCONFIG_
#define INCLUDED_OVERLAYCONFIG_

#include <cstddef>

namespace OverlayValues {
    constexpr double pi = 3.14159265358979323846;
}

struct OverlayConfig 
{
    int window_width      = 600;
    int window_height     = 600;
    int margin            = 30;
    int arrow_length      = 60;
    int arrow_head_length = 18;
    double arrow_head_angle = OverlayValues::pi / 7;
    std::size_t compass_arrow_count = 16;
    
    OverlayConfig() = default;
    OverlayConfig(int x, int h);
};
        
#endif
