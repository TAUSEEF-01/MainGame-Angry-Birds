#include "../include/header.h"

SDL_Event story_page_event;
bool story_page_cursor_inside = 1;
SDL_Rect story_page_cursor_rect;


void back_button_music_storyPage()
{
    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/audio/back_button.mp3");
    Mix_PlayMusic(backgroundMusic, 0); // Start playing music once
    SDL_Delay(100);
    // Mix_FreeMusic(backgroundMusic);
    // Mix_CloseAudio();
}


void storyPage()
{
    SDL_GetMouseState(&X, &Y);
    story_page_cursor_rect = {X, Y, 30, 45};
    story_page_cursor_inside = (X >= 1 && X <= 1599 && Y >= 1 && Y <= 899) ? true : false;

    while (SDL_PollEvent(&story_page_event))
    {

        if (story_page_event.type == SDL_QUIT)
        {
            running = false;
            return;
        }
        else if (story_page_event.type == SDL_MOUSEBUTTONDOWN)
        {
            // if back button is clicked then returns to menu
            if (isHovered({X, Y}, back_button_rect) && story_page_event.button.button == SDL_BUTTON_LEFT)
            {
                Current_state = MENU;

                back_button_music_storyPage();

                return;
            }
        }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture[STORY_PAGE], NULL, NULL);



    // back button functionality - start
    if (isHovered({X, Y}, back_button_rect))
        SDL_SetTextureColorMod(texture[BACK_BUTTON], 255, 255, 255);
    else
        SDL_SetTextureColorMod(texture[BACK_BUTTON], 150, 150, 150);

    SDL_RenderCopy(renderer, texture[BACK_BUTTON], NULL, &back_button_rect);
    // back button functionality - end




    if(story_page_cursor_inside)
        SDL_RenderCopy(renderer, texture[CURSOR], NULL, &story_page_cursor_rect);

    SDL_RenderPresent(renderer);
}