#include "main.h"

const int INPUT_BOX_WIDTH = 300;
const int INPUT_BOX_HEIGHT = 40;
const int INPUT_BOX_POS_X = (SCREEN_WIDTH - INPUT_BOX_WIDTH) / 2;
const int INPUT_BOX_POS_Y = 400;

void handleNameInput(SDL_Renderer *renderer, TTF_Font *font, bool &quit, State &currentState, std::string &playerName)
{
    SDL_Event nameInputEvent;
    SDL_StartTextInput(); // Enable text input

    bool inputActive = true;
    SDL_Color textColor = {255, 255, 255};
    std::string inputText;

    while (inputActive)
    {
        while (SDL_PollEvent(&nameInputEvent) != 0)
        {
            if (nameInputEvent.type == SDL_QUIT)
            {
                quit = true;
                inputActive = false;
            }
            else if (nameInputEvent.type == SDL_KEYDOWN)
            {
                if (nameInputEvent.key.keysym.sym == SDLK_RETURN)
                {
                    // Enter key pressed, exit the name input
                    inputActive = false;
                    currentState = MENU;    // Change the state to MENU after name input
                    playerName = inputText; // Save the entered name
                }
                else if (nameInputEvent.key.keysym.sym == SDLK_BACKSPACE && !inputText.empty())
                {
                    // Backspace key pressed, remove a character
                    inputText.pop_back();
                }
            }
            else if (nameInputEvent.type == SDL_TEXTINPUT)
            {
                // Handle text input
                inputText += nameInputEvent.text.text;
            }
        }

        // Render the background
        SDL_RenderClear(renderer);
        SDL_Surface *backgroundSurface = IMG_Load("../res/name_input_page.png");
        SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
        SDL_FreeSurface(backgroundSurface);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        // Render the input box
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect inputBoxRect = {INPUT_BOX_POS_X, INPUT_BOX_POS_Y, INPUT_BOX_WIDTH, INPUT_BOX_HEIGHT};
        SDL_RenderDrawRect(renderer, &inputBoxRect);

        // Render the input text
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, inputText.c_str(), textColor);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
        SDL_RenderCopy(renderer, textTexture, NULL, &inputBoxRect);

        SDL_RenderPresent(renderer);
    }

    SDL_StopTextInput(); // Disable text input
}

// bool loadMediaNameInput()
// {
//     // Loading success flag
//     bool success = true;
//     gBGTexture.loadFromFile("res/Assets/Enter_Name.png");
//     // Open the font
//     gFont = TTF_OpenFont("MyFont3.ttf", 60);
//     if (gFont == NULL)
//     {
//         printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
//         success = false;
//     }
//     else
//     {
//         // Render the prompt
//         SDL_Color textColor = {255, 255, 255, 255};
//         if (!gNameTexture.loadFromRenderedText("Enter Your Nickname! :", textColor))
//         {
//             printf("Failed to render prompt text!\n");
//             success = false;
//         }
//     }
//     return success;
// }

/**/

// #include <iostream>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>

// const int SCREEN_WIDTH = 1600;
// const int SCREEN_HEIGHT = 900;
// const int PLAY_BUTTON_POS_X = 620;
// const int PLAY_BUTTON_POS_Y = 500;

// enum State
// {
//     MENU,
//     NEW_PAGE,
//     PLAY_WINDOW
// };

// void handleMenu(SDL_Renderer *renderer, SDL_Texture *startButtonTexture, SDL_Rect startButtonRect, bool &quit, State &currentState, std::string &playerName);
// void handleNewPage(SDL_Renderer *renderer, SDL_Texture *newPageTexture, SDL_Texture *playButtonTexture, SDL_Rect playButtonRect, bool &quit, State &currentState, std::string &playerName);
// void handlePlayWindow(SDL_Renderer *renderer, SDL_Texture *backgroundTexture, bool &quit, const std::string &playerName);

// int main(int argc, char *argv[])
// {
//     // if (SDL_Init(SDL_INIT_VIDEO) < 0)
//     // {
//     //     printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
//     //     return 1;
//     // }

//     if (TTF_Init() == -1)
//     {
//         printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
//         return 1;
//     }

//     // SDL_Window *window = SDL_CreateWindow("Menu Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//     // if (window == nullptr)
//     // {
//     //     printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
//     //     return 1;
//     // }

//     // SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     // if (renderer == nullptr)
//     // {
//     //     printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
//     //     return 1;
//     // }

//     // SDL_Surface *startButtonSurface = IMG_Load("enter3.png");
//     // if (startButtonSurface == nullptr)
//     // {
//     //     printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
//     //     return 1;
//     // }

//     // SDL_Texture *startButtonTexture = SDL_CreateTextureFromSurface(renderer, startButtonSurface);
//     // SDL_FreeSurface(startButtonSurface);

//     // if (startButtonTexture == nullptr)
//     // {
//     //     printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
//     //     return 1;
//     // }

//     // SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
//     // SDL_Rect startButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 200, 250, 60};

//     // bool quit = false;
//     // State currentState = MENU;
//     std::string playerName;

//     while (!quit)
//     {
//         if (currentState == MENU)
//         {
//             handleMenu(renderer, startButtonTexture, startButtonRect, quit, currentState, playerName);
//         }
//         else if (currentState == NEW_PAGE)
//         {
//             handleNewPage(renderer, startButtonTexture, startButtonRect, quit, currentState, playerName);
//         }
//         else if (currentState == PLAY_WINDOW)
//         {
//             handlePlayWindow(renderer, startButtonTexture, startButtonRect, quit, playerName);
//         }
//     }

//     // SDL_DestroyTexture(startButtonTexture);
//     // SDL_DestroyRenderer(renderer);
//     // SDL_DestroyWindow(window);

//     // TTF_Quit();
//     // IMG_Quit();
//     // SDL_Quit();

//     // return 0;
// }

// void handleMenu(SDL_Renderer *renderer, SDL_Texture *startButtonTexture, SDL_Rect startButtonRect, bool &quit, State &currentState, std::string &playerName)
// {
//     SDL_Event menuEvent;
//     while (SDL_PollEvent(&menuEvent) != 0)
//     {
//         if (menuEvent.type == SDL_QUIT)
//         {
//             quit = true;
//         }
//         else if (menuEvent.type == SDL_MOUSEMOTION)
//         {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);
//             if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
//                 mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h))
//             {
//                 SDL_SetTextureColorMod(startButtonTexture, 255, 255, 255);
//             }
//             else
//             {
//                 SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
//             }
//         }
//         else if (menuEvent.type == SDL_MOUSEBUTTONDOWN)
//         {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);
//             if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
//                 mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h))
//             {
//                 currentState = NEW_PAGE;
//             }
//         }
//     }

//     // SDL_RenderClear(renderer);
//     // SDL_Surface *backgroundSurface = IMG_Load("background2.png");
//     // SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
//     // SDL_FreeSurface(backgroundSurface);
//     // SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//     // SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);

//     // Render player name input
//     TTF_Font *font = TTF_OpenFont("arial.ttf", 28);
//     SDL_Color textColor = {255, 255, 255};
//     SDL_Surface *playerNameSurface = TTF_RenderText_Solid(font, playerName.c_str(), textColor);
//     SDL_Texture *playerNameTexture = SDL_CreateTextureFromSurface(renderer, playerNameSurface);
//     SDL_FreeSurface(playerNameSurface);
//     SDL_Rect playerNameRect = {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 20, 200, 40};
//     SDL_RenderCopy(renderer, playerNameTexture, NULL, &playerNameRect);

//     // SDL_RenderPresent(renderer);

//     // SDL_DestroyTexture(backgroundTexture);
//     SDL_DestroyTexture(playerNameTexture);
//     TTF_CloseFont(font);
// }

// void handleNewPage(SDL_Renderer *renderer, SDL_Texture *startButtonTexture, SDL_Rect startButtonRect, bool &quit, State &currentState, std::string &playerName)
// {
//     SDL_Event newPageEvent;
//     while (SDL_PollEvent(&newPageEvent) != 0)
//     {
//         if (newPageEvent.type == SDL_QUIT)
//         {
//             quit = true;
//         }
//         else if (newPageEvent.type == SDL_MOUSEBUTTONDOWN)
//         {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);
//             if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
//                 mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h))
//             {
//                 currentState = PLAY_WINDOW;
//             }
//         }
//         else if (newPageEvent.type == SDL_TEXTINPUT)
//         {
//             playerName += newPageEvent.text.text;
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);

//     // Render player name input
//     TTF_Font *font = TTF_OpenFont("arial.ttf", 28);
//     SDL_Color textColor = {255, 255, 255};
//     SDL_Surface *playerNameSurface = TTF_RenderText_Solid(font, playerName.c_str(), textColor);
//     SDL_Texture *playerNameTexture = SDL_CreateTextureFromSurface(renderer, playerNameSurface);
//     SDL_FreeSurface(playerNameSurface);
//     SDL_Rect playerNameRect = {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 20, 200, 40};
//     SDL_RenderCopy(renderer, playerNameTexture, NULL, &playerNameRect);

//     SDL_RenderPresent(renderer);

//     SDL_DestroyTexture(playerNameTexture);
//     TTF_CloseFont(font);
// }

// void handlePlayWindow(SDL_Renderer *renderer, SDL_Texture *startButtonTexture, SDL_Rect startButtonRect, bool &quit, const std::string &playerName)
// {
//     SDL_Event playWindowEvent;
//     while (SDL_PollEvent(&playWindowEvent) != 0)
//     {
//         if (playWindowEvent.type == SDL_QUIT)
//         {
//             quit = true;
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);

//     // Render player name
//     TTF_Font *font = TTF_OpenFont("arial.ttf", 28);
//     SDL_Color textColor = {255, 255, 255};
//     SDL_Surface *playerNameSurface = TTF_RenderText_Solid(font, playerName.c_str(), textColor);
//     SDL_Texture *playerNameTexture = SDL_CreateTextureFromSurface(renderer, playerNameSurface);
//     SDL_FreeSurface(playerNameSurface);
//     SDL_Rect playerNameRect = {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 20, 200, 40};
//     SDL_RenderCopy(renderer, playerNameTexture, NULL, &playerNameRect);

//     SDL_RenderPresent(renderer);

//     SDL_DestroyTexture(playerNameTexture);
//     TTF_CloseFont(font);
// }
