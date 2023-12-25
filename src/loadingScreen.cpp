#include "../include/header.h"

bool wait = 1;
SDL_Event loadingScreen_Event;

SDL_Rect border = {50, 850, 1500, 20};
SDL_Rect inside = {51, 851, 0, 18};

void loadingScreen()
{
    while (SDL_PollEvent(&loadingScreen_Event))
    {
        if (loadingScreen_Event.type == SDL_QUIT)
        {
            running = false;
            return;
        }
    }

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, texture[LOADING_SCREEN_BACKGROUND], NULL, NULL);

    if (wait)
    {
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        wait = 0;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawRect(renderer, &border);

    // Render red filled quad

    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &inside);

    if (inside.w <= 1498)
        inside.w++;
    else
    {
        Current_state = MENU;
        SDL_Delay(1000);
        return;
    }

    SDL_RenderPresent(renderer);
}