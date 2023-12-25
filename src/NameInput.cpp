#include "../include/header.h"

bool font_initialized = false;
string inputText;
SDL_Surface *textSurface;
SDL_Texture *textTexture;
bool font_cursor_inside;

SDL_Event nameInputEvent;

SDL_Rect textRect, inputRect;


void back_button_music_nameInput()
{
    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/audio/back_button.mp3");
    Mix_PlayMusic(backgroundMusic, 0); // Start playing music once
    SDL_Delay(100);
    // Mix_FreeMusic(backgroundMusic);
    // Mix_CloseAudio();
}


void nameInput()
{
    Previous_state = MENU;
    // Initialization
    if (!font_initialized)
    {
        font_initialized = 1;

        score = 0;
        valorax_font = TTF_OpenFont("../res/font/Valorax.ttf", 70);
        textSurface = TTF_RenderText_Solid(valorax_font, "Enter Your Name", {0, 0, 0}); // showing the typed letter and the current string
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        textRect = {20, 210, textSurface->w, textSurface->h};
        SDL_StartTextInput(); // enable text input

        inputText = " "; // initializing with space so that the

        if (valorax_font == NULL)
        {
            printf("font load hoynai\n%s\n", TTF_GetError());
        }
    }

    SDL_GetMouseState(&X, &Y);
    font_cursor_inside = (X >= 1 && X <= 1599 && Y >= 1 && Y <= 899) ? true : false;

    SDL_Rect font_cursor_rect = {X, Y, 30, 45}; // position of mouse cursor

    while (SDL_PollEvent(&nameInputEvent))
    {
        if (nameInputEvent.type == SDL_QUIT)
        {
            running = false;
            SDL_StopTextInput(); // Stops taking input
            font_initialized = false;
            return;
        }
        else if (nameInputEvent.type == SDL_KEYDOWN)
        {
            if (nameInputEvent.key.keysym.sym == SDLK_RETURN)
            {
                // Enter key pressed, exit the name input
                
                SDL_StopTextInput(); // Stops taking input
                Current_state = LEVEL_1; // Change the state to LEVEL 1 after name input
                playerName = inputText;  // Save the entered name
                font_initialized = false;
                return;
            }
            else if (nameInputEvent.key.keysym.sym == SDLK_BACKSPACE && inputText.size() > 1)
            {
                // Backspace key pressed, remove a character
                inputText.pop_back();
            }
        }
        else if (nameInputEvent.type == SDL_TEXTINPUT && inputText.size() < 14)
        {
            // Handle text input
            inputText += nameInputEvent.text.text;
        }
        else if (nameInputEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            // if back button is clicked then returns to menu
            if (isHovered({X, Y}, back_button_rect) && nameInputEvent.button.button == SDL_BUTTON_LEFT)
            {
                Current_state = MENU;

                font_initialized = 0;

                back_button_music_nameInput();
                return;
            }
        }
    }



    // Creating texture from inputText
    SDL_Surface *temp = TTF_RenderText_Solid(valorax_font, inputText.c_str(), {0, 0, 0});
    if (temp == NULL)
    {
        printf("temp surface load hoynai\n");
        return;
    }
    SDL_Texture *temp_texture = SDL_CreateTextureFromSurface(renderer, temp);
    inputRect = {390 - (temp->w) / 2, 420, temp->w, temp->h};
    SDL_FreeSurface(temp);




    // rendering everything
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture[NAME_INPUT_PAGE], NULL, NULL);

    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_RenderCopy(renderer, temp_texture, NULL, &inputRect);


    // back button functionality - start
    if (isHovered({X, Y}, back_button_rect))
        SDL_SetTextureColorMod(texture[BACK_BUTTON], 255, 255, 255);
    else
        SDL_SetTextureColorMod(texture[BACK_BUTTON], 150, 150, 150);

    SDL_RenderCopy(renderer, texture[BACK_BUTTON], NULL, &back_button_rect);
    // back button functionality - end


    if (font_cursor_inside)
        SDL_RenderCopy(renderer, texture[CURSOR], NULL, &font_cursor_rect);

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(temp_texture); // clears RAM
}