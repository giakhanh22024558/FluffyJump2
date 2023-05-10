#pragma once
#include "Object.h"

class Bird : public Object
{
private:
    //for animation
    int BirdindexFlying[8] = {0, 160, 160*2, 160*3, 160*4, 160*5, 160*6, 160*7};
    int BirdindexIdle[2] = {0, 160};
    int animationSpeed;
    int frames1;
    int frames2;
    Uint64 animationTimer;
    int Timer = 0;

    //for hitbox
    SDL_Rect hitbox;
public:
    double bird_motion;
    bool fly = false;
    double bird_Ypos;
    void Render(SDL_Renderer* ren, bool pause);
    void SetFlyAnimation(SDL_Renderer* ren, bool pause);
    void InitFly();
    SDL_Rect& Return_hitbox();
};