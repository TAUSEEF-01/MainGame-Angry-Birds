#include "main.h"

void playMusic(Mix_Music *backgroundMusic,const char* musicPath)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }
    backgroundMusic = Mix_LoadMUS(musicPath);
    if (backgroundMusic == NULL)
    {
        printf("Failed to load %s music! SDL_mixer Error: %s\n",musicPath, Mix_GetError());
        return;
    }
    Mix_PlayMusic(backgroundMusic, -1); // Start playing music
    
}
