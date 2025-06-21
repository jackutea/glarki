#include "lib.h"

int AK_Lib_Run() {
    AKBindingFunctions();

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Could not initialize SDL: %s", SDL_GetError());
        return -1;
    }

    // Create a window
    SDL_Window *window =
        SDL_CreateWindow("SDL OpenGL Example", 800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Create an OpenGL context
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        SDL_Log("Could not create OpenGL context: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        SDL_Log("Failed to initialize GLAD");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Set the OpenGL viewport
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // Main loop
    AKColorByte color = {255, 0, 0, 255}; // Example color
    SDL_Event event;
    int running = 1;
    while (running) {

        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }

        // Clear the screen
        AKColorFloat colorFloat = AKColor_Func.ToFloat(color);
        glClearColor(colorFloat.r, colorFloat.g, colorFloat.b, colorFloat.a);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers
        SDL_GL_SwapWindow(window);
    }

    // Clean up
    SDL_GL_DestroyContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}