#include "main.h"

// This is the second page where Play Button is added.

void Handle_Menu(SDL_Renderer *renderer, bool &quit, State &currentState)
{
    SDL_Surface *newPageSurface = IMG_Load("../res/new_page2.png");
    if (newPageSurface == nullptr)
    {
        printf("Unable to load new page image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *newPageTexture = SDL_CreateTextureFromSurface(renderer, newPageSurface);
    SDL_FreeSurface(newPageSurface);

    if (newPageTexture == nullptr)
    {
        printf("Unable to create texture from new page image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    // SDL_Surface *playButtonSurface = IMG_Load("../res/play_button2.png");
    SDL_Surface *playButtonSurface = IMG_Load("../res/start3.png");
    if (playButtonSurface == nullptr)
    {
        printf("Unable to load play button image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *playButtonTexture = SDL_CreateTextureFromSurface(renderer, playButtonSurface);
    SDL_FreeSurface(playButtonSurface);

    if (playButtonTexture == nullptr)
    {
        printf("Unable to create texture from play button image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150);
    SDL_Rect playButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 100, 250, 60};

    // SDL_Surface *optionButtonSurface = IMG_Load("../res/option_button.png");
    SDL_Surface *optionButtonSurface = IMG_Load("../res/exit2.png");
    if (optionButtonSurface == nullptr)
    {
        printf("Unable to load option button image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *optionButtonTexture = SDL_CreateTextureFromSurface(renderer, optionButtonSurface);
    SDL_FreeSurface(optionButtonSurface);

    if (optionButtonTexture == nullptr)
    {
        printf("Unable to create texture from option button image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_SetTextureColorMod(optionButtonTexture, 150, 150, 150);
    SDL_Rect optionButtonRect = {OPTION_BUTTON_POS_X + 50, OPTION_BUTTON_POS_Y + 200, 250, 60};

    SDL_Surface *backgroundPlaySurface = IMG_Load("../res/background_play.png");
    if (backgroundPlaySurface == nullptr)
    {
        printf("Unable to load background play image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *backgroundPlayTexture = SDL_CreateTextureFromSurface(renderer, backgroundPlaySurface);
    SDL_FreeSurface(backgroundPlaySurface);

    if (backgroundPlayTexture == nullptr)
    {
        printf("Unable to create texture from background play image! SDL_Error: %s\n", SDL_GetError());
        return;
    }



    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/back_button.mp3");
    if (backgroundMusic == NULL)
    {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return; 
    }


    // if (TTF_Init() == -1)
    // {
    //     printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    //     return;
    // }

    // // Load a font
    // TTF_Font* font = TTF_OpenFont("arial.ttf", 28);
    // if (font == nullptr) {
    //     printf("Unable to load font! SDL_ttf Error: %s\n", TTF_GetError());
    //     return;
    // }

    // std::string playerName;


    SDL_Event newPageEvent;
    // State currentState = NAME_INPUT;  // Start with the name input screen

    while (SDL_PollEvent(&newPageEvent) != 0)
    {
        if (newPageEvent.type == SDL_QUIT)
        {
            quit = true;
        }
        else if (newPageEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
                mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h))
            {
                Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely          
                SDL_Delay(100);          
                // currentState = LEVEL1_LOADING_PAGE;
                currentState = NAME_INPUT;
                Mix_FreeMusic(backgroundMusic);
                Mix_CloseAudio();
            }

            if (mouseX >= optionButtonRect.x && mouseX <= (optionButtonRect.x + optionButtonRect.w) &&
                mouseY >= optionButtonRect.y && mouseY <= (optionButtonRect.y + optionButtonRect.h))
            {
                printf("Exit button clicked!\n"); // make sure kortesi j setting button kaj kore kina

                Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely          
                SDL_Delay(100);          
                // currentState = SETTING;
                currentState = EXIT_PAGE;
                Mix_FreeMusic(backgroundMusic);
                Mix_CloseAudio();
            }
        }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, newPageTexture, NULL, NULL);

    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
        mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h))
    {
        SDL_SetTextureColorMod(playButtonTexture, 255, 255, 255);
    }
    else
    {
        SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150);
    }

    if (mouseX >= optionButtonRect.x && mouseX <= (optionButtonRect.x + optionButtonRect.w) &&
        mouseY >= optionButtonRect.y && mouseY <= (optionButtonRect.y + optionButtonRect.h))
    {
        SDL_SetTextureColorMod(optionButtonTexture, 255, 255, 255);
    }
    else
    {
        SDL_SetTextureColorMod(optionButtonTexture, 150, 150, 150);
    }

    // /**/
    // // Render player name input
    // TTF_Font *font = TTF_OpenFont("arial.ttf", 28);
    // SDL_Color textColor = {255, 255, 255};
    // SDL_Surface *playerNameSurface = TTF_RenderText_Solid(font, playerName.c_str(), textColor);
    // SDL_Texture *playerNameTexture = SDL_CreateTextureFromSurface(renderer, playerNameSurface);
    // SDL_FreeSurface(playerNameSurface);
    // SDL_Rect playerNameRect = {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 20, 200, 40};
    // SDL_RenderCopy(renderer, playerNameTexture, NULL, &playerNameRect);
    // /**/


    SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);

    SDL_RenderCopy(renderer, optionButtonTexture, NULL, &optionButtonRect);

    SDL_RenderPresent(renderer);


    SDL_DestroyTexture(playButtonTexture);
    SDL_DestroyTexture(optionButtonTexture);
    SDL_DestroyTexture(backgroundPlayTexture);
    
    // /**/
    // SDL_DestroyTexture(playerNameTexture);
    // TTF_CloseFont(font);
}
