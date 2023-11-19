#include "main.h"

void handleMenu(SDL_Renderer *renderer, SDL_Texture *startButtonTexture, SDL_Rect startButtonRect, bool &quit, State &currentState)
{

    SDL_Texture *texture = IMG_LoadTexture(renderer, "../res/background2.png");
    SDL_Event menuEvent;

    SDL_Event e;
    bool wait = 1;

    SDL_Rect border = {50, 850, 1500, 20};

    SDL_Rect inside = {51, 851, 0, 18};

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture, NULL, NULL);

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
            currentState = NEW_PAGE;
            SDL_Delay(1000);
            return;
        }

        SDL_RenderPresent(renderer);
    }
}
