#pragma once
#include "Object.h"
#include "time.h"

static int xPos[3]; //distance among trees

class Trees: public Object
{
private:
    SDL_Rect hitbox;
public:
    const int space = 130;
    int tree_motion[3] = {700, 950, 1200}; // distance = 250
    int tree_ypos[3] = {380, 360, 340};
    int tree_height[3] = {183, 203, 223};
    int tree_yposUp[2];
    int tree_heightUp[2];
    void Render(SDL_Renderer* ren);
    SDL_Rect& Return_hitbox(int i);
    SDL_Rect& Return_hitboxUp(int i);
    void Get_scale(int i, int width, int x);
    void rand_ypos(int i);
    void rand_height(int i);
    void tree_updateX(int i, int game_speed, bool pause, bool start);
};