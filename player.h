#pragma once
#include "Object.h"

class Player : public Object
{
private:
    static const int PLAYER_HEIGHT = 513;
    static const int PLAYER_WIDTH = 486;
    //for jumping
    //for animation
    int Playerindex[6] = {0, 486, 486*2, 486*3, 486*4, 486*5};
    int animationSpeed;
    int frames;
    //for hitbox
    SDL_Rect hitbox;
public:
    double g = 0.5;
    double speed = 0;
    bool inJump = false;
    double Ypos = 120;
    int whitbox = 180 - 140;
    int hhitbox = 207 - 147;
    int xhitbox = 73 + 10;
    double JumpHeight = -13.5;
    double jumpTimer;
    double LastJump = 0;
    void Gravity(bool pause, bool start);
    void GetJumpTime();
    void Jump();
    bool JumpState();
    void Render(SDL_Renderer* ren, bool pause);
    void Render2(SDL_Renderer* ren, bool jump, bool hit_ground, bool hit);
    SDL_Rect& Return_hitbox();
    void setYpos(double i);
    double ReturnYpos();
};