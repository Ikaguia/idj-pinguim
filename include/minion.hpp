#ifndef MINIONHPP
#define MINIONHPP

#include <common.hpp>
#include <gameObject.hpp>
#include <geometry.hpp>
#include <sprite.hpp>

class Minion : public GameObject{
	GameObject* center;
	Sprite sp;
	float arc;
public:
	Minion(GameObject* c,float arcOffset=0);

	void Update(float time);
	void Render();
	bool IsDead();
	void Shoot(Vec2 pos);
};

#endif//MINIONHPP