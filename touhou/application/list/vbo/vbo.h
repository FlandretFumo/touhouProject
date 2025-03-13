#pragma once
#include"../../golb.h"
#include"../../texture/texture.h"
#include <cmath>
#include <vector>
class GameObject {
public:
	GameObject();
	GameObject(float cencal_x, float cencal_y, int width, int height, int gemeObject);
	GameObject(float cencal_x, float cencal_y,std::string path,int unit, int gemeObject);
	GameObject(float cencal_x, float cencal_y, Texture*, int gemeObject);
	~GameObject();
	void moveToLocation(float x, float y);
	Texture* getTexture();
	void update();
	void updatePosition(float cencal_x, float cencal_y);
	GLuint getVao();
	int getWidth();
	int getHeight();
	void setWidth(float off);
	float getCenter_x();
	float getCenter_y();
	float getAbsDrection();
	int getGameObject();
	void setAbsDirection(float drection);
	void setGameObject(int gameObject);
	void getGameObject(int gameObject);
	void rotateAroundCenter(float angle);
	void setVector_x(float K);
	void setVector_y(float B);
	void setLife(int life);
	void setMaxLife(int life);
	void setAlpah(float alpha);
	float getAlpah();
	bool getIsAlpah();
	int getMaxLife();
	int getLife();
	void loop(float center_x,float center_y,float du,float);
	float getVector_x();
	float getVector_y();
	float getLeftUpx();
	float getLeftUpy();
	float getRightUpx();
	float getRightUpy();
	float getLeftDownx();
	float getLeftDowny();
	float getRightDownx();
	float getRightDowny();
private:
	int createPostion(float cencal_x, float cencal_y, int width, int height);

	float mLeftUpx;
	float mLeftUpy;
	float mRightUpx;
	float mRightUpy;
	float mLeftDownx;
	float mLeftDowny;
	float mRightDownx;
	float mRightDowny;
	int mObject{ 0 };
	GLuint aVbo{ 0 };
	std::vector<float> position{ 0 };
	GLuint veo{ 0 };
	Texture* mTexture{ 0 };
	int mWidth{ 0 };
	int mHeight{ 0 };
	float mCenter_x{ 0 };
	float mCenter_y{ 0 };
	int size{ 0 };
	int mAbsDrection{ 0 };
	int mOppoDrection{ 0 };
	float mVector_x;
	float mVector_y;
	int mLife{ 0 };
	int mMAXlife{ 0 };
	float  alpha = 1.0f;
	bool  isAlpah = false;

};