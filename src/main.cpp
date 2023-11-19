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


    int musicPlaying = 1;  


    
    bool quit = false;
    State currentState = MENU;

    while (!quit)
    {
        if (currentState == MENU)
        {
            handleMenu(renderer, quit, currentState);
        }
        else if (currentState == NEW_PAGE)
        {
            handleNewPage(renderer, quit, currentState);
        }
        else if (currentState == SETTING) 
        {
            settingPage(renderer, quit, currentState);
            // settingPage(renderer, SettingPageTexture, muteButtonTexture, unmuteButtonTexture, musicButtonRect, quit, currentState);
        }
        else if (currentState == PLAY_WINDOW)
        {
            handlePlayWindow(renderer, quit, currentState, musicPlaying);
        }
        else if (currentState == LEVEL2)
        {
            level2(renderer, quit, currentState, musicPlaying);
        }   
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}










// Mix_Music *backgroundMusic = NULL;



    // if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    // {
    //     printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    //     return 1;
    // }

    // backgroundMusic = Mix_LoadMUS("../res/background_music.mp3");
    // if (backgroundMusic == NULL)
    // {
    //     printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
    //     return 1;
    // }

    // Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely

    /**/

    // SDL_Texture *SettingPageTexture = surfaceToTexture(renderer,"../res/new_page.png");

    // SDL_Texture *muteButtonTexture = surfaceToTexture(renderer,"../res/mute.png");

    // SDL_Texture *unmuteButtonTexture = surfaceToTexture(renderer,"../res/unmute.png");
   

    // SDL_SetTextureColorMod(muteButtonTexture, 150, 150, 150);
    // SDL_Rect musicButtonRect = {MUSIC_BUTTON_POS_X + 50, MUSIC_BUTTON_POS_Y + 50, 250, 250};


    // SDL_Texture *SettingPageTexture = surfaceToTexture(renderer,"../res/new_page.png");
    // SDL_Texture *muteButtonTexture = surfaceToTexture(renderer,"../res/mute.png");
    // SDL_Texture *unmuteButtonTexture = surfaceToTexture(renderer,"../res/unmute.png");
   
    // SDL_SetTextureColorMod(muteButtonTexture, 150, 150, 150);
    // SDL_Rect musicButtonRect = {MUSIC_BUTTON_POS_X + 50, MUSIC_BUTTON_POS_Y + 50, 250, 250};













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