#pragma once
#include"../list/vao/vao.h"
class Butter : public GameObject {
public:
	Butter();
	Butter(float x, float y, Texture * butterTexture);
	~Butter();
	
private:
	bool move(float center_x, float center_y, int time);
	RenderObject* redObj;
	bool isMove = false;
	int moveUnitTime;
	int nx;
	int ny;
};