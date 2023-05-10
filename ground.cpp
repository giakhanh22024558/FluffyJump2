#include "ground.h"

void ground::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), &GetSrc() , &GetDest());
}

SDL_Rect& ground::Return_hitbox(){
    hitbox.x = 0;
    hitbox.y = 608;
    hitbox.w = 612;
    hitbox.h = 30;

    return hitbox;
}