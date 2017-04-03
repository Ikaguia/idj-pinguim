#include <state.hpp>
#include <game.hpp>
#include <face.hpp>
#include <inputManager.hpp>
#include <camera.hpp>


State::State():quitRequested{false},bg{Sprite("img/ocean.jpg")},tileSet{TileSet(64,64,"img/tileset.png")},tileMap{TileMap("map/tileMap.txt",&tileSet)}{
	loadAssets();
}

State::~State(){
	objectArray.clear();
}

void State::addObject(float mouseX,float mouseY){
	Vec2 v(200,0);
	int ri=rand()%36000;
	float rf=ri/100.0f;
	v = v.rotate(rf);
	objectArray.emplace_back(unique_ptr<GameObject>(new Face(v.x+mouseX,v.y+mouseY)));
}

bool State::QuitRequested(){
	return quitRequested;
}

void State::loadAssets(){}
void State::render(){
	bg.render(0,0);
	tileMap.renderLayer(0,Camera::pos.x,Camera::pos.y);
	for(const auto &i:objectArray)i->render();
	tileMap.renderLayer(1,Camera::pos.x*2,Camera::pos.y*2);
}
void State::update(){
	Camera::Update(Game::getInstance().GetDeltaTime());
	if(INPUTMAN.QuitRequested() || INPUTMAN.KeyPress(ESCAPE_KEY))quitRequested=true;
	if(INPUTMAN.IsKeyDown(SPACEBAR_KEY))addObject(INPUTMAN.GetMouseX()+Camera::pos.x,INPUTMAN.GetMouseY()+Camera::pos.y);

	int i=0;
	while(i<objectArray.size()){
		objectArray[i]->update(Game::getInstance().GetDeltaTime());
		if(objectArray[i]->isDead())objectArray.erase(objectArray.begin() + i);
		else i++;
	}
}
