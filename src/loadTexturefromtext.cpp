#include "../include/header.h"

SDL_Texture *loadTextureFromText(string s, TTF_Font *font, int font_size, SDL_Rect &rect, SDL_Color color)
{
    SDL_Texture *temporary_texture = NULL;
    SDL_Surface *temporary_surface = NULL;
    temporary_surface = TTF_RenderText_Solid(font, s.c_str(), color);

    temporary_texture = SDL_CreateTextureFromSurface(renderer, temporary_surface);
    rect.w = temporary_surface->w;
    rect.h = temporary_surface->h;
    
    SDL_FreeSurface(temporary_surface);
    return temporary_texture;
}