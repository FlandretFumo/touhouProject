#include"vbo.h"

GameObject::GameObject() {

}
GameObject::GameObject(float cencal_x,float cencal_y, int width, int height,int gemeObject) {
	isAlpah = false;
	mObject = gemeObject;
	mCenter_x = cencal_x;
	mCenter_y = cencal_y;
	mWidth = width;
	mHeight = height;
	glGenBuffers(1, &aVbo);
	glBindBuffer(GL_ARRAY_BUFFER, aVbo);
	if (!createPostion(cencal_x, cencal_y, mWidth, mHeight)) {
		glBufferData(GL_ARRAY_BUFFER, position.size()*sizeof(float), position.data(), GL_STATIC_DRAW);
	}

}
GameObject::GameObject(float cencal_x, float cencal_y, std::string path, int unit, int gemeObject) {
	isAlpah = false;

	mObject = gemeObject;
	mCenter_x = cencal_x;
	mCenter_y = cencal_y;
	mTexture = new Texture(path, unit);
	mWidth = mTexture->getHeight();
	mHeight = mTexture->getHeight();
	glGenBuffers(1, &aVbo);
	glBindBuffer(GL_ARRAY_BUFFER, aVbo);
	if (!createPostion(cencal_x, cencal_y, mWidth, mHeight)) {
		glBufferData(GL_ARRAY_BUFFER, position.size() * sizeof(float), position.data(), GL_STATIC_DRAW);
	}
}
GameObject::GameObject(float cencal_x, float cencal_y, Texture* texture, int gemeObject) {
	isAlpah = false;

	mObject = gemeObject;
	mCenter_x = cencal_x;
	mCenter_y = cencal_y;
	mTexture = texture;
	mWidth = mTexture->getWidth();
	mHeight = mTexture->getHeight();
	glGenBuffers(1, &aVbo);
	glBindBuffer(GL_ARRAY_BUFFER, aVbo);
	if (!createPostion(cencal_x, cencal_y, mWidth, mHeight)) {
		glBufferData(GL_ARRAY_BUFFER, position.size() * sizeof(float), position.data(), GL_STATIC_DRAW);
	}
}
GameObject::~GameObject() {
	glDeleteBuffers(1, &aVbo);
	position.clear();
	position.shrink_to_fit();
}
int GameObject::createPostion(float center_x, float center_y, int width, int height) {
	float widthSize = STD_PIX_SIZE;//每个像素大小
	float heightSize = STD_PIX_SIZE;//每个像素大小
	if (position.size() > 0) position.clear();
	position = {
		center_x + (width / 2) * widthSize,center_y + (height / 2) * heightSize,0.0,
		center_x - (width / 2) * widthSize,center_y + (height / 2) * heightSize,0.0,
		center_x + (width / 2) * widthSize,center_y - (height / 2) * heightSize,0.0,
		center_x - (width / 2) * widthSize,center_y - (height / 2) * heightSize,0.0
	};
	mLeftUpx = position[0];
	mLeftUpy = position[1];
	mRightUpx= position[3];
	mRightUpy= position[4];
	mLeftDownx= position[6];
	mLeftDowny= position[7];
	mRightDownx = position[9];
	mRightDowny = position[10];
	return 0; 
}
void GameObject::rotateAroundCenter(float angle) {
	float cos_theta = std::cos(angle);
	float sin_theta = std::sin(angle);

	for (size_t i = 0; i < position.size(); i += 3) {
		float original_x = position[i];
		float original_y = position[i + 1];

		// 计算相对于中心点的偏移量
		float offset_x = original_x - mCenter_x;
		float offset_y = original_y - mCenter_y;

		// 应用旋转矩阵
		float rotated_x = cos_theta * offset_x - sin_theta * offset_y;
		float rotated_y = sin_theta * offset_x + cos_theta * offset_y;

		// 平移回原来的中心位置
		position[i] = rotated_x + mCenter_x;
		position[i + 1] = rotated_y + mCenter_y;
	}
}
GLuint GameObject::getVao() {
	return aVbo;
}
void GameObject::update() {
	glBindBuffer(GL_ARRAY_BUFFER, aVbo);;
	glBufferSubData(GL_ARRAY_BUFFER, 0, position.size() * sizeof(float), position.data());
	if (position.size()>0) {
		position.clear();
		position.shrink_to_fit();
	}
}
void GameObject::updatePosition(float cencal_x, float cencal_y) {
	createPostion(cencal_x, cencal_y, mWidth, mHeight);
	mCenter_x = cencal_x;
	mCenter_y = cencal_y;
}
Texture* GameObject::getTexture() {
	return mTexture;
}
float GameObject::getCenter_x() {return mCenter_x;}
float GameObject::getCenter_y() {return mCenter_y;}
float GameObject::getAbsDrection() {
	return mAbsDrection;
}
int GameObject::getGameObject() {
	return mObject;
}
void GameObject::setAbsDirection(float drection) {
	mAbsDrection = drection;
}
void GameObject::setGameObject(int gameObject) {
	mObject = gameObject;
}
int GameObject::getWidth() {
	return mWidth;
}
void GameObject::loop(float center_x, float center_y, float directionDegrees,float distance) {
	float directionRadians = directionDegrees * M_PI / 180.0f;

	float x = std::sin(directionRadians)* distance;
	float y = std::cos(directionRadians)* distance;

	mCenter_x = center_x + x;
	mCenter_y = center_y + y;
	createPostion(mCenter_x, mCenter_y, mWidth, mHeight);
}
void GameObject::setWidth(float off) {
	//mCenter_x -= width * 0.01;
	createPostion(mCenter_x, mCenter_y, mWidth * off, mHeight);
}
const float STEP_SIZE = 0.01; // 每次移动的步长
void GameObject::setLife(int life) {
	mLife = life;
}
void GameObject::setMaxLife(int life) {
	mMAXlife = life;
}
int GameObject::getMaxLife(){
	return mMAXlife;
}

int GameObject::getLife() {
	return mLife;
}
void GameObject::setVector_x(float vector_y) {
	mVector_x = vector_y;
}
void GameObject::setVector_y(float vector_y) {
	 mVector_y = vector_y;
}
float GameObject::getVector_x() {
	return mVector_x;
}
float GameObject::getVector_y() {
	return mVector_y;
}
void GameObject::moveToLocation(float target_x, float target_y) {
	
	float dx = target_x - mCenter_x;
	float dy = target_y - mCenter_y;
	float distance = sqrt(dx * dx + dy * dy);

	// 如果距离已经很近，则停止移动
	if (distance < STEP_SIZE) {
		mCenter_x = target_x;
		mCenter_y = target_y;
		return;
	}

	// 计算单位向量
	float nx = dx / distance;
	float ny = dy / distance;

	// 沿着单位向量方向移动一步
	mCenter_x += nx * STEP_SIZE;
	mCenter_y += ny * STEP_SIZE;

}
int GameObject::getHeight() {
	return mHeight;
}
void GameObject::getGameObject(int gameObject) {
	mObject = gameObject;
}

void GameObject::setAlpah(float alpha) {
	isAlpah = true;
	this->alpha = alpha;
}
float GameObject::getAlpah() {
	if(alpha<=1.0) alpha += 0.01;
	return alpha;
}
bool GameObject::getIsAlpah() {
	return isAlpah;
}
// 获取左上角顶点的 x 坐标
float GameObject::getLeftUpx(){
	return mLeftUpx;
}
// 获取左上角顶点的 y 坐标
float GameObject::getLeftUpy(){
	return mLeftUpy;
}
// 获取右上角顶点的 x 坐标
float GameObject::getRightUpx(){
	return mRightUpx;
}
// 获取右上角顶点的 y 坐标
float GameObject::getRightUpy(){
	return mRightUpy;
}
// 获取左下角顶点的 x 坐标
float GameObject::getLeftDownx() {
	return mLeftDownx;
}
// 获取左下角顶点的 y 坐标
float GameObject::getLeftDowny(){
	return mLeftDowny;
}
// 获取右下角顶点的 x 坐标
float GameObject::getRightDownx(){
	return mRightDownx;
}
// 获取右下角顶点的 y 坐标
float GameObject::getRightDowny(){
	return mRightDowny;
}