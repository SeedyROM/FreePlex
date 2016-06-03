//
//  Setup.h
//  FreePlex
//
//  Created by Zack Kollar on 5/31/16.
//  Copyright © 2016 Mutex12. All rights reserved.
//

#pragma once

// Standard library stuff.
#include <stdio.h>
#include <stdlib.h>

// Use SDL2.
#include <SDL2/SDL.h>

// Struct to simplify SDL calls and scope.
struct _SDL_Context {
    int running;
    int height, width;
    SDL_Window *window;
    SDL_Surface *screen_surface;
    SDL_Event current_event;
    //Timer globalTimer;
};
typedef struct _SDL_Context SDL_Context;

void SDL_Wake(SDL_Context *_SDL, int _width, int _height);
void SDL_ListenForStandardEvents(SDL_Context *_SDL);
void SDL_Kill(SDL_Context *_SDL);