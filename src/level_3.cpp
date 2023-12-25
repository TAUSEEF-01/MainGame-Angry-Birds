#include "../include/header.h"

SDL_Event level_3_event;

bool jump_3 = 0, green_3 = 1, level_3_initialized = 0, clicked_3 = 0, L3_cursor_inside = true, L3_Loading_Screen = true;
bool score_added_3 = 0;
bool green_3_up = 1, L3_obstacle_up_0 = 0, L3_obstacle_up_1 = 1;
int Start_x3 = 210, Start_y3 = 560 + 65;
int Bird_length_3 = 50;
int prev_x_position_3 = -100;

double speed_x3 = 0.0, speed_y3 = 0.0;
double gravity3 = 0.5;

SDL_Rect bird_rect_3, slingshot_rect_3, green_3_bird_rect_3, L3_cursor_rect, L3_obstacle_rect[2];
SDL_Rect cloud, cloud_1, cloud_2, cloud_3, cloud_4, cloud_5;
// SDL_Point slingshot_rubber_center;

SDL_Surface *temp_surface3;
SDL_Texture *temp_texture3;
SDL_Rect text_rec3;


void level_3_initialize()
{
    bird_rect_3 = {Start_x3, Start_y3, Bird_length_3, Bird_length_3};
    // slingshot_rubber_center = {800, 450};
    L3_obstacle_rect[0] = {1000, 0, 50, 150};
    L3_obstacle_rect[1] = {1200, 625, 50, 150};
    slingshot_rect_3 = {210, 580 + 65, 47, 124};
    green_3_bird_rect_3 = {1400, 480 + 65, 100, 100};

    turns_left = 10; // 10 turns will be given

    cloud = {0, 100, 300, 100};
    cloud_1 = cloud_2 = cloud_3 = cloud_4 = cloud_5 = cloud;
    cloud_2.x = cloud.x + 400;
    cloud_3.x = cloud.x + 800;
    cloud_4.x = cloud.x + 1200;
    cloud_5.x = cloud.x + 1600;
}

void cloud_reset()
{

    cloud = {0, 100, 300, 100};
    cloud_1 = cloud_2 = cloud_3 = cloud_4 = cloud_5 = cloud;
    cloud_2.x = cloud.x + 400;
    cloud_3.x = cloud.x + 800;
    cloud_4.x = cloud.x + 1200;
    cloud_5.x = cloud.x + 1600;
}

bool collide_3(SDL_Rect a, SDL_Rect b)
{
    if (((a.x + a.w) > (b.x + 10)) && ((a.x + 10) < (b.x + b.w)) && ((a.y + a.h) > (b.y + 10)) && (((a.y + 10) < (b.y + b.h))))
        return 1;
    return 0;
}

bool normal_collide_3(SDL_Rect a, SDL_Rect b)
{
    if (((a.x + a.w) > (b.x)) && ((a.x) < (b.x + b.w)) && ((a.y + a.h) > (b.y)) && (((a.y) < (b.y + b.h))))
        return 1;
    return 0;
}


// music part --> start

// int musicPlaying = 1;           // Flag to indicate if music is playing (1 for playing, 0 for stopped)

// Function to toggle music on/off
void toggleMusic3(SDL_Texture *muteTexture, SDL_Texture *unmuteTexture, int &musicPlaying)
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

void reset_3()
{
    jump_3 = 0;
    green_3 = 1;

    bird_rect_3.x = Start_x3;
    bird_rect_3.y = Start_y3;

    // SDL_Delay(500);
}

void back_button_music_level3()
{
    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/audio/back_button.mp3");
    Mix_PlayMusic(backgroundMusic, 0); // Start playing music once
    SDL_Delay(100);
    // Mix_FreeMusic(backgroundMusic);
}

void levelThree() // main function
{
    Previous_state = Current_state;

    SDL_SetTextureColorMod(texture[MUTE_BUTTON], 150, 150, 150);
    SDL_Rect musicButtonRect = {1450, 30, 80, 80};


    if (L3_Loading_Screen)
    {
        L3_Loading_Screen = false;

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture[LEVEL_3_LOADING_PAGE], NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }

    if (!level_3_initialized)
    {
        level_3_initialized = true;
        level_3_initialize();

        // // music will start to play
        if (musicPlaying)
            Mix_PlayMusic(music[BACKGROUND_MUSIC], -1); // Start playing music indefinitely
        // else
        //     toggleMusic3(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);



        temp_surface3 = TTF_RenderText_Solid(valorax_font, playerName.c_str(), {255, 255, 255});
        temp_texture3 = SDL_CreateTextureFromSurface(renderer, temp_surface3);
        text_rec3 = {600, 30, temp_surface3->w -30 , temp_surface3->h - 20};
        
    }

    while (SDL_PollEvent(&level_3_event))
    {
        SDL_GetMouseState(&X, &Y);
        L3_cursor_rect = {X, Y, 30, 45};
        L3_cursor_inside = (X >= 1 && X <= 1599 && Y >= 1 && Y <= 899) ? true : false;

        if (level_3_event.type == SDL_QUIT)
        {
            running = false;
            return;
        }
        else if (level_3_event.type == SDL_MOUSEMOTION && SDL_MOUSEBUTTONDOWN)
        {
            if (!jump_3)
            {

                if (level_3_event.button.button == SDL_BUTTON_LEFT)
                {
                    if (clicked_3 || (X >= bird_rect_3.x && X <= bird_rect_3.x + Bird_length_3) && (Y >= bird_rect_3.y && Y <= bird_rect_3.y + Bird_length_3)) // is clicked_3 inside bird
                    {

                        clicked_3 = 1; // extra

                        // This is the range of bird where it can be stretched
                        // start
                        if ((X - Bird_length_3 / 2) >= 0 && (X) <= 600)
                        {
                            bird_rect_3.x = X - Bird_length_3 / 2;
                        }
                        if ((Y - Bird_length_3) >= 300 && (Y) <= (SCREEN_HEIGHT - 4.5 * Bird_length_3 + 70))
                            bird_rect_3.y = Y - Bird_length_3 / 2;
                        // bird stretch range end
                    }
                }
            }
        }
        else if (level_3_event.type == SDL_MOUSEBUTTONDOWN)
        {
            // if back button is clicked then returns to menu
            if (isHovered({X, Y}, back_button_rect) && level_3_event.button.button == SDL_BUTTON_LEFT)
            {
                Current_state = MENU;
                level_3_initialized = 0;
                L3_Loading_Screen = true;

                // music closed here
                if (musicPlaying)
                {
                    toggleMusic3(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
                    // Mix_CloseAudio();
                }

                back_button_music_level3();

                return;
            }

            // extra -->
            else if (isHovered({X, Y}, musicButtonRect) && level_3_event.button.button == SDL_BUTTON_LEFT)
            {
                toggleMusic3(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
            }
            
        }
        else if (level_3_event.type == SDL_MOUSEBUTTONUP)
        {
            clicked_3 = 0;

            if (level_3_event.button.button == SDL_BUTTON_LEFT)
            {

                if (!jump_3) // speed after releasing
                {
                    speed_x3 = (Start_x3 - bird_rect_3.x) / 5.0;
                    speed_y3 = -(Start_y3 - bird_rect_3.y) / 5.0;
                    

                    if (isHovered({X, Y}, bird_rect_3)) // after releasing the bird, one turn will be lost
                    {
                        turns_left--;
                        printf("%d turns left\n", turns_left); // checking
                    }

                    bird_rect_3.x = Start_x3;
                    bird_rect_3.y = Start_y3;

                    jump_3 = 1;
                }
            }
        }

        /**/
        if (level_3_event.type == SDL_MOUSEMOTION)
        {
            int mouseX, mouseY;
        }

        /**/
        if (level_3_event.type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_GetMouseState(&X, &Y);
        }
    }

    /**/
    if (level_3_event.type == SDL_MOUSEMOTION)
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


    if (jump_3 && speed_x3)
    {
        bird_rect_3.x += speed_x3;

        if (bird_rect_3.x - 50 >= (SCREEN_WIDTH) || (bird_rect_3.x + Bird_length_3 + 100 <= 0))
        {
            jump_3 = 0;

            if (green_3 == 0) // Level
            {
                Current_state = GAME_SUCCESSFULLY_COMPLETED; // Winning moment
                L3_Loading_Screen = true;

                level_3_initialized = 0;
                green_3 = 1;

                // music closed here
                if (musicPlaying)
                {
                    toggleMusic3(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
                }

                Mix_PlayMusic(music[GAME_WIN_MUSIC], 0); // Start playing music once

                return;
            }
            else if (turns_left == 0) // if number of turns left is 0 before hitting the bird - GAME OVER
            {
                Current_state = GAME_OVER;
                L3_Loading_Screen = true;
                level_3_initialized = 0; // Level 1 will be initialized when opened again
                green_3 = 1;


                // music closed here
                if (musicPlaying)
                {
                    toggleMusic3(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
                }

                Mix_PlayMusic(music[GAME_OVER_MUSIC], 0); // Start playing music once

                return;
            }

            green_3 = 1; // whether green_3 bird would render or not

            bird_rect_3.x = Start_x3;
            bird_rect_3.y = Start_y3;

            // SDL_Delay(500);

            goto here;
            // speed_x3 = -speed_x3;
        }

        bird_rect_3.y -= speed_y3;
        speed_y3 -= gravity3; // speed of y asix reduces due to gravity

        if ((bird_rect_3.y >= (SCREEN_HEIGHT - 5 * Bird_length_3 + 65))) // (bird_rect_3.y <= 0)
        {
            speed_y3 = -(speed_y3);                                     // bounces from ground
            bird_rect_3.y = (SCREEN_HEIGHT - 4.8 * Bird_length_3 + 65); // if goes down the limit, it is forced to stay at the limit

            // reamaining speed after a bounce
            speed_y3 *= 0.60; // speed loss due to friction
            speed_x3 *= 0.90; // speed loss due to friction
        }
    }

    if (((abs(speed_x3) < 0.01) || (prev_x_position_3 == bird_rect_3.x)) && abs(speed_y3) < 5 && jump_3)
    {
        if (green_3 == 0) // Level
        {
            Current_state = GAME_SUCCESSFULLY_COMPLETED; // Winning moment
            L3_Loading_Screen = true;

            level_3_initialized = 0; // Current will be initialized when opened again
            green_3 = 1;

            // music closed here
            if (musicPlaying)
            {
                toggleMusic3(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
            }

            Mix_PlayMusic(music[GAME_WIN_MUSIC], 0); // Start playing music once

            return;
        }
        else if (turns_left == 0) // if number of turns left is 0 before hitting the bird - GAME OVER
        {
            Current_state = GAME_OVER;
            L3_Loading_Screen = true;
            level_3_initialized = 0; // Level 1 will be initialized when opened again
            green_3 = 1;

            // music closed here
            if (musicPlaying)
            {
                toggleMusic3(texture[MUTE_BUTTON], texture[UNMUTE_BUTTON], musicPlaying);
            }

            Mix_PlayMusic(music[GAME_OVER_MUSIC], 0); // Start playing music once

            return;
        }

        jump_3 = 0;
        speed_y3 = 0.0;
        green_3 = 1;

        // if (bird_rect_3.x != Start_x3 || bird_rect_3.y != Start_y3)
        //     SDL_Delay(500);

        bird_rect_3.x = Start_x3;
        bird_rect_3.y = Start_y3;
    }

    // green bird up and down section - start
    if (green_3_up)
    {
        green_3_bird_rect_3.y -= 6;
        green_3_bird_rect_3.x = 1400 + 40 * sin(green_3_bird_rect_3.y);
    }
    else
    {
        green_3_bird_rect_3.y += 6;
        green_3_bird_rect_3.x = 1400 + 40 * sin(green_3_bird_rect_3.y);
    }

    if (green_3_bird_rect_3.y <= 0)
        green_3_up = 0;
    else if (green_3_bird_rect_3.y >= 660)
        green_3_up = 1;
    // green bird up and down section - end

    // colliding with walls and bounce back part - start
    if (normal_collide_3(bird_rect_3, L3_obstacle_rect[0]))
    {
        speed_x3 = -speed_x3;
        speed_x3 *= 0.60;
        bird_rect_3.x = L3_obstacle_rect[0].x - Bird_length_3;
    }
    if (normal_collide_3(bird_rect_3, L3_obstacle_rect[1]))
    {
        speed_x3 = -speed_x3;
        speed_x3 *= 0.60;
        bird_rect_3.x = L3_obstacle_rect[1].x - Bird_length_3;
    }
    // colliding with walls and bounce back part - end

here:
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture[LEVEL_3_BACKGROUND], NULL, NULL);


    // clouds rendering - start

    SDL_RenderCopy(renderer, texture[LEVEL_3_CLOUD], NULL, &cloud_1);
    SDL_RenderCopy(renderer, texture[LEVEL_3_CLOUD], NULL, &cloud_2);
    SDL_RenderCopy(renderer, texture[LEVEL_3_CLOUD], NULL, &cloud_3);
    SDL_RenderCopy(renderer, texture[LEVEL_3_CLOUD], NULL, &cloud_4);
    SDL_RenderCopy(renderer, texture[LEVEL_3_CLOUD], NULL, &cloud_5);



    cloud_1.x--;
    cloud_2.x--;
    cloud_3.x--;
    cloud_4.x--;
    cloud_5.x--;

    if (cloud_1.x <= -400)
        cloud_reset();

    // coulds rendering - end




// slingshot back rubber rendering - start   -    before slingshot back

    SDL_Rect slingshot_rubber_rect_1 = {slingshot_rect_3.x + 43, slingshot_rect_3.y, 100, 20};
    SDL_Point slingshot_rubber_center = {0, 10};
    Stretch rubber;

    slingshot_rubber_rect_1.w = rubber.distance({slingshot_rubber_rect_1.x, slingshot_rubber_rect_1.y}, {(bird_rect_3.x + bird_rect_3.w/2), (bird_rect_3.y + bird_rect_3.h/2)});
    // slingshot_rubber_rect_1.h = ((100 * 5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) < 100 ? ((100*5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) : 100;

    if((bird_rect_3.x != Start_x3 || bird_rect_3.y != Start_y3) && clicked_3)
        SDL_RenderCopyEx(renderer, texture[SLINGSHOT_RUBBER], NULL, &slingshot_rubber_rect_1, rubber.calculateAngle((bird_rect_3.x + bird_rect_3.w/2) - slingshot_rubber_rect_1.x, (bird_rect_3.y + bird_rect_3.h/2) - (slingshot_rubber_rect_1.y)), &slingshot_rubber_center, SDL_FLIP_NONE);

// slingshot back rubber rendering - end




    SDL_RenderCopy(renderer, texture[SLINGSHOT_BACK], NULL, &slingshot_rect_3);
    SDL_RenderCopy(renderer, texture[LEVEL_3_BLACK_BIRD], NULL, &bird_rect_3);
    // SDL_RenderCopyEx(renderer, texture[SLINGSHOT_RUBBER], NULL,  &L3_obstacle_rect, 45.0, &slingshot_rubber_center, SDL_FLIP_NONE);
    SDL_RenderCopy(renderer, texture[SLINGSHOT_FRONT], NULL, &slingshot_rect_3);





// slingshot front rubber rendering - start  after slingshot front

    slingshot_rubber_rect_1 = {slingshot_rect_3.x  + 12, slingshot_rect_3.y, 100, 20};
    // SDL_Rect slingshot_rubber_rect_1 = {slingshot_rect_3.x + 43, 580, 100, 20};
    slingshot_rubber_center = {0, 10};

    slingshot_rubber_rect_1.w = rubber.distance({slingshot_rubber_rect_1.x, slingshot_rubber_rect_1.y}, {(bird_rect_3.x + bird_rect_3.w/2), (bird_rect_3.y + bird_rect_3.h/2)});
    // slingshot_rubber_rect_1.h = ((100 * 5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) < 100 ? ((100*5) / ((slingshot_rubber_rect_1.w) ? slingshot_rubber_rect_1.w : 1)) : 100;

    if((bird_rect_3.x != Start_x3 || bird_rect_3.y != Start_y3) && clicked_3)
        SDL_RenderCopyEx(renderer, texture[SLINGSHOT_RUBBER], NULL, &slingshot_rubber_rect_1, rubber.calculateAngle((bird_rect_3.x + bird_rect_3.w/2) - slingshot_rubber_rect_1.x, (bird_rect_3.y + bird_rect_3.h/2) - (slingshot_rubber_rect_1.y)), &slingshot_rubber_center, SDL_FLIP_NONE);

// slingshot front ubber rendering - end



    SDL_RenderCopy(renderer, temp_texture3, NULL, &text_rec3);


    // Music playing
    if (!musicPlaying)
        SDL_RenderCopy(renderer, texture[MUTE_BUTTON], NULL, &musicButtonRect); // showing the music button
    if (musicPlaying)
        SDL_RenderCopy(renderer, texture[UNMUTE_BUTTON], NULL, &musicButtonRect); // showing the music button


    // obstacle movement - start

    SDL_RenderCopy(renderer, texture[LEVEL_2_OBSTACLE], NULL, &L3_obstacle_rect[0]); // rendering obstacle
    SDL_RenderCopy(renderer, texture[LEVEL_2_OBSTACLE], NULL, &L3_obstacle_rect[1]);

    if (L3_obstacle_up_0 == 1)
        L3_obstacle_rect[0].y -= 3;
    else
        L3_obstacle_rect[0].y += 3;

    if (L3_obstacle_rect[0].y <= 0)
    {
        L3_obstacle_rect[0].y = 0;
        L3_obstacle_up_0 = 0;
    }
    else if (L3_obstacle_rect[0].y >= 625)
    {
        L3_obstacle_rect[0].y = 625;
        L3_obstacle_up_0 = 1;
    }

    if (L3_obstacle_up_1 == 1)
        L3_obstacle_rect[1].y -= 5;
    else
        L3_obstacle_rect[1].y += 5;

    if (L3_obstacle_rect[1].y <= 0)
    {
        L3_obstacle_rect[1].y = 0;
        L3_obstacle_up_1 = 0;
    }
    else if (L3_obstacle_rect[1].y >= 625)
    {
        L3_obstacle_rect[1].y = 625;
        L3_obstacle_up_1 = 1;
    }

    // obstacle movement - end

    if (!collide_3(bird_rect_3, green_3_bird_rect_3) && green_3) // rendering green bird/pig
    {
        SDL_RenderCopy(renderer, texture[LEVEL_3_GREEN_PIG], NULL, &green_3_bird_rect_3);
    
        if(score_added_3)
        {
            score_added_3 = 0;

            printf("%d\n", score); // checking
        }

    }
    else
    {
        green_3 = 0;

        if(!score_added_3) // score
        {
            score += 10 + 10*turns_left;
            score_added_3 = 1;

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



    if (L3_cursor_inside) // shows cursor while inside
        SDL_RenderCopy(renderer, texture[CURSOR], NULL, &L3_cursor_rect);

    SDL_Delay(10); // FRAME RATE

    SDL_RenderPresent(renderer); // updating window

    prev_x_position_3 = bird_rect_3.x;
}
