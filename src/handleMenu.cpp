#include "main.h"

// void handleMenu(SDL_Renderer *renderer, SDL_Texture *startButtonTexture, SDL_Rect startButtonRect, bool &quit, State &currentState)
void handleMenu(SDL_Renderer *renderer, bool &quit, State &currentState)
{
    SDL_Surface *startButtonSurface = IMG_Load("../res/enter3.png");
    if (startButtonSurface == nullptr)
    {
        printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *startButtonTexture = SDL_CreateTextureFromSurface(renderer, startButtonSurface);
    SDL_FreeSurface(startButtonSurface);

    if (startButtonTexture == nullptr)
    {
        printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
    SDL_Rect startButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 200, 250, 60};

    SDL_Surface *newPageSurface = IMG_Load("../res/new_page2.png");
    if (newPageSurface == nullptr)
    {
        printf("Unable to load new page image! SDL_Error: %s\n", SDL_GetError());
        return;
    }


    // SDL_Surface *newPageSurface = IMG_Load("../res/new_page2.png");
    // if (newPageSurface == nullptr)
    // {
    //     printf("Unable to load new page image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }

    SDL_Texture *newPageTexture = SDL_CreateTextureFromSurface(renderer, newPageSurface);
    SDL_FreeSurface(newPageSurface);

    if (newPageTexture == nullptr)
    {
        printf("Unable to create texture from new page image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    // SDL_Surface *playButtonSurface = IMG_Load("../res/play_button2.png");
    // if (playButtonSurface == nullptr)
    // {
    //     printf("Unable to load play button image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }

    // SDL_Texture *playButtonTexture = SDL_CreateTextureFromSurface(renderer, playButtonSurface);
    // SDL_FreeSurface(playButtonSurface);

    // if (playButtonTexture == nullptr)
    // {
    //     printf("Unable to create texture from play button image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }

    // SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150);
    // SDL_Rect playButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 100, 250, 60};

    // SDL_Surface *optionButtonSurface = IMG_Load("../res/option_button.png");
    // if (optionButtonSurface == nullptr)
    // {
    //     printf("Unable to load option button image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }

    // SDL_Texture *optionButtonTexture = SDL_CreateTextureFromSurface(renderer, optionButtonSurface);
    // SDL_FreeSurface(optionButtonSurface);

    // if (optionButtonTexture == nullptr)
    // {
    //     printf("Unable to create texture from option button image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }

    // SDL_SetTextureColorMod(optionButtonTexture, 150, 150, 150);
    // SDL_Rect optionButtonRect = {OPTION_BUTTON_POS_X + 50, OPTION_BUTTON_POS_Y + 200, 250, 60};

    // SDL_Surface *backgroundPlaySurface = IMG_Load("../res/background_play.png");
    // if (backgroundPlaySurface == nullptr)
    // {
    //     printf("Unable to load background play image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }

    // SDL_Texture *backgroundPlayTexture = SDL_CreateTextureFromSurface(renderer, backgroundPlaySurface);
    // SDL_FreeSurface(backgroundPlaySurface);

    // if (backgroundPlayTexture == nullptr)
    // {
    //     printf("Unable to create texture from background play image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }

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


    SDL_Event menuEvent;
    while (SDL_PollEvent(&menuEvent) != 0)
    {
        if (menuEvent.type == SDL_QUIT)
        {
            quit = true;
        }
        else if (menuEvent.type == SDL_MOUSEMOTION)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
                mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h))
            {
                SDL_SetTextureColorMod(startButtonTexture, 255, 255, 255);
            }
            else
            {
                SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
            }
        }
        else if (menuEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
                mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h))
            {
                Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely          
                SDL_Delay(100);          
                currentState = NEW_PAGE;
                Mix_FreeMusic(backgroundMusic);
                Mix_CloseAudio();
            }
        }
    }

    SDL_RenderClear(renderer);
    
    SDL_Surface *backgroundSurface = IMG_Load("../res/background2.png");
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(backgroundTexture);


    SDL_DestroyTexture(startButtonTexture);
    SDL_DestroyTexture(newPageTexture);
    // SDL_DestroyTexture(playButtonTexture);
    // SDL_DestroyTexture(optionButtonTexture);
    // SDL_DestroyTexture(backgroundPlayTexture);
}
