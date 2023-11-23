#include "main.h"


int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
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


    /**/
    TTF_Font* font = TTF_OpenFont("arial.ttf", 28);
    if (font == nullptr) {
        printf("Unable to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }


    int musicPlaying = 1;  

    /**/
    std::string playerName;

    
    bool quit = false;
    State currentState = MENU;

    while (!quit)
    {
        if (currentState == MENU)
        {
            handleMenu(renderer, quit, currentState);
        }
        else if (currentState == NEW_PAGE)
        {
            handleNewPage(renderer, quit, currentState);
        }
        else if (currentState == SETTING) 
        {
            settingPage(renderer, quit, currentState);
            // settingPage(renderer, SettingPageTexture, muteButtonTexture, unmuteButtonTexture, musicButtonRect, quit, currentState);
        }
        else if (currentState == PLAY_WINDOW)
        {
            handlePlayWindow(renderer, quit, currentState, musicPlaying, playerName);
        }
        else if (currentState == LEVEL2)
        {
            level2(renderer, quit, currentState, musicPlaying, playerName);
        }
        else if (currentState == LEVEL1_LOADING_PAGE)
        {
            level1_loading_page(renderer, quit, currentState);
        }
        else if (currentState == LEVEL2_LOADING_PAGE)
        {
            level2_loading_page(renderer, quit, currentState);
        }
        /**/
        else if (currentState == NAME_INPUT)
        {
            handleNameInput(renderer, font, quit, currentState, playerName);
        }
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    /**/
    TTF_CloseFont(font);
    TTF_Quit();

    IMG_Quit();
    SDL_Quit();

    return 0;
}



// void handleNameInput(SDL_Renderer* renderer, TTF_Font* font, bool& quit, State& currentState, std::string& playerName) {
//     SDL_Event nameInputEvent;
//     SDL_StartTextInput();  // Enable text input

//     bool inputActive = true;
//     SDL_Color textColor = {255, 255, 255};
//     std::string inputText;

//     while (inputActive) {
//         while (SDL_PollEvent(&nameInputEvent) != 0) {
//             if (nameInputEvent.type == SDL_QUIT) {
//                 quit = true;
//                 inputActive = false;
//             } else if (nameInputEvent.type == SDL_KEYDOWN) {
//                 if (nameInputEvent.key.keysym.sym == SDLK_RETURN) {
//                     // Enter key pressed, exit the name input
//                     inputActive = false;
//                     currentState = MENU;  // Change the state to MENU after name input
//                     playerName = inputText;  // Save the entered name
//                 } else if (nameInputEvent.key.keysym.sym == SDLK_BACKSPACE && !inputText.empty()) {
//                     // Backspace key pressed, remove a character
//                     inputText.pop_back();
//                 }
//             } else if (nameInputEvent.type == SDL_TEXTINPUT) {
//                 // Handle text input
//                 inputText += nameInputEvent.text.text;
//             }
//         }

//         // Render the background
//         SDL_RenderClear(renderer);
//         SDL_Surface* backgroundSurface = IMG_Load("background2.png");
//         SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
//         SDL_FreeSurface(backgroundSurface);
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//         // Render the input box
//         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//         SDL_Rect inputBoxRect = {INPUT_BOX_POS_X, INPUT_BOX_POS_Y, INPUT_BOX_WIDTH, INPUT_BOX_HEIGHT};
//         SDL_RenderDrawRect(renderer, &inputBoxRect);

//         // Render the input text
//         SDL_Surface* textSurface = TTF_RenderText_Solid(font, inputText.c_str(), textColor);
//         SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//         SDL_FreeSurface(textSurface);
//         SDL_RenderCopy(renderer, textTexture, NULL, &inputBoxRect);

//         SDL_RenderPresent(renderer);
//     }

//     SDL_StopTextInput();  // Disable text input
// }







// Mix_Music *backgroundMusic = NULL;



    // if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    // {
    //     printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    //     return 1;
    // }

    // backgroundMusic = Mix_LoadMUS("../res/background_music.mp3");
    // if (backgroundMusic == NULL)
    // {
    //     printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
    //     return 1;
    // }

    // Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely

    /**/

    // SDL_Texture *SettingPageTexture = surfaceToTexture(renderer,"../res/new_page.png");

    // SDL_Texture *muteButtonTexture = surfaceToTexture(renderer,"../res/mute.png");

    // SDL_Texture *unmuteButtonTexture = surfaceToTexture(renderer,"../res/unmute.png");
   

    // SDL_SetTextureColorMod(muteButtonTexture, 150, 150, 150);
    // SDL_Rect musicButtonRect = {MUSIC_BUTTON_POS_X + 50, MUSIC_BUTTON_POS_Y + 50, 250, 250};


    // SDL_Texture *SettingPageTexture = surfaceToTexture(renderer,"../res/new_page.png");
    // SDL_Texture *muteButtonTexture = surfaceToTexture(renderer,"../res/mute.png");
    // SDL_Texture *unmuteButtonTexture = surfaceToTexture(renderer,"../res/unmute.png");
   
    // SDL_SetTextureColorMod(muteButtonTexture, 150, 150, 150);
    // SDL_Rect musicButtonRect = {MUSIC_BUTTON_POS_X + 50, MUSIC_BUTTON_POS_Y + 50, 250, 250};













/*

for adding music-->


    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return 1;
    }

    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/background_music.mp3");
    if (backgroundMusic == NULL)
    {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return 1;
    }

    Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely



    // Mix_FreeMusic(backgroundMusic);
    // Mix_CloseAudio();

    

*/