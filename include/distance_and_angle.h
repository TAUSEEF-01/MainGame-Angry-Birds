#ifndef DISTANCE_AND_ANGLE
#define DISTANCE_AND_ANGLE

#include "header.h"

class Stretch 
{
public:
    double distance(SDL_Point a, SDL_Point b);
    double calculateAngle(double x, double y);

};

#endif