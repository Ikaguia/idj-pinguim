#include <face.hpp>

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

}

void Face::render(){
	sp.render(box.x,box.y);
}

bool Face::isDead(){
	return (hitPoints<=0);
}

