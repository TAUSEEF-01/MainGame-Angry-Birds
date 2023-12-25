#include "../include/header.h"

SDL_Texture *loadTexture(string path)
{
    SDL_Texture *tempTexture = IMG_LoadTexture(renderer, path.c_str());
    if(tempTexture == NULL)
    {
        printf("%s texture could not be loaded!\n", path.c_str());
    }

    return tempTexture;
}