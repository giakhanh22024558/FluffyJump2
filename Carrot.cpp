#include "Carrot.h"

void Carrot::Render(SDL_Renderer* ren, bool pause)
{
    animationSpeed = SDL_GetTicks64() / 200;
    frames = animationSpeed % 4;
    if(!pause)
        setSource(Carrotindex[frames], 0, 90, 90); 
    SDL_RenderCopy(ren, getTexture(), &GetSrc() , &GetDest());
}

SDL_Rect& Carrot::Return_hitbox(int x_motion, int y)
{
    hitbox.x = x_motion + 50;
    hitbox.y = y;
    hitbox.w = 60;
    hitbox.h = 80;

    return hitbox;
}

