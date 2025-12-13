#include "main.ih"

int main(int argc, char **argv) 
try
{
    int size = 40;
    double angle = 3;
    //size_t count = 16;
    if (argc == 3)
    {
        size = stoi(argv[1]);
        angle = stod(argv[2]);
    }
    
    OverlayConfig config(size, angle);                // setting arrow type
    //config.compass_arrow_count = count;
    ArrowOverlay overlay(config);
    overlay.run();
}
catch (...)
{
    return handleExceptions();
}
