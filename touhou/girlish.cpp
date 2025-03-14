#include"girlish.h"
Girlishclass::Girlishclass() {

}
Girlishclass* Girlishclass::addCard(int Time, int loopTime,
	int ShootTime, int boosLife, int createShortVelue,
	Texture* cardNameTexture, Texture* boosTexture,
	std::vector<Texture*> bulletTextureList) {
	cade* c = new cade{Time,loopTime,ShootTime,boosLife,createShortVelue,cardNameTexture ,boosTexture ,bulletTextureList };
	return this;
}

Girlishclass* Girlishclass::releaseBoosList() {
	for (int i = 0; i < boosList.size(); i++) {
		delete boosList.at(i)->cardNameTexture;
		delete boosList.at(i)->boosTexture;
		for (int j = 0; j < boosList.at(i)->bulletTextureList.size(); j++) {
			delete boosList.at(i)->bulletTextureList.at(j);
		}
		delete boosList.at(i);
	}
	return this;
}