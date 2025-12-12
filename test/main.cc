#include "main.ih"

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("HUD Prototype",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }

        // Semi-transparent background (black, 200 alpha)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200);
        SDL_RenderClear(renderer);

        // Draw simple arrow (from center to top)
        int cx = 300, cy = 300, length = 100;
        double angle = -M_PI / 2; // Upwards (radians)
        int ex = cx + (int)(length * cos(angle));
        int ey = cy + (int)(length * sin(angle));

        // Arrow shaft
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // bright green
        SDL_RenderDrawLine(renderer, cx, cy, ex, ey);

        // Arrowhead
        double arrow_angle = M_PI / 6; // 30 deg for the head
        int ah1x = ex + (int)(30 * cos(angle + M_PI - arrow_angle));
        int ah1y = ey + (int)(30 * sin(angle + M_PI - arrow_angle));
        int ah2x = ex + (int)(30 * cos(angle + M_PI + arrow_angle));
        int ah2y = ey + (int)(30 * sin(angle + M_PI + arrow_angle));
        SDL_RenderDrawLine(renderer, ex, ey, ah1x, ah1y);
        SDL_RenderDrawLine(renderer, ex, ey, ah2x, ah2y);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);  // ~60fps
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
