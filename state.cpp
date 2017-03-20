#include <state.hpp>


State::State():quitRequested{false}{}

bool State::QuitRequested(){
	return quitRequested;
}

void State::loadAssets(){}
void State::render(){}
void State::update(){
	if(SDL_QuitRequested())quitRequested=true;
}
