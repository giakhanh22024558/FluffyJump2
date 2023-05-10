#include "GameLoop.h"

GameLoop* g = new GameLoop();



int main(int argc, char* args[]){
    double firstframe;
    double lastframe = 0;
    Mix_OpenAudio(48000, AUDIO_S16SYS, 2, 2048);
    g->Initialize();
    while(g->GetGameState())
    {
        g->Event();
        g->Update();
        g->Render();
        g->CollisionDetection();
        firstframe = SDL_GetTicks64();
        //limit frame <= 60 fps
        if(firstframe - lastframe < 16.7)
        {
            SDL_Delay(16.7 - (firstframe - lastframe));
        }
        lastframe = firstframe;
    }
    g->Clear();
    return 0;
}

