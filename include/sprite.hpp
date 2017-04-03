#ifndef SPRITEHPP
#define SPRITEHPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <common.hpp>


class Sprite{
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;
public:
	Sprite();
	Sprite(string file);
	~Sprite();

	void open(string file);
	void setClip(int x,int y,int w,int h);
	void render(int x,int y);

	int getWidth();
	int getHeight();

	bool isOpen();
};

#endif//SPRITEHPP