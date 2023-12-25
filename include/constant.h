#ifndef CONSTANT
#define CONSTANT

#include "header.h"

enum textures{
    LOADING_SCREEN_BACKGROUND,  
    MENU_BACKGROUND,
    START_BUTTON,
    STORY_BUTTON,
    EXIT_BUTTON,
    CONTINUE_BUTTON,
    LEADERBOARD_BUTTON,
    EXIT_PAGE_BACKGROUND,
    EXIT_PAGE_YES,
    EXIT_PAGE_NO,
    NAME_INPUT_PAGE,
    LEADERBOARD_BACKGROUND,
    SLINGSHOT_BACK,
    SLINGSHOT_FRONT,
    BACK_BUTTON,

    STORY_PAGE,

    MUTE_BUTTON,
    UNMUTE_BUTTON,
    MUSIC_BUTTON,

    SLINGSHOT_RUBBER,
    SLINGSHOT_LEATHER,
    
    LEVEL_1_LOADING_PAGE,
    LEVEL_1_BACKGROUND,
    LEVEL_1_RED_BIRD,
    LEVEL_1_GREEN_PIG,

    LEVEL_2_LOADING_PAGE,
    LEVEL_2_BACKGROUND,
    LEVEL_2_YELLOW_BIRD,
    LEVEL_2_GREEN_PIG,
    LEVEL_2_OBSTACLE,

    LEVEL_3_LOADING_PAGE,
    LEVEL_3_BACKGROUND,
    LEVEL_3_BLACK_BIRD,
    LEVEL_3_GREEN_PIG,
    LEVEL_3_CLOUD,

    GAME_OVER_BACKGROUND,
    GAME_WON_BACKGROUND,

    CURSOR,
    TOTAL_TEXTURES
};

enum Musics
{
    BACKGROUND_MUSIC,
    BUTTON_CLICK_MUSIC,
    GAME_OVER_MUSIC,
    GAME_WIN_MUSIC,
    TOTAL_MUSIC
};

enum State{
    LOADING_SCREEN,
    MENU,
    NAME_INPUT,
    STORY,
    EXIT_PAGE,
    SETTING,
    LEADERBOARD,
    CONTINUE,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    LEVEL_4,
    LEVEL_5,
    SCORE_PAGE,
    GAME_OVER,
    GAME_SUCCESSFULLY_COMPLETED,
    TOTAL_STATES
};

extern State Current_state;
extern State Previous_state;


extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int score;
extern int turns_left;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture[TOTAL_TEXTURES];

extern Mix_Music *music[TOTAL_MUSIC];
extern int musicPlaying;

extern bool running;

extern int X, Y;
extern TTF_Font *valorax_font;

extern string playerName;

extern SDL_Rect back_button_rect;

    


#endif