//
//  Sprite.c
//  FreePlex
//
//  Created by Zack Kollar on 5/31/16.
//  Copyright © 2016 Mutex12. All rights reserved.
//

#include "Setup.h"
#include "Sprite.h"

Sprite Sprite_BMP(const char* filename) {
    Sprite sprite;
    
    sprite.surface = NULL;
    sprite.surface = SDL_LoadBMP(filename);
    
    if(sprite.surface == NULL) {
        fprintf(stderr, "Could not load BMP: %s", filename);
        exit(EXIT_FAILURE);
    }
    
    sprite.source.w = sprite.surface->w;
    sprite.source.h = sprite.surface->h;
    sprite.position.x = 0;
    sprite.position.y = 0;
    
    return sprite;
}

void Sprite_Render(SDL_Context *_SDL, Sprite* _sprite) {
    SDL_BlitSurface(_sprite->surface,
                    &_sprite->source,
                    _SDL->screen_surface,
                    &_sprite->position);
    
}

void Sprite_Free(Sprite* _sprite) {
    SDL_FreeSurface(_sprite->surface);
    _sprite->surface = NULL;
}