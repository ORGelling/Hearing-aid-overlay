#ifndef INCLUDED_ARROWOVERLAY_
#define INCLUDED_ARROWOVERLAY_

#include "../overlayconfig/overlayconfig.h"
#include <vector>

struct SDL_Window;
struct SDL_Renderer;

class ArrowOverlay
{
    OverlayConfig d_cfg;            // struct holding std values

    int d_cx;                       // arrow orientation
    int d_cy;
    int d_rx;                       // for ellips
    int d_ry;
    int d_radius;
    std::vector<double> d_arrow_angles;
       
    SDL_Window *d_window;
    SDL_Renderer *d_renderer; 
    
    public:
        explicit ArrowOverlay(OverlayConfig const &config);
        ~ArrowOverlay();
        bool run();

    private:
        void initialiseWindow();
        void configureWindow();
        void mainLoop();
        void renderFrame();
        void drawArrow(std::size_t size, double angle);

};
        
#endif
