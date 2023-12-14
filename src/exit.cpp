/**/
#include "main.h"

void exit_page(SDL_Renderer *renderer, bool &quit, State &currentState)
{

    SDL_Texture *yes_button = surfaceToTexture(renderer, "../res/yes.png");
    SDL_Texture *no_button = surfaceToTexture(renderer, "../res/no.png");

    SDL_SetTextureColorMod(yes_button, 150, 150, 150);
    SDL_Rect yesButtonRect = {PLAY_BUTTON_POS_X -100, PLAY_BUTTON_POS_Y , 250, 250};

    SDL_SetTextureColorMod(no_button, 150, 150, 150);
    SDL_Rect noButtonRect = {PLAY_BUTTON_POS_X + 200, PLAY_BUTTON_POS_Y , 250, 250};
    

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/back_button.mp3");
    if (backgroundMusic == NULL)
    {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }


    SDL_Event menuEvent;
    while (SDL_PollEvent(&menuEvent) != 0)
    {
        if (menuEvent.type == SDL_QUIT)
        {
            quit = true;
        }
        else if (menuEvent.type == SDL_MOUSEMOTION)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (mouseX >= yesButtonRect.x && mouseX <= (yesButtonRect.x + yesButtonRect.w) &&
                mouseY >= yesButtonRect.y && mouseY <= (yesButtonRect.y + yesButtonRect.h))
            {
                SDL_SetTextureColorMod(yes_button, 255, 255, 255);
            }
            else
            {
                SDL_SetTextureColorMod(yes_button, 150, 150, 150);
            }

            if (mouseX >= noButtonRect.x && mouseX <= (noButtonRect.x + noButtonRect.w) &&
                mouseY >= noButtonRect.y && mouseY <= (noButtonRect.y + noButtonRect.h))
            {
                SDL_SetTextureColorMod(no_button, 255, 255, 255);
            }
            else
            {
                SDL_SetTextureColorMod(no_button, 150, 150, 150);
            }

        }
        else if (menuEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (mouseX >= yesButtonRect.x && mouseX <= (yesButtonRect.x + yesButtonRect.w) &&
                mouseY >= yesButtonRect.y && mouseY <= (yesButtonRect.y + yesButtonRect.h))
            {
                Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely          
                SDL_Delay(100);  
                quit = true;
                Mix_FreeMusic(backgroundMusic);
                Mix_CloseAudio();
                return;
            }

            if (mouseX >= noButtonRect.x && mouseX <= (noButtonRect.x + noButtonRect.w) &&
                mouseY >= noButtonRect.y && mouseY <= (noButtonRect.y + noButtonRect.h))
            {
                Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely          
                SDL_Delay(100);  

                currentState = NEW_PAGE;
                Mix_FreeMusic(backgroundMusic);
                Mix_CloseAudio();
                return;
            }
        }
    }

    SDL_RenderClear(renderer);

    SDL_Surface *backgroundSurface = IMG_Load("../res/exit_page_background.png");
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);

    /**/

    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= noButtonRect.x && mouseX <= (noButtonRect.x + noButtonRect.w) &&
        mouseY >= noButtonRect.y && mouseY <= (noButtonRect.y + noButtonRect.h))
    {
        SDL_SetTextureColorMod(no_button, 255, 255, 255);
    }
    else
    {
        SDL_SetTextureColorMod(no_button, 150, 150, 150);
    }

    if (mouseX >= yesButtonRect.x && mouseX <= (yesButtonRect.x + yesButtonRect.w) &&
        mouseY >= yesButtonRect.y && mouseY <= (yesButtonRect.y + yesButtonRect.h))
    {
        SDL_SetTextureColorMod(yes_button, 255, 255, 255);
    }
    else
    {
        SDL_SetTextureColorMod(yes_button, 150, 150, 150);
    }

    /**/

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_RenderCopy(renderer, yes_button, NULL, &yesButtonRect);

    SDL_RenderCopy(renderer, no_button, NULL, &noButtonRect);

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(backgroundTexture);

    // SDL_DestroyTexture(newPageTexture);

}
























// #include "main.h"
// Assume you have two textures for mute and unmute buttons: muteButtonTexture and unmuteButtonTexture

// int musicPlaying = 1;              // Flag to indicate if music is playing (1 for playing, 0 for stopped)
// SDL_Texture *currentButtonTexture; // Variable to hold the current button texture

// // Function to toggle music on/off
// void toggleMusic(SDL_Texture *muteTexture, SDL_Texture *unmuteTexture)
// {
//     if (musicPlaying)
//     {
//         Mix_PauseMusic();                     // Pause the music
//         musicPlaying = 0;                     // Update the flag to indicate music is stopped
//         currentButtonTexture = unmuteTexture; // Set the texture to unmute button
//     }
//     else
//     {
//         Mix_ResumeMusic();                  // Resume the music
//         musicPlaying = 1;                   // Update the flag to indicate music is playing
//         currentButtonTexture = muteTexture; // Set the texture to mute button
//     }
// }

// void settingPage(SDL_Renderer *renderer, SDL_Texture *SettingPageTexture, SDL_Texture *muteButtonTexture, SDL_Texture *unmuteButtonTexture, SDL_Rect musicButtonRect, bool &quit, State &currentState)
// {
//     SDL_Event settingPageEvent;

//     while (SDL_PollEvent(&settingPageEvent) != 0)
//     {
//         if (settingPageEvent.type == SDL_QUIT)
//         {
//             quit = true;
//         }
//         else if (settingPageEvent.type == SDL_MOUSEBUTTONDOWN)
//         {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);

//             if (mouseX >= musicButtonRect.x && mouseX <= (musicButtonRect.x + musicButtonRect.w) &&
//                 mouseY >= musicButtonRect.y && mouseY <= (musicButtonRect.y + musicButtonRect.h))
//             {
//                 toggleMusic(muteButtonTexture, unmuteButtonTexture);
//                 SDL_Delay(150);
//                 currentState = NEW_PAGE;
//                 // add new settings page and there should be an option of music change when mouse click on the button just call togglemusic
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, SettingPageTexture, NULL, NULL);

//     int mouseX, mouseY;
//     SDL_GetMouseState(&mouseX, &mouseY);

//     if (musicPlaying)
//     {
//         currentButtonTexture = muteButtonTexture;
//     }
//     else
//     {
//         currentButtonTexture = unmuteButtonTexture;
//     }

//     if (mouseX >= musicButtonRect.x && mouseX <= (musicButtonRect.x + musicButtonRect.w) &&
//         mouseY >= musicButtonRect.y && mouseY <= (musicButtonRect.y + musicButtonRect.h))
//     {
//         SDL_SetTextureColorMod(currentButtonTexture, 255, 255, 255);
//     }
//     else
//     {
//         SDL_SetTextureColorMod(currentButtonTexture, 150, 150, 150);
//     }

//     SDL_RenderCopy(renderer, currentButtonTexture, NULL, &musicButtonRect);
//     SDL_RenderPresent(renderer);
// }








// #include "main.h"
// // Assume you have two textures for mute and unmute buttons: muteButtonTexture and unmuteButtonTexture

// int musicPlaying = 1;              // Flag to indicate if music is playing (1 for playing, 0 for stopped)
// SDL_Texture *currentButtonTexture; // Variable to hold the current button texture

// // Function to toggle music on/off
// void toggleMusic(SDL_Texture *muteTexture, SDL_Texture *unmuteTexture)
// {
//     if (musicPlaying)
//     {
//         Mix_PauseMusic();                     // Pause the music
//         musicPlaying = 0;                     // Update the flag to indicate music is stopped
//         currentButtonTexture = unmuteTexture; // Set the texture to unmute button
//     }
//     else
//     {
//         Mix_ResumeMusic();                  // Resume the music
//         musicPlaying = 1;                   // Update the flag to indicate music is playing
//         currentButtonTexture = muteTexture; // Set the texture to mute button
//     }
// }

// void settingPage(SDL_Renderer *renderer, bool &quit, State &currentState)
// // void settingPage(SDL_Renderer* renderer, SDL_Texture* SettingPageTexture, SDL_Texture* muteButtonTexture, SDL_Texture* unmuteButtonTexture, SDL_Rect musicButtonRect, bool& quit, State& currentState)
// {
//     if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
//     {
//         printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
//         return;
//     }

//     Mix_Music *backgroundMusic = Mix_LoadMUS("../res/background_music.mp3");
//     if (backgroundMusic == NULL)
//     {
//         printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
//         return;
//     }

//     Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely


//     SDL_Texture *SettingPageTexture = surfaceToTexture(renderer, "../res/new_page.png");

//     SDL_Texture *muteButtonTexture = surfaceToTexture(renderer, "../res/mute.png");

//     SDL_Texture *unmuteButtonTexture = surfaceToTexture(renderer, "../res/unmute.png");

//     SDL_SetTextureColorMod(muteButtonTexture, 150, 150, 150);
//     SDL_Rect musicButtonRect = {MUSIC_BUTTON_POS_X + 50, MUSIC_BUTTON_POS_Y + 50, 250, 250};

//     SDL_Event settingPageEvent;

//     while (SDL_PollEvent(&settingPageEvent) != 0)
//     {
//         if (settingPageEvent.type == SDL_QUIT)
//         {
//             quit = true;
//         }
//         else if (settingPageEvent.type == SDL_MOUSEBUTTONDOWN)
//         {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);

//             if (mouseX >= musicButtonRect.x && mouseX <= (musicButtonRect.x + musicButtonRect.w) &&
//                 mouseY >= musicButtonRect.y && mouseY <= (musicButtonRect.y + musicButtonRect.h))
//             {
//                 toggleMusic(muteButtonTexture, unmuteButtonTexture);
//                 SDL_Delay(150);
//                 currentState = NEW_PAGE;
//                 // add new settings page and there should be an option of music change when mouse click on the button just call togglemusic
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, SettingPageTexture, NULL, NULL);

//     int mouseX, mouseY;
//     SDL_GetMouseState(&mouseX, &mouseY);

//     if (musicPlaying)
//     {
//         currentButtonTexture = muteButtonTexture;
//     }
//     else
//     {
//         currentButtonTexture = unmuteButtonTexture;
//     }

//     if (mouseX >= musicButtonRect.x && mouseX <= (musicButtonRect.x + musicButtonRect.w) &&
//         mouseY >= musicButtonRect.y && mouseY <= (musicButtonRect.y + musicButtonRect.h))
//     {
//         SDL_SetTextureColorMod(currentButtonTexture, 255, 255, 255);
//     }
//     else
//     {
//         SDL_SetTextureColorMod(currentButtonTexture, 150, 150, 150);
//     }

    // Mix_FreeMusic(backgroundMusic);
    // Mix_CloseAudio();

    // SDL_RenderCopy(renderer, currentButtonTexture, NULL, &musicButtonRect);
    // SDL_RenderPresent(renderer);

    // SDL_DestroyTexture(muteButtonTexture);
    // SDL_DestroyTexture(unmuteButtonTexture);
    // SDL_DestroyTexture(SettingPageTexture);
// }
