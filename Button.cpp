#include "Button.h"
#include <iostream>

void Button::RenderPause(SDL_Renderer* ren, bool pause, bool point)
{
    if(!pause && !ReturnButtonState()){
        setDest(550, 10, 58, 62);
        setSource(36, 261, 58, 62);
        if(point)
            setSource(36 + 497, 261, 58, 62);
    }
    else if(pause && !ReturnButtonState()){
        setDest(330, 270, 58, 62);
        setSource(102, 261, 60, 61);
        if(point)
            setSource(102 + 497, 261, 60, 62);
    }
    SDL_RenderCopy(ren, getTexture(), &GetSrc() , &GetDest());
}

void Button::RenderMenuButton(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), &GetSrc(), &GetDest());
}

bool Button::CheckClick(SDL_Rect button, int x, int y)
{
    if(x > button.x && x < button.x + button.w && y > button.y && y < button.y + button.h){
        return true;
    }
    return false;
}

void Button::CheckPoint(SDL_Rect button, int x2, SDL_Rect buttonSrc, int x, int y)
{
    if(CheckClick(button, x, y)){
        setSource(x2 + 497, buttonSrc.y, buttonSrc.w, buttonSrc.h);
    }
    else{
        setSource(x2, buttonSrc.y, buttonSrc.w, buttonSrc.h);
    }
}

bool Button::ReturnButtonState()
{
    return ButtonState;
}
