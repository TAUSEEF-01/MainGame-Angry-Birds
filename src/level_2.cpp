#include "../include/header.h"

SDL_Event level_2_event;

bool jump_2 = 0, green_2 = 1, level_2_initialized = 0, clicked_2 = 0, L2_cursor_inside = true, L2_Loading_Screen = true;
bool score_added_2 = 0;
bool green_2_up = 1, L2_obstacle_up = 1;
int Start_x2 = 210, Start_y2 = 560 + 65;
int Bird_length_2 = 50;
int prev_x_position_2 = -100;

double speed_x2 = 0.0, speed_y2 = 0.0;
double gravity2 = 0.5;

SDL_Rect bird_rect_2, slingshot_rect_2, green_2_bird_rect_2, L2_cursor_rect, L2_obstacle_rect[2];
// SDL_Point slingshot_rubber_center;

SDL_Surface *temp_surface2;
SDL_Texture *temp_texture2;
SDL_Rect text_rec2;

void level_2_initialize()
{
    bird_rect_2 = {Start_x2, Start_y2, Bird_length_2, Bird_length_2};
    // slingshot_rubber_center = {800, 450};
    L2_obstacle_rect[0] = {1000, 300, 50, 150};
    L2_obstacle_rect[1] = {1200, 625, 50, 150};
    slingshot_rect_2 = {210, 580 + 65, 47, 124};
    green_2_bird_rect_2 = {1400, 480 + 65, 100, 100};

    turns_left = 5; // 5 turns will be given
}

bool collide_2(SDL_Rect a, SDL_Rect b)
{
    if (((a.x + a.w) > (b.x + 10)) && ((a.x + 10) < (b.x + b.w)) && ((a.y + a.h) > (b.y + 10)) && (((a.y + 10) < (b.y + b.h))))
        return 1;
    return 0;
}

bool normal_collide_2(SDL_Rect a, SDL_Rect b)
{
    if (((a.x + a.w) > (b.x)) && ((a.x) < (b.x + b.w)) && ((a.y + a.h) > (b.y)) && (((a.y) < (b.y + b.h))))
        return 1;
    return 0;
}

// music part --> start

// int musicPlaying = 1;           // Flag to indicate if music is playing (1 for playing, 0 for stopped)

// Function to toggle music on/off
void toggleMusic2(SDL_Texture *muteTexture, SDL_Texture *unmuteTexture, int &musicPlaying)
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

void reset_2()
{
    jump_2 = 0;
    green_2 = 1;

    bird_rect_2.x = Start_x2;
    bird_rect_2.y = Start_y2;

    // SDL_Delay(500);
}

void back_button_music_level2()
{
    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/audio/back_button.mp3");
    Mix_PlayMusic(backgroundMusic, 0); // Start playing music once
    SDL_Delay(100);
    // Mix_FreeMusic(backgroundMusic);
    // Mix_CloseAudio();
}

void levelTwo() // main function
{

    Previous_state = Current_state;

    SDL_SetTextureColorMod(texture[MUTE_BUTTON], 150, 150, 150);
    SDL_Rect musicButtonRect = {1450, 30, 80, 80};

    if (L2_Loading_Screen)
    {
        L2_Loading_Screen = false;

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture[LEVEL_2_LOADING_PAGE], NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }

    if (!level_2_initialized)
    {
        level_2_initialized = true;
        level_2_initialize();

        // music will start to play
        if (musicPlaying)
            Mix_PlayMusic(music[BACKGROUND_MUSIC], -1); // Start playing music indefinitely
        // else
        //     toggleMusic2(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);

        temp_surface2 = TTF_RenderText_Solid(valorax_font, playerName.c_str(), {255, 255, 255});
        temp_texture2 = SDL_CreateTextureFromSurface(renderer, temp_surface2);
        text_rec2 = {600, 30, temp_surface2->w - 30, temp_surface2->h - 20};
    }

    while (SDL_PollEvent(&level_2_event))
    {
        SDL_GetMouseState(&X, &Y);
        L2_cursor_rect = {X, Y, 30, 45};
        L2_cursor_inside = (X >= 1 && X <= 1599 && Y >= 1 && Y <= 899) ? true : false;

        if (level_2_event.type == SDL_QUIT)
        {
            running = false;
            return;
        }
        else if (level_2_event.type == SDL_MOUSEMOTION && SDL_MOUSEBUTTONDOWN)
        {
            if (!jump_2)
            {

                if (level_2_event.button.button == SDL_BUTTON_LEFT)
                {
                    if (clicked_2 || (X >= bird_rect_2.x && X <= bird_rect_2.x + Bird_length_2) && (Y >= bird_rect_2.y && Y <= bird_rect_2.y + Bird_length_2)) // is clicked_2 inside bird
                    {

                        clicked_2 = 1; // extra

                        // This is the range of bird where it can be stretched
                        // start
                        if ((X - Bird_length_2 / 2) >= 0 && (X) <= 600)
                        {
                            bird_rect_2.x = X - Bird_length_2 / 2;
                        }
                        if ((Y - Bird_length_2) >= 300 && (Y) <= (SCREEN_HEIGHT - 4.5 * Bird_length_2 + 70))
                            bird_rect_2.y = Y - Bird_length_2 / 2;
                        // bird stretch range end
                    }
                }
            }
        }
        else if (level_2_event.type == SDL_MOUSEBUTTONDOWN)
        {
            // if back button is clicked then returns to menu
            if (isHovered({X, Y}, back_button_rect) && level_2_event.button.button == SDL_BUTTON_LEFT)
            {
                Current_state = MENU;
                level_2_initialized = 0;
                L2_Loading_Screen = true;

                // music closed here
                if (musicPlaying)
                {
                    toggleMusic2(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
                    // Mix_CloseAudio();
                }

                back_button_music_level2();

                return;
            }

            // extra -->
            else if (isHovered({X, Y}, musicButtonRect) && level_2_event.button.button == SDL_BUTTON_LEFT)
            {
                toggleMusic2(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
            }
        }
        else if (level_2_event.type == SDL_MOUSEBUTTONUP)
        {
            clicked_2 = 0;

            if (level_2_event.button.button == SDL_BUTTON_LEFT)
            {

                if (!jump_2) // speed after releasing
                {
                    speed_x2 = (Start_x2 - bird_rect_2.x) / 5.0;
                    speed_y2 = -(Start_y2 - bird_rect_2.y) / 5.0;

                    if (isHovered({X, Y}, bird_rect_2)) // after releasing the bird, one turn will be lost
                    {
                        turns_left--;
                        printf("%d turns left\n", turns_left); // checking
                    }

                    bird_rect_2.x = Start_x2;
                    bird_rect_2.y = Start_y2;

                    jump_2 = 1;
                }
            }
        }

        /**/
        if (level_2_event.type == SDL_MOUSEMOTION)
        {
            int mouseX, mouseY;
        }

        /**/
        if (level_2_event.type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_GetMouseState(&X, &Y);
        }
    }

    /**/
    if (level_2_event.type == SDL_MOUSEMOTION)
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

    if (jump_2 && speed_x2)
    {
        bird_rect_2.x += speed_x2;

        if (bird_rect_2.x - 50 >= (SCREEN_WIDTH) || (bird_rect_2.x + Bird_length_2 + 100 <= 0))
        {
            jump_2 = 0;

            if (green_2 == 0) // Level
            {
                Current_state = LEVEL_3; // Next Level
                L2_Loading_Screen = true;

                level_2_initialized = 0;
                green_2 = 1;

                // // music closed here
                // if (musicPlaying)
                // {
                //     toggleMusic2(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
                // }

                return;
            }
            else if (turns_left == 0) // if number of turns left is 0 before hitting the bird - GAME OVER
            {
                Current_state = GAME_OVER;
                L2_Loading_Screen = true;
                level_2_initialized = 0; // Level 1 will be initialized when opened again
                green_2 = 1;

                // music closed here
                if (musicPlaying)
                {
                    toggleMusic2(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
                }

                Mix_PlayMusic(music[GAME_OVER_MUSIC], 0); // Start playing music once

                return;
            }

            green_2 = 1; // whether green_2 bird would render or not

            bird_rect_2.x = Start_x2;
            bird_rect_2.y = Start_y2;

            // SDL_Delay(500);

            goto here;
            // speed_x2 = -speed_x2;
        }

        bird_rect_2.y -= speed_y2;
        speed_y2 -= gravity2; // speed of y asix reduces due to gravity

        if ((bird_rect_2.y >= (SCREEN_HEIGHT - 5 * Bird_length_2 + 65))) // (bird_rect_2.y <= 0)
        {
            speed_y2 = -(speed_y2);                                     // bounces from ground
            bird_rect_2.y = (SCREEN_HEIGHT - 4.8 * Bird_length_2 + 65); // if goes down the limit, it is forced to stay at the limit

            // remaining speed after a bounce
            speed_y2 *= 0.60; // speed loss due to friction
            speed_x2 *= 0.90; // speed loss due to friction
        }
    }

    if (((abs(speed_x2) < 0.01) || (prev_x_position_2 == bird_rect_2.x)) && abs(speed_y2) < 5 && jump_2)
    {
        if (green_2 == 0) // Level
        {
            Current_state = LEVEL_3; // Next level
            L2_Loading_Screen = true;

            level_2_initialized = 0; // Current will be initialized when opened again
            green_2 = 1;

            // // music closed here
            // if (musicPlaying)
            // {
            //     toggleMusic2(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
            // }

            return;
        }
        else if (turns_left == 0) // if number of turns left is 0 before hitting the bird - GAME OVER
        {
            Current_state = GAME_OVER;
            L2_Loading_Screen = true;
            level_2_initialized = 0; // Level 1 will be initialized when opened again
            green_2 = 1;

            // music closed here
            if (musicPlaying)
            {
                toggleMusic2(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
            }

            Mix_PlayMusic(music[GAME_OVER_MUSIC], 0); // Start playing music once

            return;
        }

        jump_2 = 0;
        speed_y2 = 0.0;
        green_2 = 1;

        // if (bird_rect_2.x != Start_x2 || bird_rect_2.y != Start_y2)
        //     SDL_Delay(500);

        bird_rect_2.x = Start_x2;
        bird_rect_2.y = Start_y2;
    }

    // green bird up and down section - start
    if (green_2_up)
        green_2_bird_rect_2.y -= 6;
    else
        green_2_bird_rect_2.y += 6;

    if (green_2_bird_rect_2.y <= 130)
        green_2_up = 0;
    else if (green_2_bird_rect_2.y >= 660)
        green_2_up = 1;
    // green bird up and down section - end

    // colliding with walls and bounce back part - start
    if (normal_collide_2(bird_rect_2, L2_obstacle_rect[0]))
    {
        speed_x2 = -speed_x2;
        speed_x2 *= 0.60;
        bird_rect_2.x = L2_obstacle_rect[0].x - Bird_length_2;
    }
    if (normal_collide_2(bird_rect_2, L2_obstacle_rect[1]))
    {
        speed_x2 = -speed_x2;
        speed_x2 *= 0.60;
        bird_rect_2.x = L2_obstacle_rect[1].x - Bird_length_2;
    }
    // colliding with walls and bounce back part - end

here:
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture[LEVEL_2_BACKGROUND], NULL, NULL);

    // slingshot back rubber rendering - start   -    before slingshot back

    SDL_Rect slingshot_rubber_rect_1 = {slingshot_rect_2.x + 43, slingshot_rect_2.y, 100, 20};
    SDL_Point slingshot_rubber_center = {0, 10};
    Stretch rubber;

    slingshot_rubber_rect_1.w = rubber.distance({slingshot_rubber_rect_1.x, slingshot_rubber_rect_1.y}, {(bird_rect_2.x + bird_rect_2.w / 2), (bird_rect_2.y + bird_rect_2.h / 2)});
    // slingshot_rubber_rect_1.h = ((100 * 5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) < 100 ? ((100*5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) : 100;

    if ((bird_rect_2.x != Start_x2 || bird_rect_2.y != Start_y2) && clicked_2)
        SDL_RenderCopyEx(renderer, texture[SLINGSHOT_RUBBER], NULL, &slingshot_rubber_rect_1, rubber.calculateAngle((bird_rect_2.x + bird_rect_2.w / 2) - slingshot_rubber_rect_1.x, (bird_rect_2.y + bird_rect_2.h / 2) - (slingshot_rubber_rect_1.y)), &slingshot_rubber_center, SDL_FLIP_NONE);

    // slingshot back rubber rendering - end

    SDL_RenderCopy(renderer, texture[SLINGSHOT_BACK], NULL, &slingshot_rect_2);
    SDL_RenderCopy(renderer, texture[LEVEL_2_YELLOW_BIRD], NULL, &bird_rect_2);
    // SDL_RenderCopyEx(renderer, texture[SLINGSHOT_RUBBER], NULL,  &L2_obstacle_rect, 45.0, &slingshot_rubber_center, SDL_FLIP_NONE);
    SDL_RenderCopy(renderer, texture[SLINGSHOT_FRONT], NULL, &slingshot_rect_2);

    // slingshot front rubber rendering - start  after slingshot front

    slingshot_rubber_rect_1 = {slingshot_rect_2.x + 12, slingshot_rect_2.y, 100, 20};
    // SDL_Rect slingshot_rubber_rect_1 = {slingshot_rect_2.x + 43, 580, 100, 20};
    slingshot_rubber_center = {0, 10};

    slingshot_rubber_rect_1.w = rubber.distance({slingshot_rubber_rect_1.x, slingshot_rubber_rect_1.y}, {(bird_rect_2.x + bird_rect_2.w / 2), (bird_rect_2.y + bird_rect_2.h / 2)});
    // slingshot_rubber_rect_1.h = ((100 * 5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) < 100 ? ((100*5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) : 100;

    if ((bird_rect_2.x != Start_x2 || bird_rect_2.y != Start_y2) && clicked_2)
        SDL_RenderCopyEx(renderer, texture[SLINGSHOT_RUBBER], NULL, &slingshot_rubber_rect_1, rubber.calculateAngle((bird_rect_2.x + bird_rect_2.w / 2) - slingshot_rubber_rect_1.x, (bird_rect_2.y + bird_rect_2.h / 2) - (slingshot_rubber_rect_1.y)), &slingshot_rubber_center, SDL_FLIP_NONE);

    // slingshot front ubber rendering - end

    SDL_RenderCopy(renderer, texture[LEVEL_2_OBSTACLE], NULL, &L2_obstacle_rect[0]); // rendering obstacle
    SDL_RenderCopy(renderer, texture[LEVEL_2_OBSTACLE], NULL, &L2_obstacle_rect[1]);

    SDL_RenderCopy(renderer, temp_texture2, NULL, &text_rec2);

    if (!musicPlaying)
        SDL_RenderCopy(renderer, texture[MUTE_BUTTON], NULL, &musicButtonRect); // showing the music button
    if (musicPlaying)
        SDL_RenderCopy(renderer, texture[UNMUTE_BUTTON], NULL, &musicButtonRect); // showing the music button

    if (!collide_2(bird_rect_2, green_2_bird_rect_2) && green_2) // rendering green bird/pig
    {
        SDL_RenderCopy(renderer, texture[LEVEL_2_GREEN_PIG], NULL, &green_2_bird_rect_2);

        if (score_added_2)
        {
            score_added_2 = 0;

            printf("%d\n", score); // checking
        }
    }
    else
    {
        green_2 = 0;

        if (!score_added_2) // score
        {
            score += 10 + 10 * turns_left;
            score_added_2 = 1;

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


    if (L2_cursor_inside) // shows cursor while inside
        SDL_RenderCopy(renderer, texture[CURSOR], NULL, &L2_cursor_rect);

    SDL_Delay(10); // FRAME RATE

    SDL_RenderPresent(renderer); // updating window

    prev_x_position_2 = bird_rect_2.x;
}
