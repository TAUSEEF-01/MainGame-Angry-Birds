#include "../include/header.h"

SDL_Event game_over_event;
SDL_Rect text_rect;
SDL_Texture *text_texture;
SDL_Rect gameover_cursor_rect;
SDL_Rect backButton = {1470, 30, 100, 100};
bool gameover_cursor_inside = false;


void back_button_music_gameOver()
{
    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/audio/back_button.mp3");
    Mix_PlayMusic(backgroundMusic, 0); // Start playing music once
    SDL_Delay(100);
    // Mix_FreeMusic(backgroundMusic);
}


void gameOver()
{
    Previous_state = MENU;

    while (SDL_PollEvent(&game_over_event))
    {
        SDL_GetMouseState(&X, &Y);
        if (game_over_event.type == SDL_QUIT)
        {
            running = false;
            return;
        }
        if(game_over_event.type == SDL_MOUSEBUTTONDOWN && isHovered({X, Y}, backButton))
        {
            Current_state = MENU;
            SDL_DestroyTexture(text_texture);

            back_button_music_gameOver();

            Mix_HaltMusic();  // Stop music immediately
            
            return;
        }

    }
    char leader[15] = {'\0'};
    int maximum_score = 0;
    FILE *scoreboard;
    scoreboard = fopen("../res/leaderboard_stuff/leaderBoard.txt", "r+");
    if (scoreboard == NULL)
    {
        printf("Error in opening leaderboad.txt for reading.\n");
        return;
    }

    if (fscanf(scoreboard, "%14s %d", leader, &maximum_score) != 2)
    {
        printf("Error reading leaderboard data.\n");
        fclose(scoreboard);
        return;
    }
    fclose(scoreboard);

    // printf("Leader: %s, Maximum Score: %d\n", leader, maximum_score);

    if (score > maximum_score)
    {
        scoreboard = fopen("../res/leaderboard_stuff/leaderBoard.txt", "w+");
        if (scoreboard == NULL)
            printf("Error in opening leaderboad for writing.txt.\n");
        fprintf(scoreboard, "%s %d", playerName.c_str(), score);
        fclose(scoreboard);
    }

    text_texture = loadTextureFromText((" Score: " + to_string(score)).c_str(), valorax_font, 70, text_rect, {0, 0, 0});

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture[GAME_OVER_BACKGROUND], NULL, NULL);

    text_rect.x = 490;
    text_rect.y = 700;
    SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);

    // back_button

    if (isHovered({X, Y}, backButton))
    {
        SDL_SetTextureColorMod(texture[BACK_BUTTON], 255, 255, 255);
    }
    else
    {
        SDL_SetTextureColorMod(texture[BACK_BUTTON], 150, 150, 150);
    }
    SDL_RenderCopy(renderer, texture[BACK_BUTTON], NULL, &backButton);

    

    // cursor - start
    gameover_cursor_inside = (X >= 1 && X <= 1599 && Y >= 1 && Y <= 899) ? true : false;
    gameover_cursor_rect = {X, Y, 30, 45};
    if (gameover_cursor_inside)
        SDL_RenderCopy(renderer, texture[CURSOR], NULL, &gameover_cursor_rect);
    // cursor - end

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(text_texture);

    // SDL_Delay(5000);

    // Current_state = MENU;
    // return;
}