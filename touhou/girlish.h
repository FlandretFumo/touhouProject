#pragma once

#include"golb.h"
#include"../../application/media/threadManager.h"
#include"../../application/media/MediaManager.h"
#include"../../application/Texture/texture.h"
#include"../../application/Texture/textTexture.h"
#include"../../application/shader/shader.h"
#include"../../application/list/vao/vao.h"
class Girlishclass {
public:
	Girlishclass();
	Girlishclass* addCard(int Time, int loopTime, 
		int ShootTime, int boosLife,int createShortVelue,
		Texture* cardNameTexture, Texture* boosTexture,
		std::vector<Texture*> bulletTextureList
		);
	Girlishclass* releaseBoosList();
private:
	struct cade {
		int Time;
		int loopTime;
		int ShootTime;
		int boosLife;
		int createShortVelue;
		Texture* cardNameTexture;
		Texture* boosTexture;
		std::vector<Texture*> bulletTextureList;
	};
	std::vector<cade*> boosList;
};