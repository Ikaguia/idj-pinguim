#include <pinguims.hpp>
#include <inputManager.hpp>
#include <camera.hpp>
#include <game.hpp>
#include <state.hpp>
#include <bullet.hpp>
#include <animation.hpp>

Pinguims* Pinguims::player=nullptr;

#define ACEL (75.0f)
#define MAXSDP (350.0f)
#define MINSPD (-25.0f)
#define ANGSPD (95.0f)
#define SHOOT_COOLDOWN (0.25f)

Pinguims::Pinguims(float x,float y):bodySp{"../resources/img/penguin.png"},canonSp{"../resources/img/cubngun.png"},speed{Vec2(1,0)},linearSpeed{0.0f},canonAngle{0.0f},hp{30}{
	box.x=x-bodySp.GetWidth()/2;
	box.y=y-bodySp.GetHeight()/2;
	box.w=bodySp.GetWidth();
	box.h=bodySp.GetHeight();
	player=this;
}
Pinguims::~Pinguims(){
	player=nullptr;
	Camera::Unfollow();
}

void Pinguims::Update(float time){
	t.Update(time);
	box+=(speed*linearSpeed*time);
	Vec2 mouse(INPUTMAN.GetMouseX()+Camera::pos.x,INPUTMAN.GetMouseY()+Camera::pos.y);
	canonAngle=(mouse-box.center()).angle();
	if(INPUTMAN.IsKeyDown(W_KEY) && !INPUTMAN.IsKeyDown(S_KEY))linearSpeed=std::min(linearSpeed+(ACEL*time),MAXSDP);
	if(INPUTMAN.IsKeyDown(S_KEY) && !INPUTMAN.IsKeyDown(W_KEY))linearSpeed=std::max(linearSpeed-(ACEL*time),MINSPD);
	if(INPUTMAN.IsKeyDown(D_KEY) && !INPUTMAN.IsKeyDown(A_KEY)){
		rotation+=(ANGSPD*time);
		speed=speed.unit().rotate((ANGSPD*time));
	}
	if(INPUTMAN.IsKeyDown(A_KEY) && !INPUTMAN.IsKeyDown(D_KEY)){
		rotation-=(ANGSPD*time);
		speed=speed.unit().rotate(-(ANGSPD*time));
	}
	if(INPUTMAN.MousePress(RIGHT_MOUSE_BUTTON))linearSpeed=0.0f;
	if(INPUTMAN.MousePress(LEFT_MOUSE_BUTTON))Shoot();
}
void Pinguims::Render(){
	bodySp.render(box.x-Camera::pos.x,box.y-Camera::pos.y,rotation);
	canonSp.render(box.x-Camera::pos.x-(canonSp.GetWidth()-bodySp.GetWidth()),box.y-Camera::pos.y+(bodySp.GetHeight()-canonSp.GetHeight()),canonAngle);
}
bool Pinguims::IsDead(){
	return hp<=0;
}

void Pinguims::Shoot(){
	if(t.Get()>=SHOOT_COOLDOWN){
		Vec2 c = box.center()+(Vec2(box.w/2,0).rotate(canonAngle));
		GAMESTATE.AddObject(new Bullet(c.x,c.y,canonAngle,500,750,"../resources/img/penguinbullet.png",4,0.375,this));
		t.Restart();
	}
}

void Pinguims::Damage(int dmg){
	hp-=dmg;
	if(IsDead())GAMESTATE.AddObject(new Animation(box.x,box.y,rotation,"../resources/img/penguindeath.png",5,0.2f,true));
}


void Pinguims::NotifyCollision(GameObject& other){
	if(other.Is("Bullet")){
		Bullet* b=(Bullet*)&other;
		if(this != b->owner){
			if(!b->IsDead())b->NotifyCollision(*this);//tell the bullet to destroy itself and call this again
			else Damage(10+rand()%10);//dmg the penguim
		}
	}
}
bool Pinguims::Is(string type){
	return (type=="Pinguims");
}
