#include "main.h"
#include <SDL2/SDL_mixer.h>

bool collide(SDL_Rect a, SDL_Rect b)
{
    if (((a.x + a.w) > (b.x + 30)) && ((a.x + 50) < (b.x + b.w)) && ((a.y + a.h) > (b.y + 10)) && (((a.y + 30) < (b.y + b.h))))
        return 1;
    return 0;
}

void handlePlayWindow(SDL_Renderer *renderer, bool &quit, State &currentState)
{
    SDL_Surface *backgroundPlaySurface = IMG_Load("../res/background_play.png");
    if (backgroundPlaySurface == nullptr)
    {
        printf("Unable to load background play image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *backgroundPlayTexture = SDL_CreateTextureFromSurface(renderer, backgroundPlaySurface);
    SDL_FreeSurface(backgroundPlaySurface);

    if (backgroundPlayTexture == nullptr)
    {
        printf("Unable to create texture from background play image! SDL_Error: %s\n", SDL_GetError());
        return;
    }


    SDL_Surface *birdSurface = IMG_Load("../res/bird.png");
    if (birdSurface == nullptr)
    {
        printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
    SDL_FreeSurface(birdSurface);

    if (birdTexture == nullptr)
    {
        printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *slingshot_back = IMG_LoadTexture(renderer, "../res/slingshot_back.png");

    if (slingshot_back == nullptr)
    {
        printf("Unable to create sling_shot back image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *slingshot_front = IMG_LoadTexture(renderer, "../res/slingshot_front.png");

    if (slingshot_back == nullptr)
    {
        printf("Unable to create sling_shot front image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *green_bird = IMG_LoadTexture(renderer, "../res/green_bird.png");

    if (green_bird == nullptr)
    {
        printf("Unable to create green bird image! SDL_Error: %s\n", SDL_GetError());
        return;
    }


    SDL_Surface *back_button = IMG_Load("../res/back_button.png");
    if (back_button == nullptr)
    {
        printf("Unable to load back button image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture *back_buttonTexture = SDL_CreateTextureFromSurface(renderer, back_button);
    SDL_FreeSurface(back_button);

    if (back_buttonTexture == nullptr)
    {
        printf("Unable to create texture from back button image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_SetTextureColorMod(back_buttonTexture, 150, 150, 150);
    SDL_Rect playButtonRect = {30, 30, 100, 100};


    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    Mix_Music *backButtonMusic = Mix_LoadMUS("../res/back_button.mp3");
    if (backButtonMusic == NULL)
    {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return; 
    }

    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/background_music.mp3");
    if (backgroundMusic == NULL)
    {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely


    SDL_Event e;

    bool jump = 0, Green = 1;
    int Bird_length = 80;

    double speed_x = 0.0, speed_y = 0.0, vf = 0.0;
    double g = 0.01;

    int X = 0, Y = 0, count = 0, Start_x = 210, Start_y = 495, count_of_collision_with_wall = 0;

    SDL_Rect bird_rect = {Start_x, Start_y, Bird_length, Bird_length};
    SDL_Rect slingshot_rect = {210, 515, 75, 3 * 64};
    SDL_Rect green_bird_rect = {1400, 480, 100, 100};

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

                        if ((X - Bird_length / 2) >= 0 && (X) <= (SCREEN_WIDTH / 2))
                        {
                            bird_rect.x = X - Bird_length / 2;
                        }
                        if ((Y - Bird_length) >= 0 && (Y) <= (SCREEN_HEIGHT - 3 * Bird_length))
                            bird_rect.y = Y - Bird_length / 2;
                    }
                }
                
            }
            else if (e.type == SDL_MOUSEBUTTONUP)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    speed_x = (Start_x - bird_rect.x) / 45.0;
                    speed_y = -(Start_y - bird_rect.y) / 45.0;
                    bird_rect.x = Start_x;
                    bird_rect.y = Start_y;

                    jump = 1;
                }
            }

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
            }

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

                    
                    return;
                }
            }
        }

        if (jump && speed_x)
        {
            // bird_rect.x += (((int)speed_x) ? ((int)speed_x) : 1);
            bird_rect.x += speed_x;

            if (bird_rect.x - 50 >= (SCREEN_WIDTH) || (bird_rect.x + Bird_length + 100 <= 0))
            {
                jump = 0;
                Green = 1;
                bird_rect.x = Start_x;
                bird_rect.y = Start_y;
                SDL_Delay(500);
                // speed_x = -speed_x;
            }

            bird_rect.y -= speed_y;
            speed_y -= g;

            if ((bird_rect.y >= (SCREEN_HEIGHT - 3.5 * Bird_length))) // (bird_rect.y <= 0)
            {
                speed_y = -(speed_y);
                // printf("%lf\n", speed_y);
                speed_y *= 0.5;
                // speed_y--;
                // speed_y -= 2.0 / 30.0;
                // printf("%lf\n", speed_y);
            }
        }
        else
            jump = 0;

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundPlayTexture, NULL, NULL);
        SDL_RenderCopy(renderer, slingshot_back, NULL, &slingshot_rect);
        SDL_RenderCopy(renderer, birdTexture, NULL, &bird_rect);

        SDL_RenderCopy(renderer, back_buttonTexture, NULL, &playButtonRect); // showing the back button

        // if()

        if (!collide(bird_rect, green_bird_rect) && Green)
            SDL_RenderCopy(renderer, green_bird, NULL, &green_bird_rect);
        else
        {
            Green = 0;

            // currentState = LEVEL2; //added extra
            // return;
            // bird_rect.x = Start_x;
            // bird_rect.y = Start_y;
            // SDL_Delay(500);
        }

        SDL_RenderCopy(renderer, slingshot_front, NULL, &slingshot_rect);
        SDL_RenderPresent(renderer);

        if (Green == 0)
        {
            currentState = LEVEL2; //added extra

            SDL_DestroyTexture(backgroundPlayTexture);
            SDL_DestroyTexture(birdTexture);
            return;
        }
    }

    // Destroy the bird texture when done
    // SDL_DestroyTexture(back_buttonTexture);

    SDL_DestroyTexture(backgroundPlayTexture);
    SDL_DestroyTexture(birdTexture);
}














                // int mouseX, mouseY;
                // SDL_GetMouseState(&mouseX, &mouseY);
                
                // if (X >= playButtonRect.x && X <= (playButtonRect.x + playButtonRect.w) &&
                //     Y >= playButtonRect.y && Y <= (playButtonRect.y + playButtonRect.h))
                // {
                //     SDL_SetTextureColorMod(back_buttonTexture, 255, 255, 255);
                //     // if (e.button.button == SDL_BUTTON_LEFT)
                //     if (e.type == SDL_MOUSEBUTTONDOWN)
                //     {
                //         printf("Back button clicked!\n"); // make sure kortesi j setting button kaj kore kina
                //         currentState = NEW_PAGE;
                //     }
                //     // if (e.button.button == SDL_BUTTON_LEFT)

                // }

                // if (X >= playButtonRect.x && X <= (playButtonRect.x + playButtonRect.w) &&
                //     Y >= playButtonRect.y && Y <= (playButtonRect.y + playButtonRect.h))
                // {
                //     printf("Back button clicked!\n"); // make sure kortesi j setting button kaj kore kina
                // }





















// #include "main.h"

// bool collide(SDL_Rect a, SDL_Rect b)
// {
//     if (((a.x + a.w) > (b.x + 30)) && ((a.x + 50) < (b.x + b.w)) && ((a.y + a.h) > (b.y + 10)) && (((a.y + 30) < (b.y + b.h))))
//         return 1;
//     return 0;
// }

// void handlePlayWindow(SDL_Renderer *renderer, SDL_Texture *backgroundTexture, bool &quit)
// {

//     SDL_Surface *birdSurface = IMG_Load("../res/bird.png");
//     if (birdSurface == nullptr)
//     {
//         printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture *birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
//     SDL_FreeSurface(birdSurface);

//     if (birdTexture == nullptr)
//     {
//         printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture *slingshot_back = IMG_LoadTexture(renderer, "../res/slingshot_back.png");

//     if (slingshot_back == nullptr)
//     {
//         printf("Unable to create sling_shot back image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture *slingshot_front = IMG_LoadTexture(renderer, "../res/slingshot_front.png");

//     if (slingshot_back == nullptr)
//     {
//         printf("Unable to create sling_shot front image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture *green_bird = IMG_LoadTexture(renderer, "../res/green_bird.png");

//     if (green_bird == nullptr)
//     {
//         printf("Unable to create green bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Event e;

//     bool jump = 0, Green = 1;
//     int Bird_length = 80;

//     double speed_x = 0.0, speed_y = 0.0, vf = 0.0;
//     double g = 0.01;

//     int X = 0, Y = 0, count = 0, Start_x = 210, Start_y = 495, count_of_collision_with_wall = 0;

//     SDL_Rect bird_rect = {Start_x, Start_y, Bird_length, Bird_length};
//     SDL_Rect slingshot_rect = {210, 515, 75, 3 * 64};
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

//                         if ((X - Bird_length / 2) >= 0 && (X) <= (SCREEN_WIDTH / 2))
//                         {
//                             bird_rect.x = X - Bird_length / 2;
//                         }
//                         if ((Y - Bird_length) >= 0 && (Y) <= (SCREEN_HEIGHT - 3 * Bird_length))
//                             bird_rect.y = Y - Bird_length / 2;
//                     }
//                 }
//             }
//             else if (e.type == SDL_MOUSEBUTTONUP)
//             {
//                 if (e.button.button == SDL_BUTTON_LEFT)
//                 {
//                     speed_x = (Start_x - bird_rect.x) / 45.0;
//                     speed_y = -(Start_y - bird_rect.y) / 45.0;
//                     bird_rect.x = Start_x;
//                     bird_rect.y = Start_y;

//                     jump = 1;
//                 }
//             }
//         }

//         if (jump && speed_x)
//         {
//             // bird_rect.x += (((int)speed_x) ? ((int)speed_x) : 1);
//             bird_rect.x += speed_x;

//             if (bird_rect.x - 50 >= (SCREEN_WIDTH) || (bird_rect.x + Bird_length + 100 <= 0))
//             {
//                 jump = 0;
//                 Green = 1;
//                 bird_rect.x = Start_x;
//                 bird_rect.y = Start_y;
//                 SDL_Delay(500);
//                 // speed_x = -speed_x;
//             }

//             bird_rect.y -= speed_y;
//             speed_y -= g;

//             if ((bird_rect.y >= (SCREEN_HEIGHT - 3.5 * Bird_length))) // (bird_rect.y <= 0)
//             {
//                 speed_y = -(speed_y);
//                 // printf("%lf\n", speed_y);
//                 speed_y *= 0.5;
//                 // speed_y--;
//                 // speed_y -= 2.0 / 30.0;
//                 // printf("%lf\n", speed_y);
//             }
//         }
//         else
//             jump = 0;

//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
//         SDL_RenderCopy(renderer, slingshot_back, NULL, &slingshot_rect);
//         SDL_RenderCopy(renderer, birdTexture, NULL, &bird_rect);

//         if (!collide(bird_rect, green_bird_rect) && Green)
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
//     }

//     // Destroy the bird texture when done

//     SDL_DestroyTexture(backgroundTexture);
//     SDL_DestroyTexture(birdTexture);
// }