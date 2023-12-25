#include "../include/header.h"

SDL_Rect hover_init(SDL_Rect &a)
{
    SDL_Rect temp = {a.x - 5, a.y - 5, a.w + 10, a.h + 10};
    return temp;
}