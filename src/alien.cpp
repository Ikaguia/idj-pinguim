#include <alien.hpp>
#include <inputManager.hpp>
#include <camera.hpp>


Alien::Action::Action(ActionType t,float x,float y):pos{Vec2(x,y)},type{t}{}


Alien::Alien(float x,float y,int nMinions):sp{Sprite("../resources/img/alien.png")}{
	hp=30;
	box.x=x-sp.getWidth()/2;
	box.y=y-sp.getHeight()/2;
	box.w=sp.getWidth();
	box.h=sp.getHeight();
	float ang=360.0f/nMinions;
	FOR(i,nMinions)minionArray.push_back(Minion(this,ang*i));
}
Alien::~Alien(){}


#define SPEED 200.0f * time

void Alien::Update(float time){
	rotation-=(10.0f*time);
	if(INPUTMAN.MousePress(LEFT_MOUSE_BUTTON))taskQueue.push(Action(Action::ActionType::SHOOT,INPUTMAN.GetMouseX()+Camera::pos.x,INPUTMAN.GetMouseY()+Camera::pos.y));
	if(INPUTMAN.MousePress(RIGHT_MOUSE_BUTTON))taskQueue.push(Action(Action::ActionType::MOVE,INPUTMAN.GetMouseX()+Camera::pos.x-sp.getWidth()/2,INPUTMAN.GetMouseY()+Camera::pos.y-sp.getHeight()/2));
	if(taskQueue.size()){
		auto i=taskQueue.front();
		if(i.type==Action::ActionType::MOVE){
			Vec2 movePos=i.pos;
			Vec2 pos(box.x,box.y);
			if((movePos-pos).len()<SPEED){
				box.x=i.pos.x;
				box.y=i.pos.y;
				taskQueue.pop();
			}
			else{
				movePos=(movePos-pos).unit();
				movePos*=SPEED;
				box.x+=movePos.x;
				box.y+=movePos.y;
			}
		}
		else if(i.type==Action::ActionType::SHOOT){
			int closest=0;
			float min=i.pos.dist(minionArray[0].box.center());
			FOR2(it,1,minionArray.size()){
				float dist=i.pos.dist(minionArray[it].box.center());
				if(dist<min){
					closest=it;
					min=dist;
				}
			}
			minionArray[closest].Shoot(i.pos);
			taskQueue.pop();
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
