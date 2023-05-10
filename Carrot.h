#pragma once
#include "Object.h"

class Carrot : public Object
{
private:
    int Carrotindex[4] = {0, 90, 90*2, 90*3};
    int animationSpeed;
    int frames;
    SDL_Rect hitbox;
public:
    int motion_x;
    void Render(SDL_Renderer* ren, bool pause);
    SDL_Rect& Return_hitbox(int x_motion, int y);
};