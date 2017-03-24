#ifndef BULLETHPP
#define BULLETHPP

#include <common.hpp>
#include <gameObject.hpp>
#include <geometry.hpp>
#include <sprite.hpp>

class Bullet : public GameObject{
	Sprite sp;
	Vec2 speed;
	float distLeft;
	float angle;
public:
	Bullet(float x,float y,float ang,float spd,float mD,string spr);

	void Update(float time);
	void Render();
	bool IsDead();
};

#endif//BULLETHPP