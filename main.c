//
//  main.c
//  FreePlex
//
//  Created by Zack Kollar on 5/31/16.
//  Copyright © 2016 Mutex12. All rights reserved.
//

// Local includes:
#include "Macros.h"
#include "Setup.h"
#include "Sprite.h"

SDL_Surface *test_image = NULL;
Sprite sprite;

int main(int argc, char** args) {
    SDL_Context context;
    SDL_Wake(&context, 850, 400);
    
    sprite = Sprite_BMP("test.bmp");
    
    int old_time, current_time = 0;
    float frame_time;
    
    while(context.running) {
        SDL_ListenForStandardEvents(&context);
        
        old_time = current_time;
        current_time = SDL_GetTicks();
        frame_time = (current_time - old_time) / 1000.0f;
        
        SDL_FillRect(context.screen_surface, NULL,
                     SDL_MapRGB(context.screen_surface->format, 0xFF, 0xAA, 0x5F));
        
        sprite.position.x += (200 * frame_time);
        
        Sprite_Render(&context, &sprite);
        
        SDL_UpdateWindowSurface(context.window);
    }
    
    Sprite_Free(&sprite);
    
    SDL_Kill(&context);
    return 0;
}
