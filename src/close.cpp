#include "../include/header.h"

void close()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    for(int i = 0; i<TOTAL_TEXTURES; i++)
    {
        SDL_DestroyTexture(texture[i]);
    }

    for(int i = 0; i<TOTAL_MUSIC; i++)
    {
        Mix_FreeMusic(music[i]);
    }

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    // close audio added
    Mix_CloseAudio();
}