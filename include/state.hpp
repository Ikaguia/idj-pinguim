#ifndef STATEHPP
#define STATEHPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <common.hpp>
#include <sprite.hpp>
#include <gameObject.hpp>
#include <tileSet.hpp>
#include <tileMap.hpp>


class State{
	Sprite bg;
	vector<unique_ptr<GameObject>> objectArray;

	bool quitRequested;

	void addObject(float mouseX,float mouseY);

	TileSet tileSet;
	TileMap tileMap;
public:

	State();
	~State();

	bool QuitRequested();

	void loadAssets();
	void update();
	void render();
};

#endif//STATEHPP