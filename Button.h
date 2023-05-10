#pragma once
#include "Object.h"

class Button : public Object
{
public:
    bool ButtonState = false;
    bool point;
    int x2;
    void RenderPause(SDL_Renderer* ren, bool pause, bool point);
    void RenderMenuButton(SDL_Renderer* ren);
    bool CheckClick(SDL_Rect button, int x, int y);
    void CheckPoint(SDL_Rect button, int x2, SDL_Rect buttonSrc, int x, int y);
    void updateButton(SDL_Rect button, bool click);
    bool ReturnButtonState();
};