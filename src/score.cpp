#include "main.h"

void handleScoreDisplay(SDL_Renderer *renderer, State &currentState, int &playerScore, const std::string &playerName, bool &quit)
{
    SDL_Event scoreDisplayEvent;

    SDL_Texture *back_buttonTexture = surfaceToTexture(renderer, "../res/home2.png");

    SDL_SetTextureColorMod(back_buttonTexture, 150, 150, 150);
    SDL_Rect playButtonRect = {OPTION_BUTTON_POS_X + 50, OPTION_BUTTON_POS_Y + 200, 250, 80};



    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    Mix_Music *backgroundMusic = Mix_LoadMUS("../res/back_button.mp3");
    if (backgroundMusic == NULL)
    {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }


    TTF_Font* font2 = TTF_OpenFont("roboto.ttf", 36);
    if (font2 == nullptr) {
        printf("Unable to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return;
    }


    while (SDL_PollEvent(&scoreDisplayEvent) != 0)
    {
        if (scoreDisplayEvent.type == SDL_QUIT)
        {
            quit = true;
        }

        else if (scoreDisplayEvent.type == SDL_MOUSEMOTION)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
                mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h))
            {
                SDL_SetTextureColorMod(back_buttonTexture, 255, 255, 255);
            }
            else
            {
                SDL_SetTextureColorMod(back_buttonTexture, 150, 150, 150);
            }
        }
        else if (scoreDisplayEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
                mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h))
            {
                Mix_PlayMusic(backgroundMusic, -1); // Start playing music indefinitely
                SDL_Delay(100);

                currentState = NEW_PAGE;
                Mix_FreeMusic(backgroundMusic);
                Mix_CloseAudio();
                return;
            }
        }
    }

    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
        mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h))
    {
        SDL_SetTextureColorMod(back_buttonTexture, 255, 255, 255);
    }
    else
    {
        SDL_SetTextureColorMod(back_buttonTexture, 150, 150, 150);
    }

    SDL_RenderClear(renderer);
    SDL_Surface *backgroundSurface = IMG_Load("../res/score_page.png");
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);


    SDL_RenderCopy(renderer, back_buttonTexture, NULL, &playButtonRect);


    // playerScore = 100;

    // Render the score text
    std::string scoreText = "Your Score: " + std::to_string(playerScore);
    SDL_Surface *scoreSurface = TTF_RenderText_Solid(font2, scoreText.c_str(), {0, 0, 0});
    SDL_Texture *scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_FreeSurface(scoreSurface);

    SDL_Rect scoreRect = {OPTION_BUTTON_POS_X , 100, scoreSurface->w, scoreSurface->h};
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
    SDL_DestroyTexture(scoreTexture);

    // Render the player's name
    SDL_Surface *nameSurface = TTF_RenderText_Solid(font2, ("Player        : " + playerName).c_str(), {0, 0, 0});
    SDL_Texture *nameTexture = SDL_CreateTextureFromSurface(renderer, nameSurface);
    SDL_FreeSurface(nameSurface);

    SDL_Rect nameRect = {OPTION_BUTTON_POS_X , 50, nameSurface->w, nameSurface->h};
    SDL_RenderCopy(renderer, nameTexture, NULL, &nameRect);
    SDL_DestroyTexture(nameTexture);

    SDL_RenderPresent(renderer);

}
