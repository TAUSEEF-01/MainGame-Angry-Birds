#include "main.h"

Mix_Music *buttonMusic1=NULL;
void handleNewPage(SDL_Renderer *renderer, SDL_Texture *newPageTexture, SDL_Texture *playButtonTexture, SDL_Rect playButtonRect, SDL_Texture *settingButtonTexture, SDL_Rect settingButtonRect, bool &quit, State &currentState)
{
    SDL_Event newPageEvent;
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
            	playMusic(buttonMusic1,"../res/button_click.mp3");
            	SDL_Delay(100);
                currentState = PLAY_WINDOW;
                Mix_FreeMusic(buttonMusic1);
                Mix_CloseAudio();
            }

            if (mouseX >= settingButtonRect.x && mouseX <= (settingButtonRect.x + settingButtonRect.w) &&
                mouseY >= settingButtonRect.y && mouseY <= (settingButtonRect.y + settingButtonRect.h))
            {
            	playMusic(buttonMusic1,"../res/button_click.mp3");
            	SDL_Delay(100);
                currentState= SETTINGS;
                Mix_FreeMusic(buttonMusic1);
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

    if (mouseX >= settingButtonRect.x && mouseX <= (settingButtonRect.x + settingButtonRect.w) &&
        mouseY >= settingButtonRect.y && mouseY <= (settingButtonRect.y + settingButtonRect.h))
    {
        SDL_SetTextureColorMod(settingButtonTexture, 255, 255, 255);
    }
    else
    {
        SDL_SetTextureColorMod(settingButtonTexture, 150, 150, 150);
    }

    SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);

    SDL_RenderCopy(renderer, settingButtonTexture, NULL, &settingButtonRect);

    SDL_RenderPresent(renderer);
}
