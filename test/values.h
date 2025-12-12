#ifndef OVERLAY_CONFIG_HPP
#define OVERLAY_CONFIG_HPP

#include <cstdint>
#include <SDL2/SDL.h>
#include <cmath>

// For clarity, enum class to namespace config constants
enum class Overlay : std::uint32_t {
    WindowWidth = 600,
    WindowHeight = 600,
    Margin = 30,
    ArrowLength = 60,
    ArrowHeadLength = 18,
    ArrowHeadAngle = 0 // not used directly, see below for constexpr
};

constexpr double ArrowHeadAngleRadians = M_PI / 7;
constexpr std::size_t CompassArrowCount = 8;

#endif // OVERLAY_CONFIG_HPP
