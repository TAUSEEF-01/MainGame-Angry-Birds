#include "main.h"

void level2_loading_page(SDL_Renderer *renderer, bool &quit, State &currentState)
{
    SDL_Texture *backgroundTexture = surfaceToTexture(renderer, "../res/level2_loading_page3.png");

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_RenderPresent(renderer);

    SDL_Delay(2000);
    currentState = LEVEL2;

    SDL_DestroyTexture(backgroundTexture);
}