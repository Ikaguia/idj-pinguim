#ifndef STATEHPP
#define STATEHPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <sprite.hpp>
#include <gameObject.hpp>
#include <face.hpp>
#include <vector>
#include <memory>


class State{
	Sprite bg;
	bool quitRequested;
	std::vector<std::unique_ptr<GameObject>> objectArray;

	void input();
	void addObject(float mouseX,float mouseY);
public:
	State();
	~State();

	bool QuitRequested();

	void loadAssets();
	void update();
	void render();
};

#endif//STATEHPP