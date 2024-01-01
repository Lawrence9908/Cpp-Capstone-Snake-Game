#include "food.h"
#include <iostream>
#include <chrono>

Food::Food() {
    _currentPhase = FoodPhase::Fresh;
    _isGameRunning = true;
    t = std::thread(&Food::cycleThroughPhases, this);
}

Food::~Food() {
    t.join();
}

void Food::cycleThroughPhases() {
    int cycle_duration = 5000;
    auto last_time = std::chrono::high_resolution_clock::now();

    while (_isGameRunning) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        auto current_time = std::chrono::high_resolution_clock::now();
        auto time_diff = current_time - last_time;

        if (std::chrono::duration_cast<std::chrono::milliseconds>(time_diff).count() > cycle_duration) {
            std::unique_lock<std::mutex> uLock(_mutex);
            // Toggle food phase among available phases
            switch (_currentPhase) {
                case FoodPhase::Fresh:
                    _currentPhase = FoodPhase::Rotten;
                    break;
                case FoodPhase::Rotten:
                    _currentPhase = FoodPhase::Special;
                    break;
                case FoodPhase::Special:
                    _currentPhase = FoodPhase::Fresh;
                    break;
            }

            uLock.unlock();
            last_time = std::chrono::high_resolution_clock::now();
        }
    }
}

FoodPhase Food::getCurrentFood() {
    std::lock_guard<std::mutex> uLock(_mutex);
    return _currentPhase;
}

void Food::setGameRunning(bool running) {
    _isGameRunning = running;
}