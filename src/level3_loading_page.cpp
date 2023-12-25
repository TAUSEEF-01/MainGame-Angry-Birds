#include "main.h"

void level3_loading_page(SDL_Renderer *renderer, bool &quit, State &currentState)
{
    SDL_Texture *backgroundTexture = surfaceToTexture(renderer, "../res/level3_loading_page.png");

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_RenderPresent(renderer);

    SDL_Delay(2000);
    currentState = LEVEL3;

    SDL_DestroyTexture(backgroundTexture);
}