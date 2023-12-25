
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>



enum textures
{
    START,
    STORY,
    EXIT,
    BACKGROUND,
    CURSOR,
    TOTAL
};

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

bool init();
bool loadMedia();
void close();

SDL_Texture *loadTexture(std::string path);

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
SDL_Texture *gTexture[TOTAL] = {NULL};

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    // Loading success flag
    bool success = true;

    // Load PNG texture
    gTexture[START] = loadTexture("./Start_Button.png");
    gTexture[STORY] = loadTexture("./Story_Button.png");
    gTexture[EXIT] = loadTexture("./Exit_Button.png");
    gTexture[BACKGROUND] = loadTexture("./Background.jpg");
    gTexture[CURSOR] = loadTexture("./Cursor.png");

    for (int i = 0; i < TOTAL; i++)
    {
        if (gTexture[i] == NULL)
        {
            printf("Failed to load texture image! %d\n", i);
            success = false;
            break;
        }
    }

    return success;
}

void close()
{
    // Free loaded image

    for (int i = 0; i < TOTAL; i++)
    {
        SDL_DestroyTexture(gTexture[i]);
        gTexture[i] = NULL;
    }

    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture *loadTexture(std::string path)
{
    SDL_Texture *newTexture = NULL;
    newTexture = IMG_LoadTexture(gRenderer, path.c_str());
    return newTexture;
}

int main(int argc, char *args[])
{
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            bool quit = false;

            SDL_Event e;
            int X, Y;
            bool start_hovered = false, story_hovered = false, exit_hovered = false;

            SDL_Rect start, story, exit, start_hover, story_hover, exit_hover;
            start = {677, 600, 246, 59};
            story = {677, 680, 246, 59};
            exit = {677, 760, 246, 59};

            start_hover = {start.x - 5, start.y - 5, start.w + 10, start.h + 10};
            story_hover = {story.x - 5, story.y - 5, story.w + 10, story.h + 10};
            exit_hover = {exit.x - 5, exit.y - 5, exit.w + 10, exit.h + 10};

            while (!quit)
            {
                SDL_ShowCursor(0);
                SDL_GetMouseState(&X, &Y);

                SDL_Rect cursor_rect = {X, Y, 30, 45};

                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN && exit_hovered)
                    {
                        quit = true;
                    }
                }

                if (!start_hovered && (X >= start.x && X <= start.x + start.w && Y >= start.y && Y <= start.y + start.h))
                {
                    start_hovered = true;
                    // SDL_SetTextureColorMod(gTexture[START], 255, 255, 255);
                }
                else if (start_hovered && (X >= start_hover.x && X <= start_hover.x + start_hover.w && Y >= start_hover.y && Y <= start_hover.y + start_hover.h))
                {
                    start_hovered = true;
                    // SDL_SetTextureColorMod(gTexture[START], 255, 255, 255);
                }
                else
                {
                    start_hovered = false;
                    // SDL_SetTextureColorMod(gTexture[START], 150, 150, 150);
                }

                if (!story_hovered && (X >= story.x && X <= story.x + story.w && Y >= story.y && Y <= story.y + story.h))
                {
                    story_hovered = true;
                }
                else if (story_hovered && (X >= story_hover.x && X <= story_hover.x + story_hover.w && Y >= story_hover.y && Y <= story_hover.y + story_hover.h))
                {
                    story_hovered = true;
                }
                else
                {
                    story_hovered = false;
                }

                if (!exit_hovered && (X >= exit.x && X <= exit.x + exit.w && Y >= exit.y && Y <= exit.y + exit.h))
                {
                    exit_hovered = true;
                }
                else if (exit_hovered && (X >= exit_hover.x && X <= exit_hover.x + exit_hover.w && Y >= exit_hover.y && Y <= exit_hover.y + exit_hover.h))
                {
                    exit_hovered = true;
                }
                else
                {
                    exit_hovered = false;
                }

                SDL_RenderClear(gRenderer);

                SDL_RenderCopy(gRenderer, gTexture[BACKGROUND], NULL, NULL);
                if (!start_hovered)
                    SDL_RenderCopy(gRenderer, gTexture[START], NULL, &start);
                else
                    SDL_RenderCopy(gRenderer, gTexture[START], NULL, &start_hover);

                if (!story_hovered)
                    SDL_RenderCopy(gRenderer, gTexture[STORY], NULL, &story);
                else
                    SDL_RenderCopy(gRenderer, gTexture[STORY], NULL, &story_hover);

                if (!exit_hovered)
                    SDL_RenderCopy(gRenderer, gTexture[EXIT], NULL, &exit);
                else
                    SDL_RenderCopy(gRenderer, gTexture[EXIT], NULL, &exit_hover);

                if(X>=0 && X<=1600 && Y>=0 && Y<=900)
                    SDL_RenderCopy(gRenderer, gTexture[CURSOR], NULL, &cursor_rect);

                SDL_RenderPresent(gRenderer);
            }
        }
    }

    close();

    return 0;
}
