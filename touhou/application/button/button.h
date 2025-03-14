#pragma once
#include"../list/vao/vao.h"
#include<functional>
#define BUTTON 325423
class Button : public GameObject {
public:
	Button();
	Button(std::vector<Button*> * buttonList);
	Button(std::vector<Button*>* buttonList,float cencal_x, float cencal_y, Texture* texture);
	~Button();
	Button* setclick(std::function<void()> fun);
	Button* run(float windowsLocation_x, float windowsLocation_y);
	RenderObject* getVAO();
private:
	std::function<void()> fun = nullptr;
	RenderObject* vao;
};

