#include "player.h"
#include <iostream>

void Player::Render(SDL_Renderer* ren, bool pause)
{
    animationSpeed = SDL_GetTicks64() / 100;
    frames = animationSpeed % 6;
    if(!pause)
        setSource(Playerindex[frames], 0, PLAYER_WIDTH, PLAYER_HEIGHT);
    SDL_RenderCopy(ren, getTexture(), &GetSrc(), &GetDest());  
}

void Player::Render2(SDL_Renderer* ren, bool jump, bool hit_ground, bool hit)
{
    if(jump)
        setSource(0, 513, 486, 513);
    else if(hit_ground)
        setSource(972, 513, 486, 513);
    else if(hit)
        setSource(486, 513, 486, 513);
    SDL_RenderCopy(ren, getTexture(), &GetSrc(), &GetDest());
}

void Player::Gravity(bool pause, bool start)
{
    if(!start)
        setDest(10, Ypos, 180, 207);
    else{
        if(!pause){
            if(JumpState())
            {
                speed = JumpHeight;
                inJump = false;
            }
            Ypos += speed / 3.55;
            speed += g/1.5;
            setDest(10, Ypos, 180, 207);
            //std::cout << Ypos << std::endl;
        }
    }
}

void Player::Jump()
{
    if(jumpTimer - LastJump >= 165)
    {
        inJump = true;
        LastJump = jumpTimer;
    }
    else{
        inJump = false  ;
    }
}

void Player::GetJumpTime()
{
    jumpTimer = SDL_GetTicks64();
}

bool Player::JumpState()
{
    return inJump;
}

double Player::ReturnYpos(){
    return Ypos;
}

SDL_Rect& Player::Return_hitbox(){
    hitbox.x = 73 + 10;
    hitbox.y = Ypos + 70;
    hitbox.w = whitbox;
    hitbox.h = hhitbox;
    //std::cout << hitbox.y << std::endl;

    return hitbox;
}

void Player::setYpos(double i){
    Ypos = i;
}
