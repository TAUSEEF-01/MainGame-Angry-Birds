#include "main.h"

// This is the second level of the game.


SDL_Texture *currentButtonTexture5; // Variable to hold the current button texture

// Function to toggle music on/off
void toggleMusic5(SDL_Texture *muteTexture, SDL_Texture *unmuteTexture, int &musicPlaying)
{
    if (musicPlaying)
    {
        Mix_PauseMusic();                      // Pause the music
        musicPlaying = 0;                      // Update the flag to indicate music is stopped
        currentButtonTexture5 = unmuteTexture; // Set the texture to unmute button
    }
    else
    {
        Mix_ResumeMusic();                   // Resume the music
        musicPlaying = 1;                    // Update the flag to indicate music is playing
        currentButtonTexture5 = muteTexture; // Set the texture to mute button
    }
}

bool collide5(SDL_Rect a, SDL_Rect b)
{
    if (((a.x + a.w) > (b.x + 30)) && ((a.x + 50) < (b.x + b.w)) && ((a.y + a.h) > (b.y + 10)) && (((a.y + 30) < (b.y + b.h))))
        return 1;
    return 0;
}

void level5(SDL_Renderer *renderer, bool &quit, State &currentState, int &musicPlaying, std::string &playerName, int &playerScore, int &turns)
{
    SDL_Texture *backgroundPlayTexture = surfaceToTexture(renderer, "../res/level2_background.png");
    SDL_Texture *birdTexture = surfaceToTexture(renderer, "../res/yellow_bird2.png");
    SDL_Texture *slingshot_back = surfaceToTexture(renderer, "../res/slingshot_back.png");
    SDL_Texture *slingshot_front = surfaceToTexture(renderer, "../res/slingshot_front.png");
    SDL_Texture *green_bird = surfaceToTexture(renderer, "../res/green_bird.png");
    // SDL_Texture *back_buttonTexture = surfaceToTexture(renderer, "../res/back_button.png");
    SDL_Texture *back_buttonTexture = surfaceToTexture(renderer, "../res/exit_page.png");
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
    Mix_Music *backgroundMusic = Music("../res/background_music2.mp3");

    if (musicPlaying)
        Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely


    /**/
    // Render the player's name on top of the window
    TTF_Font* nameFont = TTF_OpenFont("roboto.ttf", 32);  // Use a font size that fits your needs
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

    // SDL_Rect nameRect = {namePosX, namePosY, nameSurface->w, nameSurface->h};
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


    TTF_Font* font2 = TTF_OpenFont("roboto.ttf", 32);
    if (font2 == nullptr) {
        printf("Unable to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return;
    }


    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if(turns <= 0 && (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP))
            {
                currentState = SCORE_PAGE;
                SDL_DestroyTexture(backgroundPlayTexture);
                SDL_DestroyTexture(birdTexture);
                return;
            }

            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_MOUSEMOTION && SDL_MOUSEBUTTONDOWN)
            {
                if (!jump)
                {
                    SDL_GetMouseState(&X, &Y);

                    if (e.button.button == SDL_BUTTON_LEFT)
                    {
                        // turns--;

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
                    if(!((X >= playButtonRect.x && X <= (playButtonRect.x + playButtonRect.w) && 
                    Y >= playButtonRect.y && Y <= (playButtonRect.y + playButtonRect.h)) ||
                    (X >= musicButtonRect.x && X <= (musicButtonRect.x + musicButtonRect.w) &&
                    Y >= musicButtonRect.y && Y <= (musicButtonRect.y + musicButtonRect.h))) && 
                    (clicked || (X >= bird_rect.x && X <= bird_rect.x + Bird_length) && (Y >= bird_rect.y && Y <= bird_rect.y + Bird_length)))
                    {
                        turns--;
                        printf("Button clicked. Turns : %d\n", turns);
                    }


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
                    SDL_SetTextureColorMod(currentButtonTexture5, 255, 255, 255);
                }
                else
                {
                    SDL_SetTextureColorMod(currentButtonTexture5, 150, 150, 150);
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

                    currentButtonTexture5 = unmuteButtonTexture;
                    musicPlaying = 1;

                    return;
                }

                if (X >= musicButtonRect.x && X <= (musicButtonRect.x + musicButtonRect.w) &&
                    Y >= musicButtonRect.y && Y <= (musicButtonRect.y + musicButtonRect.h))
                {
                    toggleMusic5(muteButtonTexture, unmuteButtonTexture, musicPlaying);
                    // SDL_Delay(150);
                }
            }
        }



        if (musicPlaying)
        {
            currentButtonTexture5 = muteButtonTexture;
        }
        else
        {
            currentButtonTexture5 = unmuteButtonTexture;
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
                    playerScore += 10;
                    currentState = SCORE_PAGE; // added extra

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

        // Render the score text
        std::string scoreText = "Turns Left: " + std::to_string(turns);
        SDL_Surface *scoreSurface = TTF_RenderText_Solid(font2, scoreText.c_str(), {255, 255, 255});
        SDL_Texture *scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
        SDL_FreeSurface(scoreSurface);

        SDL_Rect scoreRect = {namePosX - 100, namePosY + 50, 200, 50};
        SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
        // SDL_DestroyTexture(scoreTexture);


        SDL_RenderCopy(renderer, back_buttonTexture, NULL, &playButtonRect); // showing the back button

        if (!musicPlaying)
        {
            SDL_RenderCopy(renderer, muteButtonTexture, NULL, &musicButtonRect); // showing the music button
        }
        if (musicPlaying)
        {
            SDL_RenderCopy(renderer, unmuteButtonTexture, NULL, &musicButtonRect); // showing the music button
        }

        if (!collide5(bird_rect, green_bird_rect) && Green)
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


        /**/
        if(turns <= -1)
        {
            currentState = SCORE_PAGE;
            SDL_DestroyTexture(backgroundPlayTexture);
            SDL_DestroyTexture(birdTexture);
            return;
        }
        /**/
    }

    // Render the score text
    std::string scoreText = "Turns Left: " + std::to_string(turns);
    SDL_Surface *scoreSurface = TTF_RenderText_Solid(font2, scoreText.c_str(), {255, 255, 255});
    SDL_Texture *scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_FreeSurface(scoreSurface);

    SDL_Rect scoreRect = {namePosX , namePosY + 50, nameSurface->w, nameSurface->h};
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
    SDL_DestroyTexture(scoreTexture);



    Mix_FreeMusic(backgroundMusic);
    Mix_CloseAudio();

    SDL_RenderCopy(renderer, currentButtonTexture5, NULL, &musicButtonRect);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(muteButtonTexture);
    SDL_DestroyTexture(unmuteButtonTexture);

    SDL_DestroyTexture(backgroundPlayTexture);
    SDL_DestroyTexture(birdTexture);


    /**/
    SDL_DestroyTexture(nameTexture);
    TTF_CloseFont(nameFont);
}