#include "arrowoverlay.ih"

    // by

void ArrowOverlay::configureWindow() 
{
    // Make window transparent
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    SDL_GetWindowWMInfo(d_window, &wmInfo);
    HWND hwnd = wmInfo.info.win.window;
    
    // Set the window as topmost
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    
    // Set layered and transparent
    LONG exStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
    SetWindowLong(hwnd, GWL_EXSTYLE, exStyle | WS_EX_LAYERED | WS_EX_TRANSPARENT);

    // Set the color key and alpha (0 = fully transparent)
    SetLayeredWindowAttributes(hwnd, RGB(0,0,0), 0, LWA_COLORKEY);
}