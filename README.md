# CPPND: Capstone Snake Game Example
<img src="snake_game.gif"/>

This project represents an extended and refined version of the Snake Game, incorporating principles gleaned from my Nanodegree Program. One significant enhancement is the introduction of a dedicated food class, which now operates in three distinct phases: fresh, rotten, and special. A concurrent thread expertly manages the toggling of these phases based on predefined time intervals, contributing to a more dynamic gaming experience.

Integral to the project is the revamped scoring system, intricately tied to the food's phase. The current score increments by 1 for fresh food, decreases by 1 for rotten food, and surges by 5 for special food. Meanwhile, the game's escalating challenge is underscored by the consistent acceleration of the snake's speed and size, heightening the difficulty for players.

Aesthetic enhancements are apparent in the renderer, which dynamically adjusts the color of the food to reflect its phase: yellow for fresh, green for special, and red for rotten.

The repository showcases an evolved Snake Game codebase, meticulously refined for improved readability, maintainability, and adherence to best coding practices. Key modifications include the use of initialization lists for member variable setup, the explicit keyword addition to single-argument constructors, eliminating implicit type conversions. The codebase is further streamlined by cleaning up unnecessary header inclusions. The critical PlaceFood function has been refactored, significantly improving readability and mitigating potential infinite loops.

Moreover, the FoodPhase enum has been upgraded to an enum class, offering better scoping and type safety. An explicit constructor has been introduced to fortify code robustness. These enhancements collectively result in a more organized and efficient codebase, fostering an environment where understanding, maintenance, and contributions to the Snake Game project are streamlined and accessible.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Addressed Rubric Points

All required rubric points are met specifications. The other rubric points that I addressed:

### Loops, Functions, I/O
Criteria | Explanation
--- | ---
The project demonstrates an understanding of C++ functions and control structures. | There are variety of control structures and functions I added in files [food.cpp](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.cpp), [game.cpp](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/game.cpp), [renderer.cpp](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/renderer.cpp).

### Object Oriented Programming
Criteria | Explanation
--- | ---
The project uses Object Oriented Programming techniques. | The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks in files [food.cpp](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.cpp), [food.h](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.h).
Classes use appropriate access specifiers for class members. | All class data members are explicitly specified as public, protected, or private in [food.h](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.h).
Classes encapsulate behavior. | Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions such as [getCurrentPhase](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.h#L18) and [setGameRunning](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.h#L19)
Classes follow an appropriate inheritance hierarchy. | [Food class](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.h#L13) inherited from SDL_Point to keep its previous functionality.

### Concurrency
Criteria | Explanation
--- | ---
The project uses multithreading. | The project uses multiple threads in the execution. [cycleThroughPhases](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.h#L27) function starts on another thread in the [constructor of Food class](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.cpp#L11).
A mutex or lock is used in the project. | A [mutex](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.h#L28), [lock_guard](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.cpp#L53) and [unique_lock](https://github.com/korhanmd/cppnd-capstone-project/blob/main/src/food.cpp#L37) are used to protect data that is shared across multiple threads in the project code.

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
