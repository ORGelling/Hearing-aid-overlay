#include "main.ih"

int main() 
{
    OverlayConfig config(24, 3);                // setting arrow type
    //config.window_width = 2048;
    //config.window_height = ; // 1152
    //config.compass_arrow_count = 16;
    ArrowOverlay overlay(config);
    overlay.run();
}
