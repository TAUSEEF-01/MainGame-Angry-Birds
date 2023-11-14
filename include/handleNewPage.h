#ifndef HANDLE_NEW_PAGE
#define HANDLE_NEW_PAGE

#include "header.h"

void handleNewPage(SDL_Renderer *renderer, SDL_Texture *newPageTexture, SDL_Texture *playButtonTexture, SDL_Rect playButtonRect, SDL_Texture *settingButtonTexture, SDL_Rect settingButtonRect, bool &quit, State &currentState);

#endif