#include"bullet.h"
Butter::Butter() {

}
Butter::Butter(float x, float y,Texture * butterTexture) 
	: GameObject(x,y, butterTexture,NULL){
	redObj = new RenderObject(this,false);
}
Butter::~Butter() {
	delete redObj;
}
bool Butter::move(float inputx, float inputy,int time) {
	float center_x = this->getCenter_x();
	float center_y = this->getCenter_y();
	if (!isMove) {
		float vector_x = inputx - center_x;
		float vector_y = inputy - center_y;
		//移动距离,向量模长
		float distance = sqrt(pow(vector_x, 2) + pow(vector_y, 2));
		//移动时间
		int moveUnitTime = time * 20;
		this->moveUnitTime = moveUnitTime;
		//移动速度
		float speed = distance / moveUnitTime;
		//单位向量
		float dx = vector_x / distance;
		float dy = vector_y / distance;

		nx = dx * speed;
		ny = dy * speed;
		isMove = true;
	}
	moveUnitTime -= 1;
	if (moveUnitTime == 0) {
		isMove = false;
	}
	else {
		this->updatePosition(center_x + nx, center_y + ny);
		this->update();
	}
	return true;
}