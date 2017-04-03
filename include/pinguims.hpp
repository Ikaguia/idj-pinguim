#ifndef PINGUIMSHPP
#define PINGUIMSHPP

#include <common.hpp>
#include <gameObject.hpp>
#include <sprite.hpp>
#include <geometry.hpp>
#include <timer.hpp>

class Pinguims : public GameObject{
	Sprite bodySp;
	Sprite canonSp;
	Vec2 speed;
	float linearSpeed;
	float canonAngle;
	int hp;
	Timer t;
public:
	static Pinguims* player;

	Pinguims(float x,float y);
	~Pinguims();

	void Update(float time);
	void Render();
	bool IsDead();

	void Shoot();
	void Damage(int dmg=15);

	virtual void NotifyCollision(GameObject& other);
	virtual bool Is(string type);
};

#endif//PINGUIMSHPP