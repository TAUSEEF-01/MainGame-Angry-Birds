// #include "main.h"

// // This is the first level of the game.



// // int musicPlaying = 1;              // Flag to indicate if music is playing (1 for playing, 0 for stopped)
// SDL_Texture *currentButtonTexture2; // Variable to hold the current button texture

// // Function to toggle music on/off
// void toggleMusic2(SDL_Texture *muteTexture, SDL_Texture *unmuteTexture, int &musicPlaying)
// {
//     if (musicPlaying)
//     {
//         Mix_PauseMusic();                     // Pause the music
//         musicPlaying = 0;                     // Update the flag to indicate music is stopped
//         currentButtonTexture2 = unmuteTexture; // Set the texture to unmute button
//     }
//     else
//     {
//         Mix_ResumeMusic();                  // Resume the music
//         musicPlaying = 1;                   // Update the flag to indicate music is playing
//         currentButtonTexture2 = muteTexture; // Set the texture to mute button
//     }
// }

// bool collide2(SDL_Rect a, SDL_Rect b)
// {
//     if (((a.x + a.w) > (b.x + 30)) && ((a.x + 50) < (b.x + b.w)) && ((a.y + a.h) > (b.y + 10)) && (((a.y + 30) < (b.y + b.h))))
//         return 1;
//     return 0;
// }


// // void handlePlayWindow(SDL_Renderer *renderer, bool &quit, State &currentState, int &musicPlaying)
// void level2(SDL_Renderer *renderer, bool &quit, State &currentState, int &musicPlaying, std::string &playerName)
// {
//     SDL_Texture *backgroundPlayTexture = surfaceToTexture(renderer, "../res/background_play.png");
//     SDL_Texture *birdTexture = surfaceToTexture(renderer, "../res/yellow_bird2.png");
//     SDL_Texture *slingshot_back = surfaceToTexture(renderer, "../res/slingshot_back.png");
//     SDL_Texture *slingshot_front = surfaceToTexture(renderer, "../res/slingshot_front.png");
//     SDL_Texture *green_bird = surfaceToTexture(renderer, "../res/green_bird.png");
//     SDL_Texture *back_buttonTexture = surfaceToTexture(renderer, "../res/back_button.png");
//     SDL_Texture *muteButtonTexture = surfaceToTexture(renderer, "../res/mute2.png");
//     SDL_Texture *unmuteButtonTexture = surfaceToTexture(renderer, "../res/unmute2.png");

//     SDL_SetTextureColorMod(back_buttonTexture, 150, 150, 150);
//     SDL_Rect playButtonRect = {30, 30, 100, 100};

//     SDL_SetTextureColorMod(muteButtonTexture, 150, 150, 150);
//     SDL_Rect musicButtonRect = {1450, 30, 80, 80};

//     if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
//     {
//         printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
//         return;
//     }

//     Mix_Music *backButtonMusic = Music("../res/back_button.mp3");
//     Mix_Music *backgroundMusic = Music("../res/background_music.mp3");

//     if (musicPlaying)
//         Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely



//     /**/
//     // Render the player's name on top of the window
//     TTF_Font* nameFont = TTF_OpenFont("roboto.ttf", 28);  // Use a font size that fits your needs
//     if (nameFont == nullptr) {
//         printf("Unable to load font! SDL_ttf Error: %s\n", TTF_GetError());
//         return;
//     }

//     SDL_Color nameColor = {255, 255, 255};
//     SDL_Surface* nameSurface = TTF_RenderText_Solid(nameFont, playerName.c_str(), nameColor);
//     SDL_Texture* nameTexture = SDL_CreateTextureFromSurface(renderer, nameSurface);
//     SDL_FreeSurface(nameSurface);

//     // Position the player's name at the top center of the window
//     int namePosX = (SCREEN_WIDTH - nameSurface->w) / 2;
//     int namePosY = 20;

//     SDL_Rect nameRect = {namePosX, namePosY, nameSurface->w, nameSurface->h};
//     /**/


//     SDL_Event e;

//     bool jump = 0, Green = 1, clicked = 0; // clikcked
//     int Bird_length = 50;

//     double speed_x = 0.0, speed_y = 0.0, vf = 0.0;
//     double gravity = 0.5;

//     int X = 0, Y = 0, count = 0, Start_x = 210, Start_y = 560, count_of_collision_with_wall = 0;
//     int prev_x_position = -100;

//     SDL_Rect bird_rect = {Start_x, Start_y, Bird_length, Bird_length};
//     SDL_Rect slingshot_rect = {210, 580, 47, 124};
//     SDL_Rect green_bird_rect = {1400, 480, 100, 100};

//     while (!quit)
//     {
//         while (SDL_PollEvent(&e))
//         {
//             if (e.type == SDL_QUIT)
//                 quit = true;
//             else if (e.type == SDL_MOUSEMOTION && SDL_MOUSEBUTTONDOWN)
//             {
//                 if (!jump)
//                 {
//                     SDL_GetMouseState(&X, &Y);

//                     if (e.button.button == SDL_BUTTON_LEFT)
//                     {

//                         if (clicked || (X >= bird_rect.x && X <= bird_rect.x + Bird_length) && (Y >= bird_rect.y && Y <= bird_rect.y + Bird_length)) // is clicked inside bird
//                         {

//                             clicked = 1; // extra
//                             if ((X - Bird_length / 2) >= 0 && (X) <= (SCREEN_WIDTH / 2))
//                             {
//                                 bird_rect.x = X - Bird_length / 2;
//                             }
//                             if ((Y - Bird_length) >= 0 && (Y) <= (SCREEN_HEIGHT - 4.5 * Bird_length))
//                                 bird_rect.y = Y - Bird_length / 2;
//                         }
//                     }
//                 }
//             }
//             else if (e.type == SDL_MOUSEBUTTONUP)
//             {
//                 clicked = 0;

//                 if (e.button.button == SDL_BUTTON_LEFT)
//                 {
//                     speed_x = (Start_x - bird_rect.x) / 5.0;
//                     speed_y = -(Start_y - bird_rect.y) / 5.0;
//                     bird_rect.x = Start_x;
//                     bird_rect.y = Start_y;

//                     jump = 1;
//                 }
//             }

//             /**/
//             if (e.type == SDL_MOUSEMOTION)
//             {
//                 int mouseX, mouseY;
//                 SDL_GetMouseState(&mouseX, &mouseY);
//                 if (X >= playButtonRect.x && X <= (playButtonRect.x + playButtonRect.w) &&
//                     Y >= playButtonRect.y && Y <= (playButtonRect.y + playButtonRect.h))
//                 {
//                     SDL_SetTextureColorMod(back_buttonTexture, 255, 255, 255);
//                 }
//                 else
//                 {
//                     SDL_SetTextureColorMod(back_buttonTexture, 150, 150, 150);
//                 }

//                 if (mouseX >= musicButtonRect.x && mouseX <= (musicButtonRect.x + musicButtonRect.w) &&
//                     mouseY >= musicButtonRect.y && mouseY <= (musicButtonRect.y + musicButtonRect.h))
//                 {
//                     SDL_SetTextureColorMod(currentButtonTexture2, 255, 255, 255);
//                 }
//                 else
//                 {
//                     SDL_SetTextureColorMod(currentButtonTexture2, 150, 150, 150);
//                 }
//             }

//             /**/
//             if (e.type == SDL_MOUSEBUTTONDOWN)
//             {
//                 SDL_GetMouseState(&X, &Y);

//                 if (X >= playButtonRect.x && X <= (playButtonRect.x + playButtonRect.w) &&
//                     Y >= playButtonRect.y && Y <= (playButtonRect.y + playButtonRect.h))
//                 {
//                     printf("Back button clicked!\n"); // make sure kortesi j setting button kaj kore kina

//                     Mix_PlayMusic(backButtonMusic, -1); // Start playing music indefinitely
//                     Mix_FreeMusic(backgroundMusic);
//                     Mix_CloseAudio();
//                     SDL_Delay(100);

//                     currentState = NEW_PAGE;
//                     Mix_FreeMusic(backButtonMusic);
//                     Mix_CloseAudio();

//                     return;
//                 }

//                 if (X >= musicButtonRect.x && X <= (musicButtonRect.x + musicButtonRect.w) &&
//                     Y >= musicButtonRect.y && Y <= (musicButtonRect.y + musicButtonRect.h))
//                 {
//                     toggleMusic2(muteButtonTexture, unmuteButtonTexture, musicPlaying);
//                     // SDL_Delay(150);
//                 }
//             }
//         }

//         if (musicPlaying)
//         {
//             currentButtonTexture2 = muteButtonTexture;
//         }
//         else
//         {
//             currentButtonTexture2 = unmuteButtonTexture;
//         }

//         if (jump && speed_x)
//         {
//             // bird_rect.x += (((int)speed_x) ? ((int)speed_x) : 1);
//             bird_rect.x += speed_x;

//             if (bird_rect.x - 50 >= (SCREEN_WIDTH) || (bird_rect.x + Bird_length + 100 <= 0))
//             {
//                 jump = 0;

//                 if (Green == 0) // Level
//                 {
//                     currentState = LEVEL3_LOADING_PAGE; // added extra

//                     printf("Bird got hit.\n");

//                     SDL_DestroyTexture(backgroundPlayTexture);
//                     SDL_DestroyTexture(birdTexture);
//                     return;
//                 }
                
//                 Green = 1;

//                 bird_rect.x = Start_x;
//                 bird_rect.y = Start_y;

//                 SDL_Delay(500);

//                 goto here;
//                 // speed_x = -speed_x;
//             }

//             bird_rect.y -= speed_y;
//             speed_y -= gravity;

//             if ((bird_rect.y >= (SCREEN_HEIGHT - 5 * Bird_length))) // (bird_rect.y <= 0)
//             {
//                 speed_y = -(speed_y);
//                 bird_rect.y = (SCREEN_HEIGHT - 4.8 * Bird_length); // if goes down the limit, it is forced to stay at the limit
//                 // printf("%lf\n", speed_y);

//                 // reamaining speed after a bounce
//                 speed_y *= 0.60;
//                 speed_x *= 0.90;

//                 // speed_y--;
//                 // speed_y -= 2.0 / 30.0;
//                 // printf("%lf\n", speed_y);
//             }
//         }

//         if (((abs(speed_x) < 0.01) || (prev_x_position == bird_rect.x)) && abs(speed_y) < 5 && jump)
//         {
//             jump = 0;
//             speed_y = 0.0;
//             Green = 1;

//             if (bird_rect.x != Start_x || bird_rect.y != Start_y)
//                 SDL_Delay(500);

//             bird_rect.x = Start_x;
//             bird_rect.y = Start_y;
//         }

//         if (jump) // frame rate
//             SDL_Delay(10);

//     here:
//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, backgroundPlayTexture, NULL, NULL);
//         SDL_RenderCopy(renderer, slingshot_back, NULL, &slingshot_rect);
//         SDL_RenderCopy(renderer, birdTexture, NULL, &bird_rect);
//         SDL_RenderCopy(renderer, nameTexture, NULL, &nameRect);

//         SDL_RenderCopy(renderer, back_buttonTexture, NULL, &playButtonRect); // showing the back button

//         if (!musicPlaying)
//             SDL_RenderCopy(renderer, muteButtonTexture, NULL, &musicButtonRect); // showing the music button
//         if (musicPlaying)
//             SDL_RenderCopy(renderer, unmuteButtonTexture, NULL, &musicButtonRect); // showing the music button

//         if (!collide2(bird_rect, green_bird_rect) && Green)
//             SDL_RenderCopy(renderer, green_bird, NULL, &green_bird_rect);
//         else
//         {
//             Green = 0;
//             // bird_rect.x = Start_x;
//             // bird_rect.y = Start_y;
//             // SDL_Delay(500);
//         }

//         SDL_RenderCopy(renderer, slingshot_front, NULL, &slingshot_rect);
//         SDL_RenderPresent(renderer);

//         prev_x_position = bird_rect.x;
//     }


//     Mix_FreeMusic(backgroundMusic);
//     Mix_CloseAudio();

//     SDL_RenderCopy(renderer, currentButtonTexture2, NULL, &musicButtonRect);
//     SDL_RenderPresent(renderer);

//     SDL_DestroyTexture(muteButtonTexture);
//     SDL_DestroyTexture(unmuteButtonTexture);

//     SDL_DestroyTexture(backgroundPlayTexture);
//     SDL_DestroyTexture(birdTexture);


//     /**/
//     SDL_DestroyTexture(nameTexture);
//     TTF_CloseFont(nameFont);
// }











#include "main.h"

// This is the second level of the game.


SDL_Texture *currentButtonTexture2; // Variable to hold the current button texture

// Function to toggle music on/off
void toggleMusic2(SDL_Texture *muteTexture, SDL_Texture *unmuteTexture, int &musicPlaying)
{
    if (musicPlaying)
    {
        Mix_PauseMusic();                      // Pause the music
        musicPlaying = 0;                      // Update the flag to indicate music is stopped
        currentButtonTexture2 = unmuteTexture; // Set the texture to unmute button
    }
    else
    {
        Mix_ResumeMusic();                   // Resume the music
        musicPlaying = 1;                    // Update the flag to indicate music is playing
        currentButtonTexture2 = muteTexture; // Set the texture to mute button
    }
}

bool collide2(SDL_Rect a, SDL_Rect b)
{
    if (((a.x + a.w) > (b.x + 30)) && ((a.x + 50) < (b.x + b.w)) && ((a.y + a.h) > (b.y + 10)) && (((a.y + 30) < (b.y + b.h))))
        return 1;
    return 0;
}

void level2(SDL_Renderer *renderer, bool &quit, State &currentState, int &musicPlaying, std::string &playerName)
{
    SDL_Texture *backgroundPlayTexture = surfaceToTexture(renderer, "../res/level2_background.png");
    SDL_Texture *birdTexture = surfaceToTexture(renderer, "../res/yellow_bird2.png");
    SDL_Texture *slingshot_back = surfaceToTexture(renderer, "../res/slingshot_back.png");
    SDL_Texture *slingshot_front = surfaceToTexture(renderer, "../res/slingshot_front.png");
    SDL_Texture *green_bird = surfaceToTexture(renderer, "../res/green_bird.png");
    SDL_Texture *back_buttonTexture = surfaceToTexture(renderer, "../res/back_button.png");
    SDL_Texture *muteButtonTexture = surfaceToTexture(renderer, "../res/mute2.png");
    SDL_Texture *unmuteButtonTexture = surfaceToTexture(renderer, "../res/unmute2.png");

    SDL_SetTextureColorMod(back_buttonTexture, 150, 150, 150);
    SDL_Rect playButtonRect = {30, 30, 100, 100};

    SDL_SetTextureColorMod(muteButtonTexture, 150, 150, 150);
    SDL_Rect musicButtonRect = {1450, 30, 80, 80};

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    Mix_Music *backButtonMusic = Music("../res/back_button.mp3");
    Mix_Music *backgroundMusic = Music("../res/background_music.mp3");

    if (musicPlaying)
        Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely


    /**/
    // Render the player's name on top of the window
    TTF_Font* nameFont = TTF_OpenFont("roboto.ttf", 28);  // Use a font size that fits your needs
    if (nameFont == nullptr) {
        printf("Unable to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return;
    }

    SDL_Color nameColor = {255, 255, 255};
    SDL_Surface* nameSurface = TTF_RenderText_Solid(nameFont, playerName.c_str(), nameColor);
    SDL_Texture* nameTexture = SDL_CreateTextureFromSurface(renderer, nameSurface);
    SDL_FreeSurface(nameSurface);

    // Position the player's name at the top center of the window
    int namePosX = (SCREEN_WIDTH - nameSurface->w) / 2;
    int namePosY = 20;

    SDL_Rect nameRect = {namePosX, namePosY, nameSurface->w, nameSurface->h};
    /**/



    SDL_Event e;

    bool jump = 0, Green = 1, clicked = 0; // clikcked
    int Bird_length = 50;

    double speed_x = 0.0, speed_y = 0.0, vf = 0.0;
    double gravity = 0.5;

    int X = 0, Y = 0, count = 0, Start_x = 210, Start_y = 625, count_of_collision_with_wall = 0;
    int prev_x_position = -100;

    SDL_Rect bird_rect = {Start_x, Start_y, Bird_length, Bird_length};
    SDL_Rect slingshot_rect = {210, 645, 47, 124};
    SDL_Rect green_bird_rect = {1400, 545, 100, 100};

    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_MOUSEMOTION && SDL_MOUSEBUTTONDOWN)
            {
                if (!jump)
                {
                    SDL_GetMouseState(&X, &Y);

                    if (e.button.button == SDL_BUTTON_LEFT)
                    {

                        if (clicked || (X >= bird_rect.x && X <= bird_rect.x + Bird_length) && (Y >= bird_rect.y && Y <= bird_rect.y + Bird_length)) // is clicked inside bird
                        {

                            clicked = 1; // extra
                            if ((X - Bird_length / 2) >= 0 && (X) <= (SCREEN_WIDTH / 2))
                            {
                                bird_rect.x = X - Bird_length / 2;
                            }
                            if ((Y - Bird_length) >= 0 && (Y) <= (SCREEN_HEIGHT - 4.5 * Bird_length + 70))
                                bird_rect.y = Y - Bird_length / 2;
                        }
                    }
                }
            }
            else if (e.type == SDL_MOUSEBUTTONUP)
            {
                clicked = 0;

                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    speed_x = (Start_x - bird_rect.x) / 5.0;
                    speed_y = -(Start_y - bird_rect.y) / 5.0;
                    bird_rect.x = Start_x;
                    bird_rect.y = Start_y;

                    jump = 1;
                }
            }

            /**/
            if (e.type == SDL_MOUSEMOTION)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (X >= playButtonRect.x && X <= (playButtonRect.x + playButtonRect.w) &&
                    Y >= playButtonRect.y && Y <= (playButtonRect.y + playButtonRect.h))
                {
                    SDL_SetTextureColorMod(back_buttonTexture, 255, 255, 255);
                }
                else
                {
                    SDL_SetTextureColorMod(back_buttonTexture, 150, 150, 150);
                }

                if (mouseX >= musicButtonRect.x && mouseX <= (musicButtonRect.x + musicButtonRect.w) &&
                    mouseY >= musicButtonRect.y && mouseY <= (musicButtonRect.y + musicButtonRect.h))
                {
                    SDL_SetTextureColorMod(currentButtonTexture2, 255, 255, 255);
                }
                else
                {
                    SDL_SetTextureColorMod(currentButtonTexture2, 150, 150, 150);
                }
            }

            /**/
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&X, &Y);

                if (X >= playButtonRect.x && X <= (playButtonRect.x + playButtonRect.w) &&
                    Y >= playButtonRect.y && Y <= (playButtonRect.y + playButtonRect.h))
                {
                    printf("Back button clicked!\n"); // make sure kortesi j setting button kaj kore kina

                    Mix_PlayMusic(backButtonMusic, -1); // Start playing music indefinitely
                    Mix_FreeMusic(backgroundMusic);
                    Mix_CloseAudio();
                    SDL_Delay(100);

                    currentState = NEW_PAGE;
                    Mix_FreeMusic(backButtonMusic);
                    Mix_CloseAudio();

                    currentButtonTexture2 = unmuteButtonTexture;
                    musicPlaying = 1;

                    return;
                }

                if (X >= musicButtonRect.x && X <= (musicButtonRect.x + musicButtonRect.w) &&
                    Y >= musicButtonRect.y && Y <= (musicButtonRect.y + musicButtonRect.h))
                {
                    toggleMusic2(muteButtonTexture, unmuteButtonTexture, musicPlaying);
                    // SDL_Delay(150);
                }
            }
        }

        if (musicPlaying)
        {
            currentButtonTexture2 = muteButtonTexture;
        }
        else
        {
            currentButtonTexture2 = unmuteButtonTexture;
        }

        if (jump && speed_x)
        {
            // bird_rect.x += (((int)speed_x) ? ((int)speed_x) : 1);
            bird_rect.x += speed_x;

            if (bird_rect.x - 50 >= (SCREEN_WIDTH) || (bird_rect.x + Bird_length + 100 <= 0))
            {
                jump = 0;

                if (Green == 0) // Level
                {
                    currentState = LEVEL3_LOADING_PAGE; // added extra

                    printf("Bird got hit. level2\n");

                    SDL_DestroyTexture(backgroundPlayTexture);
                    SDL_DestroyTexture(birdTexture);
                    return;
                }

                Green = 1;

                bird_rect.x = Start_x;
                bird_rect.y = Start_y;

                SDL_Delay(500);
                goto here;
                // speed_x = -speed_x;
            }

            bird_rect.y -= speed_y;
            speed_y -= gravity;

            if ((bird_rect.y >= (SCREEN_HEIGHT - 5 * Bird_length + 70))) // (bird_rect.y <= 0)
            {
                speed_y = -(speed_y);
                bird_rect.y = (SCREEN_HEIGHT - 4.8 * Bird_length + 70); // if goes down the limit, it is forced to stay at the limit
                // printf("%lf\n", speed_y);

                // reamaining speed after a bounce
                speed_y *= 0.60;
                speed_x *= 0.90;

                // speed_y--;
                // speed_y -= 2.0 / 30.0;
                // printf("%lf\n", speed_y);
            }
        }

        if (((abs(speed_x) < 0.01) || (prev_x_position == bird_rect.x)) && abs(speed_y) < 5 && jump)
        {
            jump = 0;
            speed_y = 0.0;
            Green = 1;

            if (bird_rect.x != Start_x || bird_rect.y != Start_y)
                SDL_Delay(500);

            bird_rect.x = Start_x;
            bird_rect.y = Start_y;
        }

        if (jump) // frame rate
            SDL_Delay(10);

    here:
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundPlayTexture, NULL, NULL);
        SDL_RenderCopy(renderer, slingshot_back, NULL, &slingshot_rect);
        SDL_RenderCopy(renderer, birdTexture, NULL, &bird_rect);
        SDL_RenderCopy(renderer, nameTexture, NULL, &nameRect);


        SDL_RenderCopy(renderer, back_buttonTexture, NULL, &playButtonRect); // showing the back button

        if (!musicPlaying)
        {
            SDL_RenderCopy(renderer, muteButtonTexture, NULL, &musicButtonRect); // showing the music button
        }
        if (musicPlaying)
        {
            SDL_RenderCopy(renderer, unmuteButtonTexture, NULL, &musicButtonRect); // showing the music button
        }

        if (!collide2(bird_rect, green_bird_rect) && Green)
            SDL_RenderCopy(renderer, green_bird, NULL, &green_bird_rect);
        else
        {
            Green = 0;
            // bird_rect.x = Start_x;
            // bird_rect.y = Start_y;
            // SDL_Delay(500);
        }

        SDL_RenderCopy(renderer, slingshot_front, NULL, &slingshot_rect);
        SDL_RenderPresent(renderer);

        prev_x_position = bird_rect.x;

        // if (Green == 0)
        // {
        //     currentState = LEVEL2; //added extra

        //     SDL_DestroyTexture(backgroundPlayTexture);
        //     SDL_DestroyTexture(birdTexture);
        //     return;
        // }
    }

    Mix_FreeMusic(backgroundMusic);
    Mix_CloseAudio();

    SDL_RenderCopy(renderer, currentButtonTexture2, NULL, &musicButtonRect);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(muteButtonTexture);
    SDL_DestroyTexture(unmuteButtonTexture);

    SDL_DestroyTexture(backgroundPlayTexture);
    SDL_DestroyTexture(birdTexture);


    /**/
    SDL_DestroyTexture(nameTexture);
    TTF_CloseFont(nameFont);
}










// Mix_Music *backButtonMusic = Mix_LoadMUS("../res/back_button.mp3");
// if (backButtonMusic == NULL)
// {
//     printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
//     return;
// }

// Mix_Music *backgroundMusic = Mix_LoadMUS("../res/background_music.mp3");
// if (backgroundMusic == NULL)
// {
//     printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
//     return;
// }

// SDL_Surface *muteButtonSurface = IMG_Load("../res/mute2.png");
// if (muteButtonSurface == nullptr)
// {
//     printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Texture *muteButtonTexture = SDL_CreateTextureFromSurface(renderer, muteButtonSurface);
// SDL_FreeSurface(muteButtonSurface);

// if (muteButtonTexture == nullptr)
// {
//     printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Surface *unmuteButtonSurface = IMG_Load("../res/unmute2.png");
// if (unmuteButtonSurface == nullptr)
// {
//     printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Texture *unmuteButtonTexture = SDL_CreateTextureFromSurface(renderer, unmuteButtonSurface);
// SDL_FreeSurface(unmuteButtonSurface);

// if (unmuteButtonTexture == nullptr)
// {
//     printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Surface *backgroundPlaySurface = IMG_Load("../res/level2_background.png");
// if (backgroundPlaySurface == nullptr)
// {
//     printf("Unable to load background play image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Texture *backgroundPlayTexture = SDL_CreateTextureFromSurface(renderer, backgroundPlaySurface);
// SDL_FreeSurface(backgroundPlaySurface);

// if (backgroundPlayTexture == nullptr)
// {
//     printf("Unable to create texture from background play image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Surface *birdSurface = IMG_Load("../res/bird.png");
// if (birdSurface == nullptr)
// {
//     printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Texture *birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
// SDL_FreeSurface(birdSurface);

// if (birdTexture == nullptr)
// {
//     printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Texture *slingshot_back = IMG_LoadTexture(renderer, "../res/slingshot_back.png");

// if (slingshot_back == nullptr)
// {
//     printf("Unable to create sling_shot back image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Texture *slingshot_front = IMG_LoadTexture(renderer, "../res/slingshot_front.png");

// if (slingshot_back == nullptr)
// {
//     printf("Unable to create sling_shot front image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Texture *green_bird = IMG_LoadTexture(renderer, "../res/green_bird.png");

// if (green_bird == nullptr)
// {
//     printf("Unable to create green bird image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Surface *back_button = IMG_Load("../res/back_button.png");
// if (back_button == nullptr)
// {
//     printf("Unable to load back button image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// SDL_Texture *back_buttonTexture = SDL_CreateTextureFromSurface(renderer, back_button);
// SDL_FreeSurface(back_button);

// if (back_buttonTexture == nullptr)
// {
//     printf("Unable to create texture from back button image! SDL_Error: %s\n", SDL_GetError());
//     return;
// }

// bool jump = 0, Green = 1;
// int Bird_length = 80;

// double speed_x = 0.0, speed_y = 0.0, vf = 0.0;
// double g = 0.01;

// int X = 0, Y = 0, count = 0, Start_x = 210, Start_y = 560, count_of_collision_with_wall = 0;

// SDL_Rect bird_rect = {Start_x, Start_y, Bird_length, Bird_length};
// SDL_Rect slingshot_rect = {210, 580, 75, 3 * 64};
// SDL_Rect green_bird_rect = {1400, 480, 100, 100};

// while (!quit)
// {
//     while (SDL_PollEvent(&e))
//     {
//         if (e.type == SDL_QUIT)
//             quit = true;
//         else if (e.type == SDL_MOUSEMOTION && SDL_MOUSEBUTTONDOWN)
//         {
//             if (!jump)
//             {
//                 SDL_GetMouseState(&X, &Y);

//                 if (e.button.button == SDL_BUTTON_LEFT)
//                 {

//                     if ((X - Bird_length / 2) >= 0 && (X) <= (SCREEN_WIDTH / 2))
//                     {
//                         bird_rect.x = X - Bird_length / 2;
//                     }
//                     if ((Y - Bird_length) >= 0 && (Y) <= (SCREEN_HEIGHT - 3 * Bird_length))
//                         bird_rect.y = Y - Bird_length / 2;
//                 }
//             }
//         }
//         else if (e.type == SDL_MOUSEBUTTONUP)
//         {
//             if (e.button.button == SDL_BUTTON_LEFT)
//             {
//                 speed_x = (Start_x - bird_rect.x) / 45.0;
//                 speed_y = -(Start_y - bird_rect.y) / 45.0;
//                 bird_rect.x = Start_x;
//                 bird_rect.y = Start_y;

//                 jump = 1;
//             }
//         }

//         /**/
//         if (e.type == SDL_MOUSEMOTION)
//         {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);
//             if (X >= playButtonRect.x && X <= (playButtonRect.x + playButtonRect.w) &&
//                 Y >= playButtonRect.y && Y <= (playButtonRect.y + playButtonRect.h))
//             {
//                 SDL_SetTextureColorMod(back_buttonTexture, 255, 255, 255);
//             }
//             else
//             {
//                 SDL_SetTextureColorMod(back_buttonTexture, 150, 150, 150);
//             }

//             if (mouseX >= musicButtonRect.x && mouseX <= (musicButtonRect.x + musicButtonRect.w) &&
//                 mouseY >= musicButtonRect.y && mouseY <= (musicButtonRect.y + musicButtonRect.h))
//             {
//                 SDL_SetTextureColorMod(currentButtonTexture2, 255, 255, 255);
//             }
//             else
//             {
//                 SDL_SetTextureColorMod(currentButtonTexture2, 150, 150, 150);
//             }
//         }

//         /**/
//         if (e.type == SDL_MOUSEBUTTONDOWN)
//         {
//             SDL_GetMouseState(&X, &Y);

//             if (X >= playButtonRect.x && X <= (playButtonRect.x + playButtonRect.w) &&
//                 Y >= playButtonRect.y && Y <= (playButtonRect.y + playButtonRect.h))
//             {
//                 printf("Back button clicked!\n"); // make sure kortesi j setting button kaj kore kina

// Mix_PlayMusic(backButtonMusic, -1); // Start playing music indefinitely
// Mix_FreeMusic(backgroundMusic);
// Mix_CloseAudio();
// SDL_Delay(100);

// currentState = NEW_PAGE;
// Mix_FreeMusic(backButtonMusic);
// Mix_CloseAudio();

// currentButtonTexture2 = unmuteButtonTexture;
// musicPlaying = 1;

//                 return;
//             }

//             if (X >= musicButtonRect.x && X <= (musicButtonRect.x + musicButtonRect.w) &&
//                 Y >= musicButtonRect.y && Y <= (musicButtonRect.y + musicButtonRect.h))
//             {
//                 toggleMusic2(muteButtonTexture, unmuteButtonTexture, musicPlaying);
//                 // SDL_Delay(150);
//             }
//         }
//     }

//     if (musicPlaying)
//     {
//         currentButtonTexture2 = muteButtonTexture;
//     }
//     else
//     {
//         currentButtonTexture2 = unmuteButtonTexture;
//     }

//     if (jump && speed_x)
//     {
//         // bird_rect.x += (((int)speed_x) ? ((int)speed_x) : 1);
//         bird_rect.x += speed_x;

//         if (bird_rect.x - 50 >= (SCREEN_WIDTH) || (bird_rect.x + Bird_length + 100 <= 0))
//         {
//             jump = 0;
//             Green = 1;
//             bird_rect.x = Start_x;
//             bird_rect.y = Start_y;
//             SDL_Delay(500);
//             // speed_x = -speed_x;
//         }

//         bird_rect.y -= speed_y;
//         speed_y -= g;

//         if ((bird_rect.y >= (SCREEN_HEIGHT - 3.5 * Bird_length))) // (bird_rect.y <= 0)
//         {
//             speed_y = -(speed_y);
//             // printf("%lf\n", speed_y);
//             speed_y *= 0.5;
//             // speed_y--;
//             // speed_y -= 2.0 / 30.0;
//             // printf("%lf\n", speed_y);
//         }
//     }
//     else
//     {
//         jump = 0;
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, backgroundPlayTexture, NULL, NULL);
//     SDL_RenderCopy(renderer, slingshot_back, NULL, &slingshot_rect);
//     SDL_RenderCopy(renderer, birdTexture, NULL, &bird_rect);

//     SDL_RenderCopy(renderer, back_buttonTexture, NULL, &playButtonRect); // showing the back button

// if (!musicPlaying)
// {
//     SDL_RenderCopy(renderer, muteButtonTexture, NULL, &musicButtonRect); // showing the music button
// }
// if (musicPlaying)
// {
//     SDL_RenderCopy(renderer, unmuteButtonTexture, NULL, &musicButtonRect); // showing the music button
// }

//     /**/
//     if (!collide2(bird_rect, green_bird_rect) && Green)
//     {
//         SDL_RenderCopy(renderer, green_bird, NULL, &green_bird_rect);
//     }
//     else
//     {
//         Green = 0;

//         // bird_rect.x = Start_x;
//         // bird_rect.y = Start_y;
//         // SDL_Delay(500);
//     }

// SDL_RenderCopy(renderer, slingshot_front, NULL, &slingshot_rect);
// SDL_RenderPresent(renderer);
// }

// Destroy the bird texture when done
// SDL_DestroyTexture(back_buttonTexture);