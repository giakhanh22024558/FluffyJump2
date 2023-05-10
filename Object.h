#pragma once
#include <SDL2/SDL.h>
#include "TextureManager.h"

class Object
{
private:
    SDL_Rect src, dest;
    SDL_Texture* Tex;
public:
    Object();
    SDL_Texture* getTexture();
    SDL_Rect& GetSrc();
    SDL_Rect& GetDest();
    void setSource(int x, int y, int w, int h);
    void setDest(int x, int y, int w, int h);
    void CreateTexture(const char* address, SDL_Renderer* ren);
};