    // bool quit = false;
    // SDL_Event e;

    // while (!quit) {
    //     // Handle events on queue
    //     while (SDL_PollEvent(&e) != 0) {
    //         if (e.type == SDL_QUIT) {
    //             quit = true;
    //         } else if (e.type == SDL_WINDOWEVENT) {
    //             if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
    //                 // Handle window resize
    //                 // You might want to update your rendering logic here
    //             }
    //         }
    //     }

    //     // Clear the renderer
    //     SDL_RenderClear(renderer);

    //     // Render the image
    //     SDL_RenderCopy(renderer, imageTexture, NULL, NULL);

    //     // Your rendering code goes here

    //     // Update the window
    //     SDL_RenderPresent(renderer);
    // }






















//////////////////////////////////////////////////////

// void handleNewPage(SDL_Renderer* renderer, SDL_Texture* newPageTexture, SDL_Texture* playButtonTexture, SDL_Rect playButtonRect, bool& quit, State& currentState) {
//     SDL_Event newPageEvent;
//     while (SDL_PollEvent(&newPageEvent) != 0) {
//         if (newPageEvent.type == SDL_QUIT) {
//             quit = true;
//         } else if (newPageEvent.type == SDL_MOUSEBUTTONDOWN) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);
//             if (mouseX >= PLAY_BUTTON_POS_X && mouseX <= (PLAY_BUTTON_POS_X + 400) &&
//                 mouseY >= PLAY_BUTTON_POS_Y && mouseY <= (PLAY_BUTTON_POS_Y + 300)) {
//                 currentState = PLAY_WINDOW;
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, newPageTexture, NULL, NULL);
//     SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);
//     SDL_RenderPresent(renderer);
// }
















//////////////////////////////////////////////////////////////////////////////////////////


// void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit) {
//     SDL_Event playWindowEvent;
//     while (SDL_PollEvent(&playWindowEvent) != 0) {
//         if (playWindowEvent.type == SDL_QUIT) {
//             quit = true;
//         }
//     }

//     SDL_RenderClear(renderer);

//     // Render the background image
//     SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//     // Load the bird texture
//     SDL_Surface* birdSurface = IMG_Load("bird.png");
//     if (birdSurface == nullptr) {
//         printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
//     SDL_FreeSurface(birdSurface);

//     if (birdTexture == nullptr) {
//         printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     // Set the position and size of the bird
//     SDL_Rect birdRect = { 130, 700, 100, 100 };  // Adjust the position and size as needed

//     // Render the bird texture
//     SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

//     // Add any additional rendering or logic here

//     SDL_RenderPresent(renderer);

//     // Destroy the bird texture when done
//     SDL_DestroyTexture(birdTexture);
// }


// void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit) {
//     // Load the bird texture
//     SDL_Surface* birdSurface = IMG_Load("bird.png");
//     if (birdSurface == nullptr) {
//         printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
//     SDL_FreeSurface(birdSurface);

//     if (birdTexture == nullptr) {
//         printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     // Set the initial position and size of the bird
//     SDL_Rect birdRect = { 130, 700, 100, 100 };  // Adjust the position and size as needed

//     // Flag to track if the bird is glowing
//     bool isGlowing = false;

//     // Main game loop for the play window
//     SDL_Event playWindowEvent;
//     while (!quit) {
//         while (SDL_PollEvent(&playWindowEvent) != 0) {
//             if (playWindowEvent.type == SDL_QUIT) {
//                 quit = true;
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONDOWN) {
//                 int mouseX, mouseY;
//                 SDL_GetMouseState(&mouseX, &mouseY);

//                 // Check if the mouse click is on the bird
//                 if (mouseX >= birdRect.x && mouseX <= (birdRect.x + birdRect.w) &&
//                     mouseY >= birdRect.y && mouseY <= (birdRect.y + birdRect.h)) {
//                     isGlowing = true;  // Start glowing when clicked
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONUP) {
//                 // Stop glowing when the mouse button is released
//                 isGlowing = false;

//                 // Simulate the launch by changing the velocity of the bird
//                 // You can customize the velocity based on the user's drag distance and direction
//                 // In this example, a fixed velocity is used
//                 int launchVelocity = 10;
//                 birdRect.x += launchVelocity;  // Adjust the direction and speed as needed
//             }
//         }

//         SDL_RenderClear(renderer);

//         // Render the background image
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//         // Render the bird texture with or without glow based on the isGlowing flag
//         if (isGlowing) {
//             // Glow effect when the bird is clicked
//             SDL_SetTextureColorMod(birdTexture, 255, 255, 255);
//         } else {
//             SDL_SetTextureColorMod(birdTexture, 150, 150, 150);  // Normal color
//         }

//         // Render the bird texture
//         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

//         // Add any additional rendering or logic here

//         SDL_RenderPresent(renderer);
//     }

//     // Destroy the bird texture when done
//     SDL_DestroyTexture(birdTexture);
// }

// void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit) {
//     // Load the bird texture
//     SDL_Surface* birdSurface = IMG_Load("bird.png");
//     if (birdSurface == nullptr) {
//         printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
//     SDL_FreeSurface(birdSurface);

//     if (birdTexture == nullptr) {
//         printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     // Set the initial position and size of the bird
//     SDL_Rect birdRect = { 130, 700, 100, 100 };  // Adjust the position and size as needed

//     // Flag to track if the bird is glowing
//     bool isGlowing = false;

//     // Flag to track if the bird is being dragged
//     bool isDragging = false;

//     // Initial position of the bird when dragging starts
//     int dragStartX = 0;
//     int dragStartY = 0;

//     // Main game loop for the play window
//     SDL_Event playWindowEvent;
//     while (!quit) {
//         while (SDL_PollEvent(&playWindowEvent) != 0) {
//             if (playWindowEvent.type == SDL_QUIT) {
//                 quit = true;
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONDOWN) {
//                 int mouseX, mouseY;
//                 SDL_GetMouseState(&mouseX, &mouseY);

//                 // Check if the mouse click is on the bird
//                 if (mouseX >= birdRect.x && mouseX <= (birdRect.x + birdRect.w) &&
//                     mouseY >= birdRect.y && mouseY <= (birdRect.y + birdRect.h)) {
//                     isGlowing = true;  // Start glowing when clicked
//                     isDragging = true;  // Start dragging
//                     dragStartX = mouseX - birdRect.x;
//                     dragStartY = mouseY - birdRect.y;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEMOTION) {
//                 if (isDragging) {
//                     // Update the bird's position while dragging
//                     int mouseX, mouseY;
//                     SDL_GetMouseState(&mouseX, &mouseY);
//                     birdRect.x = mouseX - dragStartX;
//                     birdRect.y = mouseY - dragStartY;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONUP) {
//                 if (isDragging) {
//                     // Stop glowing and dragging when the mouse button is released
//                     isGlowing = false;
//                     isDragging = false;

//                     // Calculate launch velocity based on the drag distance and direction
//                     int dragEndX = playWindowEvent.button.x;
//                     int dragEndY = playWindowEvent.button.y;
//                     int dragDistanceX = dragEndX - (birdRect.x + birdRect.w / 2);
//                     int dragDistanceY = dragEndY - (birdRect.y + birdRect.h / 2);

//                     // Adjust the launch speed factor as needed
//                     double launchSpeedFactor = 0.1;

//                     // Calculate launch velocity components
//                     double launchVelocityX = launchSpeedFactor * dragDistanceX;
//                     double launchVelocityY = launchSpeedFactor * dragDistanceY;

//                     // Update the bird's position based on launch velocity
//                     while (birdRect.y > 0) {
//                         birdRect.x += static_cast<int>(launchVelocityX);
//                         birdRect.y += static_cast<int>(launchVelocityY);

//                         // Update the renderer
//                         SDL_RenderClear(renderer);
//                         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
//                         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);
//                         SDL_RenderPresent(renderer);

//                         // Introduce a small delay to control the frame rate
//                         SDL_Delay(10);
//                     }
//                 }
//             }
//         }

//         SDL_RenderClear(renderer);

//         // Render the background image
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//         // Render the bird texture with or without glow based on the isGlowing flag
//         if (isGlowing) {
//             // Glow effect when the bird is clicked
//             SDL_SetTextureColorMod(birdTexture, 255, 255, 255);
//         } else {
//             SDL_SetTextureColorMod(birdTexture, 150, 150, 150);  // Normal color
//         }

//         // Render the bird texture
//         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

//         // Add any additional rendering or logic here

//         SDL_RenderPresent(renderer);
//     }

//     // Destroy the bird texture when done
//     SDL_DestroyTexture(birdTexture);
// }






//######################################################################

    // Main game loop for the play window
    // SDL_Event playWindowEvent;
    // while (!quit) {
    //     while (SDL_PollEvent(&playWindowEvent) != 0) {
    //         if (playWindowEvent.type == SDL_QUIT) {
    //             quit = true;
    //         } else if (playWindowEvent.type == SDL_MOUSEBUTTONDOWN) {
    //             int mouseX, mouseY;
    //             SDL_GetMouseState(&mouseX, &mouseY);

    //             // Check if the mouse click is on the bird
    //             if (mouseX >= birdRect.x && mouseX <= (birdRect.x + birdRect.w) &&
    //                 mouseY >= birdRect.y && mouseY <= (birdRect.y + birdRect.h)) {
    //                 isGlowing = true;  // Start glowing when clicked
    //                 isDragging = true;  // Start dragging
    //                 dragStartX = mouseX - birdRect.x;
    //                 dragStartY = mouseY - birdRect.y;
    //             }
    //         } else if (playWindowEvent.type == SDL_MOUSEMOTION) {
    //             if (isDragging) {
    //                 // Update the bird's position while dragging
    //                 int mouseX, mouseY;
    //                 SDL_GetMouseState(&mouseX, &mouseY);
    //                 birdRect.x = mouseX - dragStartX;
    //                 birdRect.y = mouseY - dragStartY;
    //             }
    //         } else if (playWindowEvent.type == SDL_MOUSEBUTTONUP) {
    //             if (isDragging) {
    //                 // Stop glowing and dragging when the mouse button is released
    //                 isGlowing = false;
    //                 isDragging = false;

    //                 // Calculate launch velocity based on the drag distance and direction
    //                 int dragEndX = playWindowEvent.button.x;
    //                 int dragEndY = playWindowEvent.button.y;
    //                 int dragDistanceX = dragEndX - (birdRect.x + birdRect.w / 2);
    //                 int dragDistanceY = dragEndY - (birdRect.y + birdRect.h / 2);

    //                 // Adjust the launch speed factor as needed
    //                 double launchSpeedFactor = 0.1;

    //                 // Calculate launch velocity components
    //                 double launchVelocityX = launchSpeedFactor * dragDistanceX;
    //                 double launchVelocityY = launchSpeedFactor * dragDistanceY;

    //                 // Update the bird's position based on launch velocity
    //                 while (birdRect.y > 0) {
    //                     birdRect.x += static_cast<int>(launchVelocityX);
    //                     birdRect.y += static_cast<int>(launchVelocityY);

    //                     // Update the renderer
    //                     SDL_RenderClear(renderer);
    //                     SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
    //                     SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);
    //                     SDL_RenderPresent(renderer);

    //                     // Introduce a small delay to control the frame rate
    //                     SDL_Delay(10);
    //                 }
    //             }
    //         }
    //     }

    //     SDL_RenderClear(renderer);

    //     // Render the background image
    //     SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    //     // Render the bird texture with or without glow based on the isGlowing flag
    //     if (isGlowing) {
    //         // Glow effect when the bird is clicked
    //         SDL_SetTextureColorMod(birdTexture, 255, 255, 255);
    //     } else {
    //         SDL_SetTextureColorMod(birdTexture, 150, 150, 150);  // Normal color
    //     }

    //     // Render the bird texture
    //     SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

    //     // Add any additional rendering or logic here

    //     SDL_RenderPresent(renderer);
    // }

    // // Destroy the bird texture when done
    // SDL_DestroyTexture(birdTexture);












//###################################################




// void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit) {
//     // Load the bird texture
//     SDL_Surface* birdSurface = IMG_Load("bird.png");
//     if (birdSurface == nullptr) {
//         printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
//     SDL_FreeSurface(birdSurface);

//     if (birdTexture == nullptr) {
//         printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     // Set the initial position and size of the bird
//     SDL_Rect birdRect = { 130, 700, 100, 100 };  // Adjust the position and size as needed

//     // Flag to track if the bird is glowing
//     bool isGlowing = false;

//     // Flag to track if the bird is being dragged
//     bool isDragging = false;

//     // Initial position of the bird when dragging starts
//     int dragStartX = 0;
//     int dragStartY = 0;



//     // Main game loop for the play window
//     SDL_Event playWindowEvent;
//     while (!quit) {
//         while (SDL_PollEvent(&playWindowEvent) != 0) {
//             if (playWindowEvent.type == SDL_QUIT) {
//                 quit = true;
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONDOWN) {
//                 int mouseX, mouseY;
//                 SDL_GetMouseState(&mouseX, &mouseY);

//                 // Check if the mouse click is on the bird
//                 if (mouseX >= birdRect.x && mouseX <= (birdRect.x + birdRect.w) &&
//                     mouseY >= birdRect.y && mouseY <= (birdRect.y + birdRect.h)) {
//                     isGlowing = true;  // Start glowing when clicked
//                     isDragging = true;  // Start dragging
//                     dragStartX = mouseX - birdRect.x;
//                     dragStartY = mouseY - birdRect.y;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEMOTION) {
//                 if (isDragging) {
//                     // Update the bird's position while dragging
//                     int mouseX, mouseY;
//                     SDL_GetMouseState(&mouseX, &mouseY);
//                     birdRect.x = mouseX - dragStartX;
//                     birdRect.y = mouseY - dragStartY;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONUP) {
//                 if (isDragging) {
//                     // Stop glowing and dragging when the mouse button is released
//                     isGlowing = false;
//                     isDragging = false;

//                     // Calculate launch velocity based on the drag distance and direction
//                     int dragEndX = playWindowEvent.button.x;
//                     int dragEndY = playWindowEvent.button.y;
//                     int dragDistanceX = dragEndX - (birdRect.x + birdRect.w / 2);
//                     int dragDistanceY = dragEndY - (birdRect.y + birdRect.h / 2);

//                     // Adjust the launch speed factor as needed
//                     double launchSpeedFactor = 0.1;

//                     // Calculate launch velocity components
//                     double launchVelocityX = launchSpeedFactor * dragDistanceX;
//                     double launchVelocityY = launchSpeedFactor * dragDistanceY;

//                     // Main loop for bird's projectile motion
//                     while (birdRect.y < SCREEN_HEIGHT) {
//                         // Update the bird's position based on launch velocity
//                         birdRect.x += static_cast<int>(launchVelocityX);
//                         birdRect.y += static_cast<int>(launchVelocityY);

//                         // Update the renderer
//                         SDL_RenderClear(renderer);
//                         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
//                         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);
//                         SDL_RenderPresent(renderer);

//                         // Introduce a small delay to control the frame rate
//                         SDL_Delay(5);
//                     }
//                 }
//             }
//         }

//         SDL_RenderClear(renderer);

//         // Render the background image
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//         // Render the bird texture with or without glow based on the isGlowing flag
//         if (isGlowing) {
//             // Glow effect when the bird is clicked
//             SDL_SetTextureColorMod(birdTexture, 255, 255, 255);
//         } else {
//             SDL_SetTextureColorMod(birdTexture, 150, 150, 150);  // Normal color
//         }

//         // Render the bird texture
//         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

//         // Add any additional rendering or logic here

//         SDL_RenderPresent(renderer);
//     }

//     // Destroy the bird texture when done
//     SDL_DestroyTexture(birdTexture);

// }






// void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit) {
//     // Load the bird texture
//     SDL_Surface* birdSurface = IMG_Load("bird.png");
//     if (birdSurface == nullptr) {
//         printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
//     SDL_FreeSurface(birdSurface);

//     if (birdTexture == nullptr) {
//         printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     // Set the initial position and size of the bird
//     SDL_Rect birdRect = { 130, 700, 100, 100 };  // Adjust the position and size as needed

//     // Flag to track if the bird is glowing
//     bool isGlowing = false;

//     // Flag to track if the bird is being dragged
//     bool isDragging = false;

//     // Initial position of the bird when dragging starts
//     int dragStartX = 0;
//     int dragStartY = 0;

//     // Flag to track if the bird has reached the bottom of the window
//     bool isBirdAtBottom = false;

//     // Main game loop for the play window
//     SDL_Event playWindowEvent;
//     while (!quit) {
//         while (SDL_PollEvent(&playWindowEvent) != 0) {
//             if (playWindowEvent.type == SDL_QUIT) {
//                 quit = true;
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONDOWN) {
//                 int mouseX, mouseY;
//                 SDL_GetMouseState(&mouseX, &mouseY);

//                 // Check if the mouse click is on the bird
//                 if (mouseX >= birdRect.x && mouseX <= (birdRect.x + birdRect.w) &&
//                     mouseY >= birdRect.y && mouseY <= (birdRect.y + birdRect.h)) {
//                     isGlowing = true;  // Start glowing when clicked
//                     isDragging = true;  // Start dragging
//                     dragStartX = mouseX - birdRect.x;
//                     dragStartY = mouseY - birdRect.y;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEMOTION) {
//                 if (isDragging) {
//                     // Update the bird's position while dragging
//                     int mouseX, mouseY;
//                     SDL_GetMouseState(&mouseX, &mouseY);
//                     birdRect.x = mouseX - dragStartX;
//                     birdRect.y = mouseY - dragStartY;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONUP) {
//                 if (isDragging) {
//                     // Stop glowing and dragging when the mouse button is released
//                     isGlowing = false;
//                     isDragging = false;

//                     // Calculate launch velocity based on the drag distance and direction
//                     int dragEndX = playWindowEvent.button.x;
//                     int dragEndY = playWindowEvent.button.y;
//                     int dragDistanceX = dragEndX - (birdRect.x + birdRect.w / 2);
//                     int dragDistanceY = dragEndY - (birdRect.y + birdRect.h / 2);

//                     // Adjust the launch speed factor as needed
//                     double launchSpeedFactor = 0.1;

//                     // Calculate launch velocity components
//                     double launchVelocityX = launchSpeedFactor * dragDistanceX;
//                     double launchVelocityY = launchSpeedFactor * dragDistanceY;

//                     // Main loop for bird's projectile motion
//                     while (birdRect.y < SCREEN_HEIGHT) {
//                         // Update the bird's position based on launch velocity
//                         birdRect.x += static_cast<int>(launchVelocityX);
//                         birdRect.y += static_cast<int>(launchVelocityY);

//                         // If the bird has reached the bottom of the window, stop updating its position
//                         if (birdRect.y + birdRect.h >= SCREEN_HEIGHT) {
//                             isBirdAtBottom = true;
//                             break;
//                         }

//                         // Update the renderer
//                         SDL_RenderClear(renderer);
//                         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
//                         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);
//                         SDL_RenderPresent(renderer);

//                         // Introduce a small delay to control the frame rate
//                         SDL_Delay(5);
//                     }
//                 }
//             }
//         }

//         SDL_RenderClear(renderer);

//         // Render the background image
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//         // Render the bird texture with or without glow based on the isGlowing flag
//         if (isGlowing) {
//             // Glow effect when the bird is clicked
//             SDL_SetTextureColorMod(birdTexture, 255, 255, 255);
//         } else {
//             SDL_SetTextureColorMod(birdTexture, 150, 150, 150);  // Normal color
//         }

//         // Render the bird texture
//         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

//         // Add any additional rendering or logic here

//         SDL_RenderPresent(renderer);

//         // If the bird has reached the bottom of the window, break out of the loop
//         if (isBirdAtBottom) {
//             break;
//         }
//     }

//     // Destroy the bird texture when done
//     SDL_DestroyTexture(birdTexture);
// }














////////////##################################################















// void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit) {
//     // Load the bird texture
//     SDL_Surface* birdSurface = IMG_Load("bird.png");
//     if (birdSurface == nullptr) {
//         printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
//     SDL_FreeSurface(birdSurface);

//     if (birdTexture == nullptr) {
//         printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     // Set the initial position and size of the bird
//     SDL_Rect birdRect = { 130, 700, 100, 100 };  // Adjust the position and size as needed

//     // Flag to track if the bird is glowing
//     bool isGlowing = false;

//     // Flag to track if the bird is being dragged
//     bool isDragging = false;

//     // Initial position of the bird when dragging starts
//     int dragStartX = 0;
//     int dragStartY = 0;

//     // Flag to track if the bird is at the bottom of the window
//     bool isBirdAtBottom = false;

//     // Main game loop for the play window
//     SDL_Event playWindowEvent;
//     while (!quit) {
//         while (SDL_PollEvent(&playWindowEvent) != 0) {
//             if (playWindowEvent.type == SDL_QUIT) {
//                 quit = true;
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONDOWN) {
//                 int mouseX, mouseY;
//                 SDL_GetMouseState(&mouseX, &mouseY);

//                 // Check if the mouse click is on the bird
//                 if (mouseX >= birdRect.x && mouseX <= (birdRect.x + birdRect.w) &&
//                     mouseY >= birdRect.y && mouseY <= (birdRect.y + birdRect.h)) {
//                     isGlowing = true;  // Start glowing when clicked
//                     isDragging = true;  // Start dragging
//                     dragStartX = mouseX - birdRect.x;
//                     dragStartY = mouseY - birdRect.y;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEMOTION) {
//                 if (isDragging) {
//                     // Update the bird's position while dragging
//                     int mouseX, mouseY;
//                     SDL_GetMouseState(&mouseX, &mouseY);
//                     birdRect.x = mouseX - dragStartX;
//                     birdRect.y = mouseY - dragStartY;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONUP) {
//                 if (isDragging) {
//                     // Stop glowing and dragging when the mouse button is released
//                     isGlowing = false;
//                     isDragging = false;

//                     // Calculate launch velocity based on the drag distance and direction
//                     int dragEndX = playWindowEvent.button.x;
//                     int dragEndY = playWindowEvent.button.y;
//                     int dragDistanceX = dragEndX - (birdRect.x + birdRect.w / 2);
//                     int dragDistanceY = dragEndY - (birdRect.y + birdRect.h / 2);

//                     // Adjust the launch speed factor as needed
//                     double launchSpeedFactor = 0.1;

//                     // Calculate launch velocity components
//                     double launchVelocityX = launchSpeedFactor * dragDistanceX;
//                     double launchVelocityY = launchSpeedFactor * dragDistanceY;

//                     // Main loop for bird's projectile motion
//                     while (birdRect.y < SCREEN_HEIGHT) {
//                         // Update the bird's position based on launch velocity
//                         birdRect.x += static_cast<int>(launchVelocityX);
//                         birdRect.y += static_cast<int>(launchVelocityY);

//                         // If the bird has reached the bottom of the window, stop updating its position
//                         if (birdRect.y + birdRect.h >= SCREEN_HEIGHT) {
//                             isBirdAtBottom = true;
//                             break;
//                         }

//                         // Restrict the bird's movement within the left and right boundaries
//                         if (birdRect.x < 0) {
//                             birdRect.x = 0;
//                         } else if (birdRect.x + birdRect.w > SCREEN_WIDTH) {
//                             birdRect.x = SCREEN_WIDTH - birdRect.w;
//                         }

//                         // Update the renderer
//                         SDL_RenderClear(renderer);
//                         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
//                         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);
//                         SDL_RenderPresent(renderer);

//                         // Introduce a small delay to control the frame rate
//                         SDL_Delay(5);
//                     }
//                 }
//             }
//         }

//         SDL_RenderClear(renderer);

//         // Render the background image
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//         // Render the bird texture with or without glow based on the isGlowing flag
//         if (isGlowing) {
//             // Glow effect when the bird is clicked
//             SDL_SetTextureColorMod(birdTexture, 255, 255, 255);
//         } else {
//             SDL_SetTextureColorMod(birdTexture, 150, 150, 150);  // Normal color
//         }

//         // Render the bird texture
//         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

//         // If the bird has reached the bottom of the window, break out of the loop
//         if (isBirdAtBottom) {
//             break;
//         }

//         // Add any additional rendering or logic here

//         SDL_RenderPresent(renderer);
//     }

//     // Destroy the bird texture when done
//     SDL_DestroyTexture(birdTexture);
// }














////////////////////////////////////////////////////////////////////////////////////
//this is the code for which the bird doesn't go out of the window







// void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit) {
//     // Load the bird texture
//     SDL_Surface* birdSurface = IMG_Load("bird.png");
//     if (birdSurface == nullptr) {
//         printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
//     SDL_FreeSurface(birdSurface);

//     if (birdTexture == nullptr) {
//         printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     // Set the initial position and size of the bird
//     SDL_Rect birdRect = { 130, 700, 100, 100 };  // Adjust the position and size as needed

//     // Flags to track bird's state
//     bool isGlowing = false;
//     bool isDragging = false;
//     bool isBirdAtBottom = false;  // Flag to track if the bird has reached the bottom

//     // Initial position of the bird when dragging starts
//     int dragStartX = 0;
//     int dragStartY = 0;

//     // Variables for launch velocity
//     double launchSpeedFactor = 0.1;
//     double launchVelocityX = 0.0;
//     double launchVelocityY = 0.0;

//     // Main game loop for the play window
//     SDL_Event playWindowEvent;
//     while (!quit) {
//         while (SDL_PollEvent(&playWindowEvent) != 0) {
//             if (playWindowEvent.type == SDL_QUIT) {
//                 quit = true;
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONDOWN) {
//                 int mouseX, mouseY;
//                 SDL_GetMouseState(&mouseX, &mouseY);

//                 // Check if the mouse click is on the bird
//                 if (mouseX >= birdRect.x && mouseX <= (birdRect.x + birdRect.w) &&
//                     mouseY >= birdRect.y && mouseY <= (birdRect.y + birdRect.h)) {
//                     isGlowing = true;  // Start glowing when clicked
//                     isDragging = true;  // Start dragging
//                     isBirdAtBottom = false;  // Reset flag
//                     dragStartX = mouseX - birdRect.x;
//                     dragStartY = mouseY - birdRect.y;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEMOTION) {
//                 if (isDragging) {
//                     // Update the bird's position while dragging
//                     int mouseX, mouseY;
//                     SDL_GetMouseState(&mouseX, &mouseY);
//                     birdRect.x = mouseX - dragStartX;
//                     birdRect.y = mouseY - dragStartY;

//                     // Restrict the bird's movement within the top boundary
//                     if (birdRect.y < 0) {
//                         birdRect.y = 0;
//                     }
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONUP) {
//                 if (isDragging) {
//                     // Stop glowing and dragging when the mouse button is released
//                     isGlowing = false;
//                     isDragging = false;

//                     // Calculate launch velocity based on the drag distance and direction
//                     int dragEndX = playWindowEvent.button.x;
//                     int dragEndY = playWindowEvent.button.y;
//                     int dragDistanceX = dragEndX - (birdRect.x + birdRect.w / 2);
//                     int dragDistanceY = dragEndY - (birdRect.y + birdRect.h / 2);

//                     // Calculate launch velocity components
//                     launchVelocityX = launchSpeedFactor * dragDistanceX;
//                     launchVelocityY = launchSpeedFactor * dragDistanceY;

//                     // Main loop for bird's projectile motion
//                     while (birdRect.y < SCREEN_HEIGHT) {
//                         // Update the bird's position based on launch velocity
//                         birdRect.x += static_cast<int>(launchVelocityX);
//                         birdRect.y += static_cast<int>(launchVelocityY);

//                         // If the bird has reached the bottom, set its position to the bottom boundary
//                         if (birdRect.y + birdRect.h >= SCREEN_HEIGHT) {
//                             birdRect.y = SCREEN_HEIGHT - birdRect.h;
//                             isBirdAtBottom = true;  // Set the flag
//                         }

//                         // If the bird has reached the top of the window, set its position to the top boundary
//                         if (birdRect.y < 0) {
//                             birdRect.y = 0;
//                         }

//                         // Restrict the bird's movement within the left and right boundaries
//                         if (birdRect.x < 0) {
//                             birdRect.x = 0;
//                         } else if (birdRect.x + birdRect.w > SCREEN_WIDTH) {
//                             birdRect.x = SCREEN_WIDTH - birdRect.w;
//                         }

//                         // Update the renderer
//                         SDL_RenderClear(renderer);
//                         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
//                         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);
//                         SDL_RenderPresent(renderer);

//                         // Introduce a small delay to control the frame rate
//                         SDL_Delay(5);
//                     }
//                 }
//             }
//         }


//         // Render the background image
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//         // Render the bird texture with or without glow based on the isGlowing flag
//         if (isGlowing) {
//             // Glow effect when the bird is clicked
//             SDL_SetTextureColorMod(birdTexture, 255, 255, 255);
//         } else {
//             SDL_SetTextureColorMod(birdTexture, 150, 150, 150);  // Normal color
//         }

//         // Render the bird texture
//         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

//         // If the bird has reached the bottom, render a message
//         if (isBirdAtBottom) {
//             // You can add additional rendering or logic here
//         }

//         // Add any additional rendering or logic here

//         SDL_RenderPresent(renderer);
//     }

//     // Destroy the bird texture when done
//     SDL_DestroyTexture(birdTexture);

// }














//################################




// void handleNewPage(SDL_Renderer* renderer, SDL_Texture* newPageTexture, SDL_Texture* playButtonTexture, SDL_Texture* optionButtonTexture, SDL_Rect playButtonRect, SDL_Rect optionButtonRect, bool& quit, State& currentState) {
//     SDL_Event newPageEvent;
//     while (SDL_PollEvent(&newPageEvent) != 0) {
//         if (newPageEvent.type == SDL_QUIT) {
//             quit = true;
//         } else if (newPageEvent.type == SDL_MOUSEBUTTONDOWN) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);

//             // Check if the mouse click is on the Play button
//             if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
//                 mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
//                 currentState = PLAY_WINDOW;
//             }

//             // Check if the mouse click is on the Option button
//             if (mouseX >= optionButtonRect.x && mouseX <= (optionButtonRect.x + optionButtonRect.w) &&
//                 mouseY >= optionButtonRect.y && mouseY <= (optionButtonRect.y + optionButtonRect.h)) {
//                 // Handle Option button click (you can set currentState accordingly)
//                 // Example: currentState = OPTION_MENU;
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, newPageTexture, NULL, NULL);

//     // Check if the mouse is over the Play button
//     int mouseX, mouseY;
//     SDL_GetMouseState(&mouseX, &mouseY);
//     if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
//         mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
//         // Glow effect when the cursor is over the Play button
//         SDL_SetTextureColorMod(playButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150); // Normal color
//     }

//     // Render the Play button
//     SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);

//     // Check if the mouse is over the Option button
//     if (mouseX >= optionButtonRect.x && mouseX <= (optionButtonRect.x + optionButtonRect.w) &&
//         mouseY >= optionButtonRect.y && mouseY <= (optionButtonRect.y + optionButtonRect.h)) {
//         // Glow effect when the cursor is over the Option button
//         SDL_SetTextureColorMod(optionButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(optionButtonTexture, 150, 150, 150); // Normal color
//     }

//     // Render the Option button
//     SDL_RenderCopy(renderer, optionButtonTexture, NULL, &optionButtonRect);

//     SDL_RenderPresent(renderer);
// }


// void handleNewPage(SDL_Renderer* renderer, SDL_Texture* newPageTexture, SDL_Texture* playButtonTexture, SDL_Texture* optionButtonTexture, SDL_Rect playButtonRect, SDL_Rect optionButtonRect, bool& quit, State& currentState) {
//     SDL_Event newPageEvent;
//     while (SDL_PollEvent(&newPageEvent) != 0) {
//         if (newPageEvent.type == SDL_QUIT) {
//             quit = true;
//         } else if (newPageEvent.type == SDL_MOUSEBUTTONDOWN) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);

//             if (mouseX >= PLAY_BUTTON_POS_X && mouseX <= (PLAY_BUTTON_POS_X + 400) &&
//                 mouseY >= PLAY_BUTTON_POS_Y && mouseY <= (PLAY_BUTTON_POS_Y + 300)) {
//                 currentState = PLAY_WINDOW;
//             } else if (mouseX >= OPTION_BUTTON_POS_X && mouseX <= (OPTION_BUTTON_POS_X + 400) &&
//                        mouseY >= OPTION_BUTTON_POS_Y && mouseY <= (OPTION_BUTTON_POS_Y + 300)) {
//                 // Handle option button click
//                 // You can add the functionality for the option button here
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, newPageTexture, NULL, NULL);

//     // Check if the mouse is over the play button
//     int mouseX, mouseY;
//     SDL_GetMouseState(&mouseX, &mouseY);

//     if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
//         mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
//         // Glow effect when the cursor is over the play button
//         SDL_SetTextureColorMod(playButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150); // Normal color
//     }

//     if (mouseX >= optionButtonRect.x && mouseX <= (optionButtonRect.x + optionButtonRect.w) &&
//         mouseY >= optionButtonRect.y && mouseY <= (optionButtonRect.y + optionButtonRect.h)) {
//         // Glow effect when the cursor is over the option button
//         SDL_SetTextureColorMod(optionButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(optionButtonTexture, 150, 150, 150); // Normal color
//     }

//     SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);
//     SDL_RenderCopy(renderer, optionButtonTexture, NULL, &optionButtonRect);
//     SDL_RenderPresent(renderer);
// }


// void handleNewPage(SDL_Renderer* renderer, SDL_Texture* newPageTexture, SDL_Texture* playButtonTexture, SDL_Texture* optionButtonTexture, SDL_Rect playButtonRect, SDL_Rect optionButtonRect, bool& quit, State& currentState) {
//     SDL_Event newPageEvent;
//     while (SDL_PollEvent(&newPageEvent) != 0) {
//         if (newPageEvent.type == SDL_QUIT) {
//             quit = true;
//         } else if (newPageEvent.type == SDL_MOUSEBUTTONDOWN) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);

//             if (mouseX >= PLAY_BUTTON_POS_X && mouseX <= (PLAY_BUTTON_POS_X + 400) &&
//                 mouseY >= PLAY_BUTTON_POS_Y && mouseY <= (PLAY_BUTTON_POS_Y + 300)) {
//                 currentState = PLAY_WINDOW;
//             } else if (mouseX >= OPTION_BUTTON_POS_X && mouseX <= (OPTION_BUTTON_POS_X + 400) &&
//                        mouseY >= OPTION_BUTTON_POS_Y && mouseY <= (OPTION_BUTTON_POS_Y + 300)) {
//                 // Handle option button click
//                 // You can add the functionality for the option button here
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, newPageTexture, NULL, NULL);

//     // Check if the mouse is over the play button
//     int mouseX, mouseY;
//     SDL_GetMouseState(&mouseX, &mouseY);

//     if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
//         mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
//         // Glow effect when the cursor is over the play button
//         SDL_SetTextureColorMod(playButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150); // Normal color
//     }

//     if (mouseX >= optionButtonRect.x && mouseX <= (optionButtonRect.x + optionButtonRect.w) &&
//         mouseY >= optionButtonRect.y && mouseY <= (optionButtonRect.y + optionButtonRect.h)) {
//         // Glow effect when the cursor is over the option button
//         SDL_SetTextureColorMod(optionButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(optionButtonTexture, 150, 150, 150); // Normal color
//     }

//     SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);
//     SDL_RenderCopy(renderer, optionButtonTexture, NULL, &optionButtonRect);
//     SDL_RenderPresent(renderer);
// }



// void handleNewPage(SDL_Renderer* renderer, SDL_Texture* newPageTexture, SDL_Texture* playButtonTexture, SDL_Texture* optionButtonTexture, SDL_Rect playButtonRect, SDL_Rect optionButtonRect, bool& quit, State& currentState) {
//     SDL_Event newPageEvent;
//     while (SDL_PollEvent(&newPageEvent) != 0) {
//         if (newPageEvent.type == SDL_QUIT) {
//             quit = true;
//         } else if (newPageEvent.type == SDL_MOUSEBUTTONDOWN) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);

//             if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
//                 mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
//                 currentState = PLAY_WINDOW;
//             } else if (mouseX >= optionButtonRect.x && mouseX <= (optionButtonRect.x + optionButtonRect.w) &&
//                        mouseY >= optionButtonRect.y && mouseY <= (optionButtonRect.y + optionButtonRect.h)) {
//                 // Handle option button click
//                 // You can add the functionality for the option button here
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, newPageTexture, NULL, NULL);

//     // Check if the mouse is over the play button
//     int mouseX, mouseY;
//     SDL_GetMouseState(&mouseX, &mouseY);

//     if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
//         mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
//         // Glow effect when the cursor is over the play button
//         SDL_SetTextureColorMod(playButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150); // Normal color
//     }

//     if (mouseX >= optionButtonRect.x && mouseX <= (optionButtonRect.x + optionButtonRect.w) &&
//         mouseY >= optionButtonRect.y && mouseY <= (optionButtonRect.y + optionButtonRect.h)) {
//         // Glow effect when the cursor is over the option button
//         SDL_SetTextureColorMod(optionButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(optionButtonTexture, 150, 150, 150); // Normal color
//     }

//     SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);
//     SDL_RenderCopy(renderer, optionButtonTexture, NULL, &optionButtonRect);
//     SDL_RenderPresent(renderer);
// }














/////////////////////////////////////









// void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit) {
//     // Load the bird texture
//     SDL_Surface* birdSurface = IMG_Load("bird.png");
//     if (birdSurface == nullptr) {
//         printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
//     SDL_FreeSurface(birdSurface);

//     if (birdTexture == nullptr) {
//         printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     // Set the initial position and size of the bird
//     SDL_Rect birdRect = { 130, 700, 100, 100 };  // Adjust the position and size as needed

//     // Flags to track bird's state
//     bool isGlowing = false;
//     bool isDragging = false;

//     // Initial position of the bird when dragging starts
//     int dragStartX = 0;
//     int dragStartY = 0;

//     // Variables for launch velocity
//     double launchSpeedFactor = 0.1;
//     double launchVelocityX = 0.0;
//     double launchVelocityY = 0.0;

//     // Main game loop for the play window
//     SDL_Event playWindowEvent;
//     while (!quit) {
//         while (SDL_PollEvent(&playWindowEvent) != 0) {
//             if (playWindowEvent.type == SDL_QUIT) {
//                 quit = true;
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONDOWN) {
//                 int mouseX, mouseY;
//                 SDL_GetMouseState(&mouseX, &mouseY);

//                 // Check if the mouse click is on the bird
//                 if (mouseX >= birdRect.x && mouseX <= (birdRect.x + birdRect.w) &&
//                     mouseY >= birdRect.y && mouseY <= (birdRect.y + birdRect.h)) {
//                     isGlowing = true;  // Start glowing when clicked
//                     isDragging = true;  // Start dragging
//                     dragStartX = mouseX - birdRect.x;
//                     dragStartY = mouseY - birdRect.y;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEMOTION) {
//                 if (isDragging) {
//                     // Update the bird's position while dragging
//                     int mouseX, mouseY;
//                     SDL_GetMouseState(&mouseX, &mouseY);
//                     birdRect.x = mouseX - dragStartX;
//                     birdRect.y = mouseY - dragStartY;

//                     // Restrict the bird's movement within the top boundary
//                     if (birdRect.y < 0) {
//                         birdRect.y = 0;
//                     }
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONUP) {
//                 if (isDragging) {
//                     // Stop glowing and dragging when the mouse button is released
//                     isGlowing = false;
//                     isDragging = false;

//                     // Calculate launch velocity based on the drag distance and direction
//                     int dragEndX = playWindowEvent.button.x;
//                     int dragEndY = playWindowEvent.button.y;
//                     int dragDistanceX = dragEndX - (birdRect.x + birdRect.w / 2);
//                     int dragDistanceY = dragEndY - (birdRect.y + birdRect.h / 2);

//                     // Calculate launch velocity components
//                     launchVelocityX = launchSpeedFactor * dragDistanceX;
//                     launchVelocityY = launchSpeedFactor * dragDistanceY;
//                 }
//             }
//         }

//         // Update the bird's position based on launch velocity
//         birdRect.x += static_cast<int>(launchVelocityX);
//         birdRect.y += static_cast<int>(launchVelocityY);

//         // If the bird has reached the top of the window, set its position to the top boundary
//         if (birdRect.y < 0) {
//             birdRect.y = 0;
//         }

//         // Render the background image
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//         // Render the bird texture with or without glow based on the isGlowing flag
//         if (isGlowing) {
//             // Glow effect when the bird is clicked
//             SDL_SetTextureColorMod(birdTexture, 255, 255, 255);
//         } else {
//             SDL_SetTextureColorMod(birdTexture, 150, 150, 150);  // Normal color
//         }

//         // Render the bird texture
//         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

//         // Add any additional rendering or logic here

//         SDL_RenderPresent(renderer);

//         // Introduce a small delay to control the frame rate
//         SDL_Delay(5);
//     }

//     // Destroy the bird texture when done
//     SDL_DestroyTexture(birdTexture);
// }


















////////////////////////////////////





// void handleMenu(SDL_Renderer* renderer, SDL_Texture* startButtonTexture, SDL_Rect startButtonRect, bool& quit, State& currentState) {
//     SDL_Event menuEvent;
//     while (SDL_PollEvent(&menuEvent) != 0) {
//         if (menuEvent.type == SDL_QUIT) {
//             quit = true;
//         } else if (menuEvent.type == SDL_MOUSEMOTION) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);
//             if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
//                 mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h)) {
//                 SDL_SetTextureColorMod(startButtonTexture, 255, 255, 255);
//             } else {
//                 SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
//             }
//         } else if (menuEvent.type == SDL_MOUSEBUTTONDOWN) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);
//             if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
//                 mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h)) {
//                 currentState = NEW_PAGE;
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_Surface* backgroundSurface = IMG_Load("background2.png");
//     SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
//     SDL_FreeSurface(backgroundSurface);
//     SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//     SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);
//     SDL_RenderPresent(renderer);

//     SDL_DestroyTexture(backgroundTexture);
// }





// void handleNewPage(SDL_Renderer* renderer, SDL_Texture* newPageTexture, SDL_Texture* playButtonTexture, SDL_Rect playButtonRect, SDL_Texture* settingButtonTexture, SDL_Rect settingButtonRect, bool& quit, State& currentState) {
//     SDL_Event newPageEvent;
//     while (SDL_PollEvent(&newPageEvent) != 0) {
//         if (newPageEvent.type == SDL_QUIT) {
//             quit = true;
//         } else if (newPageEvent.type == SDL_MOUSEBUTTONDOWN) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);

//             // Check if the mouse click is on the "Play" button
//             if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
//                 mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
//                 currentState = PLAY_WINDOW;
//             }

//             // Check if the mouse click is on the "Setting" button
//             if (mouseX >= settingButtonRect.x && mouseX <= (settingButtonRect.x + settingButtonRect.w) &&
//                 mouseY >= settingButtonRect.y && mouseY <= (settingButtonRect.y + settingButtonRect.h)) {
//                 // Add logic to handle the "Setting" button click (e.g., open a settings menu)
//                 // For now, you can print a message to the console.
//                 std::cout << "Setting button clicked!\n";
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, newPageTexture, NULL, NULL);

//     // Check if the mouse is over the "Play" button
//     int mouseX, mouseY;
//     SDL_GetMouseState(&mouseX, &mouseY);
//     if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
//         mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
//         // Glow effect when the cursor is over the "Play" button
//         SDL_SetTextureColorMod(playButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150); // Normal color
//     }

//     // Check if the mouse is over the "Setting" button
//     if (mouseX >= settingButtonRect.x && mouseX <= (settingButtonRect.x + settingButtonRect.w) &&
//         mouseY >= settingButtonRect.y && mouseY <= (settingButtonRect.y + settingButtonRect.h)) {
//         // Glow effect when the cursor is over the "Setting" button
//         SDL_SetTextureColorMod(settingButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(settingButtonTexture, 150, 150, 150); // Normal color
//     }

//     // Render the "Play" button texture
//     SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);

//     // Render the "Setting" button texture
//     SDL_RenderCopy(renderer, settingButtonTexture, NULL, &settingButtonRect);

//     SDL_RenderPresent(renderer);
// }






// void handlePlayWindow(SDL_Renderer *renderer, SDL_Texture *backgroundTexture, bool &quit)
// {

//     SDL_Surface *birdSurface = IMG_Load("bird.png");
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

//     SDL_Texture *slingshot_back = IMG_LoadTexture(renderer, "./slingshot_back.png");

//     if (slingshot_back == nullptr)
//     {
//         printf("Unable to create sling_shot back image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture *slingshot_front = IMG_LoadTexture(renderer, "./slingshot_front.png");

//     if (slingshot_back == nullptr)
//     {
//         printf("Unable to create sling_shot front image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Event e;

//     bool running = true, right = 0, down = 0, jump = 0, up = 0;
//     int Bird_length = 100;
//     double speed_x = 0.0, speed_y = 0.0, g = 0.01, vf = 0.0;
//     int X = 0, Y = 0, count = 0, Start_x = 200, Start_y = 495, count_of_collision_with_wall = 0;
//     SDL_Rect bird_rect = {Start_x, Start_y, Bird_length, Bird_length};
//     SDL_Rect slingshot_rect = {210, 515, 75, 3*64};

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

//                         if ((X - Bird_length/2) >= 0 && (X) <= (SCREEN_WIDTH/2))
//                         {
//                             bird_rect.x = X - Bird_length / 2;
//                         }
//                         if ((Y - Bird_length) >= 0 && (Y) <= (SCREEN_HEIGHT - 2.5 * Bird_length))
//                             bird_rect.y = Y - Bird_length / 2;
//                     }
//                 }
//             }
//             else if (e.type == SDL_MOUSEBUTTONUP)
//             {
//                 if (e.button.button == SDL_BUTTON_LEFT)
//                 {
//                     speed_x = (Start_x - bird_rect.x) / 50.0;
//                     speed_y = -(Start_y - bird_rect.y) / 50.0;
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

//             if (bird_rect.x >= (SCREEN_WIDTH) || (bird_rect.x + Bird_length + 100 <= 0))
//             {
//                 jump = 0;
//                 bird_rect.x = Start_x;
//                 bird_rect.y = Start_y;
//                 SDL_Delay(500);
//                 // speed_x = -speed_x;
//             }

//             bird_rect.y -= speed_y;
//             speed_y -= g;

//             if ((bird_rect.y >= (SCREEN_HEIGHT - 3 * Bird_length))) // (bird_rect.y <= 0)
//             {
//                 speed_y = -(speed_y);
//                 // printf("%lf\n", speed_y);
//                 speed_y--;
//                 speed_y -= 2.0 / 30.0;
//                 // printf("%lf\n", speed_y);
//             }
//         }
//         else
//             jump = 0;

//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
//         SDL_RenderCopy(renderer, slingshot_back, NULL, &slingshot_rect);
//         SDL_RenderCopy(renderer, birdTexture, NULL, &bird_rect);
//         SDL_RenderCopy(renderer, slingshot_front, NULL, &slingshot_rect);
//         SDL_RenderPresent(renderer);
//     }

//     // Destroy the bird texture when done

//     SDL_DestroyTexture(backgroundTexture);
//     SDL_DestroyTexture(birdTexture);

// }




// void handlePlayWindow(SDL_Renderer *renderer, SDL_Texture *backgroundTexture, bool &quit)
// {

//     SDL_Surface *birdSurface = IMG_Load("bird.png");
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

//     SDL_Texture *slingshot_back = IMG_LoadTexture(renderer, "./slingshot_back.png");

//     if (slingshot_back == nullptr)
//     {
//         printf("Unable to create sling_shot back image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture *slingshot_front = IMG_LoadTexture(renderer, "./slingshot_front.png");

//     if (slingshot_back == nullptr)
//     {
//         printf("Unable to create sling_shot front image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture *green_bird = IMG_LoadTexture(renderer, "./green_bird.png");

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





// void handleMenu(SDL_Renderer* renderer, SDL_Texture* startButtonTexture, SDL_Rect startButtonRect, bool& quit, State& currentState) {
//     SDL_Event menuEvent;
//     while (SDL_PollEvent(&menuEvent) != 0) {
//         if (menuEvent.type == SDL_QUIT) {
//             quit = true;
//         } else if (menuEvent.type == SDL_MOUSEMOTION) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);
//             if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
//                 mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h)) {
//                 SDL_SetTextureColorMod(startButtonTexture, 255, 255, 255);
//             } else {
//                 SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
//             }
//         } else if (menuEvent.type == SDL_MOUSEBUTTONDOWN) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);
//             if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
//                 mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h)) {
//                 currentState = NEW_PAGE;
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_Surface* backgroundSurface = IMG_Load("background2.png");
//     SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
//     SDL_FreeSurface(backgroundSurface);
//     SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//     SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);
//     SDL_RenderPresent(renderer);

//     SDL_DestroyTexture(backgroundTexture);
// }





// void handleNewPage(SDL_Renderer* renderer, SDL_Texture* newPageTexture, SDL_Texture* playButtonTexture, SDL_Rect playButtonRect, SDL_Texture* settingButtonTexture, SDL_Rect settingButtonRect, bool& quit, State& currentState) {
//     SDL_Event newPageEvent;
//     while (SDL_PollEvent(&newPageEvent) != 0) {
//         if (newPageEvent.type == SDL_QUIT) {
//             quit = true;
//         } else if (newPageEvent.type == SDL_MOUSEBUTTONDOWN) {
//             int mouseX, mouseY;
//             SDL_GetMouseState(&mouseX, &mouseY);

//             // Check if the mouse click is on the "Play" button
//             if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
//                 mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
//                 currentState = PLAY_WINDOW;
//             }

//             // Check if the mouse click is on the "Setting" button
//             if (mouseX >= settingButtonRect.x && mouseX <= (settingButtonRect.x + settingButtonRect.w) &&
//                 mouseY >= settingButtonRect.y && mouseY <= (settingButtonRect.y + settingButtonRect.h)) {
//                 // Add logic to handle the "Setting" button click (e.g., open a settings menu)
//                 // For now, you can print a message to the console.
//                 std::cout << "Setting button clicked!\n";
//             }
//         }
//     }

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, newPageTexture, NULL, NULL);

//     // Check if the mouse is over the "Play" button
//     int mouseX, mouseY;
//     SDL_GetMouseState(&mouseX, &mouseY);
//     if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
//         mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
//         // Glow effect when the cursor is over the "Play" button
//         SDL_SetTextureColorMod(playButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150); // Normal color
//     }

//     // Check if the mouse is over the "Setting" button
//     if (mouseX >= settingButtonRect.x && mouseX <= (settingButtonRect.x + settingButtonRect.w) &&
//         mouseY >= settingButtonRect.y && mouseY <= (settingButtonRect.y + settingButtonRect.h)) {
//         // Glow effect when the cursor is over the "Setting" button
//         SDL_SetTextureColorMod(settingButtonTexture, 255, 255, 255);
//     } else {
//         SDL_SetTextureColorMod(settingButtonTexture, 150, 150, 150); // Normal color
//     }

//     // Render the "Play" button texture
//     SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);

//     // Render the "Setting" button texture
//     SDL_RenderCopy(renderer, settingButtonTexture, NULL, &settingButtonRect);

//     SDL_RenderPresent(renderer);
// }






// void handlePlayWindow(SDL_Renderer *renderer, SDL_Texture *backgroundTexture, bool &quit)
// {

//     SDL_Surface *birdSurface = IMG_Load("bird.png");
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

//     SDL_Texture *slingshot_back = IMG_LoadTexture(renderer, "./slingshot_back.png");

//     if (slingshot_back == nullptr)
//     {
//         printf("Unable to create sling_shot back image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture *slingshot_front = IMG_LoadTexture(renderer, "./slingshot_front.png");

//     if (slingshot_back == nullptr)
//     {
//         printf("Unable to create sling_shot front image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Event e;

//     bool running = true, right = 0, down = 0, jump = 0, up = 0;
//     int Bird_length = 100;
//     double speed_x = 0.0, speed_y = 0.0, g = 0.01, vf = 0.0;
//     int X = 0, Y = 0, count = 0, Start_x = 200, Start_y = 495, count_of_collision_with_wall = 0;
//     SDL_Rect bird_rect = {Start_x, Start_y, Bird_length, Bird_length};
//     SDL_Rect slingshot_rect = {210, 515, 75, 3*64};

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

//                         if ((X - Bird_length/2) >= 0 && (X) <= (SCREEN_WIDTH/2))
//                         {
//                             bird_rect.x = X - Bird_length / 2;
//                         }
//                         if ((Y - Bird_length) >= 0 && (Y) <= (SCREEN_HEIGHT - 2.5 * Bird_length))
//                             bird_rect.y = Y - Bird_length / 2;
//                     }
//                 }
//             }
//             else if (e.type == SDL_MOUSEBUTTONUP)
//             {
//                 if (e.button.button == SDL_BUTTON_LEFT)
//                 {
//                     speed_x = (Start_x - bird_rect.x) / 50.0;
//                     speed_y = -(Start_y - bird_rect.y) / 50.0;
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

//             if (bird_rect.x >= (SCREEN_WIDTH) || (bird_rect.x + Bird_length + 100 <= 0))
//             {
//                 jump = 0;
//                 bird_rect.x = Start_x;
//                 bird_rect.y = Start_y;
//                 SDL_Delay(500);
//                 // speed_x = -speed_x;
//             }

//             bird_rect.y -= speed_y;
//             speed_y -= g;

//             if ((bird_rect.y >= (SCREEN_HEIGHT - 3 * Bird_length))) // (bird_rect.y <= 0)
//             {
//                 speed_y = -(speed_y);
//                 // printf("%lf\n", speed_y);
//                 speed_y--;
//                 speed_y -= 2.0 / 30.0;
//                 // printf("%lf\n", speed_y);
//             }
//         }
//         else
//             jump = 0;

//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
//         SDL_RenderCopy(renderer, slingshot_back, NULL, &slingshot_rect);
//         SDL_RenderCopy(renderer, birdTexture, NULL, &bird_rect);
//         SDL_RenderCopy(renderer, slingshot_front, NULL, &slingshot_rect);
//         SDL_RenderPresent(renderer);
//     }

//     // Destroy the bird texture when done

//     SDL_DestroyTexture(backgroundTexture);
//     SDL_DestroyTexture(birdTexture);

// }




// void handlePlayWindow(SDL_Renderer *renderer, SDL_Texture *backgroundTexture, bool &quit)
// {

//     SDL_Surface *birdSurface = IMG_Load("bird.png");
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

//     SDL_Texture *slingshot_back = IMG_LoadTexture(renderer, "./slingshot_back.png");

//     if (slingshot_back == nullptr)
//     {
//         printf("Unable to create sling_shot back image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture *slingshot_front = IMG_LoadTexture(renderer, "./slingshot_front.png");

//     if (slingshot_back == nullptr)
//     {
//         printf("Unable to create sling_shot front image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture *green_bird = IMG_LoadTexture(renderer, "./green_bird.png");

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
