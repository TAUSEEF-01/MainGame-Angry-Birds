/**/
#include "main.h"

void settingPage(SDL_Renderer *renderer, bool &quit, State &currentState)
{
    SDL_Surface *startButtonSurface = IMG_Load("../res/enter3.png");
    if (startButtonSurface == nullptr)
    {
        printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *startButtonTexture = SDL_CreateTextureFromSurface(renderer, startButtonSurface);
    SDL_FreeSurface(startButtonSurface);

    if (startButtonTexture == nullptr)
    {
        printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
    SDL_Rect startButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 200, 250, 60};

    SDL_Surface *newPageSurface = IMG_Load("../res/Firstpage.png");
    if (newPageSurface == nullptr)
    {
        printf("Unable to load new page image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *newPageTexture = SDL_CreateTextureFromSurface(renderer, newPageSurface);
    SDL_FreeSurface(newPageSurface);

    if (newPageTexture == nullptr)
    {
        printf("Unable to create texture from new page image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

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
            if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
                mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h))
            {
                SDL_SetTextureColorMod(startButtonTexture, 255, 255, 255);
            }
            else
            {
                SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
            }
        }
        else if (menuEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
                mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h))
            {
                Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely
                SDL_Delay(100);
                currentState = NEW_PAGE;
                Mix_FreeMusic(backgroundMusic);
                Mix_CloseAudio();
            }
        }
    }

    SDL_RenderClear(renderer);

    SDL_Surface *backgroundSurface = IMG_Load("../res/Firstpage.png");
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(backgroundTexture);

    SDL_DestroyTexture(startButtonTexture);
    SDL_DestroyTexture(newPageTexture);

}
























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
