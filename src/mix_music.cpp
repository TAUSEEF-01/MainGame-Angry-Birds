#include "main.h"


Mix_Music *Music(const char *Path)
{
    Mix_Music *music = Mix_LoadMUS(Path);
    if (music == NULL)
    {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return nullptr;
    }

    return music;
}
