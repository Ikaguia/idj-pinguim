#ifndef SPRITEHPP
#define SPRITEHPP

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>


class Sprite{
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;
public:
	Sprite();
	Sprite(std::string file);
	~Sprite();

	void open(std::string file);
	void setClip(int x,int y,int w,int h);
	void render(int x,int y);

	int getWidth();
	int getHeight();

	bool isOpen();
};



#include <game.hpp>

#endif//SPRITEHPP