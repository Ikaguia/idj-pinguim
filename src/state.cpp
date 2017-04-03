#include <state.hpp>


State::State():quitRequested{false},bg{Sprite("img/ocean.jpg")}{
	loadAssets();
}

bool State::QuitRequested(){
	return quitRequested;
}

void State::loadAssets(){}
void State::render(){
	bg.render(0,0);
}
void State::update(){
	if(SDL_QuitRequested())quitRequested=true;
}
