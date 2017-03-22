#ifndef RESOURCESHPP
#define RESOURCESHPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <unordered_map>

#include <common.hpp>

class Resources{
	static std::unordered_map<string,SDL_Texture*> imageTable;
public:
	static SDL_Texture* getImage(string file);
	static void clearImages();
};

#endif//RESOURCESHPP