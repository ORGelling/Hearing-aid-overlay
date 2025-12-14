#include "main.ih"

int main(int argc, char **argv) 
try
{
    size_t count = 16;
    double angle = 3;
    int size = 40; 

    setOptions(argc, argv, count, angle, size);
    
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
