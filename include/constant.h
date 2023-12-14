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
extern const int INPUT_BOX_WIDTH;
extern const int INPUT_BOX_HEIGHT;
extern const int INPUT_BOX_POS_X;
extern const int INPUT_BOX_POS_Y;

enum State
{
    MENU,
    NEW_PAGE,
    NAME_INPUT,
    SETTING,
    PLAY_WINDOW, 
    LEVEL1_LOADING_PAGE,
    LEVEL2_LOADING_PAGE,
    LEVEL2,
    LEVEL3_LOADING_PAGE,
    LEVEL3,
    LEVEL4_LOADING_PAGE,
    LEVEL4,
    LEVEL5_LOADING_PAGE,
    LEVEL5,     
    EXIT_PAGE,
};

#endif