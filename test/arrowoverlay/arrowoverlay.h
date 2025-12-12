#ifndef INCLUDED_ARROWOVERLAY_
#define INCLUDED_ARROWOVERLAY_

#include "../overlayconfig/overlayconfig.h"
#include <vector>

struct SDL_Window;
struct SDL_Renderer;

class ArrowOverlay
{
    OverlayConfig cfg;          // struct holding std values
    
    int cx;
    int cy;
    int radius;
    std::vector<double> arrow_angles;
    SDL_Window* window;
    SDL_Renderer* renderer;

    public:
        explicit ArrowOverlay(OverlayConfig const &config);
        ~ArrowOverlay();
        bool run();

    private:
        void mainLoop();
        //void handleEvents(bool &running, SDL_Event &e);
        void renderFrame();
        void drawArrow(std::size_t size, double angle);

};
        
#endif
