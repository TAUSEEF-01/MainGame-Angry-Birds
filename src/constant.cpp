#include "../include/header.h"

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture[TOTAL_TEXTURES] = {NULL};
Mix_Music *music[TOTAL_MUSIC] = {NULL};
State Current_state = LOADING_SCREEN;
State Previous_state = MENU;
int X, Y;
TTF_Font *valorax_font;
string playerName;
int score = 0;
int turns_left = 3;

SDL_Rect back_button_rect = {30, 30, 100, 100};

bool running = true;

int musicPlaying = 1;