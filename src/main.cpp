#include "main.h"


int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
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


    /**/
    TTF_Font* font = TTF_OpenFont("roboto.ttf", 28);
    if (font == nullptr) {
        printf("Unable to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }


    int musicPlaying = 1;  

    /**/
    std::string playerName;

    
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
        else if (currentState == EXIT_PAGE) 
        {
            exit_page(renderer, quit, currentState);
        }
        else if (currentState == PLAY_WINDOW)
        {
            handlePlayWindow(renderer, quit, currentState, musicPlaying, playerName);
        }
        else if (currentState == LEVEL2)
        {
            level2(renderer, quit, currentState, musicPlaying, playerName);
        }
        else if (currentState == LEVEL3)
        {
            level3(renderer, quit, currentState, musicPlaying, playerName);
        }
        else if (currentState == LEVEL4)
        {
            level4(renderer, quit, currentState, musicPlaying, playerName);
        }
        else if (currentState == LEVEL5)
        {
            level5(renderer, quit, currentState, musicPlaying, playerName);
        }
        else if (currentState == LEVEL1_LOADING_PAGE)
        {
            level1_loading_page(renderer, quit, currentState);
        }
        else if (currentState == LEVEL2_LOADING_PAGE)
        {
            level2_loading_page(renderer, quit, currentState);
        }
        else if (currentState == LEVEL3_LOADING_PAGE)
        {
            level3_loading_page(renderer, quit, currentState);
        }
        else if (currentState == LEVEL4_LOADING_PAGE)
        {
            level4_loading_page(renderer, quit, currentState);
        }
        else if (currentState == LEVEL5_LOADING_PAGE)
        {
            level5_loading_page(renderer, quit, currentState);
        }
        /**/
        else if (currentState == NAME_INPUT)
        {
            handleNameInput(renderer, font, quit, currentState, playerName);
        }
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    /**/
    TTF_CloseFont(font);
    TTF_Quit();

    IMG_Quit();
    SDL_Quit();

    return 0;
}


