#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <fstream>
#include "TextureManager.h"
#include "Object.h"
#include "TextObject.h"
#include "player.h"
#include "Background.h"
#include "ground.h"
#include "trees.h"
#include "birdAttack.h"
#include "Carrot.h"
#include "Button.h"
#include "menu.h"
#include "jumpingDust.h"
using namespace std;

class GameLoop
{
private:
    //for Dust
    Dust jumpDust;
    //for bird
    Bird chim;
    //for Player
    Player p;
    Background b;
    static const int PLAYER_HEIGHT = 513;
    static const int PLAYER_WIDTH = 486;
    //for Ground
    bool touchGround = false;
    ground Ground1;
    static const int GROUND_WIDTH = 612;
    static const int GROUND_HEIGHT = 207;
    //for obstacle
    Trees tree[3];
    Trees treeUp[2];
    const int space = 140;
    //for carrot
    Carrot carrot[3];
    bool eat_carrot1, eat_carrot2,  eat_carrot3;
    bool takePoint1 = true;
    bool takePoint2;
    bool takePoint3;
    //for Text
    TTF_Font* scoreFont;
    TTF_Font* scoreOutline;
    TTF_Font* hsFont;
    TTF_Font* hsOutline;
    TTF_Font* PAUSEfont;
    TextObject s;
    TextObject s_outline;
    TextObject hs;
    TextObject hs_outline;
    TextObject PAUSE;
    int best = 0;
    int best2 = 0;
    int TextWidth = 45;
    int TextHeight = 55;
    SDL_Color white = {250, 250, 250}; //colorecode
    SDL_Color brown = {94, 54, 67};
    SDL_Color black = {0, 0, 0, 0};
    unsigned int score = 0;
    unsigned int SCORE = 0;
    int fontSize;
    string display1;
    string display2;
    //for button
    Button pause_button;
    Button start_button;
    Button replay;
    Button back_to_menu;
    Button record;
    Button Options;
    Button Exit;
    Button creadit;
    Button increase;
    Button decrease;
    Button audioButton[2];
    Button quitMenu;
    bool opencreadit = false;
    bool comein = false;
    bool open_option = false;
    //for menu
    Menu when_start;
    Menu poster;
    Menu endgame[2];
    Menu Creadit;
    Menu optionBar;
    Menu pause_menu;
    //for sound
    Mix_Music* backgroundSound;
    Mix_Music* windSound;
    Mix_Music* Playingmusic;
    Mix_Chunk* clickSound;
    Mix_Chunk* jumpSound;
    Mix_Chunk* eatingSound;
    Mix_Chunk* flyingBird;
    Mix_Chunk* fallSound;
    Mix_Chunk* hitSound;
    bool muteMusic = false;
    bool muteSOund = false;
    //for game
    int game_speed = 1;
    int bird_speed = 3;
    string difficulties[2] = {"Easy", "Hard"};
    int i = 0;
    bool jump;
    bool click = false;
    bool pause = false;
    bool start = false;
    bool touch;
    bool Initfly = false;
    bool PlaySound = true;
    bool back;
    bool GameState;
    const int HEIGHT = 640;
    const int WIDTH = 612;
    SDL_Event event1;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect srcPlayer, destPlayer;
public:
    GameLoop();
    void Initialize();
    void Event();
    void updateButton();
    bool GetGameState();
    void Render();
    void Clear();
    void Update();
    bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
    void CollisionDetection();
    void NewGame();
    void AudioPlay();
};