#include "menu.h"

void Menu::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), &GetSrc() , &GetDest());
}