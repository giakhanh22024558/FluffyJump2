#include "jumpingDust.h"
#include <iostream>

void Dust::Render(SDL_Renderer* ren, SDL_Rect hitbox, bool pause, bool &click)
{
    Timer += (SDL_GetTicks64() - animationTimer);
    animationTimer = SDL_GetTicks64();
    framesIndex = (Timer/65) % 7;
    if(!pause){
        setDest(hitbox.x - 10, hitbox.y + 10, 60, 80);
        setSource(frames[framesIndex], 0, 32, 32);
    }
    if(framesIndex == 6){
        click = false;
    }
    SDL_RenderCopy(ren, getTexture(), &GetSrc() , &GetDest());
}

void Dust::InitRender()
{
    animationTimer = SDL_GetTicks64();
    Timer = 0;
    framesIndex = 0;
}

