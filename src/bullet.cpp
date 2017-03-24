#include <bullet.hpp>
#include <camera.hpp>

Bullet::Bullet(float x,float y,float ang,float spd,float mD,string spr):sp{Sprite(spr)},distLeft{mD},angle{ang}{
	box.x=x-sp.getWidth()/2;
	box.y=y-sp.getHeight()/2;
	box.w=sp.getWidth();
	box.h=sp.getHeight();
	speed = Vec2(spd,0).rotate(angle);
}

void Bullet::Update(float time){
	box+=(speed*time);
	distLeft-=(speed*time).len();
}

void Bullet::Render(){
	sp.render(box.x-Camera::pos.x,box.y-Camera::pos.y,angle);
}

bool Bullet::IsDead(){
	return distLeft<=0;
}
