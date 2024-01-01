#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height),
      sdl_initialized(SDL_Init(SDL_INIT_VIDEO) == 0) {
    if (!sdl_initialized) {
        LogSDLError("SDL could not initialize.");
        return;
    }

    // Create Window
    sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, screen_width,
                                  screen_height, SDL_WINDOW_SHOWN);

    if (sdl_window == nullptr) {
        LogSDLError("Window could not be created.");
        return;
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (sdl_renderer == nullptr) {
        LogSDLError("Renderer could not be created.");
        return;
    }
}

Renderer::~Renderer() {
    if (sdl_initialized) {
        SDL_DestroyWindow(sdl_window);
        SDL_Quit();
    }
}

void Renderer::Render(Snake const snake, Food &food) {
    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render food
    SetFoodColor(food);
    block.x = food.x * block.w;
    block.y = food.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);

    // Render snake's body
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (SDL_Point const &point : snake.body) {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    block.x = static_cast<int>(snake.head_x) * block.w;
    block.y = static_cast<int>(snake.head_y) * block.h;
    if (snake.alive) {
        SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
    } else {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    SDL_RenderFillRect(sdl_renderer, &block);

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, double fps) {
    std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(static_cast<int>(fps))};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::SetFoodColor(Food &food) const {
    switch (food.getCurrentFood()) {
        case FoodPhase::Fresh:
            SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF); // Fresh color
            break;
        case FoodPhase::Rotten:
            SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF); // Rotten color
            break;
        case FoodPhase::Special:
            SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0xFF, 0x00, 0xFF); // Special color
            break;
    }
}

bool Renderer::IsInitialized() const {
    return sdl_initialized && sdl_window != nullptr && sdl_renderer != nullptr;
}

void Renderer::LogSDLError(const std::string &msg) const {
    std::cerr << msg << " SDL_Error: " << SDL_GetError() << "\n";
}

SDL_Window *Renderer::GetSDLWindow() const {
    return sdl_window;
}

SDL_Renderer *Renderer::GetSDLRenderer() const {
    return sdl_renderer;
}
