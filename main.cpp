#include "../include/SDL2/SDL.h"
#include "assets/cleanup.h"
#include "assets/res_path.h"
#include "assets/drawing_functions.h"
#include "../include/SDL2/SDL_mixer.h"
#include <iostream>

int main(int argv, char** args)
{
    // SDL2 Setup
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL Not initialized correctly" << endl;
        return 1;
    }
    // SDL2 Window
    // new window with (name, position [x,y], resolution [w,h], shown [fullscreen if wanted])
    SDL_Window *window = SDL_CreateWindow("Test Creation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cleanup(window);
        SDL_Quit();
        cout << "Error launching" << endl;
        return 1;
    }
    // Render set up
    // new render with (previous window, index, args)
    SDL_Renderer *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (render  == nullptr) {
        SDL_Quit();
        cout << "Render error" << endl;
        return 1;
    }
    // Set logical size --> regardless of screen size, fit particular size into a given dimension
    // before it is scaled
    SDL_RenderSetLogicalSize(render, 1920, 1080);

    // initialize image
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        SDL_Quit();
        cout << "SDL could not load image" << endl;
        return 1;
    }
    // Text to font initialization (output strings as font)
    if (TTF_Init() != 0) {
        SDL_Quit();
        cout << "TTF failure" << endl;
        return 1;
    }
    // SDL mixer (frequency, formal, channel, chunksize)
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        SDL_Quit();
        cout << "Mixer failed" << endl;
        return 1;
    }

    // Load up drawing texture
    string resPath = getResourcePath();
    // using renderer and image file
    SDL_Texture* txture = loadTexture(resPath+ "map.png", render);

    // runtime
    while (SDL_GetTicks() < 10000) {
        // clear screen
        SDL_RenderClear(render);
        // draw
        renderTexture(txture, render, 0, 0); // 0,0 is top left
        // show render
        SDL_RenderPresent(render);
    } 
    cleanup(render);
    cleanup(window);
    cleanup(txture);
    SDL_Quit();
    return 0;

}