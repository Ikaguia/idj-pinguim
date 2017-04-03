#include <face.hpp>
#include <inputManager.hpp>
#include <camera.hpp>

Face::Face(float x,float y):sp{Sprite("img/penguinface.png")}{
	hitPoints=30;
	box.x=x-sp.getWidth()/2;
	box.y=y-sp.getHeight()/2;
	box.w=sp.getWidth();
	box.h=sp.getHeight();
}


void Face::Damage(int dmg){
	hitPoints-=dmg;
}


void Face::update(float time){
	if(INPUTMAN.MousePress(LEFT_MOUSE_BUTTON) && box.contains(INPUTMAN.GetMouseX()+Camera::pos.x,INPUTMAN.GetMouseY()+Camera::pos.y))Damage(rand() % 10 + 10);
}

void Face::render(){
	sp.render(box.x-Camera::pos.x,box.y-Camera::pos.y);
}

bool Face::isDead(){
	return (hitPoints<=0);
}

