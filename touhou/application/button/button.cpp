#include"button.h"
Button::Button() {}
Button::Button(std::vector<Button*> * buttonList) {
}

Button::Button(std::vector<Button*>* buttonList,float cencal_x, float cencal_y,Texture * texture) {
	if (texture!=nullptr) {
		vao = new RenderObject(new GameObject(cencal_x, cencal_y, texture, BUTTON));
		if (buttonList!=nullptr) {
			buttonList->push_back(this);
		}
	}
}
Button::~Button() {
	if (vao!=nullptr) {
		delete vao;
	}
}
Button* Button::setclick(std::function<void()> fun) {
	this->fun = fun;
	return this;
}
RenderObject* Button::getVAO() {
	return vao;
}
Button* Button::run(float windowsLocation_x,float windowsLocation_y) {
	if (fun!=nullptr) {
		float buttonLeftDownx = vao->getGameObj()->getCenter_x() - vao->getGameObj()->getWidth() / 2 * STD_PIX_SIZE;
		float buttonLeftDowny = vao->getGameObj()->getCenter_y() - vao->getGameObj()->getHeight() / 2 * STD_PIX_SIZE;

		float buttonRightUpx = vao->getGameObj()->getCenter_x() + vao->getGameObj()->getWidth() / 2 * STD_PIX_SIZE;
		float buttonRightUpy = vao->getGameObj()->getCenter_y() + vao->getGameObj()->getHeight() / 2 * STD_PIX_SIZE;

		if (windowsLocation_x > buttonLeftDownx && windowsLocation_x < buttonRightUpx) {
			if (windowsLocation_y > buttonLeftDowny && windowsLocation_y < buttonRightUpy) {
				fun();
			}
		}
	}
	return this;
}
