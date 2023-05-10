#pragma once
#include "Object.h"

class ground : public Object
{
private:
    SDL_Rect hitbox;
public:
    int motion_x;
    int motion_x2;
    void Render(SDL_Renderer* ren);
    SDL_Rect& Return_hitbox();
};