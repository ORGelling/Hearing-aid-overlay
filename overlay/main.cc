#include "main.ih"

int main(int argc, char **argv) 
try
{
    int size = 40; 
    double angle = 3;
    size_t count = 16;

    setOptions(argc, argv, size, angle, count);
    
    // getoptons proper, this is mid
    // processoptions
    
    OverlayConfig config(size, angle, count);       // setting arrow type
    ArrowOverlay overlay(config);
    overlay.run();
}
catch (...)
{
    return handleExceptions();
}
