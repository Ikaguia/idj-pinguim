#ifndef GAMEHPP
#define GAMEHPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class State;

class Game{
	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;
	
public:
	Game(std::string title,int width,int height);
	~Game();

	void run();
	SDL_Renderer* getRenderer();
	State& getState();
	static Game& getInstance();
};

#include <state.hpp>

#endif//GAMEHPP