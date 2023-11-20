#include "main.h"
Mix_Music *backgroundMusic = NULL;


int main(int argc, char *argv[])
{
     if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

   SDL_Window *window = SDL_CreateWindow("Angry Birds", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }


    SDL_Texture *startButtonTexture = surfaceToTexture(renderer, "../res/enter3.png");
   
	
    SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
    SDL_Rect startButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 200, 250, 60};

    SDL_Texture *newPageTexture = surfaceToTexture(renderer,"../res/new_page2.png");
    
    

     SDL_Texture *playButtonTexture = surfaceToTexture(renderer,"../res/play_button2.png");
   

    SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150);
    SDL_Rect playButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 100, 250, 60};

    SDL_Texture *optionButtonTexture = surfaceToTexture(renderer,"../res/option_button.png");
    

    SDL_SetTextureColorMod(optionButtonTexture, 150, 150, 150);
    SDL_Rect optionButtonRect = {OPTION_BUTTON_POS_X + 50, OPTION_BUTTON_POS_Y + 200, 250, 60};

    
    SDL_Texture *backgroundPlayTexture = surfaceToTexture(renderer,"../res/background_play.png");
    

    SDL_Surface *birdSurface = IMG_Load("../res/bird.png");
    if (birdSurface == nullptr)
    {
        printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }


    SDL_Texture *SettingPageTexture = surfaceToTexture(renderer,"../res/new_page.png");
    
    

    SDL_Texture *muteButtonTexture = surfaceToTexture(renderer,"../res/mute.png");
    

    SDL_Texture *unmuteButtonTexture = surfaceToTexture(renderer,"../res/unmute.png");
   

    SDL_SetTextureColorMod(muteButtonTexture, 150, 150, 150);
    SDL_Rect musicButtonRect = {MUSIC_BUTTON_POS_X + 50, MUSIC_BUTTON_POS_Y + 50, 250, 250};

    bool quit = false;
    State currentState = MENU;
	int musicPlaying=1;
    SDL_Event event;
while (!quit) {
    if (currentState == MENU) {
        handleMenu(renderer, startButtonTexture, startButtonRect, quit, currentState);
    } else if (currentState == NEW_PAGE) {
        handleNewPage(renderer, newPageTexture, playButtonTexture, playButtonRect, optionButtonTexture, optionButtonRect, quit, currentState);
    } else if (currentState == SETTINGS) {
        handleSettings(renderer, SettingPageTexture, muteButtonTexture, unmuteButtonTexture, musicButtonRect, quit, currentState,musicPlaying);
    } else if (currentState == PLAY_WINDOW) {
    	if(musicPlaying)
    	  playMusic(backgroundMusic,"../res/background_music.mp3");
        handlePlayWindow(renderer, backgroundPlayTexture, quit);
    }
}


    Mix_FreeMusic(backgroundMusic);
    Mix_CloseAudio();

    SDL_DestroyTexture(startButtonTexture);
    SDL_DestroyTexture(newPageTexture);
    SDL_DestroyTexture(playButtonTexture);
    SDL_DestroyTexture(optionButtonTexture);
    SDL_DestroyTexture(muteButtonTexture);
    SDL_DestroyTexture(unmuteButtonTexture);
    SDL_DestroyTexture(SettingPageTexture);
    SDL_DestroyTexture(backgroundPlayTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}
