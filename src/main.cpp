#include "main.h"


int main(int argc, char *argv[])
{
     if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }


    SDL_Window *window = SDL_CreateWindow("Angry Birds", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // SDL_Surface *startButtonSurface = IMG_Load("../res/enter3.png");
    // if (startButtonSurface == nullptr)
    // {
    //     printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // SDL_Texture *startButtonTexture = SDL_CreateTextureFromSurface(renderer, startButtonSurface);
    // SDL_FreeSurface(startButtonSurface);

    // if (startButtonTexture == nullptr)
    // {
    //     printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
    // SDL_Rect startButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 200, 250, 60};

    // SDL_Surface *newPageSurface = IMG_Load("../res/new_page2.png");
    // if (newPageSurface == nullptr)
    // {
    //     printf("Unable to load new page image! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // SDL_Texture *newPageTexture = SDL_CreateTextureFromSurface(renderer, newPageSurface);
    // SDL_FreeSurface(newPageSurface);

    // if (newPageTexture == nullptr)
    // {
    //     printf("Unable to create texture from new page image! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // SDL_Surface *playButtonSurface = IMG_Load("../res/play_button2.png");
    // if (playButtonSurface == nullptr)
    // {
    //     printf("Unable to load play button image! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // SDL_Texture *playButtonTexture = SDL_CreateTextureFromSurface(renderer, playButtonSurface);
    // SDL_FreeSurface(playButtonSurface);

    // if (playButtonTexture == nullptr)
    // {
    //     printf("Unable to create texture from play button image! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150);
    // SDL_Rect playButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 100, 250, 60};

    // SDL_Surface *optionButtonSurface = IMG_Load("../res/option_button.png");
    // if (optionButtonSurface == nullptr)
    // {
    //     printf("Unable to load option button image! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // SDL_Texture *optionButtonTexture = SDL_CreateTextureFromSurface(renderer, optionButtonSurface);
    // SDL_FreeSurface(optionButtonSurface);

    // if (optionButtonTexture == nullptr)
    // {
    //     printf("Unable to create texture from option button image! SDL_Error: %s\n", SDL_GetError());
    //     return 1;
    // }

    // SDL_SetTextureColorMod(optionButtonTexture, 150, 150, 150);
    // SDL_Rect optionButtonRect = {OPTION_BUTTON_POS_X + 50, OPTION_BUTTON_POS_Y + 200, 250, 60};



    SDL_Surface *backgroundPlaySurface = IMG_Load("../res/background_play.png");
    if (backgroundPlaySurface == nullptr)
    {
        printf("Unable to load background play image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Texture *backgroundPlayTexture = SDL_CreateTextureFromSurface(renderer, backgroundPlaySurface);
    SDL_FreeSurface(backgroundPlaySurface);

    if (backgroundPlayTexture == nullptr)
    {
        printf("Unable to create texture from background play image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface *birdSurface = IMG_Load("../res/bird.png");
    if (birdSurface == nullptr)
    {
        printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    bool quit = false;
    State currentState = MENU;

    while (!quit)
    {
        if (currentState == MENU)
        {
            // handleMenu(renderer, startButtonTexture, startButtonRect, quit, currentState);
            handleMenu(renderer, quit, currentState);
        }
        else if (currentState == NEW_PAGE)
        {
            // handleNewPage(renderer, newPageTexture, playButtonTexture, playButtonRect, optionButtonTexture, optionButtonRect, quit, currentState);
            handleNewPage(renderer, quit, currentState);
        }
        else if (currentState == PLAY_WINDOW)
        {
            handlePlayWindow(renderer, backgroundPlayTexture, quit, currentState);
        }
    }



    // SDL_DestroyTexture(startButtonTexture);
    // SDL_DestroyTexture(newPageTexture);
    // SDL_DestroyTexture(playButtonTexture);
    // SDL_DestroyTexture(optionButtonTexture);
    // SDL_DestroyTexture(backgroundPlayTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}









/*

for adding music-->


    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return 1;
    }

    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/background_music.mp3");
    if (backgroundMusic == NULL)
    {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return 1;
    }

    Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely



    // Mix_FreeMusic(backgroundMusic);
    // Mix_CloseAudio();

    

*/