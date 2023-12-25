#include "../include/header.h"

string enter = "Enter Your Name";

bool loadMedia()
{

    texture[LOADING_SCREEN_BACKGROUND] = loadTexture("../res/img/Loading Screen background.png");
    texture[MENU_BACKGROUND] = loadTexture("../res/img/Menu Background.png");
    texture[START_BUTTON] = loadTexture("../res/img/Start_Button.png");
    texture[STORY_BUTTON] = loadTexture("../res/img/Story_Button.png");
    texture[EXIT_BUTTON] = loadTexture("../res/img/Exit_Button.png");
    texture[LEADERBOARD_BUTTON] = loadTexture("../res/img/Leaderboard_Button.png");
    texture[EXIT_PAGE_BACKGROUND] = loadTexture("../res/img/Exit_Page_Background.png");
    texture[EXIT_PAGE_YES] = loadTexture("../res/img/Exit_Page - YES.png");
    texture[EXIT_PAGE_NO] = loadTexture("../res/img/Exit_Page - NO.png");
    texture[NAME_INPUT_PAGE] = loadTexture("../res/img/name_input_page.png");
    texture[LEADERBOARD_BACKGROUND] = loadTexture("../res/img/Leaderboard_background.png");
    texture[SLINGSHOT_BACK] = loadTexture("../res/img/slingshot_back.png");
    texture[SLINGSHOT_FRONT] = loadTexture("../res/img/slingshot_front.png");
    texture[BACK_BUTTON] = loadTexture("../res/img/back_button.png");

    texture[STORY_PAGE] = loadTexture("../res/img/story_page.png");
    texture[CONTINUE_BUTTON] = loadTexture("../res/img/Continue_Button.png");

    texture[MUTE_BUTTON] = loadTexture("../res/img/mute_button.png");
    texture[UNMUTE_BUTTON] = loadTexture("../res/img/unmute_button.png");
    texture[MUSIC_BUTTON] = loadTexture("../res/img/unmute_button.png");

    texture[SLINGSHOT_RUBBER] = loadTexture("../res/img/slingshot_rubber.png");
    texture[SLINGSHOT_LEATHER] = loadTexture("../res/img/slingshot_rubber_leather.png");

    texture[LEVEL_1_LOADING_PAGE] = loadTexture("../res/img/level_1_loading_screen.png");
    texture[LEVEL_1_BACKGROUND] = loadTexture("../res/img/level_1_background.png");
    texture[LEVEL_1_RED_BIRD] = loadTexture("../res/img/level_1_red_bird.png");
    texture[LEVEL_1_GREEN_PIG] = loadTexture("../res/img/level_1_green_pig.png");

    texture[LEVEL_2_LOADING_PAGE] = loadTexture("../res/img/level_2_loading_screen.png");
    texture[LEVEL_2_BACKGROUND] = loadTexture("../res/img/level_2_background.png");
    texture[LEVEL_2_YELLOW_BIRD] = loadTexture("../res/img/level_2_yellow_bird.png");
    texture[LEVEL_2_GREEN_PIG] = loadTexture("../res/img/level_1_green_pig.png");
    texture[LEVEL_2_OBSTACLE] = loadTexture("../res/img/Level_2_obstacle.png");

    texture[LEVEL_3_LOADING_PAGE] = loadTexture("../res/img/level_3_loading_screen.png");
    texture[LEVEL_3_BACKGROUND] = loadTexture("../res/img/level_2_background.png");
    texture[LEVEL_3_BLACK_BIRD] = loadTexture("../res/img/level_3_black_bird.png");
    texture[LEVEL_3_GREEN_PIG] = loadTexture("../res/img/level_1_green_pig.png");
    texture[LEVEL_3_CLOUD] = loadTexture("../res/img/cloud.png");

    texture[GAME_OVER_BACKGROUND] = loadTexture("../res/img/game_over_page.png");
    texture[GAME_WON_BACKGROUND] = loadTexture("../res/img/gameWon_page.png");

    texture[CURSOR] = loadTexture("../res/img/Cursor.png");
    

    for(int i = 0; i<TOTAL_TEXTURES; i++)
    {
        if(texture[i]== NULL)
        {
            printf("%d no. texture could not be loaded!\n", i);
            return 0;
        }
    }


    music[BUTTON_CLICK_MUSIC] = Mix_LoadMUS("../res/audio/back_button.mp3");
    music[BACKGROUND_MUSIC] = Mix_LoadMUS("../res/audio/background_music3.mp3");
    music[GAME_OVER_MUSIC] = Mix_LoadMUS("../res/audio/Game_over.mp3");
    music[GAME_WIN_MUSIC] = Mix_LoadMUS("../res/audio/Game_win.mp3");

    for(int i = 0; i<TOTAL_MUSIC; i++)
    {
        if(music[i] == NULL)
        {
            printf("%d no. music could not be loaded!\n", i);
            return 0;
        }
    }



    return 1;
}