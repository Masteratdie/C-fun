#include <SDL.h>
#include <iostream>

using namespace std;

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("New Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Surface* screen = SDL_GetWindowSurface(window);

	bool running = true;

	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit;

	return 0;
}



//A class to create windows, not really useful for my use case but just as an example

// class createWindow {
// public:
// 	createWindow(const char* title, int width, int height) {
// 		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
// 	}

// 	void killWindow() {
// 		SDL_DestroyWindow(window);
// 	}
// private:
// 	SDL_Window* window;
// 	SDL_Surface* screen = SDL_GetWindowSurface(window);

// };