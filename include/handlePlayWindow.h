#ifndef HANDLE_PLAY_WINDOW
#define HANDLE_PLAY_WINDOW

#include "header.h"

// void handlePlayWindow(SDL_Renderer* renderer, bool& quit, State &currentState);
// void handlePlayWindow(SDL_Renderer *renderer, bool &quit, State &currentState, int &musicPlaying);
void handlePlayWindow(SDL_Renderer *renderer, bool &quit, State &currentState, int &musicPlaying, std::string &playerName, int &playerScore, int &turns);

#endif