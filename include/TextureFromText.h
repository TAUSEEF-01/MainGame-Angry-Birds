#ifndef TEXTURE_FROM_TEXT
#define TEXTURE_FROM_TEXT

#include "header.h"

SDL_Texture *loadTextureFromText(string s, TTF_Font *font, int font_size, SDL_Rect &rect, SDL_Color color);

#endif 