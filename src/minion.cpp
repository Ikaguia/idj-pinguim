#include <minion.hpp>
#include <camera.hpp>
#include <game.hpp>
#include <state.hpp>
#include <bullet.hpp>
#include <alien.hpp>
#include <animation.hpp>

#define DIST 150
#define ANGSPEED 45.0f //45 graus

Minion::Minion(GameObject* c,float arcOffset):center{c},sp{"../resources/img/minion.png"},arc{arcOffset}{
	float r=(10+rand()%5)/10.0f;
	sp.SetScaleX(r);
	sp.SetScaleY(r);
	Vec2 v(center->box.x+(center->box.w/2),center->box.y+(center->box.h/2));
	v += Vec2(DIST,0).rotate(arc);
	box.x=v.x-sp.GetWidth()/2;
	box.y=v.y-sp.GetHeight()/2;
	box.w=sp.GetWidth();
	box.h=sp.GetHeight();
}

Minion::~Minion(){}

void Minion::Update(float time){
	Vec2 v(center->box.x+(center->box.w/2),center->box.y+(center->box.h/2));
	v += (Vec2(DIST,0).rotate(arc+(ANGSPEED*time)));
	arc+=(ANGSPEED*time);
	box.x=v.x-sp.GetWidth()/2;
	box.y=v.y-sp.GetHeight()/2;
}

void Minion::Render(){
	sp.render(box.x-Camera::pos.x,box.y-Camera::pos.y,90.0f+arc);
}
bool Minion::IsDead(){
	return false;
}
void Minion::Shoot(Vec2 pos){
	Vec2 c=box.center();
	GAMESTATE.AddObject(new Bullet(c.x,c.y,c.angle(pos),500,1500,"../resources/img/minionbullet2.png",3,1.0f,this));
}


void Minion::NotifyCollision(GameObject& other){
	// if(other.Is("Bullet")){
	// 	Bullet* b=(Bullet*)&other;
	// 	if(this != b->owner){
	// 		if(!b->IsDead())b->NotifyCollision(*this);//tell the bullet to destroy itself and call this again
	// 		else ((Alien*)center)->Damage(10+rand()%10);//dmg the alien
	// 	}
	// }
}
bool Minion::Is(string type){
	return (type=="Minion");
}
