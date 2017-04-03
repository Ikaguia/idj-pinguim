#ifndef ALIENHPP
#define ALIENHPP

#include <common.hpp>
#include <gameObject.hpp>
#include <geometry.hpp>
#include <sprite.hpp>
#include <minion.hpp>
#include <timer.hpp>

class Alien : public GameObject{
	Sprite sp;
	Vec2 speed;
	int hp;
	vector<Minion> minionArray;

	enum alienState{MOVING,RESTING};
	alienState state;
	Timer restTimer;
	Vec2 destination;
public:
	static int count;

	Alien(float x,float y,int nMinions);
	~Alien();

	void Update(float time);
	void Render();
	bool IsDead();
	void Damage(int dmg);

	virtual void NotifyCollision(GameObject& other);
	virtual bool Is(string type);
};

#endif//ALIENHPP