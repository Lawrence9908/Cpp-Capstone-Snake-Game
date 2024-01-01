// renderer.h
#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "food.h"

class Renderer {
public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height,
             const std::size_t grid_width, const std::size_t grid_height);
    ~Renderer();
  
    void Render(Snake const snake, Food &food);
    void UpdateWindowTitle(int score, double fps);
    bool IsInitialized() const;
    void LogSDLError(const std::string &msg) const;
    SDL_Window *GetSDLWindow() const;
    SDL_Renderer *GetSDLRenderer() const;

private:
    bool sdl_initialized;
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width;
    const std::size_t grid_height;
    // Add a function to set color based on FoodPhase
    void SetFoodColor(Food &food) const;
};

#endif
