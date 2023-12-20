#include "main.h"

void handleNameInput(SDL_Renderer *renderer, TTF_Font *font, bool &quit, State &currentState, std::string &playerName, int &turns)
{
    turns = 15;

    SDL_Event nameInputEvent;
    SDL_StartTextInput(); // Enable text input

    bool inputActive = true;
    SDL_Color textColor = {255, 0, 0};
    std::string inputText;

    
    playerName = ""; // every time  initialize the player's name with empty string.

    // Render text
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, ("Write your name: " + playerName).c_str(), {0, 0, 0});
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

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
        SDL_Surface *backgroundSurface = IMG_Load("../res/name_input_page3.png");
        SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
        SDL_FreeSurface(backgroundSurface);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);


        // Set drawing color to white
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // Draw a filled white rectangle at the top
        SDL_Rect topRect = {0, 0, SCREEN_WIDTH, 50};
        SDL_RenderFillRect(renderer, &topRect);
        // SDL_RenderDrawRect(renderer, &topRect);

        // Set drawing color to black for text
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        // // Render text
        // textSurface = TTF_RenderText_Solid(font, ("Write your name: " + playerName).c_str(), {0, 0, 0});
        textSurface = TTF_RenderText_Solid(font, ("Write your name: " + inputText).c_str(), {0, 0, 0}); // showing the typed letter and the current string
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        SDL_Rect textRect = {10, 10, textSurface->w, textSurface->h};  // Adjust position as needed
        SDL_FreeSurface(textSurface);
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);


        SDL_RenderPresent(renderer);
        SDL_Delay(500);
        
    }

    SDL_StopTextInput(); // Disable text input
    SDL_DestroyTexture(textTexture);
    
    currentState = LEVEL1_LOADING_PAGE;
}
