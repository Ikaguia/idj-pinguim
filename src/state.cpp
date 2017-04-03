#include <memory>

#include <state.hpp>
#include <game.hpp>
#include <inputManager.hpp>
#include <camera.hpp>
#include <alien.hpp>
#include <resources.hpp>

State::State():quitRequested{false},bg{Sprite("img/ocean.jpg")},tileSet{TileSet(64,64,"img/tileset.png")},tileMap{TileMap("map/tileMap.txt",&tileSet)}{
	loadAssets();
	objectArray.emplace_back(unique_ptr<GameObject>(new Alien(512,300,8)));
	Resources::clearImages();
}

State::~State(){
	objectArray.clear();
}

bool State::QuitRequested(){
	return quitRequested;
}

void State::loadAssets(){
	Resources::getImage("img/alien.png");
	Resources::getImage("img/minion.png");
}
void State::render(){
	bg.render(0,0);
	tileMap.renderLayer(0,Camera::pos.x,Camera::pos.y);
	for(const auto &i:objectArray)i->Render();
	tileMap.renderLayer(1,Camera::pos.x*2,Camera::pos.y*2);
}
void State::update(){
	Camera::Update(Game::getInstance().GetDeltaTime());
	if(INPUTMAN.QuitRequested() || INPUTMAN.KeyPress(ESCAPE_KEY))quitRequested=true;

	int i=0;
	while(i<objectArray.size()){
		objectArray[i]->Update(Game::getInstance().GetDeltaTime());
		if(objectArray[i]->IsDead())objectArray.erase(objectArray.begin() + i);
		else i++;
	}
}

void State::AddObject(GameObject* obj){
	objectArray.emplace_back(unique_ptr<GameObject>(obj));
}
