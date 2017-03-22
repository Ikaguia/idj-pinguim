#ifndef FACEHPP
#define FACEHPP

#include <common.hpp>
#include <gameObject.hpp>
#include <sprite.hpp>

class Face : public GameObject{
	int hitPoints;
	Sprite sp;
public:
	Face(float x,float y);
	virtual ~Face(){}

	void Damage(int dmg);

	void update(float time);
	void render();
	bool isDead();
};

#endif//FACEHPP
