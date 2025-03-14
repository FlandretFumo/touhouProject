#include"player.h"
Player::Player() {

}
Player::Player(int life, float x, float y, Texture* playerTexture)
	: GameObject(x,y,playerTexture,NULL){
	this->life = life;
	redObj = new RenderObject(this,false);
}

Player::~Player() {
	delete redObj;
}