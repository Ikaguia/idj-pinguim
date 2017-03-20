#ifndef GAMEHPP
#define GAMEHPP

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

class State;

class Game{
	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;
	
public:
	Game(std::string title,int height,int width);
	~Game();

	void run();
	SDL_Renderer* getRenderer();
	State& getState();
	static Game& getInstance();
};

#include <state.hpp>

#endif//GAMEHPP