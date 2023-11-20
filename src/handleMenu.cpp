#include "main.h"

Mix_Music *buttonMusic = NULL;
void handleMenu(SDL_Renderer *renderer, SDL_Texture *startButtonTexture, SDL_Rect startButtonRect, bool &quit, State &currentState)
{
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
            	playMusic(buttonMusic,"../res/button_click.mp3");
            	SDL_Delay(100);
                currentState = NEW_PAGE;
                Mix_FreeMusic(buttonMusic);
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
