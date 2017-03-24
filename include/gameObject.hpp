#ifndef GAMEOBJECTHPP
#define GAMEOBJECTHPP

#include <common.hpp>
#include <geometry.hpp>

class GameObject{
public:
	Rect box;
	float rotation;

	GameObject();
	virtual ~GameObject(){}

	virtual void Update(float time)=0;
	virtual void Render()=0;
	virtual bool IsDead()=0;
};

#endif//GAMEOBJECTHPP