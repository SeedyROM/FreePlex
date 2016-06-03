//
//  Sprite.h
//  FreePlex
//
//  Created by Zack Kollar on 5/31/16.
//  Copyright © 2016 Mutex12. All rights reserved.
//

#pragma once

#include <SDL2/SDL.h>

struct _Sprite {
    SDL_Rect source;
    SDL_Rect position;
    SDL_Surface *surface;
};
typedef struct _Sprite Sprite;

Sprite Sprite_BMP(const char* filename);
void Sprite_Render(SDL_Context *_SDL, Sprite* _sprite);
void Sprite_Free(Sprite* _sprite);