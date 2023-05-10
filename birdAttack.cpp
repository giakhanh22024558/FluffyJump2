#include "birdAttack.h"
#include <iostream>

void Bird::Render(SDL_Renderer* ren, bool pause)
{   
    animationSpeed = SDL_GetTicks64() / 180;
    frames1 = animationSpeed % 2;
    //if(frames<2)
    if(!pause)
        setSource(BirdindexIdle[frames1], 0, 160, 160);
    SDL_RenderCopy(ren, getTexture(), &GetSrc() , &GetDest());
}

void Bird::SetFlyAnimation(SDL_Renderer* ren, bool pause)
{
    Timer += (SDL_GetTicks64() - animationTimer);
    animationTimer = SDL_GetTicks64();
    frames2 = (Timer/65) % 8;
    if(!pause)
        setSource(BirdindexFlying[frames2], 160, 160, 160);
    SDL_RenderCopy(ren, getTexture(), &GetSrc() , &GetDest());
}

void Bird::InitFly()
{
    animationTimer = SDL_GetTicks64();
    Timer = 0;
    frames2 = 0;
}

SDL_Rect& Bird::Return_hitbox(){
    hitbox.x = bird_motion;
    hitbox.y = bird_Ypos;
    hitbox.w = 43;
    hitbox.h = 43;
    //std::cout << hitbox.y << std::endl;

    return hitbox;
}



