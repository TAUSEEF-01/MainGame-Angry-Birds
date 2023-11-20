#include "main.h"
// Assume you have two textures for mute and unmute buttons: muteButtonTexture and unmuteButtonTexture
Mix_Music *buttonMusic2=NULL;
 // Flag to indicate if music is playing (1 for playing, 0 for stopped)
SDL_Texture* currentButtonTexture; // Variable to hold the current button texture

// Function to toggle music on/off
void toggleMusic(SDL_Texture* muteTexture, SDL_Texture* unmuteTexture, int &musicPlaying) {
    if (musicPlaying) {
        musicPlaying = 0; // Update the flag to indicate music is stopped
        currentButtonTexture = unmuteTexture; // Set the texture to unmute button
    } else {
        musicPlaying = 1; // Update the flag to indicate music is playing
        currentButtonTexture = muteTexture; // Set the texture to mute button
    }
}

void handleSettings(SDL_Renderer* renderer, SDL_Texture* SettingPageTexture, SDL_Texture* muteButtonTexture, SDL_Texture* unmuteButtonTexture, SDL_Rect musicButtonRect, bool& quit, State& currentState,int &musicPlaying) {
    SDL_Event settingPageEvent;

    while (SDL_PollEvent(&settingPageEvent) != 0) {
        if (settingPageEvent.type == SDL_QUIT) {
            quit = true;
        } else if (settingPageEvent.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (mouseX >= musicButtonRect.x && mouseX <= (musicButtonRect.x + musicButtonRect.w) &&
                mouseY >= musicButtonRect.y && mouseY <= (musicButtonRect.y + musicButtonRect.h)) {
                playMusic(buttonMusic2,"../res/button_click.mp3");
            	SDL_Delay(100);
                
                Mix_FreeMusic(buttonMusic2);
                Mix_CloseAudio();
                toggleMusic(muteButtonTexture, unmuteButtonTexture,musicPlaying);
                currentState = NEW_PAGE;
            }
        }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, SettingPageTexture, NULL, NULL);

    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (musicPlaying) {
        currentButtonTexture = muteButtonTexture;
    } else {
        currentButtonTexture = unmuteButtonTexture;
    }

    if (mouseX >= musicButtonRect.x && mouseX <= (musicButtonRect.x + musicButtonRect.w) &&
        mouseY >= musicButtonRect.y && mouseY <= (musicButtonRect.y + musicButtonRect.h)) {
        SDL_SetTextureColorMod(currentButtonTexture, 255, 255, 255);
    } else {
        SDL_SetTextureColorMod(currentButtonTexture, 150, 150, 150);
    }

    SDL_RenderCopy(renderer, currentButtonTexture, NULL, &musicButtonRect);
    SDL_RenderPresent(renderer);
}

