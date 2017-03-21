#ifndef STATEHPP
#define STATEHPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <sprite.hpp>
#include <vector>
#include <memory>


class State{
	Sprite bg;
	bool quitRequested;

public:
	State();

	bool QuitRequested();

	void loadAssets();
	void update();
	void render();
};

#endif//STATEHPP