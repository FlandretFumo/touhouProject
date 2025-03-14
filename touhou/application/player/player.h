#pragma once
#include"../../application/list/vao/vao.h"
#ifndef PLAYER_H
#define PLAYER_H
#define LIFE 5
class Player : public GameObject {
public:
	Player();
	Player(int life, float x, float y, Texture* playerTexture);
	~Player();
	RenderObject* getRenderObject() { return redObj; };
	int getLife() { return life; };
	void setLife(int life) { if(life>=0)this->life = life; }
	bool getOP() { return isOp; }
	void setOP(bool op) { isOp = op; }
private:
	bool isOp;

	int life;
	RenderObject* redObj = nullptr;
};
#endif // !PLAYER_H
