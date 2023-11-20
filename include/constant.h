#ifndef global
#define global

#include "header.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int PLAY_BUTTON_POS_X;
extern const int PLAY_BUTTON_POS_Y;
extern const int OPTION_BUTTON_POS_X;
extern const int OPTION_BUTTON_POS_Y;
extern const int MUSIC_BUTTON_POS_X;
extern const int MUSIC_BUTTON_POS_Y;
enum State
{
    MENU,
    NEW_PAGE,
    PLAY_WINDOW,
    SETTINGS
};

#endif