/**/
#include "main.h"

void exit_page(SDL_Renderer *renderer, bool &quit, State &currentState)
{

    SDL_Texture *yes_button = surfaceToTexture(renderer, "../res/yes.png");
    SDL_Texture *no_button = surfaceToTexture(renderer, "../res/no.png");

    SDL_SetTextureColorMod(yes_button, 150, 150, 150);
    SDL_Rect yesButtonRect = {PLAY_BUTTON_POS_X - 100, PLAY_BUTTON_POS_Y, 250, 250};

    SDL_SetTextureColorMod(no_button, 150, 150, 150);
    SDL_Rect noButtonRect = {PLAY_BUTTON_POS_X + 200, PLAY_BUTTON_POS_Y, 250, 250};

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
            if (mouseX >= yesButtonRect.x && mouseX <= (yesButtonRect.x + yesButtonRect.w) &&
                mouseY >= yesButtonRect.y && mouseY <= (yesButtonRect.y + yesButtonRect.h))
            {
                SDL_SetTextureColorMod(yes_button, 255, 255, 255);
            }
            else
            {
                SDL_SetTextureColorMod(yes_button, 150, 150, 150);
            }

            if (mouseX >= noButtonRect.x && mouseX <= (noButtonRect.x + noButtonRect.w) &&
                mouseY >= noButtonRect.y && mouseY <= (noButtonRect.y + noButtonRect.h))
            {
                SDL_SetTextureColorMod(no_button, 255, 255, 255);
            }
            else
            {
                SDL_SetTextureColorMod(no_button, 150, 150, 150);
            }
        }
        else if (menuEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (mouseX >= yesButtonRect.x && mouseX <= (yesButtonRect.x + yesButtonRect.w) &&
                mouseY >= yesButtonRect.y && mouseY <= (yesButtonRect.y + yesButtonRect.h))
            {
                Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely
                SDL_Delay(100);
                quit = true;
                Mix_FreeMusic(backgroundMusic);
                Mix_CloseAudio();
                return;
            }

            if (mouseX >= noButtonRect.x && mouseX <= (noButtonRect.x + noButtonRect.w) &&
                mouseY >= noButtonRect.y && mouseY <= (noButtonRect.y + noButtonRect.h))
            {
                Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely
                SDL_Delay(100);

                currentState = MENU;
                Mix_FreeMusic(backgroundMusic);
                Mix_CloseAudio();
                return;
            }
        }
    }

    SDL_RenderClear(renderer);

    SDL_Surface *backgroundSurface = IMG_Load("../res/exit_page_background.png");
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);

    /**/

    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= noButtonRect.x && mouseX <= (noButtonRect.x + noButtonRect.w) &&
        mouseY >= noButtonRect.y && mouseY <= (noButtonRect.y + noButtonRect.h))
    {
        SDL_SetTextureColorMod(no_button, 255, 255, 255);
    }
    else
    {
        SDL_SetTextureColorMod(no_button, 150, 150, 150);
    }

    if (mouseX >= yesButtonRect.x && mouseX <= (yesButtonRect.x + yesButtonRect.w) &&
        mouseY >= yesButtonRect.y && mouseY <= (yesButtonRect.y + yesButtonRect.h))
    {
        SDL_SetTextureColorMod(yes_button, 255, 255, 255);
    }
    else
    {
        SDL_SetTextureColorMod(yes_button, 150, 150, 150);
    }

    /**/

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_RenderCopy(renderer, yes_button, NULL, &yesButtonRect);

    SDL_RenderCopy(renderer, no_button, NULL, &noButtonRect);

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(backgroundTexture);

}
