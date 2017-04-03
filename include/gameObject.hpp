#ifndef GAMEOBJECTHPP
#define GAMEOBJECTHPP

#include <geometry.hpp>

class GameObject{
public:
	Rect box;

	virtual ~GameObject(){}

	virtual void update(float time)=0;
	virtual void render()=0;
	virtual bool isDead()=0;
};

#endif//GAMEOBJECTHPP