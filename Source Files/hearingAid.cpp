#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <fmod.hpp>
#include <cmath>
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace std;

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    // Create SDL window
    SDL_Window* window = SDL_CreateWindow("Sound Direction Display", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    // Create SDL renderer (SDL3 style)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize FMOD
    FMOD::System* system = nullptr;
    FMOD::System_Create(&system);
    system->init(512, FMOD_INIT_NORMAL, nullptr);

    // Load sound
    FMOD::Sound* sound = nullptr;
    system->createSound("sound.mp3", FMOD_3D, nullptr, &sound);

    // Play sound
    FMOD::Channel* channel = nullptr;
    FMOD_VECTOR soundPos = { 10.0f, 0.0f, 10.0f };
    FMOD_VECTOR zeroVel = { 0.0f, 0.0f, 0.0f };
    system->playSound(sound, nullptr, true, &channel);
    channel->set3DAttributes(&soundPos, &zeroVel);
    channel->setPaused(false);

    // Listener
    FMOD_VECTOR listenerPos = { 0.0f, 0.0f, 0.0f };
    FMOD_VECTOR forward = { 0.0f, 0.0f, 1.0f };
    FMOD_VECTOR up = { 0.0f, 1.0f, 0.0f };
    system->set3DListenerAttributes(0, &listenerPos, &zeroVel, &forward, &up);

    // Main loop
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        system->update();

        float dx = soundPos.x - listenerPos.x;
        float dz = soundPos.z - listenerPos.z;
        float angle = atan2(dz, dx);

        // Render background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw listener
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_FRect listenerRect = { SCREEN_WIDTH / 2.0f - 10, SCREEN_HEIGHT / 2.0f - 10, 20, 20 };
        SDL_RenderFillRect(renderer, &listenerRect);

        // Draw direction line
        float lineLength = 100.0f;
        float endX = SCREEN_WIDTH / 2.0f + cos(angle) * lineLength;
        float endY = SCREEN_HEIGHT / 2.0f + sin(angle) * lineLength;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderLine(renderer,
            SCREEN_WIDTH / 2,
            SCREEN_HEIGHT / 2,
            static_cast<int>(endX),
            static_cast<int>(endY));

        SDL_RenderPresent(renderer);
        SDL_Delay(16);  // ~60 FPS
    }

    // Cleanup
    sound->release();
    system->close();
    system->release();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

/*

#include <SDL3/SDL.h>
#include <fmod.hpp>
#include <cmath>
#include <iostream>
#include "../../SDL3-3.2.12/include/SDL3/SDL_oldnames.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SDL_RenderDrawLine_renamed_SDL_RenderLine SDL_RenderDrawLine

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846 // Define M_PI if not already defined
#endif

// Convert radians to degrees
float radToDeg(float rad) {
    return rad * (180.0f / M_PI);
}

// Define SDL_RENDERER_ACCELERATED if not already defined  
#ifndef SDL_RENDERER_ACCELERATED  
#define SDL_RENDERER_ACCELERATED 0x00000002u /**< The renderer uses hardware acceleration 
#endif

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <fmod.hpp>
#include <cmath>
#include <iostream>
#include <SDL3/SDL_oldnames.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace std;

/*
float radToDeg(float rad) {
    return rad * (180.0f / M_PI);
}
*/
/*
int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "SDL Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Sound Direction Display",
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_RESIZABLE);
    if (!window) {
        cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer using SDL3 method
    SDL_RendererConfig rendererConfig{};
    rendererConfig.flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, &rendererConfig);
    if (!renderer) {
        cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize FMOD
    FMOD::System* system = nullptr;
    FMOD::System_Create(&system);
    system->init(512, FMOD_INIT_NORMAL, nullptr);

    // Load sound
    FMOD::Sound* sound = nullptr;
    system->createSound("sound.mp3", FMOD_3D, nullptr, &sound);

    // Set sound position and play
    FMOD::Channel* channel = nullptr;
    FMOD_VECTOR soundPos = { 10.0f, 0.0f, 10.0f };
    FMOD_VECTOR zeroVel = { 0.0f, 0.0f, 0.0f };
    system->playSound(sound, nullptr, true, &channel);
    channel->set3DAttributes(&soundPos, &zeroVel);
    channel->setPaused(false);

    // Set listener attributes
    FMOD_VECTOR listenerPos = { 0.0f, 0.0f, 0.0f };
    FMOD_VECTOR forward = { 0.0f, 0.0f, 1.0f };
    FMOD_VECTOR up = { 0.0f, 1.0f, 0.0f };
    system->set3DListenerAttributes(0, &listenerPos, &zeroVel, &forward, &up);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        system->update();

        // Calculate angle from listener to sound
        float dx = soundPos.x - listenerPos.x;
        float dz = soundPos.z - listenerPos.z;
        float angle = atan2(dz, dx);

        // Render scene
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw listener
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_FRect listenerRect = { SCREEN_WIDTH / 2.0f - 10, SCREEN_HEIGHT / 2.0f - 10, 20, 20 };
        SDL_RenderFillRect(renderer, &listenerRect);

        // Draw direction line
        float length = 100.0f;
        float endX = SCREEN_WIDTH / 2.0f + cos(angle) * length;
        float endY = SCREEN_HEIGHT / 2.0f + sin(angle) * length;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderLine(renderer,
            SCREEN_WIDTH / 2,
            SCREEN_HEIGHT / 2,
            static_cast<int>(endX),
            static_cast<int>(endY));

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    // Cleanup
    sound->release();
    system->close();
    system->release();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

/*
int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "SDL Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Sound Direction Display",
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_RESIZABLE);
    if (!window) {
        cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        return 1;
    }

    // Initialize FMOD
    FMOD::System* system = nullptr;
    FMOD::System_Create(&system);
    system->init(512, FMOD_INIT_NORMAL, nullptr);

    // Load sound
    FMOD::Sound* sound = nullptr;
    system->createSound("sound.mp3", FMOD_3D, nullptr, &sound);

    // Play sound at a fixed position
    FMOD::Channel* channel = nullptr;
    FMOD_VECTOR soundPos = { 10.0f, 0.0f, 10.0f };  // Arbitrary 3D position
    FMOD_VECTOR zeroVel = { 0.0f, 0.0f, 0.0f };
    system->playSound(sound, nullptr, true, &channel);
    channel->set3DAttributes(&soundPos, &zeroVel);
    channel->setPaused(false);

    // Set the listener at the origin
    FMOD_VECTOR listenerPos = { 0.0f, 0.0f, 0.0f };
    FMOD_VECTOR forward = { 0.0f, 0.0f, 1.0f };
    FMOD_VECTOR up = { 0.0f, 1.0f, 0.0f };
    system->set3DListenerAttributes(0, &listenerPos, &zeroVel, &forward, &up);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        system->update();

        // Calculate direction from listener to sound
        float dx = soundPos.x - listenerPos.x;
        float dz = soundPos.z - listenerPos.z;
        float angle = atan2(dz, dx); // in radians

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw listener
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_FRect listenerRect = { SCREEN_WIDTH / 2.0f - 10, SCREEN_HEIGHT / 2.0f - 10, 20, 20 };
        SDL_RenderFillRect(renderer, &listenerRect);

        // Draw direction line
        float lineLength = 100.0f;
        float endX = SCREEN_WIDTH / 2.0f + cos(angle) * lineLength;
        float endY = SCREEN_HEIGHT / 2.0f + sin(angle) * lineLength;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer,
            SCREEN_WIDTH / 2,
            SCREEN_HEIGHT / 2,
            static_cast<int>(endX),
            static_cast<int>(endY));

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    // Cleanup
    sound->release();
    system->close();
    system->release();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

/*

#include <SDL3/SDL.h>
#include <fmod.hpp>
#include <cmath>
#include <iostream>

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Convert radians to degrees
float radToDeg(float rad) {
    return rad * (180.0f / M_PI);
}

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "SDL Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Sound Direction Display", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr, SDL_RENDERER_ACCELERATED);

    // Initialize FMOD
    FMOD::System* system = nullptr;
    FMOD::System_Create(&system);
    system->init(512, FMOD_INIT_NORMAL, nullptr);

    // Load sound
    FMOD::Sound* sound = nullptr;
    system->createSound("sound.mp3", FMOD_3D, nullptr, &sound);

    // Play sound at a 2D position
    FMOD::Channel* channel = nullptr;
    FMOD_VECTOR soundPos = { 10.0f, 0.0f, 0.0f }; // Right of the listener
    FMOD_VECTOR vel = { 0.0f, 0.0f, 0.0f };
    system->playSound(sound, nullptr, true, &channel);
    channel->set3DAttributes(&soundPos, &vel);
    channel->setPaused(false);

    // Listener setup at origin
    FMOD_VECTOR listenerPos = { 0.0f, 0.0f, 0.0f };
    FMOD_VECTOR forward = { 0.0f, 0.0f, 1.0f };
    FMOD_VECTOR up = { 0.0f, 1.0f, 0.0f };
    system->set3DListenerAttributes(0, &listenerPos, &vel, &forward, &up);

    // Main loop
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        system->update();

        // Calculate direction
        float dx = soundPos.x - listenerPos.x;
        float dz = soundPos.z - listenerPos.z;
        float angle = atan2(dz, dx);
        float degrees = radToDeg(angle);

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White

        // Draw listener at center
        SDL_FRect listener = { SCREEN_WIDTH / 2.0f - 10, SCREEN_HEIGHT / 2.0f - 10, 20, 20 };
        SDL_RenderFillRect(renderer, &listener);

        // Draw direction line
        float lineLength = 100;
        float endX = SCREEN_WIDTH / 2.0f + cos(angle) * lineLength;
        float endY = SCREEN_HEIGHT / 2.0f + sin(angle) * lineLength;

        SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, (int)endX, (int)endY);

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    // Cleanup
    sound->release();
    system->close();
    system->release();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

*/
/*
#include <SDL3/SDL.h>
#include <fmod.hpp>
#include <iostream>
#include <cmath>
#include "../../SDL3-3.2.12/include/SDL3/SDL_oldnames.h"
#include <SDL3/SDL_video.h>

using namespace std;

// Function to map 3D sound direction to 2D screen coordinates
void mapDirectionToScreen(float x, float y, float z, int screenWidth, int screenHeight, int &screenX, int &screenY) {
    float magnitude = sqrt(x * x + y * y + z * z);
    screenX = static_cast<int>((x / magnitude) * (screenWidth / 2) + (screenWidth / 2));
    screenY = static_cast<int>((-z / magnitude) * (screenHeight / 2) + (screenHeight / 2));
}

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "Failed to initialize SDL: " << SDL_GetError() << endl;
        return -1;
    }

    // Create SDL window
    SDL_Window* window = SDL_CreateWindow("Sound Direction Overlay", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        cerr << "Failed to create SDL window: " << SDL_GetError() << endl;
        SDL_Quit();
        return -1;
    }

    // Create SDL renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        cerr << "Failed to create SDL renderer: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Initialize FMOD
    FMOD::System* system;
    FMOD::System_Create(&system);
    system->init(512, FMOD_INIT_NORMAL, nullptr);

    // Load a sound
    FMOD::Sound* sound;
    system->createSound("sound.wav", FMOD_3D, nullptr, &sound);

    // Set sound position
    FMOD::Channel* channel;
    system->playSound(sound, nullptr, true, &channel);
    FMOD_VECTOR soundPos = { 5.0f, 0.0f, 10.0f }; // Example position
    FMOD_VECTOR listenerPos = { 0.0f, 0.0f, 0.0f };
    FMOD_VECTOR listenerForward = { 0.0f, 0.0f, 1.0f };
    FMOD_VECTOR listenerUp = { 0.0f, 1.0f, 0.0f };
    channel->set3DAttributes(&soundPos, nullptr);
    system->set3DListenerAttributes(0, &listenerPos, nullptr, &listenerForward, &listenerUp);
    channel->setPaused(false);

    // Main loop
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // Update FMOD
        system->update();

        // Get sound direction
        FMOD_VECTOR relativePos;
        relativePos.x = soundPos.x - listenerPos.x;
        relativePos.y = soundPos.y - listenerPos.y;
        relativePos.z = soundPos.z - listenerPos.z;

        // Map direction to screen
        int screenX, screenY;
        mapDirectionToScreen(relativePos.x, relativePos.y, relativePos.z, 800, 600, screenX, screenY);

        // Render overlay
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderLine(renderer, 400, 300, screenX, screenY); // Draw line from center to sound direction

        SDL_RenderPresent(renderer);
    }

    // Cleanup
    sound->release();
    system->close();
    system->release();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
*/