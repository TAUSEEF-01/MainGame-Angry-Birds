#include "main.h"

void showStory(SDL_Renderer *renderer, bool &quit, State &currentState)
{
    SDL_Texture *backgroundTexture = surfaceToTexture(renderer, "../res/Designer.png");

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_RenderPresent(renderer);

    SDL_Delay(5000);
    currentState = LEVEL2;

    SDL_DestroyTexture(backgroundTexture);
}

// void showStory(SDL_Renderer* renderer, TTF_Font* font, State &currentState) {


//     // // Text color (black in this case)
//     // SDL_Color textColor = { 0, 0, 0 };

//     // // The story text
//     // std::string storyText = "In a world of colorful birds, each with unique abilities, life was peaceful until a group of green pigs stole their precious eggs." ;
//     //                         // "Led by Red, the birds, including fast Chuck and explosive Bomb, fought back using a giant slingshot."  
//     //                         // "Despite challenging battles and complex structures, the birds used their abilities and teamwork to defeat the pigs and retrieve their eggs." 
//     //                         // "The tale of their victory became a legend of courage, determination, and the power of teamwork.";

//     // // Render the story text on the screen
//     // SDL_Surface* textSurface = TTF_RenderText_Solid(font, storyText.c_str(), textColor);
//     // if (textSurface == nullptr) {
//     //     printf("Unable to render text! SDL_ttf Error: %s\n", TTF_GetError());
//     //     return;
//     // }

//     // SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//     // if (textTexture == nullptr) {
//     //     printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
//     //     SDL_FreeSurface(textSurface);
//     //     return;
//     // }

//     // // Clear the renderer
//     // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//     // SDL_RenderClear(renderer);

//     // // Set the position and size of the text rectangle
//     // SDL_Rect textRect = { 50, 50, 1500, 800 };

//     // // Render the text texture
//     // SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

//     // // Present the renderer
//     // SDL_RenderPresent(renderer);

//     // // Wait for a key press to continue or any other condition you want
//     // SDL_Event event;
//     // bool waitForKey = true;
//     // while (waitForKey) {
//     //     while (SDL_PollEvent(&event) != 0) {
//     //         if (event.type == SDL_QUIT) {
//     //             // Handle quit event
//     //             // You might want to return from the function or set a flag to exit the game
//     //         } else if (event.type == SDL_KEYDOWN) {
//     //             waitForKey = false;  // Continue when any key is pressed
//     //             currentState = NEW_PAGE;
//     //             SDL_Delay(5000);
//     //             return;
//     //         }
//     //     }
//     // }

//     // // Clean up resources
//     // SDL_DestroyTexture(textTexture);
//     // SDL_FreeSurface(textSurface);
    
// }
