#include "main.h"

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
        SDL_Surface *backgroundSurface = IMG_Load("../res/name_input_page3.png");
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
    
    currentState = LEVEL1_LOADING_PAGE;
}
