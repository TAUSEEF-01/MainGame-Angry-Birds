#include "main.h"

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
                currentState = PLAY_WINDOW;
            }

            if (mouseX >= settingButtonRect.x && mouseX <= (settingButtonRect.x + settingButtonRect.w) &&
                mouseY >= settingButtonRect.y && mouseY <= (settingButtonRect.y + settingButtonRect.h))
            {
                printf("Setting button clicked!\n"); // make sure kortesi j setting button kaj kore kina
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
