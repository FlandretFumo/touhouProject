#pragma once
#include<cmath>
#include"golb.h"
#include"../../application/media/threadManager.h"
#include"../../application/media/MediaManager.h"
#include"../../application/Texture/texture.h"
#include"../../application/Texture/textTexture.h"
#include"../../application/shader/shader.h"
#include"../../application/list/vao/vao.h"
#include"../../application/button/button.h"




struct objectStruct
{
	GameObject* gameObject;
	GameObject* loopObject;
	Texture* texture;
	RenderObject* vao;
	bool comtext;
	bool loop;
	float du = -1;
	float default_du;
};

void createEnemyBullet(float x, float y, GameObject* emitter, Texture* texture);
void createEnemyBullet(std::vector<objectStruct*> enemyCreature, GameObject* emitter, Texture* texture);

bool compleDistance(float distance, float center_x, float center_y, float comple_x, float comple_y);
