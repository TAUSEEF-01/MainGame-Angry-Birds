#include "../include/header.h"

SDL_Event e;
bool start_hovered = false, story_hovered = false, leaderboard_hovered = false, Exit_hovered = false, menu_cursor_inside = false, Continue_hovered = false;

SDL_Rect start, story, leaderboard, Exit, start_hover, story_hover, leaderboard_hover, Exit_hover, Continue, Continue_hover;

SDL_Event menuEvent;

void initialize()
{
    Continue = {677, 500, 246, 59};
    start = {677, 580, 246, 59};
    story = {677, 740, 246, 59};
    leaderboard = {677, 660, 246, 59};
    Exit = {677, 820, 246, 59};

    start_hover = hover_init(start);
    story_hover = hover_init(story);
    leaderboard_hover = hover_init(leaderboard);
    Exit_hover = hover_init(Exit);
    Continue_hover = hover_init(Continue);
}


void back_button_music_menu()
{
    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/audio/back_button.mp3");
    Mix_PlayMusic(backgroundMusic, 0); // Start playing music once
    SDL_Delay(100);
    // Mix_FreeMusic(backgroundMusic);
}

void handleMenu()
{
    initialize();

    while (running)
    {
        SDL_ShowCursor(0);
        SDL_GetMouseState(&X, &Y);
        SDL_Rect cursor_rect = {X, Y, 30, 45};

        menu_cursor_inside = (X >= 1 && X <= 1599 && Y >= 1 && Y <= 899) ? true : false;

        while (SDL_PollEvent(&menuEvent) != 0)
        {
            if (menuEvent.type == SDL_QUIT)
            {
                running = false;
                return;
            }
            if (start_hovered && menuEvent.type == SDL_MOUSEBUTTONDOWN)
            {
                Current_state = NAME_INPUT;
                back_button_music_menu();
                musicPlaying = 1;
                return;
            }
            if (story_hovered && menuEvent.type == SDL_MOUSEBUTTONDOWN)
            {
                Current_state = STORY;
                back_button_music_menu();
                return;
            }
            if (leaderboard_hovered && menuEvent.type == SDL_MOUSEBUTTONDOWN && Previous_state == MENU)
            {
                Current_state = LEADERBOARD;
                back_button_music_menu();
                return;
            }
            if (Exit_hovered && menuEvent.type == SDL_MOUSEBUTTONDOWN)
            {
                Current_state = EXIT_PAGE;
                back_button_music_menu();
                return;
            }

            // continue hovered
            if (Continue_hovered && menuEvent.type == SDL_MOUSEBUTTONDOWN)
            {
                Current_state = Previous_state;
                back_button_music_menu();
                musicPlaying = 1;
                return;
            }
        }

        if (!start_hovered && (X >= start.x && X <= start.x + start.w && Y >= start.y && Y <= start.y + start.h))
        {
            start_hovered = true;
        }
        else if (start_hovered && (X >= start_hover.x && X <= start_hover.x + start_hover.w && Y >= start_hover.y && Y <= start_hover.y + start_hover.h))
        {
            start_hovered = true;
        }
        else
        {
            start_hovered = false;
        }

        if (!story_hovered && (X >= story.x && X <= story.x + story.w && Y >= story.y && Y <= story.y + story.h))
        {
            story_hovered = true;
        }
        else if (story_hovered && (X >= story_hover.x && X <= story_hover.x + story_hover.w && Y >= story_hover.y && Y <= story_hover.y + story_hover.h))
        {
            story_hovered = true;
        }
        else
        {
            story_hovered = false;
        }

        if (!leaderboard_hovered && (X >= leaderboard.x && X <= leaderboard.x + leaderboard.w && Y >= leaderboard.y && Y <= leaderboard.y + leaderboard.h))
        {
            leaderboard_hovered = true;
        }
        else if (leaderboard_hovered && (X >= leaderboard_hover.x && X <= leaderboard_hover.x + leaderboard_hover.w && Y >= leaderboard_hover.y && Y <= leaderboard_hover.y + leaderboard_hover.h))
        {
            leaderboard_hovered = true;
        }
        else
        {
            leaderboard_hovered = false;
        }

        if (!Exit_hovered && (X >= Exit.x && X <= Exit.x + Exit.w && Y >= Exit.y && Y <= Exit.y + Exit.h))
        {
            Exit_hovered = true;
        }
        else if (Exit_hovered && (X >= Exit_hover.x && X <= Exit_hover.x + Exit_hover.w && Y >= Exit_hover.y && Y <= Exit_hover.y + Exit_hover.h))
        {
            Exit_hovered = true;
        }
        else
        {
            Exit_hovered = false;
        }

        // continue hovered
        if (!Continue_hovered && (X >= Continue.x && X <= Continue.x + Continue.w && Y >= Continue.y && Y <= Continue.y + Continue.h))
        {
            Continue_hovered = true;
        }
        else if (Continue_hovered && (X >= Continue_hover.x && X <= Continue_hover.x + Continue_hover.w && Y >= Continue_hover.y && Y <= Continue_hover.y + Continue_hover.h))
        {
            Continue_hovered = true;
        }
        else
        {
            Continue_hovered = false;
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture[MENU_BACKGROUND], NULL, NULL);
        if (!start_hovered)
            SDL_RenderCopy(renderer, texture[START_BUTTON], NULL, &start);
        else
            SDL_RenderCopy(renderer, texture[START_BUTTON], NULL, &start_hover);

        if (!story_hovered)
            SDL_RenderCopy(renderer, texture[STORY_BUTTON], NULL, &story);
        else
            SDL_RenderCopy(renderer, texture[STORY_BUTTON], NULL, &story_hover);
        
        if (!leaderboard_hovered)
            SDL_RenderCopy(renderer, texture[LEADERBOARD_BUTTON], NULL, &leaderboard);
        else
            SDL_RenderCopy(renderer, texture[LEADERBOARD_BUTTON], NULL, &leaderboard_hover);

        if (!Exit_hovered)
            SDL_RenderCopy(renderer, texture[EXIT_BUTTON], NULL, &Exit);
        else
            SDL_RenderCopy(renderer, texture[EXIT_BUTTON], NULL, &Exit_hover);

        // continue hovered
        if(Previous_state != MENU)
        {
            if (!Continue_hovered)
                SDL_RenderCopy(renderer, texture[CONTINUE_BUTTON], NULL, &Continue);
            else
                SDL_RenderCopy(renderer, texture[CONTINUE_BUTTON], NULL, &Continue_hover);
        }

        if (menu_cursor_inside)
            SDL_RenderCopy(renderer, texture[CURSOR], NULL, &cursor_rect);

        SDL_RenderPresent(renderer);
    }
}