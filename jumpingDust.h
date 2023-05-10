#pragma once
#include "Object.h"

class Dust : public Object
{
private:
    int animationSpeed;
    int framesIndex;
    Uint64 animationTimer;
    int Timer = 0;
    int frames[6] = {0, 32, 32 * 2, 32 * 3, 32 * 4, 32 * 5};
public:
    void Render(SDL_Renderer* ren, SDL_Rect hitbox, bool pause, bool &click);
    void InitRender();
};