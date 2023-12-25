#include "../include/header.h"

double Stretch::distance(SDL_Point a, SDL_Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y));
}

double Stretch::calculateAngle(double x, double y) {
    double angleRad = atan2(y, x);  
    double angleDeg = angleRad * 180.0 / M_PI;
    return angleDeg;
}