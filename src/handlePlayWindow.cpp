#include "main.h"

bool collide(SDL_Rect a, SDL_Rect b)
{
    if (((a.x + a.w) > (b.x + 30)) && ((a.x + 50) < (b.x + b.w)) && ((a.y + a.h) > (b.y + 10)) && (((a.y + 30) < (b.y + b.h))))
        return 1;
    return 0;
}

void reset(bool jump, bool Green, int Start_x, int Start_y, SDL_Rect bird_rect)
{
    jump = 0;
    Green = 1;

    bird_rect.x = Start_x;
    bird_rect.y = Start_y;

    SDL_Delay(500);
}

void handlePlayWindow(SDL_Renderer *renderer, SDL_Texture *backgroundTexture, bool &quit)
{

    SDL_Texture *birdTexture = IMG_LoadTexture(renderer, "../res/bird.png");

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

    SDL_Event e;

    bool jump = 0, Green = 1, clicked = 0; // clikcked
    int Bird_length = 50;

    double speed_x = 0.0, speed_y = 0.0, vf = 0.0;
    double gravity = 0.5;

    int X = 0, Y = 0, count = 0, Start_x = 210, Start_y = 560, count_of_collision_with_wall = 0;
    int prev_x_position = -100;

    SDL_Rect bird_rect = {Start_x, Start_y, Bird_length, Bird_length};
    SDL_Rect slingshot_rect = {210, 580, 47, 124};
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

                        if (clicked || (X >= bird_rect.x && X <= bird_rect.x + Bird_length) && (Y >= bird_rect.y && Y <= bird_rect.y + Bird_length)) // is clicked inside bird
                        {

                            clicked = 1; // extra
                            if ((X - Bird_length / 2) >= 0 && (X) <= (SCREEN_WIDTH / 2))
                            {
                                bird_rect.x = X - Bird_length / 2;
                            }
                            if ((Y - Bird_length) >= 0 && (Y) <= (SCREEN_HEIGHT - 4.5 * Bird_length))
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
                goto here;
                // speed_x = -speed_x;
            }

            bird_rect.y -= speed_y;
            speed_y -= gravity;

            if ((bird_rect.y >= (SCREEN_HEIGHT - 5 * Bird_length))) // (bird_rect.y <= 0)
            {
                speed_y = -(speed_y);
                bird_rect.y = (SCREEN_HEIGHT - 4.8 * Bird_length); // if goes down the limit, it is forced to stay at the limit
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

            if (bird_rect.x != Start_x || bird_rect.y != Start_y)
                SDL_Delay(500);

            bird_rect.x = Start_x;
            bird_rect.y = Start_y;
        }

        if (jump) // frame rate
            SDL_Delay(10);

    here:
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        SDL_RenderCopy(renderer, slingshot_back, NULL, &slingshot_rect);
        SDL_RenderCopy(renderer, birdTexture, NULL, &bird_rect);

        if (!collide(bird_rect, green_bird_rect) && Green)
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

        // printf("%d %d %lf\n", prev_x_position, bird_rect.x, speed_y); // testing
    }

    // Destroy the bird texture when done

    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(birdTexture);
}