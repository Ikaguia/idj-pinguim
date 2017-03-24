#include <minion.hpp>
#include <camera.hpp>
#include <game.hpp>
#include <state.hpp>
#include <bullet.hpp>

#define DIST 150
#define ANGSPEED 45.0f //45 graus

Minion::Minion(GameObject* c,float arcOffset):center{c},sp{"../resources/img/minion.png"},arc{arcOffset}{
	float r=(10+rand()%5)/10.0f;
	sp.SetScaleX(r);
	sp.SetScaleY(r);
	Vec2 v(center->box.x+(center->box.w/2),center->box.y+(center->box.h/2));
	v += Vec2(DIST,0).rotate(arc);
	box.x=v.x-sp.getWidth()/2;
	box.y=v.y-sp.getHeight()/2;
	box.w=sp.getWidth();
	box.h=sp.getHeight();
}

void Minion::Update(float time){
	Vec2 v(center->box.x+(center->box.w/2),center->box.y+(center->box.h/2));
	v += (Vec2(DIST,0).rotate(arc+(ANGSPEED*time)));
	arc+=(ANGSPEED*time);
	box.x=v.x-sp.getWidth()/2;
	box.y=v.y-sp.getHeight()/2;
}

void Minion::Render(){
	sp.render(box.x-Camera::pos.x,box.y-Camera::pos.y,90.0f+arc);
}
bool Minion::IsDead(){
	return false;
}
void Minion::Shoot(Vec2 pos){
	Vec2 c=box.center();
	Game::getInstance().getState().AddObject(new Bullet(c.x,c.y,c.angle(pos),500,2000,"../resources/img/minionbullet1.png"));
}
