#include "trees.h"
#include <iostream>

void Trees::rand_ypos(int i){
    srand(time(NULL));
    tree_ypos[i] = (rand() % 19 + 21) * 10; // rand()%(max-min+1)+min
    tree_ypos[i] += (rand() % 2 == 0) ? 5 : -5; 
}

void Trees::rand_height(int i){
    tree_height[i] = 608 - tree_ypos[i] - 45;
    //std::cout << tree_height[i] << std::endl;
}

void Trees::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), &GetSrc() , &GetDest());
}

SDL_Rect& Trees::Return_hitbox(int i){
    hitbox.x = tree_motion[i] + 60;
    hitbox.y = tree_ypos[i] + 55;
    hitbox.w = 165 - 120;
    hitbox.h = tree_height[i];

    return hitbox;
}

SDL_Rect& Trees::Return_hitboxUp(int i)
{
    hitbox.x = tree_motion[i] + 60;
    hitbox.y = tree_yposUp[i] - 10;
    hitbox.w = 165 - 120;
    hitbox.h = 400;

    return hitbox;
}

void Trees::Get_scale(int i, int y, int x)
{
    tree_yposUp[i] = y;
    tree_motion[i] = x;
}

void Trees::tree_updateX(int i, int game_speed, bool pause, bool start){
    if(!pause&&start)
        tree_motion[i]-=game_speed;
}