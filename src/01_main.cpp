#include "../include/header.h"

int main(int argc, char *argv[])
{

    if (!init())
    {
        printf("SDL could not initialize!! %s\n", SDL_GetError());
    }
    else
    {
        while (running)
        {
            switch (Current_state) // states of Current_state
            {
            case LOADING_SCREEN:
                loadingScreen();
                break;

            case MENU:
                handleMenu();
                break;

            case EXIT_PAGE:
                exitpage();
                break;

            case NAME_INPUT:
                nameInput();
                break;

            case LEADERBOARD:
                Leaderboard();
                break;
                
            case STORY:
                storyPage();
                break;




            case LEVEL_1:
                levelOne();
                break;

            case LEVEL_2:
                levelTwo();
                break;

            case LEVEL_3:
                levelThree();
                break;



            case GAME_OVER:
                gameOver();
                break;

            case GAME_SUCCESSFULLY_COMPLETED:
                gameWon();
                break;                




            default:
                handleMenu();
                break;
            }
        }
    }

    close();

    return 0;
}