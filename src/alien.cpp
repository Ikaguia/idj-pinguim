#include <alien.hpp>
#include <inputManager.hpp>
#include <camera.hpp>
#include <bullet.hpp>
#include <game.hpp>
#include <state.hpp>
#include <animation.hpp>
#include <pinguims.hpp>

#define REST_COOLDOWN 2.0f
#define MOVE_SPEED 200.0f * time

int Alien::count=0;

Alien::Alien(float x,float y,int nMinions):sp{Sprite("../resources/img/alien.png")},state{alienState::RESTING}{
	count++;

	hp=30;
	box.x=x-sp.GetWidth()/2;
	box.y=y-sp.GetHeight()/2;
	box.w=sp.GetWidth();
	box.h=sp.GetHeight();
	float ang=360.0f/nMinions;
	minionArray.reserve(nMinions);
	FOR(i,nMinions){
		minionArray.emplace_back(this,ang*i);
	}
}
Alien::~Alien(){
	count--;

	minionArray.clear();
}



void Alien::Update(float time){
	rotation-=(10.0f*time);
	if(Pinguims::player){
		if(state==alienState::RESTING){
			restTimer.Update(time);
			if(restTimer.Get()>REST_COOLDOWN){
				destination=Pinguims::player->box.center();
				speed=((destination-box.center()).unit())*MOVE_SPEED;
				state=alienState::MOVING;
			}
		}
		else{//alienState::MOVING
			if(box.center().dist(destination)<=MOVE_SPEED){
				box.x=destination.x-(box.w/2);
				box.y=destination.y-(box.h/2);
				//shoot
				{
					int closest=0;
					Vec2 dest = Pinguims::player->box.center();
					float min=dest.dist(minionArray[0].box.center());
					FOR2(it,1,minionArray.size()){
						float dist=dest.dist(minionArray[it].box.center());
						if(dist<min){
							closest=it;
							min=dist;
						}
					}
					minionArray[closest].Shoot(dest);
				}
				state=alienState::RESTING;
				restTimer.Restart();
			}
			else box+=speed;
		}
	}
	for(auto &i:minionArray)i.Update(time);
}
void Alien::Render(){
	sp.render(box.x-Camera::pos.x,box.y-Camera::pos.y,rotation);
	for(auto &i:minionArray)i.Render();
}
bool Alien::IsDead(){
	return (hp<=0);
}
void Alien::Damage(int dmg){
	hp-=dmg;
	if(IsDead()){
		GAMESTATE.AddObject(new Animation(box.x,box.y,rotation,"../resources/img/aliendeath.png",4,0.25f,true));
		for(auto &i:minionArray){
			GAMESTATE.AddObject(new Animation(i.box.x,i.box.y,i.rotation,"../resources/img/miniondeath.png",4,0.25f,true));
		}
	}
}

void Alien::NotifyCollision(GameObject& other){
	if(other.Is("Bullet")){
		Bullet* b=(Bullet*)&other;
		if((this != b->owner) && !(b->owner->Is("Minion"))){
			if(!b->IsDead())b->NotifyCollision(*this);//tell the bullet to destroy itself and call this again
			else Damage(10+rand()%10);//dmg the alien
		}
	}
}
bool Alien::Is(string type){
	return (type=="Alien");
}
