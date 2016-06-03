//
//  Setup.c
//  FreePlex
//
//  Created by Zack Kollar on 5/31/16.
//  Copyright © 2016 Mutex12. All rights reserved.
//

#include "Macros.h"
#include "Setup.h"

// Start SDL and check for errors...
void SDL_Wake(SDL_Context *_SDL, int _width, int _height) {
    _SDL->running = TRUE;
    
    // Check if we can initialize SDL properly.
    if(SDL_Init( SDL_INIT_VIDEO ) < 0) {
        fprintf(stderr, "SDL could not initialize! Error: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    // Create an SDL window.
    _SDL->width = _width;
    _SDL->height = _height;
    _SDL->window = SDL_CreateWindow(WINDOW_NAME,
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    _SDL->width, _SDL->height, SDL_WINDOW_SHOWN);
    
    // Verify the window was created.
    if(_SDL->window == NULL) {
        fprintf(stderr, "SDL_Window could not be created! Error: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    // Get the surface from the created window.
    _SDL->screen_surface = SDL_GetWindowSurface(_SDL->window);
}

void SDL_ListenForStandardEvents(SDL_Context *_SDL) {
    while(SDL_PollEvent(&_SDL->current_event) != 0) {
        if(_SDL->current_event.type == SDL_QUIT) {
            _SDL->running = FALSE;
        }
    }
}

void SDL_Kill(SDL_Context *_SDL) {
    SDL_DestroyWindow(_SDL->window);
    SDL_Quit();
    _SDL = NULL;
}