#include "../include/header.h"

bool leaderboard_init = false;
SDL_Surface *temp_surface;
SDL_Texture *temp_texture;
SDL_Rect text_rec;
SDL_Surface *score_surface;
SDL_Texture *score_texture;
SDL_Rect score_rec;

bool leader_cursor_inside;
SDL_Event leaderboardEvent;

void play_music_leaderboard()
{
    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/audio/back_button.mp3");
    Mix_PlayMusic(backgroundMusic, 0); // Start playing music once
    SDL_Delay(100);
    // Mix_FreeMusic(backgroundMusic);
    // Mix_CloseAudio();
}

void Leaderboard()
{

    FILE *scoreboard;

    scoreboard = fopen("../res/leaderboard_stuff/leaderBoard.txt", "r+");
    fscanf(scoreboard, "%s %d", playerName.c_str(), &score);
    fclose(scoreboard);
    string score_str = to_string(score);
    if (!leaderboard_init)
    {
        leaderboard_init = 1;
        valorax_font = TTF_OpenFont("../res/font/Valorax.ttf", 70);
        temp_surface = TTF_RenderText_Solid(valorax_font, playerName.c_str(), {255, 255, 255});
        temp_texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
        text_rec = {500, 400, temp_surface->w, temp_surface->h};
        score_surface = TTF_RenderText_Solid(valorax_font, score_str.c_str(), {255, 255, 255});
        score_texture = SDL_CreateTextureFromSurface(renderer, score_surface);
        score_rec = {1100, 400, score_surface->w, score_surface->h};

        SDL_FreeSurface(temp_surface);
        SDL_FreeSurface(score_surface);
    }
    SDL_GetMouseState(&X, &Y);
    leader_cursor_inside = (X >= 1 && X <= 1599 && Y >= 1 && Y <= 899) ? true : false;
    SDL_Rect cursor_pos = {X, Y, 30, 45};
    while (SDL_PollEvent(&leaderboardEvent))
    {
        if (leaderboardEvent.type == SDL_QUIT)
        {
            running = false;
            leaderboard_init = false;
            return;
        }
        else if (leaderboardEvent.type == SDL_MOUSEBUTTONDOWN)
        {

            if (isHovered({X, Y}, back_button_rect))
            {
                Current_state = MENU;

                play_music_leaderboard();

                leaderboard_init = 0;
                return;
            }
        } //
    }

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, texture[LEADERBOARD_BACKGROUND], NULL, NULL);




    // back button - start
    if (isHovered({X, Y}, back_button_rect))
    {
        SDL_SetTextureColorMod(texture[BACK_BUTTON], 255, 255, 255);
    }
    else
    {
        SDL_SetTextureColorMod(texture[BACK_BUTTON], 150, 150, 150);
    }
    SDL_RenderCopy(renderer, texture[BACK_BUTTON], NULL, &back_button_rect);
    // back button - end





    SDL_RenderCopy(renderer, temp_texture, NULL, &text_rec);
    SDL_RenderCopy(renderer, score_texture, NULL, &score_rec);
    if (leader_cursor_inside)
        SDL_RenderCopy(renderer, texture[CURSOR], NULL, &cursor_pos);

    SDL_RenderPresent(renderer);
}