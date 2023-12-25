#include "../include/header.h"

bool isHovered(SDL_Point p, SDL_Rect rect)
{
    if(p.x>=rect.x && p.x<=rect.x+rect.w && p.y>=rect.y && p.y<=rect.y+rect.h)
        return 1;
    return 0;
}