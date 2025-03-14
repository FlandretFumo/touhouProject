#pragma once
#include"../../application/list/vao/vao.h"
#include<cmath>
class Enemy : public GameObject{
public:
	Enemy();
	Enemy(int life, float x, float y, Texture* enemyTexture);
	~Enemy();
	int getLife() { return life; };
	RenderObject* getRedObj() { return redObj; };
	void setLife(int life) { this->life = life; };
	int getlife() { return life; };
	int getMaxLife() { return maxLife; };
	Enemy* addMovePosition(float x, float y, int time);
	Enemy* clearPositionList();
	Enemy* run(int time);


private:
	bool move(float x, float y, int time);
	struct position
	{
		float x;
		float y;
		int tick;
	};
	int life;
	int maxLife;
	bool isMove = false;
	float nx;
	float ny;
	float movex;
	float movey;
	int moveUnitTime;
	RenderObject* redObj;
	std::vector<position*> movePositionList;
};