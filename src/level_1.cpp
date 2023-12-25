#include "../include/header.h"

SDL_Event level_1_event;

bool jump_1 = 0, green_1 = 1, level_1_initialized = 0, clicked_1 = 0, L1_cursor_inside = true, L1_Loading_Screen = true;
bool score_added_1 = 0;
int Start_x1 = 210, Start_y1 = 560;
int Bird_length_1 = 50;
int prev_x_position_1 = -100;

double speed_x1 = 0.0, speed_y1 = 0.0;
double gravity1 = 0.5;

SDL_Rect bird_rect_1, slingshot_rect_1, green_1_bird_rect_1, L1_cursor_rect, slingshot_rubber_rect_1;
// SDL_Point slingshot_rubber_center;

SDL_Surface *temp_surface1;
SDL_Texture *temp_texture1;
SDL_Rect text_rec1;

void level_1_initialize()
{
    bird_rect_1 = {Start_x1, Start_y1, Bird_length_1, Bird_length_1};
    // slingshot_rubber_center = {800, 450};
    // slingshot_rubber_rect_1 = {210, 580, 300, 100}; //checking
    slingshot_rect_1 = {210, 580, 47, 124};
    green_1_bird_rect_1 = {1400, 480, 100, 100};
    turns_left = 3; // 3 turns will be given
}

bool collide_1(SDL_Rect a, SDL_Rect b)
{
    if (((a.x + a.w) > (b.x + 30)) && ((a.x + 50) < (b.x + b.w)) && ((a.y + a.h) > (b.y + 10)) && (((a.y + 30) < (b.y + b.h))))
        return 1;
    return 0;
}

// music part --> start

// int musicPlaying = 1;           // Flag to indicate if music is playing (1 for playing, 0 for stopped)

// Function to toggle music on/off
void toggleMusic(SDL_Texture *muteTexture, SDL_Texture *unmuteTexture, int &musicPlaying)
{
    if (musicPlaying)
    {
        Mix_PauseMusic();                      // Pause the music
        musicPlaying = 0;                      // Update the flag to indicate music is stopped
        texture[MUSIC_BUTTON] = unmuteTexture; // Set the texture to unmute button
    }
    else
    {
        Mix_ResumeMusic();                   // Resume the music
        musicPlaying = 1;                    // Update the flag to indicate music is playing
        texture[MUSIC_BUTTON] = muteTexture; // Set the texture to mute button
    }
}

// music part --> end

void reset_1()
{
    jump_1 = 0;
    green_1 = 1;

    bird_rect_1.x = Start_x1;
    bird_rect_1.y = Start_y1;

    // SDL_Delay(500);
}

void back_button_music_level1()
{
    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/audio/back_button.mp3");
    Mix_PlayMusic(backgroundMusic, 0); // Start playing music once
    SDL_Delay(100);
    // Mix_FreeMusic(backgroundMusic);
    // Mix_CloseAudio();
}

void levelOne() // main function
{

    Previous_state = Current_state;

    SDL_SetTextureColorMod(texture[MUTE_BUTTON], 150, 150, 150);
    SDL_Rect musicButtonRect = {1450, 30, 80, 80};

    if (L1_Loading_Screen)
    {
        L1_Loading_Screen = false;

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture[LEVEL_1_LOADING_PAGE], NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }

    if (!level_1_initialized)
    {
        level_1_initialized = true;
        level_1_initialize();

        // music will start to play
        if (musicPlaying)
            Mix_PlayMusic(music[BACKGROUND_MUSIC], -1); // Start playing music indefinitely
        else
            toggleMusic(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);

        temp_surface1 = TTF_RenderText_Solid(valorax_font, playerName.c_str(), {255, 255, 255});
        temp_texture1 = SDL_CreateTextureFromSurface(renderer, temp_surface1);
        text_rec1 = {600, 30, temp_surface1->w - 30, temp_surface1->h - 20};
        SDL_FreeSurface(temp_surface1);
    }

    while (SDL_PollEvent(&level_1_event))
    {
        SDL_GetMouseState(&X, &Y);
        L1_cursor_rect = {X, Y, 30, 45};
        L1_cursor_inside = (X >= 1 && X <= 1599 && Y >= 1 && Y <= 899) ? true : false;

        if (level_1_event.type == SDL_QUIT)
        {
            running = false;
            return;
        }
        else if (level_1_event.type == SDL_MOUSEMOTION && SDL_MOUSEBUTTONDOWN)
        {
            if (!jump_1)
            {

                if (level_1_event.button.button == SDL_BUTTON_LEFT)
                {
                    if (clicked_1 || (X >= bird_rect_1.x && X <= bird_rect_1.x + Bird_length_1) && (Y >= bird_rect_1.y && Y <= bird_rect_1.y + Bird_length_1)) // is clicked_1 inside bird
                    {

                        clicked_1 = 1; // extra

                        // This is the range of bird where it can be stretched
                        // start
                        if ((X - Bird_length_1 / 2) >= 0 && (X) <= 600)
                        {
                            bird_rect_1.x = X - Bird_length_1 / 2;
                        }
                        if ((Y - Bird_length_1) >= 300 && (Y) <= (SCREEN_HEIGHT - 4.5 * Bird_length_1))
                            bird_rect_1.y = Y - Bird_length_1 / 2;
                        // bird stretch range end
                    }
                }
            }
        }

        else if (level_1_event.type == SDL_MOUSEBUTTONDOWN)
        {
            // if back button is clicked then returns to menu
            if (isHovered({X, Y}, back_button_rect) && level_1_event.button.button == SDL_BUTTON_LEFT)
            {
                Current_state = MENU;
                L1_Loading_Screen = true;
                level_1_initialized = 0;

                back_button_music_level1();

                // music closed here
                if (musicPlaying)
                {
                    toggleMusic(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
                    // Mix_CloseAudio();
                }

                return;
            }

            // extra -->
            else if (isHovered({X, Y}, musicButtonRect) && level_1_event.button.button == SDL_BUTTON_LEFT)
            {
                toggleMusic(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
            }
        }
        else if (level_1_event.type == SDL_MOUSEBUTTONUP)
        {
            clicked_1 = 0;

            if (level_1_event.button.button == SDL_BUTTON_LEFT)
            {

                if (!jump_1) // speed after releasing
                {
                    speed_x1 = (Start_x1 - bird_rect_1.x) / 5.0;
                    speed_y1 = -(Start_y1 - bird_rect_1.y) / 5.0;

                    if (isHovered({X, Y}, bird_rect_1)) // after releasing the bird, one turn will be lost
                    {
                        turns_left--;
                        printf("%d turns left\n", turns_left); // checking
                    }

                    bird_rect_1.x = Start_x1;
                    bird_rect_1.y = Start_y1;

                    jump_1 = 1;
                }
            }
        }

        /**/
        if (level_1_event.type == SDL_MOUSEMOTION)
        {
            int mouseX, mouseY;
        }

        /**/
        if (level_1_event.type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_GetMouseState(&X, &Y);
        }
    }

    /**/
    if (level_1_event.type == SDL_MOUSEMOTION)
    {
        if (isHovered({X, Y}, musicButtonRect))
        {
            SDL_SetTextureColorMod(texture[MUSIC_BUTTON], 255, 255, 255);
        }
        else
        {
            SDL_SetTextureColorMod(texture[MUSIC_BUTTON], 150, 150, 150);
        }
    }

    // music button --> start

    if (musicPlaying)
    {
        texture[MUSIC_BUTTON] = texture[MUTE_BUTTON];
    }
    else
    {
        texture[MUSIC_BUTTON] = texture[UNMUTE_BUTTON];
    }

    // music button --> end
    

    if (jump_1 && speed_x1)
    {
        bird_rect_1.x += speed_x1;

        if (bird_rect_1.x - 50 >= (SCREEN_WIDTH) || (bird_rect_1.x + Bird_length_1 + 100 <= 0))
        {
            jump_1 = 0;

            if (green_1 == 0) // Level
            {
                Current_state = LEVEL_2; // LEVEL 2
                L1_Loading_Screen = true;

                level_1_initialized = 0;
                green_1 = 1;

                // // music closed here
                // if (musicPlaying)
                // {
                //     toggleMusic(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
                // }

                return;
            }
            else if (turns_left == 0) // if number of turns left is 0 before hitting the bird - GAME OVER
            {
                Current_state = GAME_OVER;
                L1_Loading_Screen = true;
                level_1_initialized = 0; // Level 1 will be initialized when opened again
                green_1 = 1;

                Mix_PlayMusic(music[GAME_OVER_MUSIC], 0); // Start playing music once

                return;
            }

            green_1 = 1; // whether green_1 bird would render or not

            bird_rect_1.x = Start_x1;
            bird_rect_1.y = Start_y1;

            // SDL_Delay(500);

            goto here;
            // speed_x1 = -speed_x1;
        }

        bird_rect_1.y -= speed_y1;
        speed_y1 -= gravity1; // speed of y asix reduces due to gravity

        if ((bird_rect_1.y >= (SCREEN_HEIGHT - 5 * Bird_length_1))) // (bird_rect_1.y <= 0)
        {
            speed_y1 = -(speed_y1);                                // bounces from ground
            bird_rect_1.y = (SCREEN_HEIGHT - 4.8 * Bird_length_1); // if goes down the limit, it is forced to stay at the limit

            // reamaining speed after a bounce
            speed_y1 *= 0.60; // speed loss due to friction
            speed_x1 *= 0.90; // speed loss due to friction
        }
    }

    if (((abs(speed_x1) < 0.01) || (prev_x_position_1 == bird_rect_1.x)) && abs(speed_y1) < 5 && jump_1)
    {
        if (green_1 == 0) // Level
        {
            Current_state = LEVEL_2; // LEVEL 2
            L1_Loading_Screen = true;

            level_1_initialized = 0; // Level 1 will be initialized when opened again
            green_1 = 1;

            // // music closed here
            // if (musicPlaying)
            // {
            //     toggleMusic(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
            // }

            return;
        }
        else if (turns_left == 0) // if number of turns left is 0 before hitting the bird - GAME OVER
        {
            Current_state = GAME_OVER;
            L1_Loading_Screen = true;
            level_1_initialized = 0; // Level 1 will be initialized when opened again
            green_1 = 1;

            // music closed here
            if (musicPlaying)
            {
                toggleMusic(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
            }

            Mix_PlayMusic(music[GAME_OVER_MUSIC], 0); // Start playing music once

            return;
        }

        jump_1 = 0;
        speed_y1 = 0.0;
        green_1 = 1;

        // if (bird_rect_1.x != Start_x1 || bird_rect_1.y != Start_y1)
        //     SDL_Delay(500);

        bird_rect_1.x = Start_x1;
        bird_rect_1.y = Start_y1;
    }

here:
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture[LEVEL_1_BACKGROUND], NULL, NULL);

    // slingshot back rubber rendering - start

    SDL_Rect slingshot_rubber_rect_1 = {slingshot_rect_1.x + 43, slingshot_rect_1.y, 100, 20};
    SDL_Point slingshot_rubber_center = {0, 10};
    Stretch rubber;

    slingshot_rubber_rect_1.w = rubber.distance({slingshot_rubber_rect_1.x, slingshot_rubber_rect_1.y}, {(bird_rect_1.x + bird_rect_1.w / 2), (bird_rect_1.y + bird_rect_1.h / 2)});
    // slingshot_rubber_rect_1.h = ((100 * 5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) < 100 ? ((100*5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) : 100;

    if ((bird_rect_1.x != Start_x1 || bird_rect_1.y != Start_y1) && clicked_1)
        SDL_RenderCopyEx(renderer, texture[SLINGSHOT_RUBBER], NULL, &slingshot_rubber_rect_1, rubber.calculateAngle((bird_rect_1.x + bird_rect_1.w / 2) - slingshot_rubber_rect_1.x, (bird_rect_1.y + bird_rect_1.h / 2) - (slingshot_rubber_rect_1.y)), &slingshot_rubber_center, SDL_FLIP_NONE);

    // slingshot back rubber rendering - end

    SDL_RenderCopy(renderer, texture[SLINGSHOT_BACK], NULL, &slingshot_rect_1);
    SDL_RenderCopy(renderer, texture[LEVEL_1_RED_BIRD], NULL, &bird_rect_1);

    // SDL_RenderCopyEx(renderer, texture[SLINGSHOT_RUBBER], NULL,  &slingshot_rubber_rect_1, 45.0, &slingshot_rubber_center, SDL_FLIP_NONE);
    SDL_RenderCopy(renderer, texture[SLINGSHOT_FRONT], NULL, &slingshot_rect_1);

    // slingshot front rubber rendering - start

    slingshot_rubber_rect_1 = {slingshot_rect_1.x + 12, slingshot_rect_1.y, 100, 20};
    // SDL_Rect slingshot_rubber_rect_1 = {slingshot_rect_1.x + 43, 580, 100, 20};
    slingshot_rubber_center = {0, 10};

    slingshot_rubber_rect_1.w = rubber.distance({slingshot_rubber_rect_1.x, slingshot_rubber_rect_1.y}, {(bird_rect_1.x + bird_rect_1.w / 2), (bird_rect_1.y + bird_rect_1.h / 2)});
    // slingshot_rubber_rect_1.h = ((100 * 5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) < 100 ? ((100*5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) : 100;

    if ((bird_rect_1.x != Start_x1 || bird_rect_1.y != Start_y1) && clicked_1)
        SDL_RenderCopyEx(renderer, texture[SLINGSHOT_RUBBER], NULL, &slingshot_rubber_rect_1, rubber.calculateAngle((bird_rect_1.x + bird_rect_1.w / 2) - slingshot_rubber_rect_1.x, (bird_rect_1.y + bird_rect_1.h / 2) - (slingshot_rubber_rect_1.y)), &slingshot_rubber_center, SDL_FLIP_NONE);

    // slingshot front ubber rendering - end

    SDL_RenderCopy(renderer, temp_texture1, NULL, &text_rec1);

    if (!musicPlaying)
        SDL_RenderCopy(renderer, texture[MUTE_BUTTON], NULL, &musicButtonRect); // showing the music button
    if (musicPlaying)
        SDL_RenderCopy(renderer, texture[UNMUTE_BUTTON], NULL, &musicButtonRect); // showing the music button

    if (!collide_1(bird_rect_1, green_1_bird_rect_1) && green_1)
    {
        SDL_RenderCopy(renderer, texture[LEVEL_1_GREEN_PIG], NULL, &green_1_bird_rect_1);

        if (score_added_1)
        {
            score_added_1 = 0;

            printf("%d\n", score); // checking
        }
    }
    else
    {
        green_1 = 0;

        if (!score_added_1) // score
        {
            score += 10 + 10 * turns_left;
            score_added_1 = 1;

            printf("%d\n", score); // checking
        }
    }

    // back button functionality - start

    if (isHovered({X, Y}, back_button_rect))
        SDL_SetTextureColorMod(texture[BACK_BUTTON], 255, 255, 255);
    else
        SDL_SetTextureColorMod(texture[BACK_BUTTON], 150, 150, 150);

    SDL_RenderCopy(renderer, texture[BACK_BUTTON], NULL, &back_button_rect);

    // back button - end



    // shows turns left - start

    SDL_Rect turns_left_rect;
    SDL_Texture *turns_left_texture = loadTextureFromText(("Turns left: " + (to_string(turns_left))).c_str(), valorax_font, 12, turns_left_rect, {0, 0, 0});
    turns_left_rect.x = 700;
    turns_left_rect.y = 100;
    turns_left_rect.w  = (double)turns_left_rect.w * 0.40;
    turns_left_rect.h  = (double)turns_left_rect.h * 0.40;
    SDL_RenderCopy(renderer, turns_left_texture, NULL, &turns_left_rect);
    SDL_DestroyTexture(turns_left_texture);


    // shows turns left - end





    if (L1_cursor_inside) // shows cursor while inside
        SDL_RenderCopy(renderer, texture[CURSOR], NULL, &L1_cursor_rect);

    SDL_Delay(10); // frame rate

    SDL_RenderPresent(renderer); // updating window

    prev_x_position_1 = bird_rect_1.x;
}
