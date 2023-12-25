#include "../include/header.h"

SDL_Event exit_event;

bool yes_hovered = false, no_hovered = false, initialized = 0, exit_cursor_inside = false;
SDL_Rect yes_rect, no_rect, yes_hover_rect, no_hover_rect;


void back_button_music_exitPage()
{
    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/audio/back_button.mp3");
    Mix_PlayMusic(backgroundMusic, 0); // Start playing music once
    SDL_Delay(100);
    // Mix_FreeMusic(backgroundMusic);
}

void exitpage()
{
    SDL_ShowCursor(0);
    SDL_GetMouseState(&X, &Y);
    SDL_Rect cursor_rect = {X, Y, 30, 45};

    if (!initialized)
    {
        initialized = 1;
        int height_yes, width_yes, height_no, width_no;
        SDL_QueryTexture(texture[EXIT_PAGE_YES], NULL, NULL, &width_yes, &height_yes);
        SDL_QueryTexture(texture[EXIT_PAGE_NO], NULL, NULL, &width_no, &height_no);
        yes_rect = {355, 627, width_yes, height_yes};
        yes_hover_rect = hover_init(yes_rect);
        no_rect = {1245 - width_no, 627, width_no, height_no};
        no_hover_rect = hover_init(no_rect);
    }

    exit_cursor_inside = (X >= 1 && X <= 1599 && Y >= 1 && Y <= 899) ? true : false;

    while (SDL_PollEvent(&exit_event))
    {
        if (exit_event.type == SDL_QUIT || (yes_hovered && exit_event.type == SDL_MOUSEBUTTONDOWN))
        {
            running = false;

            back_button_music_exitPage();

            return;
        }

        if(no_hovered && exit_event.type == SDL_MOUSEBUTTONDOWN)
        {
            Current_state = MENU;

            back_button_music_exitPage();

            return;
        }
    }

    if (!yes_hovered && (X >= yes_rect.x && X <= yes_rect.x + yes_rect.w && Y >= yes_rect.y && Y <= yes_rect.y + yes_rect.h))
    {
        yes_hovered = true;
    }
    else if (yes_hovered && (X >= yes_hover_rect.x && X <= yes_hover_rect.x + yes_hover_rect.w && Y >= yes_hover_rect.y && Y <= yes_hover_rect.y + yes_hover_rect.h))
    {
        yes_hovered = true;
    }
    else
    {
        yes_hovered = false;
    }

    if (!no_hovered && (X >= no_rect.x && X <= no_rect.x + no_rect.w && Y >= no_rect.y && Y <= no_rect.y + no_rect.h))
    {
        no_hovered = true;
    }
    else if (no_hovered && (X >= no_hover_rect.x && X <= no_hover_rect.x + no_hover_rect.w && Y >= no_hover_rect.y && Y <= no_hover_rect.y + no_hover_rect.h))
    {
        no_hovered = true;
    }
    else
    {
        no_hovered = false;
    }




    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture[EXIT_PAGE_BACKGROUND], NULL, NULL);

    if (!yes_hovered)
        SDL_RenderCopy(renderer, texture[EXIT_PAGE_YES], NULL, &yes_rect);
    else
        SDL_RenderCopy(renderer, texture[EXIT_PAGE_YES], NULL, &yes_hover_rect);

    if (!no_hovered)
        SDL_RenderCopy(renderer, texture[EXIT_PAGE_NO], NULL, &no_rect);
    else
        SDL_RenderCopy(renderer, texture[EXIT_PAGE_NO], NULL, &no_hover_rect);


    if (exit_cursor_inside)
        SDL_RenderCopy(renderer, texture[CURSOR], NULL, &cursor_rect);
    SDL_RenderPresent(renderer);
}