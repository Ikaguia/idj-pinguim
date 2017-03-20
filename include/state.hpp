#ifndef STATEHPP
#define STATEHPP

#include <SDL.h>
#include <SDL_image.h>
#include <sprite.hpp>


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