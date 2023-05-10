#pragma once
#include "Object.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string.h>

using namespace std;

class TextObject : public Object
{

private:
    SDL_Texture* texture;
    SDL_Surface* textSurface;

public:
    TextObject();
    ~TextObject();
    TTF_Font* font;

    SDL_Texture* getTextTexture();
    void InitTTF();
    void WriteText(string text, TTF_Font* textFont, SDL_Color color, SDL_Renderer* ren);
    void Render(SDL_Renderer* ren);
};