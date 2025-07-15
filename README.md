# Hearing-aid-overlay
Making a screen overlay to aid people with hearing trouble in where the direction of in-game sounds are coming from

Steps for SDL3:<br/>
• Install SDL3 and SDL_image (via vcpkg, package manager, or from source).
• Initialize SDL3 in the main() function.
• Load card images (e.g., "images/2H.png", "images/AS.png").
• Render cards and buttons using SDL_RenderCopy.
• Handle user input (mouse clicks, etc.) to let users pick cards or press buttons.
• Update the display as the game state changes.

For my upcoming hearing aid project I should look into sonic radar 2, a program that does exactly what I aim to do. Sonic is a built in windows 3d sound module that I should look into.



This video is a general tutorial for making simple C++ games I am going to be watching and hopefully using

https://www.youtube.com/watch?v=XOs2qynEmNE
