#ifndef ALIENHPP
#define ALIENHPP

#include <common.hpp>
#include <gameObject.hpp>
#include <geometry.hpp>
#include <sprite.hpp>
#include <minion.hpp>

class Alien : public GameObject{
	class Action{
	public:
		enum ActionType{MOVE,SHOOT};
		ActionType type;
		Vec2 pos;
		Action(ActionType t,float x,float y);
	};
	Sprite sp;
	Vec2 speed;
	int hp;
	queue<Action> taskQueue;
	vector<Minion> minionArray;
public:
	Alien(float x,float y,int nMinions);
	~Alien();

	void Update(float time);
	void Render();
	bool IsDead();
};

#endif//ALIENHPP