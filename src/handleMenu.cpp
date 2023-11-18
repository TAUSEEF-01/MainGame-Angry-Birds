#include "main.h"

void handleMenu(SDL_Renderer *renderer, SDL_Texture *startButtonTexture, SDL_Rect startButtonRect, bool &quit, State &currentState)
{

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
}
