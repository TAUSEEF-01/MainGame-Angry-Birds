#include "main.h"


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

    SDL_Texture *newPageTexture = SDL_CreateTextureFromSurface(renderer, newPageSurface);
    SDL_FreeSurface(newPageSurface);

    if (newPageTexture == nullptr)
    {
        printf("Unable to create texture from new page image! SDL_Error: %s\n", SDL_GetError());
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

                /**/ //changed this part-->
                Mix_FreeMusic(backgroundMusic);
                Mix_CloseAudio();
            }
        }
    }

    SDL_RenderClear(renderer);
    
    SDL_Surface *backgroundSurface = IMG_Load("../res/Firstpage.png");
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(backgroundTexture);

    SDL_DestroyTexture(startButtonTexture);
    
    SDL_DestroyTexture(newPageTexture);

}
