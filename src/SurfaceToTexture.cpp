#include "main.h"


SDL_Texture *surfaceToTexture(SDL_Renderer *renderer, const char *imagePath)
{
    SDL_Texture *Texture = IMG_LoadTexture(renderer, imagePath);

    if (Texture == nullptr)
    {
        printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
        return nullptr;
    }

    return Texture;
}





// SDL_Texture *surfaceToTexture(SDL_Renderer *renderer, const char *imagePath)
// {
//     SDL_Surface *surface = IMG_Load(imagePath);
//     if (surface == nullptr)
//     {
//         printf("Unable to load image %s! SDL_Error: %s\n", imagePath, SDL_GetError());
//         return nullptr;
//     }

//     SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
//     SDL_FreeSurface(surface);

//     if (texture == nullptr)
//     {
//         printf("Unable to create texture from image %s! SDL_Error: %s\n", imagePath, SDL_GetError());
//         return nullptr;
//     }

//     return texture;
// }




