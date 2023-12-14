#ifndef SCORE
#define SCORE

#include "header.h"

void handleScoreDisplay(SDL_Renderer *renderer, State &currentState, TTF_Font *font, int playerScore, const std::string &playerName, bool &quit);

#endif