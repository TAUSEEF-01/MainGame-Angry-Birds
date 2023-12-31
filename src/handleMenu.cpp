#include "main.h"

// This is the first page. Loading screen.

void handleMenu(SDL_Renderer *renderer, bool &quit, State &currentState)
{
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

    SDL_Texture *texture = IMG_LoadTexture(renderer, "../res/setting_background.png");
    SDL_Event menuEvent;

    SDL_Event e;
    bool wait = 1;

    SDL_Rect border = {50, 850, 1500, 20};

    SDL_Rect inside = {51, 851, 0, 18};

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture, NULL, NULL);

        if (wait)
        {
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            wait = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderDrawRect(renderer, &border);

        // Render red filled quad

        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &inside);

        if (inside.w <= 1498)
            inside.w++;
        else
        {
            currentState = NEW_PAGE;
            SDL_Delay(1000);
            return;
        }

        SDL_RenderPresent(renderer);
    }
}










// void handleMenu(SDL_Renderer *renderer, bool &quit, State &currentState)
// {
//     // SDL_Surface* backgroundSurface = IMG_Load("../res/Firstpage.png");
//     SDL_Surface* backgroundSurface = IMG_Load("../res/setting_background.png");
//     if (backgroundSurface == nullptr) {
//         printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
//     SDL_FreeSurface(backgroundSurface);

//     if (backgroundTexture == nullptr) {
//         printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_RenderClear(renderer);

//     SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//     SDL_RenderPresent(renderer);

//     SDL_Delay(3000);
//     currentState = NEW_PAGE;

//     SDL_DestroyTexture(backgroundTexture);

// }



















// void handleMenu(SDL_Renderer *renderer, bool &quit, State &currentState)
// {
    // SDL_Surface *startButtonSurface = IMG_Load("../res/enter3.png");
    // if (startButtonSurface == nullptr)
    // {
    //     printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }

    // SDL_Texture *startButtonTexture = SDL_CreateTextureFromSurface(renderer, startButtonSurface);
    // SDL_FreeSurface(startButtonSurface);

    // if (startButtonTexture == nullptr)
    // {
    //     printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }

    // SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
    // SDL_Rect startButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 200, 250, 60};

    // SDL_Surface *newPageSurface = IMG_Load("../res/new_page2.png");
    // if (newPageSurface == nullptr)
    // {
    //     printf("Unable to load new page image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }

    // SDL_Texture *newPageTexture = SDL_CreateTextureFromSurface(renderer, newPageSurface);
    // SDL_FreeSurface(newPageSurface);

    // if (newPageTexture == nullptr)
    // {
    //     printf("Unable to create texture from new page image! SDL_Error: %s\n", SDL_GetError());
    //     return;
    // }



    // if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    // {
    //     printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    //     return;
    // }

    // Mix_Music *backgroundMusic = Mix_LoadMUS("../res/back_button.mp3");
    // if (backgroundMusic == NULL)
    // {
    //     printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
    //     return; 
    // }



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
//                 Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely          
//                 SDL_Delay(100);          
//                 currentState = NEW_PAGE;

//                 /**/ //changed this part-->
//                 Mix_FreeMusic(backgroundMusic);
//                 Mix_CloseAudio();
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
    
//     SDL_Surface *backgroundSurface = IMG_Load("../res/Firstpage.png");
//     SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);


    

//     SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);



//     SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);

//     SDL_RenderPresent(renderer);

//     SDL_DestroyTexture(backgroundTexture);


//     SDL_DestroyTexture(startButtonTexture);

//     SDL_DestroyTexture(newPageTexture);

// }



























// #include "main.h"


// void handleMenu(SDL_Renderer *renderer, bool &quit, State &currentState)
// {
//     // SDL_Surface* backgroundSurface = IMG_Load("../res/Firstpage.png");
//     SDL_Surface* backgroundSurface = IMG_Load("../res/setting_background.png");
//     if (backgroundSurface == nullptr) {
//         printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
//     SDL_FreeSurface(backgroundSurface);

//     if (backgroundTexture == nullptr) {
//         printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_RenderClear(renderer);

//     SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//     SDL_RenderPresent(renderer);

//     SDL_Delay(3000);
//     currentState = NEW_PAGE;

//     SDL_DestroyTexture(backgroundTexture);

// }



















// // void handleMenu(SDL_Renderer *renderer, bool &quit, State &currentState)
// // {
// //     SDL_Surface *startButtonSurface = IMG_Load("../res/enter3.png");
// //     if (startButtonSurface == nullptr)
// //     {
// //         printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
// //         return;
// //     }

// //     SDL_Texture *startButtonTexture = SDL_CreateTextureFromSurface(renderer, startButtonSurface);
// //     SDL_FreeSurface(startButtonSurface);

// //     if (startButtonTexture == nullptr)
// //     {
// //         printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
// //         return;
// //     }

// //     SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
// //     SDL_Rect startButtonRect = {PLAY_BUTTON_POS_X + 50, PLAY_BUTTON_POS_Y + 200, 250, 60};

// //     SDL_Surface *newPageSurface = IMG_Load("../res/new_page2.png");
// //     if (newPageSurface == nullptr)
// //     {
// //         printf("Unable to load new page image! SDL_Error: %s\n", SDL_GetError());
// //         return;
// //     }

// //     SDL_Texture *newPageTexture = SDL_CreateTextureFromSurface(renderer, newPageSurface);
// //     SDL_FreeSurface(newPageSurface);

// //     if (newPageTexture == nullptr)
// //     {
// //         printf("Unable to create texture from new page image! SDL_Error: %s\n", SDL_GetError());
// //         return;
// //     }



// //     if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
// //     {
// //         printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
// //         return;
// //     }

// //     Mix_Music *backgroundMusic = Mix_LoadMUS("../res/back_button.mp3");
// //     if (backgroundMusic == NULL)
// //     {
// //         printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
// //         return; 
// //     }



// //     SDL_Event menuEvent;
// //     while (SDL_PollEvent(&menuEvent) != 0)
// //     {
// //         if (menuEvent.type == SDL_QUIT)
// //         {
// //             quit = true;
// //         }
// //         else if (menuEvent.type == SDL_MOUSEMOTION)
// //         {
// //             int mouseX, mouseY;
// //             SDL_GetMouseState(&mouseX, &mouseY);
// //             if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
// //                 mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h))
// //             {
// //                 SDL_SetTextureColorMod(startButtonTexture, 255, 255, 255);
// //             }
// //             else
// //             {
// //                 SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
// //             }
// //         }
// //         else if (menuEvent.type == SDL_MOUSEBUTTONDOWN)
// //         {
// //             int mouseX, mouseY;
// //             SDL_GetMouseState(&mouseX, &mouseY);
// //             if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
// //                 mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h))
// //             {
// //                 Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely          
// //                 SDL_Delay(100);          
// //                 currentState = NEW_PAGE;

// //                 /**/ //changed this part-->
// //                 Mix_FreeMusic(backgroundMusic);
// //                 Mix_CloseAudio();
// //             }
// //         }
// //     }

// //     SDL_RenderClear(renderer);
    
// //     SDL_Surface *backgroundSurface = IMG_Load("../res/Firstpage.png");
// //     SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);


    

// //     SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);



// //     SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);

// //     SDL_RenderPresent(renderer);

// //     SDL_DestroyTexture(backgroundTexture);


// //     SDL_DestroyTexture(startButtonTexture);

// //     SDL_DestroyTexture(newPageTexture);

// // }



