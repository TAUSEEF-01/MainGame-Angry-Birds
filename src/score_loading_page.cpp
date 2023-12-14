#include "main.h"

void score_loading_page(SDL_Renderer *renderer, bool &quit, State &currentState)
{
    SDL_Texture *backgroundTexture = surfaceToTexture(renderer, "../res/Firstpage.png");

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_RenderPresent(renderer);

    SDL_Delay(2000);
    currentState = SCORE_PAGE;

    SDL_DestroyTexture(backgroundTexture);
}