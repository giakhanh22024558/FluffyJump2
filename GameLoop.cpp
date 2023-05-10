#include "GameLoop.h"

GameLoop::GameLoop()
{
    window = NULL;
    renderer = NULL;
    GameState = false;

    // p.setSource(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT);
    // p.setDest(0, 0, 180, 207);

    Ground1.setSource(0, 0, 1224, 367);
    Ground1.setDest(0, 460, 1224, 207);
    Ground1.motion_x = 0;

    when_start.setSource(0, 0, 843, 94);
    when_start.setDest(150, 250, 300, 60);

    for (int i = 0; i < 3; i++)
        tree[i].setSource(0, 0, 165, 400);
    for (int i = 0; i < 2; i++)
        treeUp[i].setSource(0, 0, 165, 400);

    chim.setSource(0, 160, 1280, 160);

    b.setSource(0, 0, 612, 850);
    b.setDest(0, -30, 612, 850);

    pause_button.setSource(36, 261, 58, 62);
    pause_button.setDest(550, 10, 58, 62);


    start_button.setSource(261, 146, 204, 57);
    start_button.setDest(400, 330, 204, 57);
    replay.setSource(36, 356, 58, 62);
    replay.setDest(270, 270, 58, 62);
    back_to_menu.setSource(103, 355, 60, 63);
    back_to_menu.setDest(210, 270, 58, 62);
    //record.setSource(103, 167, 58, 62);
    //record.setDest(330, 270, 58, 62);
    Options.setSource(261, 219, 203, 57);
    Options.setDest(400, 397, 203, 57);
    Exit.setSource(260, 292, 203, 57);
    Exit.setDest(400, 464, 203, 57);
    creadit.setSource(176, 259, 60, 63);
    creadit.setDest(10, 570, 60, 63);
    increase.setSource(35, 78, 58, 62);
    decrease.setSource(103, 78, 58, 62);
    increase.setDest(500, 200, 58, 62);
    decrease.setDest(200, 200, 58, 62);
    quitMenu.setSource(176, 166, 58, 62);
    quitMenu.setDest(50, 50, 58, 62);

    poster.setSource(0, 0, WIDTH, HEIGHT);
    poster.setDest(0, 0, WIDTH, HEIGHT);
    pause_menu.setSource(0, 0, WIDTH, HEIGHT);
    pause_menu.setDest(0, 0, WIDTH, HEIGHT);
    Creadit.setSource(0, 0, 1104, 852);
    Creadit.setDest(90 - 20, 120 - 20, 449 + 40, 425 + 40);
    for(int i = 0; i < 2; i++){
        endgame[i].setSource(0, 0, 587, 425);
        endgame[i].setDest(60, 80, 506, 373);
    }
    optionBar.setSource(0, 0, 678, 636);
    optionBar.setDest(10, 10, 600, 558);
    for(int i = 0; i < 2; i++)
        audioButton[i].setSource(1, 1, 203, 97);
    audioButton[0].setDest(200, 310, 203, 97);
    audioButton[1].setDest(200, 440, 203, 97);
    
    s.setDest(280, 10, TextWidth, TextHeight);
    s_outline.setDest(280, 10, TextWidth - 4, TextHeight);
    hs.setDest(440, 350, TextWidth, TextHeight);
    hs_outline.setDest(440, 350, TextWidth - 4, TextHeight);
    PAUSE.setDest(215, 210, 58*3, 62);
    fontSize = 36;

    for (int i = 0; i < 3; i++)
        carrot[i].setSource(0, 0, 90, 90);

    display2 = difficulties[0];
}

bool GameLoop::GetGameState()
{
    return GameState;
}

void GameLoop::Initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Fluffy Jump!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (window)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            cout << "Succeeded!";
            GameState = true;
            p.CreateTexture("image/player1_everything.png", renderer);

            SDL_Surface* icon = IMG_Load("image/icon.png");
            SDL_SetWindowIcon(window, icon);
            SDL_FreeSurface(icon);

            pause_button.CreateTexture("image/buttons-set2.png", renderer);
            start_button.CreateTexture("image/buttons-set2.png", renderer);
            Options.CreateTexture("image/buttons-set2.png", renderer);
            replay.CreateTexture("image/buttons-set2.png", renderer);
            back_to_menu.CreateTexture("image/buttons-set2.png", renderer);
            record.CreateTexture("image/buttons-set2.png", renderer);
            Exit.CreateTexture("image/buttons-set2.png", renderer);
            creadit.CreateTexture("image/buttons-set2.png", renderer);
            increase.CreateTexture("image/buttons-set2.png", renderer);
            decrease.CreateTexture("image/buttons-set2.png", renderer);
            quitMenu.CreateTexture("image/buttons-set2.png", renderer);

            Creadit.CreateTexture("image/GameCreadit2.png", renderer);
            poster.CreateTexture("image/game_menu_poster2.png", renderer);
            pause_menu.CreateTexture("image/pause_menu.png", renderer);
            when_start.CreateTexture("image/press_to_start.png", renderer);
            endgame[0].CreateTexture("image/endgamemenu.png", renderer);
            endgame[1].CreateTexture("image/endgamemenu2.png", renderer);
            jumpDust.CreateTexture("image/jumpDust.png", renderer);
            optionBar.CreateTexture("image/Option.png", renderer);
            for(int i = 0; i < 2; i++)
                audioButton[i].CreateTexture("image/switches.png", renderer);

            Ground1.CreateTexture("image/ground.png", renderer);
            chim.CreateTexture("image/BirdSpriteBig.png", renderer);
            for (int i = 0; i < 3; i++)
                tree[i].CreateTexture("image/tree2.0.1.png", renderer);
            for (int i = 0; i < 2; i++)
                treeUp[i].CreateTexture("image/tree2.0.1Up.png", renderer);
            for (int i = 0; i < 3; i++)
                carrot[i].CreateTexture("image/carrot.png", renderer);
            b.CreateTexture("image/background.png", renderer);
        }
        else
        {
            cout << "Not created!";
        }
    }
    else
    {
        cout << "window failed to init!" << SDL_GetError();
    }

    if (TTF_Init() < 0)
    {
        cout << "Text could not initialize! Text_Error: " << TTF_GetError() << endl;
    }
    else
    {
        scoreFont = TTF_OpenFont("TextFont/flappy-font.TTF", fontSize);
        scoreOutline = TTF_OpenFont("TextFont/flappy-font.TTF", fontSize);
        hsFont = TTF_OpenFont("TextFont/flappy-font.TTF", fontSize);
        hsOutline = TTF_OpenFont("TextFont/flappy-font.TTF", fontSize);

        PAUSEfont = TTF_OpenFont("TextFont/flappy-font.TTF", fontSize);
        TTF_SetFontOutline(scoreOutline, 0);
    }
    if(Mix_Init(1)==0)
    {
        cout << "Sound can not initilize!" << Mix_GetError() << endl;
    }
    else
    {
        Mix_AllocateChannels(6);
        backgroundSound = Mix_LoadMUS("sound/bgmusic.mp3");
        clickSound = Mix_LoadWAV("sound/clickingsound.wav");
        windSound = Mix_LoadMUS("sound/wind.mp3");
        jumpSound = Mix_LoadWAV("sound/jumpingSound.wav");
        eatingSound = Mix_LoadWAV("sound/eatingSound.wav");
        flyingBird = Mix_LoadWAV("sound/birdSound.wav");
        fallSound = Mix_LoadWAV("sound/squeakySound.wav");
        hitSound = Mix_LoadWAV("sound/hitSound.wav");
        Playingmusic = Mix_LoadMUS("sound/Playingmusic.mp3");
        AudioPlay();
    }
    ifstream file("highscore.txt");
    ifstream file2("highscore(hard).txt");
    if(!file.is_open() || !file2.is_open())
    {
        cout << "unable to open file!";
    }
    else
    {
        file.close();
    }
}

void GameLoop::Event()
{
    p.GetJumpTime();
    SDL_PollEvent(&event1);
    if (event1.type == SDL_QUIT)
    {
        GameState = false;
    }
    //handle mouse input
    if(event1.type == SDL_MOUSEBUTTONUP){
        if(creadit.ReturnButtonState() && !comein)
        {
            //SDL_Delay(100);
            creadit.ButtonState = false;
            creadit.setDest(10, 570, 60, 63);
        }
        if(Exit.CheckClick(Exit.GetDest(), event1.motion.x, event1.motion.y) && !comein && !opencreadit)
        {
            Exit.setDest(400, 464, 203, 57);
        }
        if(start_button.ReturnButtonState() && !opencreadit)
        {
            start_button.setDest(400, 330, 204, 57);
            comein = true;
            AudioPlay();
            start_button.ButtonState = false;
        }
        if(Options.ReturnButtonState() && !opencreadit)
        {
            Options.setDest(400, 397, 203, 57);
            open_option = true;
            Options.ButtonState = false;
        }
        if
        (
            (back_to_menu.ReturnButtonState() && touchGround) ||
            (back_to_menu.ReturnButtonState() && comein && pause)
        )
        {
            if(!touchGround)
                back_to_menu.setDest(210, 270, 58, 62);
            back_to_menu.ButtonState = false;
            comein = false;
            start = false;
            AudioPlay();
            NewGame();
        }
        if
        (
            (replay.ReturnButtonState() && comein && pause) ||
            (replay.ReturnButtonState() && touchGround)
        )
        {
            if(!touchGround)
                replay.setDest(270, 270, 58, 62);
            replay.ButtonState = false;
            NewGame();
        }
        if(pause_button.ReturnButtonState() && comein && !touchGround && start)
        {
            if(!pause){
                pause_button.setDest(550, 10, 58, 62);
                pause = true;
                Mix_Pause(2);
                Mix_PauseMusic();
            }
            else if(pause){
                pause_button.setDest(330, 270 , 58, 62);
                pause = false;
                if(!muteSOund)
                    Mix_Resume(2);
                Mix_ResumeMusic();
            }
            pause_button.ButtonState = false;
            pause_button.point = false;
        }
        if(increase.ReturnButtonState() && open_option)
        {
            increase.ButtonState = false;
            increase.setDest(500, 200, 58, 62);
            if(i < 1) i++;
            display2 = difficulties[i];
        }
        if(decrease.ReturnButtonState() && open_option)
        {
            decrease.ButtonState = false;
            decrease.setDest(200, 200, 58, 62);
            if(i > 0) i--;
            display2 = difficulties[i];
        }
        if(quitMenu.ReturnButtonState() && open_option)
        {
            quitMenu.ButtonState = false;
            quitMenu.setDest(50, 50, 58, 62);
            open_option = false;
        }
    }
    if(event1.type ==SDL_MOUSEBUTTONDOWN)
    {
        if(pause_button.CheckClick(pause_button.GetDest(), event1.motion.x, event1.motion.y) && comein && !touchGround)
        {
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
            if(!pause ){
                pause_button.ButtonState = true;
                pause_button.setDest(550 + 5, 10 + 5, 58 - 10, 62 - 10);
            }
            if(pause){
                pause_button.ButtonState = true;
                pause_button.setDest(330 + 5, 270 + 5, 58 - 10, 62 - 10);
            }
        }
        if
        (
            (replay.CheckClick(replay.GetDest(), event1.motion.x, event1.motion.y) && comein && pause) ||
            (replay.CheckClick(replay.GetDest(), event1.motion.x, event1.motion.y)&& touchGround)
        )
        {
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
            if(!touchGround){
                replay.ButtonState = true;
                replay.setDest(270 + 5, 270 + 5, 58 - 10, 62 - 10);
            }
            if(touchGround){
                replay.setDest(220 + 5, 420 + 5, 58 - 10, 62 - 10);
                replay.ButtonState = true;
            }
        }
        if
        (
            (back_to_menu.CheckClick(back_to_menu.GetDest(), event1.motion.x, event1.motion.y) && touchGround) ||
            (back_to_menu.CheckClick(back_to_menu.GetDest(), event1.motion.x, event1.motion.y) && comein && pause)
        )
        {
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
            if(!touchGround){
                back_to_menu.ButtonState = true;
                back_to_menu.setDest(210 + 5, 270 + 5, 58 - 10, 62 - 10);
            }
            if(touchGround){
                back_to_menu.ButtonState = true;
                back_to_menu.setDest(160 + 5, 420 + 5, 58 - 10, 62 - 10);
            }
        }
        if(start_button.CheckClick(start_button.GetDest(), event1.motion.x, event1.motion.y) && !comein && !opencreadit && !open_option)
        {
            start_button.ButtonState = true;
            start_button.setDest(400 + 5, 330 + 5, 204 - 10, 57 - 10);
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
        }
        if(Exit.CheckClick(Exit.GetDest(), event1.motion.x, event1.motion.y) && !comein && !opencreadit && !open_option)
        {
            Exit.setDest(400 + 5, 464 + 5, 203 - 10, 57 - 10);
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
            SDL_Delay(200);
            GameState = false;
        }
        if(Options.CheckClick(Options.GetDest(), event1.motion.x, event1.motion.y) && !comein && !opencreadit && !open_option)
        {
            Options.ButtonState = true;
            Options.setDest(400 + 5, 397 + 5, 203 - 10, 57 - 10);
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
        }
        if(creadit.CheckClick(creadit.GetDest(), event1.motion.x, event1.motion.y) && !comein && !open_option)
        {
            creadit.setDest(10 + 5, 570 + 5, 60 - 10, 63 - 10);
            creadit.ButtonState = true;
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
            if(!opencreadit) opencreadit = true;
            else if(opencreadit) opencreadit = false;
        }
        if(increase.CheckClick(increase.GetDest(), event1.motion.x, event1.motion.y) && open_option)
        {
            increase.setDest(500 + 5, 200 + 5, 58 - 10, 62 - 10);
            increase.ButtonState = true;
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
        }
        if(decrease.CheckClick(decrease.GetDest(), event1.motion.x, event1.motion.y) && open_option)
        {
            decrease.setDest(200 + 5, 200 + 5, 58 - 10, 62 - 10);
            decrease.ButtonState = true;
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
        }
        if(audioButton[0].CheckClick(audioButton[0].GetDest(), event1.motion.x, event1.motion.y) && open_option)
        {
            if(!muteMusic){
                muteMusic = true;
                audioButton[0].setSource(226, 1, 203, 97);
                AudioPlay();
            }
            else if(muteMusic){
                muteMusic = false;
                audioButton[0].setSource(1, 1, 203, 97);
                AudioPlay();
            }
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
        }
        if(audioButton[1].CheckClick(audioButton[1].GetDest(), event1.motion.x, event1.motion.y) && open_option)
        {
            if(!muteSOund){
                muteSOund = true;
                audioButton[1].setSource(226, 1, 203, 97);
            }
            else if(muteSOund){
                muteSOund = false;
                audioButton[1].setSource(1, 1, 203, 97);
            }
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
        }
        if(quitMenu.CheckClick(quitMenu.GetDest(), event1.motion.x, event1.motion.y) && open_option)
        {
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
            quitMenu.setDest(50 + 5, 50 + 5, 58 - 10, 62 - 10);
            quitMenu.ButtonState = true;
        }
    }
    if(event1.type == SDL_MOUSEMOTION)
    {
        if(!opencreadit && !open_option){
            start_button.CheckPoint(start_button.GetDest(), 261, start_button.GetSrc(), event1.motion.x, event1.motion.y);
            Exit.CheckPoint(Exit.GetDest(), 260, Exit.GetSrc(), event1.motion.x, event1.motion.y);
            Options.CheckPoint(Options.GetDest(), 261, Options.GetSrc(), event1.motion.x, event1.motion.y);
        }
        back_to_menu.CheckPoint(back_to_menu.GetDest(), 103, back_to_menu.GetSrc(), event1.motion.x, event1.motion.y);
        replay.CheckPoint(replay.GetDest(), 36, replay.GetSrc(), event1.motion.x, event1.motion.y);
        if(!open_option)
            creadit.CheckPoint(creadit.GetDest(), 176, creadit.GetSrc(), event1.motion.x, event1.motion.y);
        if(open_option){
            increase.CheckPoint(increase.GetDest(), 35, increase.GetSrc(), event1.motion.x, event1.motion.y);
            decrease.CheckPoint(decrease.GetDest(), 103, decrease.GetSrc(), event1.motion.x, event1.motion.y);
            quitMenu.CheckPoint(quitMenu.GetDest(), 176, quitMenu.GetSrc(), event1.motion.x, event1.motion.y);
        }
        if(pause_button.CheckClick(pause_button.GetDest(), event1.motion.x, event1.motion.y)){
            pause_button.point = true;
        }
        else pause_button.point = false;
    }
    //handle keyboard input
    if (event1.type == SDL_KEYDOWN && comein)
    {
        if (event1.key.keysym.sym == SDLK_SPACE && !touch && !touchGround && !pause)
        {
            if (!touch && !p.JumpState() && p.ReturnYpos() > -100)
            {
                p.Jump();
                click = true;
                jump = true;
                if(!start)
                    start = true;
                Mix_VolumeChunk(jumpSound, 20);
                if(!muteSOund)
                    Mix_PlayChannel(1, jumpSound, 0);
            }
        }
        /*if (event1.key.keysym.sym == SDLK_r && (touchGround||pause))
        {
            NewGame();
        }*/
        if(event1.key.keysym.sym == SDLK_p && !touchGround && comein && start)
        {
            if(!muteSOund)
                Mix_PlayChannel(0, clickSound, 0);
            if(!pause){
                pause_button.setDest(550, 10, 58, 62);
                pause = true;
                Mix_Pause(2);
                Mix_PauseMusic();
            }
            else if(pause){
                pause_button.setDest(330, 270 , 58, 62);
                pause = false;
                if(!muteSOund)
                    Mix_Resume(2);
                Mix_ResumeMusic();
            }
        }
    }
    if (touch || touchGround)
    {
        game_speed = 0;
        p.Gravity(pause, start);
    }
    if (event1.type == SDL_KEYUP)
    {
        if (event1.key.keysym.sym == SDLK_SPACE)
            jump = false;
    }
    else
    {
        p.Gravity(pause, start);
        if (touchGround)
        {
            p.speed = 0;
            p.g = 0;
            p.Ypos = 480;
            p.setDest(10, 480, 180, 207);
            AudioPlay();
        }
    }
}

void GameLoop::NewGame()
{
    if(!muteMusic)
        Mix_PlayMusic(Playingmusic, -1);
    game_speed = 1;
    pause = false;
    touch = false;
    jump = false;
    touchGround = false;
    Ground1.motion_x = 0;
    p.g = 0.5;
    p.speed = 0;
    p.Ypos = 120;
    p.inJump = false;
    p.LastJump = 0;
    // settree
    tree[0].tree_motion[0] = 700;
    tree[1].tree_motion[1] = 950;
    tree[2].tree_motion[2] = 1200;
    // set condition
    p.setDest(10, 10, 180, 207);
    eat_carrot1 = false;
    eat_carrot2 = false;
    eat_carrot3 = false;
    start = false;
    takePoint1 = true;
    TextWidth = 45;
    s.setDest(280, 10, TextWidth, TextHeight);
    s_outline.setDest(280, 10, TextWidth - 4, TextHeight);
    replay.setDest(270, 270, 58, 62);
    back_to_menu.setDest(210, 270, 58, 62);
    score = 0;
    PAUSE.setDest(215, 210, 58*3, 62);
    AudioPlay();
}

void GameLoop::Update()
{

    if(display2 == difficulties[1] && !touchGround){
        game_speed = 2;
        bird_speed = 4;
    }
    if(display2 == difficulties[0] && !touchGround){
        game_speed = 1;
        bird_speed = 3;
    }
    // update for ground ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(!pause)
        Ground1.motion_x -= game_speed;
    if (Ground1.motion_x <= -612)
        Ground1.motion_x = 0;
    Ground1.setDest(Ground1.motion_x, 460, 1224, 207);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // NOTE: 300 is the distance between two trees
    // update for obstacles ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if (tree[0].tree_motion[0] == -150)
    {
        tree[0].tree_motion[0] = tree[2].tree_motion[2] + 250;
        tree[0].rand_ypos(0);
        tree[0].rand_height(0);
        eat_carrot1 = false;
    }
    tree[0].setDest(tree[0].tree_motion[0], tree[0].tree_ypos[0] + 45, 165, 400);

    treeUp[0].setDest(tree[0].tree_motion[0], -(400 - (tree[0].tree_ypos[0] - space)), 165, 400);
    treeUp[0].Get_scale(0, -(400 - (tree[0].tree_ypos[0] - space)), tree[0].tree_motion[0]);

    carrot[0].setDest(tree[0].tree_motion[0] + 30, tree[0].tree_ypos[0] - 90, 90, 90);
    if (eat_carrot1)
        carrot[0].setDest(tree[0].tree_motion[0] + 30, tree[0].tree_ypos[0] - 90, 0, 0);

    tree[0].tree_updateX(0, game_speed, pause, start);

    if (tree[1].tree_motion[1] == -150)
    {
        tree[1].tree_motion[1] = tree[0].tree_motion[0] + 250;
        tree[1].rand_ypos(1);
        tree[1].rand_height(1);
        eat_carrot2 = false;
    }
    tree[1].setDest(tree[1].tree_motion[1], tree[1].tree_ypos[1] + 45, 165, 400);
    // 245 = height 380 = y
    carrot[1].setDest(tree[1].tree_motion[1] + 30, tree[1].tree_ypos[1] - 90, 90, 90);
    if (eat_carrot2)
        carrot[1].setDest(tree[1].tree_motion[1] + 30, tree[1].tree_ypos[1] - 90, 0, 0);

    tree[1].tree_updateX(1, game_speed, pause, start);

    if (tree[2].tree_motion[2] == -150)
    {
        tree[2].tree_motion[2] = tree[1].tree_motion[1] + 250;
        tree[2].rand_ypos(2);
        tree[2].rand_height(2);
        eat_carrot3 = false;
    }
    tree[2].setDest(tree[2].tree_motion[2], tree[2].tree_ypos[2] + 45, 165, 400);

    treeUp[1].setDest(tree[2].tree_motion[2], -(400 - (tree[2].tree_ypos[2] - space)), 165, 400);
    treeUp[1].Get_scale(1, -(400 - (tree[2].tree_ypos[2] - space)), tree[2].tree_motion[2]);

    carrot[2].setDest(tree[2].tree_motion[2] + 30, tree[2].tree_ypos[2] - 90, 90, 90);
    if (eat_carrot3)
        carrot[2].setDest(tree[2].tree_motion[2] + 30, tree[2].tree_ypos[2] - 90, 0, 0);

    tree[2].tree_updateX(2, game_speed, pause, start);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Update for second obstacle~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if (tree[2].tree_motion[2] < 500 && tree[2].tree_motion[2] != -150)
    {
        if (tree[2].tree_height[2] < tree[1].tree_height[1] && !pause)
        {
            if(!Initfly)
                Initfly = true;
            chim.fly = true;
            chim.bird_motion -= bird_speed;
            chim.bird_Ypos -= 1;
            chim.setDest(chim.bird_motion, chim.bird_Ypos, 43, 43);

        }
        if (tree[2].tree_height[2] > tree[1].tree_height[1] && !pause)
        {
            if(!Initfly)
                Initfly = true;
            chim.fly = true;
            chim.bird_motion -= bird_speed;
            chim.setDest(chim.bird_motion, chim.bird_Ypos, 43, 43);
        }
    }
    else
    {   
        Initfly = false;
        PlaySound = true;
        chim.fly = false;
        chim.InitFly();
        chim.bird_motion = tree[2].tree_motion[2] + 60;
        chim.bird_Ypos = tree[2].tree_ypos[2] + 5;
        chim.setDest(chim.bird_motion, chim.bird_Ypos, 43, 43);
    }
    if(Initfly && PlaySound && !muteSOund){
        Mix_PlayChannel(2, flyingBird, 0);
        if(touch || touchGround)
            Mix_HaltChannel(2);
        PlaySound = false;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //Update for Text~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    s.WriteText(to_string(score), scoreFont, brown, renderer);
    s_outline.WriteText(to_string(score), scoreOutline, white, renderer);
    if(score >= 10){
        TextWidth = 70;
        s.setDest(260, 10, TextWidth, TextHeight);
        s_outline.setDest(260, 10, TextWidth - 4, TextHeight);
    }
    if(touchGround){
        s.setDest(190, 280, TextWidth, TextHeight);
        s_outline.setDest(190, 280, TextWidth - 4, TextHeight);
        if(!replay.ReturnButtonState())
            replay.setDest(220, 420, 58, 62);
        if(!back_to_menu.ReturnButtonState())
            back_to_menu.setDest(160, 420, 58, 62);
    }
    if(pause){
        display1 = "PAUSE";
        PAUSE.setDest(210, 210, 58*3, 62);
        PAUSE.WriteText(display1, PAUSEfont, black, renderer);
    }
    if(open_option){
        display2 = difficulties[i];
        PAUSE.setDest(280, 200, 200, 62);
        PAUSE.WriteText(display2, PAUSEfont, black, renderer);
    }

    //Update for score~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(display2 == difficulties[0]){
        ifstream read("highscore.txt");
        read >> best;
        read.close();
        if(score > best){
            best = score;
            ofstream file("highscore.txt");
            file << score;
            file.close();
        }
        hs.WriteText(to_string(best), scoreFont, brown, renderer);
        hs_outline.WriteText(to_string(best), scoreFont, white, renderer);
        if(best >= 10){
            TextWidth = 70;
            hs.setDest(420, 350, TextWidth, TextHeight);
            hs_outline.setDest(420, 350, TextWidth - 4, TextHeight);
        }
    }
    if(display2 == difficulties[1]){
         ifstream read("highscore(hard).txt");
        read >> best2;
        read.close();
        if(score > best2){
            best2 = score;
            ofstream file("highscore(hard).txt");
            file << score;
            file.close();
        }
        hs.WriteText(to_string(best2), scoreFont, brown, renderer);
        hs_outline.WriteText(to_string(best2), scoreFont, white, renderer);
        if(best2 >= 10){
            TextWidth = 70;
            hs.setDest(420, 350, TextWidth, TextHeight);
            hs_outline.setDest(420, 350, TextWidth - 4, TextHeight);
        }
    }

    jumpDust.setDest(10, p.Ypos, 32, 32);
}

bool GameLoop::CheckCollision(const SDL_Rect &object1, const SDL_Rect &object2)
{
    int left_a = object1.x;
    int right_a = object1.x + object1.w;
    int top_a = object1.y;
    int bottom_a = object1.y + object1.h;

    int left_b = object2.x;
    int right_b = object2.x + object2.w;
    int top_b = object2.y;
    int bottom_b = object2.y + object2.h;

    // Case 1: size object 1 < size object 2
    if (left_a > left_b && left_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }
    if (left_a > left_b && left_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }
    if (right_a > left_b && right_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            return true;
        }
    }
    if (right_a > left_b && right_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            return true;
        }
    }

    // Case 2: size object 1 > size object 2
    if (left_b > left_a && left_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }
    if (left_b > left_a && left_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }
    if (right_b > left_a && right_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            return true;
        }
    }
    if (right_b > left_a && right_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            return true;
        }
    }

    // Case 3: size object 1 = size object 2
    if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
    {
        return true;
    }

    return false;
}

void GameLoop::AudioPlay()
{
    if(muteMusic || touch || touchGround)
        Mix_HaltMusic();
    if(!comein && !muteMusic)
        Mix_PlayMusic(backgroundSound, -1);
    if(comein && !muteMusic){
        Mix_VolumeMusic(40);
        Mix_PlayMusic(Playingmusic, -1);
    }
}

void GameLoop::CollisionDetection()
{
    // touch ground
    if (CheckCollision(p.Return_hitbox(), Ground1.Return_hitbox()) && !touchGround)
    {
        touchGround = true;
        if(!muteSOund){
            Mix_PlayChannel(4, fallSound, 0);
        }
    }
    // hit the down trees
    if (
        (CheckCollision(p.Return_hitbox(), tree[0].Return_hitbox(0)) ||
        CheckCollision(p.Return_hitbox(), tree[1].Return_hitbox(1)) ||
        CheckCollision(p.Return_hitbox(), tree[2].Return_hitbox(2))) && !touch)
    {
        touch = true;
        if(!muteSOund)
            Mix_PlayChannel(5, hitSound, 0);
    }

    // hit the up trees
    if (
        (CheckCollision(p.Return_hitbox(), treeUp[0].Return_hitboxUp(0)) ||
        CheckCollision(p.Return_hitbox(), treeUp[1].Return_hitboxUp(1))) && !touch)
    {
        touch = true;
        if(!muteSOund)
            Mix_PlayChannel(5, hitSound, 0);
    }

    // hit the bird
    if (
        CheckCollision(p.Return_hitbox(), chim.Return_hitbox()) && !touch)
    {
        touch = true;
        if(!muteSOund)
            Mix_PlayChannel(5, hitSound, 0);
    }

    // eat the carrot
    if (CheckCollision(p.Return_hitbox(), carrot[0].Return_hitbox(tree[0].tree_motion[0], tree[0].tree_ypos[0] - 90)) && !touch)
    {
        eat_carrot1 = true;
        if(takePoint1){
            score++;
            if(!muteSOund)
                Mix_PlayChannel(3, eatingSound, 0);
            takePoint1 = false;
            takePoint2 = true;
        }
    }
    if (CheckCollision(p.Return_hitbox(), carrot[1].Return_hitbox(tree[1].tree_motion[1], tree[1].tree_ypos[1] - 90)) && !touch)
    {
        eat_carrot2 = true;
        if(takePoint2){
            score++;
            if(!muteSOund)
                Mix_PlayChannel(3, eatingSound, 0);
            takePoint2 = false;
            takePoint3 = true;
        }
    }
    //bug fix
    if(!CheckCollision(p.Return_hitbox(), carrot[1].Return_hitbox(tree[1].tree_motion[1], tree[1].tree_ypos[1] - 90)) && (tree[1].tree_motion[1] + 30 < 10))
    {
        if(takePoint2){
            takePoint2 = false;
            takePoint3 = true;
        }
    }
    if (CheckCollision(p.Return_hitbox(), carrot[2].Return_hitbox(tree[2].tree_motion[2], tree[2].tree_ypos[2] - 90)) && !touch)
    {
        eat_carrot3 = true;
        if(takePoint3){
            score++;
            if(!muteSOund)
                Mix_PlayChannel(3, eatingSound, 0);
            takePoint3 = false;
            takePoint1 = true;
        }
    }
}

void GameLoop::Render()
{
    SDL_RenderClear(renderer);
    b.Render(renderer);

    if(start){
        tree[0].Render(renderer);
        tree[1].Render(renderer);
        tree[2].Render(renderer);

        carrot[0].Render(renderer, pause);
        carrot[1].Render(renderer, pause);
        carrot[2].Render(renderer, pause);

        treeUp[0].Render(renderer);
        treeUp[1].Render(renderer);
    }

    if(!start)
        when_start.Render(renderer);

    Ground1.Render(renderer);

    if (!chim.fly)
        chim.Render(renderer, pause);
    else
    {
        chim.SetFlyAnimation(renderer, pause);
    }

    if(start && !touchGround){
        s.Render(renderer);
        s_outline.Render(renderer);
    }

    
    if (jump || touchGround || touch)
        p.Render2(renderer, jump, touchGround, touch);
    else{
        //jumpDust.InitRender();
        p.Render(renderer, pause);
    }

    if(click){
        jumpDust.Render(renderer, p.Return_hitbox(), pause, click);
    }
    if(!click)
        jumpDust.InitRender();

    if(pause){
        pause_menu.Render(renderer);
        SDL_SetTextureAlphaMod(pause_menu.getTexture(), 185);
    }

    if(!touchGround && start){
        pause_button.RenderPause(renderer, pause, pause_button.point);
    }

    if(pause){
        replay.RenderMenuButton(renderer);
        back_to_menu.RenderMenuButton(renderer);
        PAUSE.Render(renderer);
    }
    if(touchGround){
        if(display2 == difficulties[0])
            endgame[0].Render(renderer);
        if(display2 == difficulties[1])
            endgame[1].Render(renderer);
        replay.RenderMenuButton(renderer);
        back_to_menu.RenderMenuButton(renderer);
        hs.Render(renderer);
        hs_outline.Render(renderer);
    }

    if(start && touchGround){
        s.Render(renderer);
        s_outline.Render(renderer);
    }

    if(!comein){
        poster.Render(renderer);
        start_button.RenderMenuButton(renderer);
        Options.RenderMenuButton(renderer);
        Exit.RenderMenuButton(renderer);
        creadit.RenderMenuButton(renderer);
        if(opencreadit)
            Creadit.Render(renderer);
        if(open_option){
            optionBar.Render(renderer);
            increase.RenderMenuButton(renderer);
            decrease.RenderMenuButton(renderer);
            PAUSE.Render(renderer);
            audioButton[0].RenderMenuButton(renderer);
            audioButton[1].RenderMenuButton(renderer);
            quitMenu.RenderMenuButton(renderer);
        }
    }

    // only for testing
    /*SDL_RenderDrawRect(renderer, &p.Return_hitbox());

    SDL_RenderDrawRect(renderer, &tree[0].Return_hitbox(0));
    SDL_RenderDrawRect(renderer, &tree[1].Return_hitbox(1));
    SDL_RenderDrawRect(renderer, &tree[2].Return_hitbox(2));

    for (int i = 0; i < 3; i++)
        SDL_RenderDrawRect(renderer, &carrot[i].Return_hitbox(tree[i].tree_motion[i], tree[i].tree_ypos[i] - 90));

    SDL_RenderDrawRect(renderer, &treeUp[0].Return_hitboxUp(0));
    SDL_RenderDrawRect(renderer, &treeUp[1].Return_hitboxUp(1));

    SDL_RenderDrawRect(renderer, &Ground1.Return_hitbox());

    SDL_RenderDrawRect(renderer, &chim.Return_hitbox());*/

    SDL_RenderPresent(renderer);
}

void GameLoop::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    Mix_Quit();
}
