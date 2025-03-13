
#include"game.h"

#include"girlish.h"
#include<chrono>
#include<thread>
#define NUMBER_HEIGHT 3.15
#define NUMBER_HEIGHT_S 2.3
#define SKILL_HEIGHT 0.15
#define LIFE_HEIGHT 1.35
#define NUMBER_WIDTH 2.3
struct numberStruct
{
	char c;
	Texture* numberText;
};





std::vector<numberStruct> number;
GLuint posGameObject, colorGameObject, uvGameObject, vao;
Texture* startButtonTexture;
Texture* titleText;
Texture* exitButton;
TextTexture* titleTextSrc;
//============着色器========开始
Shader* blackWhiteShader;//背景着色器
Shader* blenderShader;//混合着色器
Shader* textShader;//文本着色器


//============着色器========结束




//按键颜色
std::atomic<int> atomic_key_color = -1;
//标题背景
RenderObject* titleBackgroundVAO;//vao
Texture* titlebackgroundTexture;//背景贴图
//标题文字
RenderObject* titleVAO;//vao
Texture* titleTexture_S;//背景贴图
//开始选项
RenderObject* startVAO;//vao
Texture* startTexturBlack;//背景贴图
Texture* startTexturWhite;
//选项
RenderObject * settingsVAO;
Texture* settingsTextureBlack;
Texture* settingsTextureWhite;
//退出
RenderObject* quitGameVAO;//vao
Texture* quitGameTexturWhite;
Texture* quitGameTexturBlack;//背景贴图
//游戏
RenderObject* gameBackgroundVAO;//vao
Texture* gameBarTexture;//背景贴图
//玩家
 GameObject* playerGameObject;//GameObject
RenderObject* playerVAO;//vao
Texture* playerTexture;//背景贴图
//游戏对象
GameObject* playerBulletGameObject;
RenderObject* playerBulletVAO;//vao
Texture* playerBulletTexture;//背景贴图
//



glm::mat4 transform(1.0f);
glm::mat4 viewMatrix(1.0f);
glm::mat4 orthoMatrix(1.0f);


//玩家弹幕
std::vector<objectStruct*> playerBullet;
//敌方弹幕
std::vector<objectStruct*> enemyBullet;
//各位少女们
std::vector<objectStruct*> enemyCreature;
//P点列表
std::vector<objectStruct*> Ppopint;
//H点列表
std::vector<objectStruct*> Hpoint;
//Touhou点
std::vector<objectStruct*> touhouPoint;
//生命列表
std::vector<RenderObject*> lifeList;
//技能点列表
std::vector<RenderObject*> skillList;
//符卡弹幕材质
Texture* cardTextureDreamSumPorint;
Texture* cardTextureDreamSum;
Texture* cardTextureDreamMoonPorint;
Texture* cardTextureDreamMoon;
Texture* enemyTexture;


std::vector<Texture*> numberTexture;
std::vector<RenderObject*> numberVAOs;
std::vector<Texture*> numberList;


//计分板
GameObject* numberGameObject0;
RenderObject* numberVAO0;
GameObject* numberGameObject1;
RenderObject* numberVAO1;
GameObject* numberGameObject2;
RenderObject* numberVAO2;
GameObject* numberGameObject3;
RenderObject* numberVAO3;
GameObject* numberGameObject4;
RenderObject* numberVAO4;
GameObject* numberGameObject5;
RenderObject* numberVAO5;
GameObject* numberGameObject6;
RenderObject* numberVAO6;
GameObject* numberGameObject7;
RenderObject* numberVAO7;
GameObject* numberGameObject8;
RenderObject* numberVAO8;
GameObject* numberGameObject9;
RenderObject* numberVAO9;
//计分板2
std::vector<RenderObject*> numberVAOs1;
std::vector<Texture*> numberList1;
GameObject* numberGameObject00;
RenderObject* numberVAO_0;
GameObject* numberGameObject01;
RenderObject* numberVAO01;
GameObject* numberGameObject02;
RenderObject* numberVAO02;
GameObject* numberGameObject03;
RenderObject* numberVAO03;
GameObject* numberGameObject04;
RenderObject* numberVAO04;
GameObject* numberGameObject05;
RenderObject* numberVAO05;
GameObject* numberGameObject06;
RenderObject* numberVAO06;
GameObject* numberGameObject07;
RenderObject* numberVAO07;
GameObject* numberGameObject08;
RenderObject* numberVAO08;
GameObject* numberGameObject09;
RenderObject* numberVAO09;

Texture* numberTexture0;
Texture* numberTexture1;
Texture* numberTexture2;
Texture* numberTexture3;
Texture* numberTexture4;
Texture* numberTexture5;
Texture* numberTexture6;
Texture* numberTexture7;
Texture* numberTexture8;
Texture* numberTexture9;

std::vector<RenderObject*> timeNumberList;
std::vector<Texture*> timeNumberTexture;
GameObject* timeNumberGameObject;
RenderObject* timeNumberVAO;
GameObject* timeNumberGameObject1;
RenderObject* timeNumberVAO1;

Texture* lifeTexture;
GameObject* lifeVAO;
RenderObject* lifeGameObject;
GameObject* lifeVAO1;
RenderObject* lifeGameObject1;
GameObject* lifeVAO2;
RenderObject* lifeGameObject2;
GameObject* lifeVAO3;
RenderObject* lifeGameObject3;
GameObject* lifeVAO4;
RenderObject* lifeGameObject4;

Texture * skillTexture;
GameObject* skillVAO;
RenderObject* skillGameObject;
GameObject* skillVAO1;
RenderObject* skillGameObject1;
GameObject* skillVAO2;
RenderObject* skillGameObject2;

Texture* bossLifeTexture;
GameObject* lifeLine;
RenderObject * bossLifeVAO;

std::vector< Texture*> levelNumberList;
GameObject* levelLine;
RenderObject* levelVAO;


//设置界面材质===================开始================================
//设置文字材质
Texture* settingTextTexture;
//设置音量文字
Texture * settingVolumeTexture;
Texture* settingVolumeTexture_black;

//设置文字VAO和GameObject
GameObject * settingTextGameObject;
RenderObject * settingTextVAO;
//设置音量VAO和GameObject
GameObject * settingVolumeTextGameObject;
RenderObject * settingVolumeTextVAO;

RenderObject* settingQuitTextVAO;

std::vector<Texture*> volumeList;
std::vector<RenderObject*> VolumeNumberVAO;

//设置界面材质====================结束===============================

//游戏中断材质===================开始================================
Texture* gameWaitBackgroundTexture;
Texture* gameKeepTextTexture;
Texture* gameKeepTextTextureBlack;
Texture* gameQuitTextTexture;
Texture* gameQuitTextTextureBlack;

Texture* playerDeadTextTextureBlack;



RenderObject* gameWaitBackgroundVAO;
RenderObject* gameKeepTextVAO;
RenderObject* gameQuitTextVAO;

RenderObject* playerdeadTextVAO;
//游戏中断材质===================结束================================
bool isClick = false;
bool clickKey = -1;
std::vector<Button*> buttonList;
float windowsLocation_x;
float windowsLocation_y;
int keySelect = 0;
bool run = true;
std::vector<Button*> button;
Button* b = new Button(&button);

void click(bool Click,int key) {
	isClick = Click;
	clickKey = key;
	if (getClick()) {
		for (auto b : button) {
			b->run(windowsLocation_x, windowsLocation_y);
		}
	}
}
bool getClick() {
	return isClick;
}
void mouseClick(int x,int y) {
	float width_edge = WIDTH / 2 * STD_PIX_SIZE;
	float height_edge = HEIGHT / 2 * STD_PIX_SIZE;

	float NDC_up = height_edge;
	float NDC_down = -height_edge;
	float NDC_right = width_edge;
	float NDC_left = -width_edge;

	float windowWidth = WIDTH * STD_PIX_SIZE;
	float windowHeight = HEIGHT * STD_PIX_SIZE;

	if (x< WIDTH/2) {
		windowsLocation_x = NDC_left + x * STD_PIX_SIZE;
	}
	else {
		windowsLocation_x =  NDC_right - (windowWidth - x * STD_PIX_SIZE);
	}

	if (y < HEIGHT / 2) {
		windowsLocation_y = -(NDC_down + y * STD_PIX_SIZE);
	}
	else {
		windowsLocation_y = -(NDC_up - (windowHeight - y * STD_PIX_SIZE));
	}
    



}

//角色或关卡选择界面材质
Texture * basicTexture1_white;
Texture* basicTexture1_black;
RenderObject * roleVAO1;

Texture* ordinaryTexture2_white;
Texture* ordinaryTexture2_black;
RenderObject* roleVAO2;

Texture* difficultyTexture3_white;
Texture* difficultyTexture3_black;
RenderObject* roleVAO3;

Texture* scourgeTexture4_white;
Texture* scourgeTexture4_black;
RenderObject* roleVAO4;




//媒体
MediaPlay* keyMedia;
//MediaPlay* boosShortMedia;
MediaPlay* backgroundMedia;
MediaPlay* gameMedia;

Texture* cardNameTexture;
GameObject* cardName;
RenderObject* cardNameVAO;

int activite = TITLE;

//boss房间
int room = 0;
//玩家生命
int playerLife = 5;




float width_edge = WIDTH / 2 * STD_PIX_SIZE;
float height_edge = HEIGHT / 2 * STD_PIX_SIZE;

// 定义矩形的边界
float left = -width_edge + (56 * STD_PIX_SIZE);
float top = height_edge - (62 * STD_PIX_SIZE);
float right = width_edge - (454 * STD_PIX_SIZE);
float bottom = -height_edge + (62 * STD_PIX_SIZE);


//用于计算的线程
float loopSpeed = 0;
float barrageCreateTime = 0;

std::atomic<bool> gameTick_update;
std::atomic<bool> life_update;
std::atomic<bool> time_updata;
std::atomic<bool> loop_updata;
std::atomic<bool> barrage_updata;
std::atomic<bool> game_tick_updata;
bool timeBuffer = true;


GameTick* gameTick;
Texture * air;

struct GameSettingData
{
	unsigned long long fileHeat = 0;
	int MainVolume = 0;
	unsigned long long fileEnd = 0;
};
GameSettingData* gameConfig = nullptr;

bool playerDead = false;
void playerListening() {

	if (playerLife == 0) {
		std::cout << "玩家已经死亡" << std::endl;
		playerDead = true;
		activite = PLAYER_DEAD;
	}

}



int fraction = 0;
int fraction_all = 0;
int gameTime = 0;
int boosLife = 100;

void releaseGame() {
	fraction = 0;
	fraction_all = 0;
	gameTime = 0;
	boosLife = 100;
	playerLife = 5;
	room = 0;
	delete gameMedia;

	gameMedia = nullptr;
	delete levelLine; levelLine = nullptr;
	delete levelVAO; levelVAO = nullptr;
	delete playerGameObject; playerGameObject = nullptr;
	delete playerVAO; playerVAO = nullptr;
	delete cardNameTexture; cardNameTexture = nullptr;
	delete	cardName; cardName = nullptr;
	delete	cardNameVAO; cardNameVAO = nullptr;
	for (auto obj : enemyCreature) {
			delete obj->vao;
	}
	for (auto obj : playerBullet) {
		delete obj->vao;
	}
	
	for (auto obj : enemyBullet) {
		 delete obj->vao;
	}
	if (enemyCreature.size()>0) {
		enemyCreature.clear();
		while (enemyCreature.capacity() != 0) {
			enemyCreature.shrink_to_fit();
		}
	}
	
	if (playerBullet.size() > 0) {
		std::cout << "" << playerBullet.size() << std::endl;
		playerBullet.clear();
		while (playerBullet.capacity() != 0) {
			playerBullet.shrink_to_fit();
		}
	}

	if (enemyBullet.size() > 0) {
		enemyBullet.clear();
		while (enemyBullet.capacity()!=0) {
			enemyBullet.shrink_to_fit();
		}
	}

}

void releaseBoos() {
	fraction = 0;
	fraction_all = 0;
	gameTime = 10;
	boosLife = 100;
	playerLife = 5;
	room = 0;
	for (auto obj : enemyCreature) {
		delete obj->vao;
	}
	for (auto obj : playerBullet) {
		delete obj->vao;
	}

	for (auto obj : enemyBullet) {
		delete obj->vao;
	}
	if (enemyCreature.size() > 0) {
		enemyCreature.clear();
		while (enemyCreature.capacity() != 0) {
			enemyCreature.shrink_to_fit();
		}
	}

	if (playerBullet.size() > 0) {
		playerBullet.clear();
		while (playerBullet.capacity() != 0) {
			playerBullet.shrink_to_fit();
		}
	}

	if (enemyBullet.size() > 0) {
		enemyBullet.clear();
		while (enemyBullet.capacity() != 0) {
			enemyBullet.shrink_to_fit();
		}
	}
}
void iniAtomic() {
	life_update.store(true);
	time_updata.store(true);
	game_tick_updata.store(true);
	gameTick_update.store(true);
	loop_updata.store(true);
	barrage_updata.store(true);
}
MediaManager* playerMediaManager;
//初始化少女
void initBoos1() {
	playerMediaManager = new MediaManager(".\\assets\\media\\shoot.mp3",5);
	iniAtomic();
	gameTime = 99;
	loopSpeed = 5/360;
	barrageCreateTime = 0.05;
	cardNameTexture = new Texture("胎儿之梦",24, 255,255,255, 0);
	cardNameVAO = new RenderObject(new GameObject(1.25, 3.59, cardNameTexture->getWidth(), cardNameTexture->getHeight(), NULL));

	//玩家
	playerGameObject = new GameObject(-2, -4.09, playerTexture->getWidth(), playerTexture->getHeight(), NULL);
	playerVAO = new RenderObject(playerGameObject->getVao());

	levelVAO = new RenderObject(new GameObject(NUMBER_WIDTH, NUMBER_HEIGHT + 1, numberTexture0->getWidth(), numberTexture0->getHeight(), NULL));

	RenderObject * boosVAO = new RenderObject(new GameObject(-2, 2, enemyTexture->getWidth(), enemyTexture->getHeight(), ENEMY));
	addGameObject(boosVAO->getGameObj(), boosVAO, enemyTexture, false, nullptr, 0, SINGLE, ENEMY);
	for (int i = 0; i < 16;i++) {
		RenderObject* moonVAO1 = new RenderObject(new GameObject(boosVAO->getGameObj()->getCenter_x(), boosVAO->getGameObj()->getCenter_y(), cardTextureDreamMoonPorint->getWidth(), cardTextureDreamMoonPorint->getHeight(), NULL));
		//如果纹理为nullptr则使用空白纹理
		addGameObject(moonVAO1->getGameObj(), moonVAO1, nullptr, true, boosVAO->getGameObj(), i * 22, SINGLE, ENEMY);
	}
	
	lifeLine->setWidth(1);
	lifeLine->update();
	if (enemyCreature.size()>0) {
		for (auto obj : enemyCreature) {
			if (obj->gameObject->getGameObject() == ENEMY) {
				obj->gameObject->setMaxLife(100);
				obj->gameObject->setLife(100);
			}
		}
	}

	ToSting(0, 10, &numberList);
	ToSting(0, 10, &numberList1); 
}
void titleMedia() {
	if (backgroundMedia==nullptr) {
		backgroundMedia = new MediaPlay(".\\assets\\media\\Hartmann's Youkai Girl.mp3");
		backgroundMedia->run();
		backgroundMedia->circulate();
	}
	if (gameConfig!=nullptr) {
		backgroundMedia->setVolume(gameConfig->MainVolume);
	}
	else {
		backgroundMedia->setVolume(100);
	}
}


std::string gameConfigPath = "gameSettng.bin";
void outputData() {
	std::ofstream file(gameConfigPath, std::ios::binary);
	if (file.is_open()) {
		std::cout << "写出" << std::endl;
		if (gameConfig != nullptr) {
			gameConfig->fileHeat = FILE_HEAT;
			gameConfig->fileEnd = FILE_END;
			file.write((const char*)&gameConfig->fileHeat, sizeof(gameConfig->fileHeat));
			file.write((const char*)&gameConfig->MainVolume, sizeof(gameConfig->MainVolume));
			file.write((const char*)&gameConfig->fileEnd, sizeof(gameConfig->fileEnd));
		}
	}
	file.close();
}
void inputData() {
	std::filesystem::path path(gameConfigPath.c_str());
	if (std::filesystem::exists(path)) {
		std::ifstream file(gameConfigPath, std::ios::binary);
		if (file.is_open()) {
			if (gameConfig != nullptr) {
				file.read((char*)&gameConfig->fileHeat, sizeof(gameConfig->fileHeat));
				file.read((char*)&gameConfig->MainVolume, sizeof(gameConfig->MainVolume));
				file.read((char*)&gameConfig->fileEnd, sizeof(gameConfig->fileEnd));
			}
		}
		file.close();
	}
	if (gameConfig != nullptr) {
		if (gameConfig->fileHeat != FILE_HEAT && gameConfig->fileEnd != FILE_END) {
			gameConfig->MainVolume = 100;
		}
	}
}

//初始化=======================开始=====================
void initTexture() {
	//数字
	numberTexture0 = new Texture("0", 50, 255, 255, 255, 0);
	numberTexture1 = new Texture("1", 50, 255, 255, 255, 0);
	numberTexture2 = new Texture("2", 50, 255, 255, 255, 0);
	numberTexture3 = new Texture("3", 50, 255, 255, 255, 0);
	numberTexture4 = new Texture("4", 50, 255, 255, 255, 0);
	numberTexture5 = new Texture("5", 50, 255, 255, 255, 0);
	numberTexture6 = new Texture("6", 50, 255, 255, 255, 0);
	numberTexture7 = new Texture("7", 50, 255, 255, 255, 0);
	numberTexture8 = new Texture("8", 50, 255, 255, 255, 0);
	numberTexture9 = new Texture("9", 50, 255, 255, 255, 0);
	numberTexture.push_back(numberTexture0);
	numberTexture.push_back(numberTexture1);
	numberTexture.push_back(numberTexture2);
	numberTexture.push_back(numberTexture3);
	numberTexture.push_back(numberTexture4);
	numberTexture.push_back(numberTexture5);
	numberTexture.push_back(numberTexture6);
	numberTexture.push_back(numberTexture7);
	numberTexture.push_back(numberTexture8);
	numberTexture.push_back(numberTexture9);
	//玩家生命
	lifeTexture = new Texture(".\\assets\\image\\life.png", 0);
	//玩家技能点
	skillTexture = new Texture(".\\assets\\image\\bread.png", 0);
	//标题背景
	titlebackgroundTexture = new Texture(".\\assets\\image\\background.jpeg", 0);
	//标题文字
	titleTexture_S = new Texture(WindowName,100, 0, 0, 0, 0);
	//开始选项
	startTexturBlack = new Texture("Start", 100, 255, 255, 255, 0);
	startTexturWhite = new Texture("Start", 100, 0, 0, 0, 0);
	//退出选项
	quitGameTexturBlack = new Texture("Quit", 100, 255, 255, 255, 0);
	quitGameTexturWhite = new Texture("Quit", 100, 0, 0, 0, 0);
	//游戏界面背景
	gameBarTexture = new Texture(".\\assets\\image\\gemeBigenBackground.png", 0);
	//boos血条纹理
	bossLifeTexture = new Texture(".\\assets\\image\\fileLine.png", 0);
	//boos
	cardTextureDreamSumPorint = new Texture(".\\assets\\image\\pointpng.png", 0);
	cardTextureDreamSum = new Texture(".\\assets\\image\\sum.png", 0);
	cardTextureDreamMoonPorint = new Texture(".\\assets\\image\\pointpng.png", 0);
	cardTextureDreamMoon = new Texture(".\\assets\\image\\moon.png", 0);
	//玩家材质
	playerTexture = new Texture(".\\assets\\image\\palyer.png", 0);
	//敌方材质
	enemyTexture = new Texture(".\\assets\\image\\palyer.png", 0);

	basicTexture1_white = new Texture("简单",100,255,255,255,0);
	basicTexture1_black = new Texture("简单", 100, 0, 0, 0, 0);

	ordinaryTexture2_white = new Texture("普通", 100, 255, 255, 255, 0);
	ordinaryTexture2_black = new Texture("普通", 100, 0, 0, 0, 0);

	difficultyTexture3_white = new Texture("困难", 100, 255, 255, 255, 0);
	difficultyTexture3_black = new Texture("困难", 100, 0, 0, 0, 0);

	scourgeTexture4_white = new Texture("天灾", 100, 255, 255, 255, 0);
	scourgeTexture4_black = new Texture("天灾", 100, 0, 0, 0, 0);

	//设置的选项材质
	settingsTextureWhite = new Texture("Settings", 100, 255, 255, 255, 0);
	settingsTextureBlack = new Texture("Settings",100, 0, 0, 0,0);

	settingTextTexture = new Texture("Settings",100,255,255,255,0);
	settingVolumeTexture = new Texture("Velume", 100, 255, 255, 255, 0);
	settingVolumeTexture_black = new Texture("Velume", 100, 0, 0, 0, 0);

	gameWaitBackgroundTexture = new Texture(".\\assets\\image\\waitBackground.png",0);
	gameKeepTextTexture = new Texture("继续", 100, 255, 0, 0, 0);
	gameKeepTextTextureBlack = new Texture("继续", 100, 0, 0, 0, 0);

	gameQuitTextTexture = new Texture("退出", 100, 255, 0, 0, 0);
	gameQuitTextTextureBlack = new Texture("退出", 100, 0, 0, 0, 0);

	playerDeadTextTextureBlack = new Texture("满目疮痍", 100, 0, 0, 0, 0);
	

}
void initShader() {
	textShader = new Shader(".\\assets\\shaders\\vertex.glsl", ".\\assets\\shaders\\fragmentText.glsl");
	blackWhiteShader = new Shader(".\\assets\\shaders\\vertex.glsl", ".\\assets\\shaders\\fragmentBlackWhite.glsl");
	blenderShader = new Shader(".\\assets\\shaders\\vertex.glsl", ".\\assets\\shaders\\fragmentBland.glsl");
}
//初始化游戏UI 
void intiShow() {
	for (int i = 0; i < 10;i++) {
		numberGameObject0 = new GameObject(NUMBER_WIDTH+ (numberTexture0->getWidth() / 2 * 0.01) * i, NUMBER_HEIGHT, numberTexture0->getWidth(), numberTexture0->getHeight(), NULL);
		numberVAO0 = new RenderObject(numberGameObject0->getVao());
		numberVAOs.push_back(numberVAO0);
	}
	for (int i = 0; i < 10; i++) {
		numberGameObject00 = new GameObject(NUMBER_WIDTH + (numberTexture0->getWidth() / 2 * 0.01) * i, NUMBER_HEIGHT_S, numberTexture0->getWidth(), numberTexture0->getHeight(), NULL);
		numberVAO_0 = new RenderObject(numberGameObject00->getVao());
		numberVAOs1.push_back(numberVAO_0);
	}


	skillVAO = new GameObject(NUMBER_WIDTH, SKILL_HEIGHT, skillTexture->getWidth(), skillTexture->getHeight(), NULL);
	skillVAO1 = new GameObject(NUMBER_WIDTH + 0.4, SKILL_HEIGHT, skillTexture->getWidth(), skillTexture->getHeight(), NULL);
	skillVAO2 = new GameObject(NUMBER_WIDTH + 0.8, SKILL_HEIGHT, skillTexture->getWidth(), skillTexture->getHeight(), NULL);
	skillGameObject = new RenderObject(skillVAO->getVao());
	skillGameObject1 = new RenderObject(skillVAO1->getVao());
	skillGameObject2 = new RenderObject(skillVAO2->getVao());
	skillList.push_back(skillGameObject);
	skillList.push_back(skillGameObject1);
	skillList.push_back(skillGameObject2);

	lifeVAO = new GameObject(NUMBER_WIDTH, LIFE_HEIGHT, lifeTexture->getWidth(), lifeTexture->getHeight(), NULL);
	lifeVAO1 = new GameObject(NUMBER_WIDTH + 0.4, LIFE_HEIGHT, lifeTexture->getWidth(), lifeTexture->getHeight(), NULL);
	lifeVAO2 = new GameObject(NUMBER_WIDTH + 0.8, LIFE_HEIGHT, lifeTexture->getWidth(), lifeTexture->getHeight(), NULL);
	lifeVAO3 = new GameObject(NUMBER_WIDTH + 1.2, LIFE_HEIGHT, lifeTexture->getWidth(), lifeTexture->getHeight(), NULL);
	lifeVAO4 = new GameObject(NUMBER_WIDTH + 1.6, LIFE_HEIGHT, lifeTexture->getWidth(), lifeTexture->getHeight(), NULL);
	lifeGameObject = new RenderObject(lifeVAO->getVao());
	lifeGameObject1 = new RenderObject(lifeVAO1->getVao());
	lifeGameObject2 = new RenderObject(lifeVAO2->getVao());
	lifeGameObject3 = new RenderObject(lifeVAO3->getVao());
	lifeGameObject4 = new RenderObject(lifeVAO4->getVao());
	lifeList.push_back(lifeGameObject);
	lifeList.push_back(lifeGameObject1);
	lifeList.push_back(lifeGameObject2);
	lifeList.push_back(lifeGameObject3);
	lifeList.push_back(lifeGameObject4);

	timeNumberGameObject = new GameObject(1.05, 4.09, numberTexture0->getWidth(), numberTexture0->getHeight(), NULL);
	timeNumberVAO = new RenderObject(timeNumberGameObject->getVao());
	timeNumberGameObject1 = new GameObject(1.05 + (numberTexture0->getWidth() / 2 * 0.01), 4.09, numberTexture0->getWidth(), numberTexture0->getHeight(), NULL);
	timeNumberVAO1 = new RenderObject(timeNumberGameObject1->getVao());
	timeNumberList.push_back(timeNumberVAO);
	timeNumberList.push_back(timeNumberVAO1);

	roleVAO1 = new RenderObject(new GameObject(0, 3.0f, basicTexture1_white->getWidth(), basicTexture1_white->getHeight(), NULL));
	roleVAO2 = new RenderObject(new GameObject(0, 2.0f, ordinaryTexture2_white->getWidth(), ordinaryTexture2_white->getHeight(), NULL));
	roleVAO3 = new RenderObject(new GameObject(0, 1.0f, difficultyTexture3_white->getWidth(), difficultyTexture3_white->getHeight(), NULL));
	roleVAO4 = new RenderObject(new GameObject(0, 0.0f, scourgeTexture4_white->getWidth(), scourgeTexture4_white->getHeight(), NULL));
	#define SETTING_LOCATION 0
	settingTextGameObject = new GameObject(SETTING_LOCATION,0,settingsTextureWhite,NULL);
	settingTextVAO = new RenderObject(settingTextGameObject);
	settingTextVAO->getGameObj()->setAlpah(0);

	
	settingVolumeTextGameObject = new GameObject(SETTING_LOCATION, -settingTextGameObject->getHeight()/1.5*0.01, settingVolumeTexture, NULL);
	settingVolumeTextVAO = new RenderObject(settingVolumeTextGameObject);
	settingVolumeTextVAO->getGameObj()->setAlpah(0);

	settingQuitTextVAO = new RenderObject(new GameObject(SETTING_LOCATION, -settingTextGameObject->getHeight() / 1.5 * 0.01*2,quitGameTexturWhite,NULL));
	settingQuitTextVAO->getGameObj()->setAlpah(0);


	VolumeNumberVAO.push_back(new RenderObject(new GameObject(settingVolumeTextGameObject->getCenter_x() + (settingVolumeTexture->getWidth() / 2) * STD_PIX_SIZE + numberTexture0->getWidth() * STD_PIX_SIZE, settingVolumeTextGameObject->getCenter_y(), numberTexture0, NULL)));
	VolumeNumberVAO.push_back(new RenderObject(new GameObject(settingVolumeTextGameObject->getCenter_x() + (settingVolumeTexture->getWidth() / 2)*STD_PIX_SIZE+2*numberTexture0->getWidth() * STD_PIX_SIZE, settingVolumeTextGameObject->getCenter_y(), numberTexture0, NULL)));
	VolumeNumberVAO.push_back(new RenderObject(new GameObject(settingVolumeTextGameObject->getCenter_x() + (settingVolumeTexture->getWidth() / 2)*STD_PIX_SIZE+3*numberTexture0->getWidth() * STD_PIX_SIZE, settingVolumeTextGameObject->getCenter_y(), numberTexture0, NULL)));

	gameWaitBackgroundVAO = new RenderObject(new GameObject(0,0,gameWaitBackgroundTexture,NULL));
	gameKeepTextVAO = new RenderObject(new GameObject(0, 0, gameKeepTextTexture, NULL));
	gameKeepTextVAO->getGameObj()->setAlpah(0);

	gameQuitTextVAO = new RenderObject(new GameObject(gameKeepTextVAO->getGameObj()->getCenter_x(), 0 - (gameKeepTextVAO->getGameObj()->getTexture()->getHeight() * 0.01), gameQuitTextTexture, NULL));
	gameQuitTextVAO->getGameObj()->setAlpah(0);

	playerdeadTextVAO = new RenderObject(new GameObject(0,1, playerDeadTextTextureBlack,NULL));


}
//整个游戏的初始化
void initializeGame() {
	initShader();
	atomic_key_color.store(START);
	gameConfig = new GameSettingData;
	gameConfig->MainVolume = 100;
	inputData();
	keyMedia = new MediaPlay(".\\assets\\media\\selectSound.wav");
	gameTick = new GameTick();
	playerBullet.reserve(MaxPlayerBullet);
	enemyBullet.reserve(MaxEnemyBullet);
	prepareCamera();
	prepareOrtho();
	initTexture();
	titleMedia();
	air = new Texture(".\\assets\\image\\air.png",0);
	//背景
	titleBackgroundVAO = new RenderObject(new GameObject(0, 0, WIDTH, HEIGHT, NULL));
	//标题文字
	titleVAO = new RenderObject(new GameObject(0, 2.8, titleTexture_S->getWidth(), titleTexture_S->getHeight(), NULL));
	titleVAO->getGameObj()->setAlpah(0);

	//开始选项
	startVAO = new RenderObject(new GameObject(0, 0.8, startTexturBlack->getWidth(), startTexturBlack->getHeight(), NULL));
	startVAO->getGameObj()->setAlpah(0);
	//选项
	settingsVAO = new RenderObject(new GameObject(0, 0.0, settingsTextureBlack->getWidth(), settingsTextureBlack->getHeight(), NULL));
	settingsVAO->getGameObj()->setAlpah(0);

	//退出
	quitGameVAO = new RenderObject(new GameObject(0, -0.8, quitGameTexturWhite->getWidth(), quitGameTexturWhite->getHeight(), NULL));
	quitGameVAO->getGameObj()->setAlpah(0);

	

	//游戏
	gameBackgroundVAO = new RenderObject(new GameObject(0, 0, WIDTH, HEIGHT, NULL));

	//积分版
	intiShow();


	ToSting(0, 10, &numberList);
	ToSting(0, 10, &numberList1);
	lifeLine = new GameObject(-2.8  ,  4.09, bossLifeTexture->getWidth(), bossLifeTexture->getHeight(),NULL);
	bossLifeVAO = new RenderObject(lifeLine->getVao());
	gameTime = 10;
	ToSting(gameTime, 2, &timeNumberTexture);
	ToSting(1, 1, &levelNumberList);
	if (gameConfig != nullptr) {
		ToSting(gameConfig->MainVolume, 3, &volumeList);
	}
	else {
		ToSting(100, 3, &volumeList);
	}
	
	

	life_update.store(true);
	time_updata.store(true);
}
//初始化=======================结束=====================

//准备相机
void prepareCamera() {
	//lookat:生成一个viewMatrix
	//eye:当前摄像机所在的位置
	//center:当前摄像机看向的那个点
	//up:穹顶向量
	viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}
//准备穹顶
void prepareOrtho() {
	orthoMatrix = glm::ortho(-width_edge, width_edge, -height_edge, height_edge, 1.0f, -1.0f);
}


//将输入数字转换为计分板上的数字
void ToSting(int v,int length, std::vector<Texture*> * numberList_s) {
	// 清空numberList
	numberList_s->clear();

	const int maxLength = length;

	// 将整数转换为字符串，并填充前导零
	std::string numberStr = std::to_string(v);
	numberStr = std::string(maxLength - numberStr.length(), '0') + numberStr;

	// 遍历字符串中的每一位数字，并从numberTexture中获取对应的材质
	for (char digitChar : numberStr) {
		int digit = digitChar - '0'; // 将字符转换为整数
		numberList_s->push_back(numberTexture.at(digit));
	}
}

//更新游戏计时器
void updataGameTime() {
	if (gameTime>=0&&gameTime<100 && time_updata.load()) {
		time_updata.store(false);
		gameTick->addAtomic(&time_updata,20);
		ToSting(gameTime--, 2, &timeNumberTexture);
	}
}
//敌方事件
void EnemyEvent() {
	for (int i = 0; i < enemyCreature.size();i++) {
		if (enemyCreature.at(i)->gameObject->getGameObject()==ENEMY) {
			float life = enemyCreature.at(i)->gameObject->getLife();
			float lv = life / enemyCreature.at(i)->gameObject->getMaxLife();
			if (life < enemyCreature.at(i)->gameObject->getMaxLife() && life >= 0) {
				lifeLine->setWidth(lv);
				lifeLine->update();
			}
		}
	}	
}
//游戏界面跳转
int stopTime = 0;
void gameLogic(GLFWwindow* window) {
	if (activite==GAME) {
		if (room==0) {
			if (gameMedia==nullptr) {
				gameMedia = new MediaPlay(".\\assets\\media\\InfiniteNightmare.wav");
				gameMedia->run();
				gameMedia->circulate();
			}
			room++;
		}
		playerEvent(window);
		if (activite == GAME&& gameTime>=0) {
			gameObjectEvent();
		}
		else {
			releaseBoos();
		}
	}
	allRenderEvent();
}


//游戏对象事件
void gameObjectEvent() {
	if (activite == GAME) {
		playerListening();
	}
	//更新游戏时间
	updataGameTime();
	//玩家子弹移动
	for (int i = 0; i < playerBullet.size();i++) {
		GameObject* game = playerBullet.at(i)->gameObject;
		if (game!=nullptr) {
			if (game->getGameObject() == BULLET) {
				if (game->getAbsDrection() == UP) {
					game->updatePosition(game->getCenter_x(), game->getCenter_y() + 0.05);
				}
				if (game->getCenter_x() > width_edge || game->getCenter_x() < -width_edge, game->getCenter_y() > top || game->getCenter_y() < -height_edge) {
		
					if (playerBullet.at(i)->vao!=nullptr) {
						delete playerBullet.at(i)->vao;
					}
					playerBullet.erase(playerBullet.begin() + i);
					game = nullptr;
				}
				if (game != nullptr) {
					//比较距离
					if (enemyCreature.size() > 0&&compleDistance(game->getWidth() / 2 * STD_PIX_SIZE,
						game->getCenter_x(),
						game->getCenter_y(),
						enemyCreature.at(0)->gameObject->getCenter_x(),
						enemyCreature.at(0)->gameObject->getCenter_y())) {
						for (auto obj : enemyCreature) {
							if (obj->gameObject->getGameObject() == ENEMY) {
								obj->gameObject->setLife(boosLife--);
								delete playerBullet.at(i)->vao;
								playerBullet.erase(playerBullet.begin() + i);
								}
							}
						ToSting(fraction += TARGET, 10, &numberList1);
						EnemyEvent();
					}
				}
			}
		}
	}
	//敌方子弹移动
	for (int i = 0; i < enemyBullet.size(); i++) {
		GameObject* game = enemyBullet.at(i)->gameObject; 
		if (game!=nullptr) {
			float vector_x = game->getVector_x();
			float vector_y = game->getVector_y();
			float  x_new = game->getCenter_x() + (vector_x * STD_PIX_SIZE*5);
			float  y_new = game->getCenter_y() + (vector_y * STD_PIX_SIZE*5);
			game->updatePosition(x_new, y_new);
			if (compleDistance((game->getWidth() / 2) * STD_PIX_SIZE, playerGameObject->getCenter_x(),
				playerGameObject->getCenter_y(), game->getCenter_x(), game->getCenter_y())) {
				if (life_update.load()) {
					if (playerLife>0) {
						life_update.store(false);
						playerLife--;
						std::cout << "子弹击中玩家" << std::endl;
						gameTick->addAtomic(&life_update, 20);
					}
				}
			}
			if (game->getCenter_x() > right || game->getCenter_x() < left ||
				game->getCenter_y() > top || game->getCenter_y() < bottom) {

				if (enemyBullet.at(i)->vao!=nullptr) {
					delete enemyBullet.at(i)->vao;
				}
				enemyBullet.erase(enemyBullet.begin() + i);
			}
		}
	}
	//处理环绕事件
	if (loop_updata.load()) {
		loop(enemyCreature,true);
		loop_updata.store(false);
		gameTick->addAtomic(&loop_updata, 2);
	}

	//////弹幕事件
	if (barrage_updata.load()) {
		barrage_updata.store(false);

		barrage(enemyCreature);
		gameTick->addAtomic(&barrage_updata,2);
	}

}
//游戏刻
void tice(float ms, std::atomic<bool> *  obj) {
		int nm = 1000000000;
		int time = nm * ms;
		std::this_thread::sleep_for(std::chrono::nanoseconds(time));
		obj->store(true);

}
//跳转到游戏界面

std::atomic<bool> bettonBufferTime;
//玩家键盘事件
void playerEvent(GLFWwindow* window) {
	if (playerLife<=0) {
	
	}
	float new_x = playerGameObject->getCenter_x();
	float new_y = playerGameObject->getCenter_y();

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS|| glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		new_y += MOVE;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		new_y -= MOVE;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		new_x -= MOVE;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		new_x += MOVE;
	}

	float playerHalfWidth = (playerGameObject->getWidth() / 2) * STD_PIX_SIZE;
	float playerHalfHeight = (playerGameObject->getHeight() / 2) * STD_PIX_SIZE;

	float playerCenterX = playerGameObject->getCenter_x();
	float playerCenterY = playerGameObject->getCenter_y();

	// 检查玩家是否在矩形区域内，考虑玩家的宽度和高度
	if (playerCenterX >= left + playerHalfWidth && playerCenterX <= right - playerHalfWidth &&
		playerCenterY >= bottom + playerHalfHeight && playerCenterY <= top - playerHalfHeight) {
	
		playerGameObject->updatePosition(new_x, new_y);
	}
	else {
		if (playerCenterX - playerHalfWidth < left) {
			playerGameObject->updatePosition(left + playerHalfWidth, playerCenterY); // 移动到左边界内
		}
		else if (playerCenterX + playerHalfWidth > right) {
			playerGameObject->updatePosition(right - playerHalfWidth, playerCenterY); // 移动到右边界内
		}

		if (playerCenterY - playerHalfHeight < bottom) {
			playerGameObject->updatePosition(playerCenterX, bottom + playerHalfHeight); // 移动到底边界内
		}
		else if (playerCenterY + playerHalfHeight > top) {
			playerGameObject->updatePosition(playerCenterX, top - playerHalfHeight); // 移动到顶边界内
		}
	}
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) {
		if (gameTick_update.load()&& playerBullet.size() <= MaxPlayerBullet) {
			gameTick_update.store(false);
			gameTick->addAtomic(&gameTick_update, 2);
			ToSting(++fraction_all, 10, &numberList);
			playerMediaManager->play();
			createPlayerBullet();
		}
	}


}
//键盘事件
void releaseBettonBufferTimeThread() {
	delete backgroundMedia;
	backgroundMedia = nullptr;

}
bool isRun() {
	return run;
}
void toTitle() {
	quitGameVAO->getGameObj()->setAlpah(0);
	settingsVAO->getGameObj()->setAlpah(0);
	startVAO->getGameObj()->setAlpah(0);
	titleVAO->getGameObj()->setAlpah(0);
	settingQuitTextVAO->getGameObj()->setAlpah(0);
	settingVolumeTextVAO->getGameObj()->setAlpah(0);
	settingTextVAO->getGameObj()->setAlpah(0);

	atomic_key_color.store(START);
	keySelect = 0;
	activite = TITLE;
	titleMedia();
}
void settings(int key) {
	if (activite == SETTINGS) {
		if (key == GLFW_KEY_ESCAPE) {
			activite = TITLE;
			atomic_key_color.store(TITLE);
			toTitle();

		}
		if (key == GLFW_KEY_UP) keySelect = (keySelect - 1 + 2) % 2;
		if (key == GLFW_KEY_DOWN) keySelect = (keySelect + 1) % 2;
		if (keySelect == 0) {
			atomic_key_color.store(VOLUME);
			if (gameConfig!=nullptr) {
				if (gameConfig->MainVolume > 100) gameConfig->MainVolume = 100;
				if (gameConfig->MainVolume < 0) gameConfig->MainVolume = 0;

				if (key == GLFW_KEY_LEFT) {
					if (gameConfig->MainVolume <= 100 && gameConfig->MainVolume > 0) {
						gameConfig->MainVolume -= 1;
						if (backgroundMedia != nullptr) {
							backgroundMedia->setVolume(gameConfig->MainVolume);
							ToSting(gameConfig->MainVolume, 3, &volumeList);
						}
					}
				}
				if (key == GLFW_KEY_RIGHT) {
					if (gameConfig->MainVolume < 100 && gameConfig->MainVolume >= 0) {
						gameConfig->MainVolume += 1;
						if (backgroundMedia != nullptr) {
							backgroundMedia->setVolume(gameConfig->MainVolume);
							ToSting(gameConfig->MainVolume, 3, &volumeList);
						}
					}
				}
			}
		}
		if (keySelect == 1) {
			if (key == GLFW_KEY_Z){
				timeBuffer = false;
				gameTick->addBool(&timeBuffer,5);
				keySelect = 0;
				activite = TITLE;
				atomic_key_color.store(TITLE);
				toTitle();
			}
			atomic_key_color.store(QUIT);
		}
	}
}
void title(int key) {
	if (activite == TITLE) {
		if(key == GLFW_KEY_UP) keySelect = (keySelect - 1 + 3) % 3;
		if(key == GLFW_KEY_DOWN) keySelect = (keySelect + 1) % 3;
		if (keySelect == 0) {
			keyMedia->run2();
			atomic_key_color.store(START);
			if (key == GLFW_KEY_Z&& timeBuffer) {
				activite = SELECT;
				bettonBufferTime.store(false);
				gameTick->addAtomic(&bettonBufferTime, 20);
				keySelect = 0;
			}
		}
		if (keySelect == 1) {
			keyMedia->run2();

			if (key == GLFW_KEY_Z) {
				activite = SETTINGS;
				keySelect = 0;
			}
			atomic_key_color.store(SETTINGS);

		}
		if (keySelect == 2) {
			keyMedia->run2();
			atomic_key_color.store(QUIT);
			if (key == GLFW_KEY_Z) {
				run = false;
			}
		}
	}
	if (activite == SELECT) {
		if (key == GLFW_KEY_UP) {
			keySelect = (keySelect - 1 + 4) % 4;
			keyMedia->run2();

		} 
		if (key == GLFW_KEY_DOWN) {
			keySelect = (keySelect + 1) % 4;
			keyMedia->run2();

		}

		if (key == GLFW_KEY_ESCAPE) {
			toTitle();
		}
		if (keySelect == 3) {
			if (key == GLFW_KEY_Z && bettonBufferTime.load()) {
				releaseBettonBufferTimeThread();
				activite = GAME;
				initBoos1();
			}
			atomic_key_color.store(3);
		}
		if (keySelect == 2) {
			if (key == GLFW_KEY_Z && bettonBufferTime.load()) {
				releaseBettonBufferTimeThread();
				activite = GAME;
				initBoos1();

			}
			atomic_key_color.store(2);
		}
		if (keySelect == 1) {
			if (key == GLFW_KEY_Z && bettonBufferTime.load()) {
				releaseBettonBufferTimeThread();
				activite = GAME;
				initBoos1();

			}
			atomic_key_color.store(1);
		}
		if (keySelect == 0) {
			if (key == GLFW_KEY_Z && bettonBufferTime.load()) {
				releaseBettonBufferTimeThread();
				activite = GAME;
				initBoos1();
			}
			atomic_key_color.store(0);
		}
	}
}
int release = 1;
void gameStopSetting(int key) {
	if (activite==GAME&& key == GLFW_KEY_ESCAPE && activite!=GAME_STOP) {
		activite = GAME_STOP;
		if (stopTime != gameTime) {
			stopTime = gameTime + 1;

		}
		bettonBufferTime.store(false);
		gameTick->addAtomic(&bettonBufferTime, 1);
	}
	if (activite == GAME_STOP&& bettonBufferTime.load() && key == GLFW_KEY_ESCAPE) {
		gameTime = stopTime;
		activite = GAME;
	}
	if (activite == GAME_STOP|| activite == PLAYER_DEAD) {
		if (key == GLFW_KEY_UP) keySelect = (keySelect - 1 + 2) % 2;
		if (key == GLFW_KEY_DOWN) keySelect = (keySelect + 1) % 2;
		if (keySelect == 0) {
			if (key == GLFW_KEY_Z) {
				gameTime = stopTime;
				if (activite == PLAYER_DEAD) {
					playerLife = 5;
					playerDead = false;
					activite = GAME;
				}
				activite = GAME;
			}
			atomic_key_color.store(KEEP);
		}
		if (keySelect == 1) {
			if (key == GLFW_KEY_Z) {
				release = 0;
				releaseGame();
				toTitle();
			}
				atomic_key_color.store(QUIT);
			}
		}

}
void keyEvent(int key) {
	settings(key);
	title(key);
	gameStopSetting(key);
}
//游戏渲染
//设置界面
void settingActivite() {
	rend(blenderShader, titleBackgroundVAO, titlebackgroundTexture);
	rend(textShader, settingTextVAO, settingsTextureWhite);
	if (atomic_key_color.load()==VOLUME) {
		rend(textShader, settingVolumeTextVAO, settingVolumeTexture_black);
	}
	else {
		rend(textShader, settingVolumeTextVAO, settingVolumeTexture);
	}
	if (atomic_key_color.load() == QUIT) {
		rend(textShader, settingQuitTextVAO, quitGameTexturWhite);
	}
	else {
		rend(textShader, settingQuitTextVAO, quitGameTexturBlack);
	}
	for (int i = 0; i < volumeList.size(); i++) {
		rend(textShader, VolumeNumberVAO.at(i), volumeList.at(i));
	}

}
//标题界面背景
void titleActivite() {
	                 
	rend(blenderShader, titleBackgroundVAO, titlebackgroundTexture);
	rend(textShader, titleVAO, titleTexture_S);
	if (atomic_key_color.load() == START) {
		rend(textShader, startVAO, startTexturWhite);
	}
	else {
		rend(textShader, startVAO, startTexturBlack);
	}
	if (atomic_key_color.load() == SETTINGS) {
		rend(textShader, settingsVAO, settingsTextureBlack);
	}
	else {
		rend(textShader, settingsVAO, settingsTextureWhite);
	}
	if (atomic_key_color.load() == QUIT) {
		rend(textShader, quitGameVAO, quitGameTexturWhite);
	}
	else {
		rend(textShader, quitGameVAO, quitGameTexturBlack);
	}
}
//难度选择界面
void selectActivite() {
	rend(blenderShader, titleBackgroundVAO, titlebackgroundTexture);
	if (atomic_key_color.load() == 0) {
		rend(textShader, roleVAO1, basicTexture1_black);

	}
	else {
		rend(textShader, roleVAO1, basicTexture1_white);

	}
	if (atomic_key_color.load() == 1) {
		rend(textShader, roleVAO2, ordinaryTexture2_black);

	}
	else {
		rend(textShader, roleVAO2, ordinaryTexture2_white);

	}
	if (atomic_key_color.load() == 2) {
		rend(textShader, roleVAO3, difficultyTexture3_black);

	}
	else {
		rend(textShader, roleVAO3, difficultyTexture3_white);

	}
	if (atomic_key_color.load() == 3) {
		rend(textShader, roleVAO4, scourgeTexture4_black);
	}
	else {
		rend(textShader, roleVAO4, scourgeTexture4_white);
	}
}
//游戏界面
void gameActivite() {
	if (activite == GAME_STOP|| activite == PLAYER_DEAD) {
		Shader* blenderShader = blackWhiteShader;
		if (playerGameObject != nullptr) {
			playerGameObject->update();
		}
		for (objectStruct* game : playerBullet) {
			if (game->gameObject != nullptr) {
				game->gameObject->update();
				rend(blenderShader, game->vao, game->texture);
			}
		}
		for (objectStruct* game : enemyBullet) {
			if (game->gameObject != nullptr) {
				game->gameObject->update();
				rend(blenderShader, game->vao, game->texture);
			}
		}

		rend(blenderShader, gameBackgroundVAO, gameBarTexture);

		for (int i = 0; i < numberList.size(); i++) {
			rend(blenderShader, numberVAOs.at(i), numberList.at(i));
			rend(blenderShader, numberVAOs1.at(i), numberList1.at(i));
		}
		for (int i = 0; i < skillList.size(); i++) {
			rend(blenderShader, skillList.at(i), skillTexture);
		}
		for (int i = 0; i < playerLife; i++) {
			rend(blenderShader, lifeList.at(i), lifeTexture);
		}
		for (int i = 0; i < timeNumberList.size(); i++) {
			rend(blenderShader, timeNumberList.at(i), timeNumberTexture.at(i));
		}
		for (int i = 0; i < levelNumberList.size(); i++) {
			rend(blenderShader, levelVAO, levelNumberList.at(i));
		}
		for (int i = 0; i < enemyCreature.size(); i++) {
			rend(blenderShader, enemyCreature.at(i)->vao, enemyCreature.at(i)->texture);
		}
		rend(blenderShader, playerVAO, playerTexture);
		rend(blenderShader, cardNameVAO, cardNameTexture);
		rend(blenderShader, bossLifeVAO, bossLifeTexture);
	}
	else {
		if (playerGameObject != nullptr) {
			playerGameObject->update();
		}
		for (objectStruct* game : playerBullet) {
			if (game->gameObject != nullptr) {
				game->gameObject->update();
				rend(blenderShader, game->vao, game->texture);
			}
		}
		for (objectStruct* game : enemyBullet) {
			if (game->gameObject != nullptr) {
				game->gameObject->update();
				rend(blenderShader, game->vao, game->texture);
			}
		}

		rend(blenderShader, gameBackgroundVAO, gameBarTexture);

		for (int i = 0; i < numberList.size(); i++) {
			rend(textShader, numberVAOs.at(i), numberList.at(i));
			rend(textShader, numberVAOs1.at(i), numberList1.at(i));
		}
		for (int i = 0; i < skillList.size(); i++) {
			rend(blenderShader, skillList.at(i), skillTexture);
		}
		for (int i = 0; i < playerLife; i++) {
			rend(blenderShader, lifeList.at(i), lifeTexture);
		}
		for (int i = 0; i < timeNumberList.size(); i++) {
			rend(textShader, timeNumberList.at(i), timeNumberTexture.at(i));
		}
		for (int i = 0; i < levelNumberList.size(); i++) {
			rend(blenderShader, levelVAO, levelNumberList.at(i));
		}
		for (int i = 0; i < enemyCreature.size(); i++) {
			rend(blenderShader, enemyCreature.at(i)->vao, enemyCreature.at(i)->texture);
		}
		rend(blenderShader, playerVAO, playerTexture);
		rend(textShader, cardNameVAO, cardNameTexture);
		rend(blenderShader, bossLifeVAO, bossLifeTexture);
	}

}
void gameStopActivite() {
	gameActivite();
	rend(blenderShader, gameWaitBackgroundVAO, gameWaitBackgroundTexture);
	if (activite == PLAYER_DEAD) {
		rend(textShader, playerdeadTextVAO, playerDeadTextTextureBlack);
	}
	if (atomic_key_color.load() == QUIT) {
		rend(textShader, gameQuitTextVAO, gameQuitTextTextureBlack);
	}
	else {
		rend(textShader, gameQuitTextVAO, gameQuitTextTexture);
	}
	if (atomic_key_color.load() == KEEP) {
		rend(textShader, gameKeepTextVAO, gameKeepTextTextureBlack);
	}
	else {
		rend(textShader, gameKeepTextVAO, gameKeepTextTexture);
	}
}
//所有的渲染事件
void allRenderEvent() {
	if (activite==TITLE) {
		titleActivite();
	}
	if (activite == SELECT) {
		selectActivite();
	}
	if(activite==SETTINGS){
		settingActivite();
	}
	if(activite==GAME){
		gameActivite();
	}
	if (activite == GAME_STOP|| activite == PLAYER_DEAD) {
		if (release) {
			gameActivite();
		}
		gameStopActivite();
	}
}
//单次游戏渲染
void rend(Shader* shader,RenderObject *vao,Texture *mTexture) {
	shader->bindShader();
	shader->IntUniform("samplerTexture", mTexture->getUnit());
	shader->setMatrix4x4("transform", transform);
	shader->setMatrix4x4("viewMatrix", viewMatrix);
	shader->setMatrix4x4("projectionMatrix", orthoMatrix);
	vao->bind();
	mTexture->bind();
	if (mTexture->getType() ==TEXT&& vao->getGameObj() != nullptr&&!vao->getGameObj()->getIsAlpah()) {
		shader->bindShader();
		shader->IntUniform("samplerTexture", mTexture->getUnit());
		shader->Float3Uniform("color", mTexture->getR(), mTexture->getG(), mTexture->getB());
		shader->FloatUniform("alpah", 1.0f);
		shader->setMatrix4x4("transform", transform);
		shader->setMatrix4x4("viewMatrix", viewMatrix);
		shader->setMatrix4x4("projectionMatrix", orthoMatrix);
		vao->bind();
		mTexture->bind();
	}
	if (mTexture->getType() == TEXT && vao->getGameObj() != nullptr && vao->getGameObj()->getIsAlpah()) {
		shader->bindShader();
		shader->IntUniform("samplerTexture", mTexture->getUnit());
		shader->Float3Uniform("color", mTexture->getR(), mTexture->getG(), mTexture->getB());
		shader->FloatUniform("alpah", vao->getGameObj()->getAlpah());
		shader->setMatrix4x4("transform", transform);
		shader->setMatrix4x4("viewMatrix", viewMatrix);
		shader->setMatrix4x4("projectionMatrix", orthoMatrix);
		vao->bind();
		mTexture->bind();
	}
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}


void clearGame() {
	outputData();
}


//游戏对象环绕
void loop(std::vector<objectStruct*> gameStruct, bool off) {
	for (auto obj : gameStruct) {
		if (obj->loop == true && obj->loopObject != nullptr) {
			if (off) {
				if (obj->du > 360) {
					obj->du = 0;
				}
				if (obj->du >= 0 && obj->du <= 360) {
					obj->du += (1.0f);
				}
			}
			obj->gameObject->loop(obj->loopObject->getCenter_x(), obj->loopObject->getCenter_y(), obj->du, obj->gameObject->getWidth() * 2 * STD_PIX_SIZE);
			obj->gameObject->update();
		}
	}
}
//敌方弹幕事件
void barrage(std::vector<objectStruct*> gameStruct) {
	for (auto obj : gameStruct) {
		if (obj->comtext == ALL) {
			createEnemyBullet(enemyCreature, obj->gameObject, cardTextureDreamSumPorint);
		}
		else {
			if (obj->loop) {

				createEnemyBullet(enemyCreature, obj->gameObject, cardTextureDreamSumPorint);
			}
		}
	}
}
void createPlayerBullet() {
		RenderObject* vao = new RenderObject(new GameObject(playerGameObject->getCenter_x(), playerGameObject->getCenter_y(), playerTexture->getWidth(), playerTexture->getHeight(), BULLET));
		vao->getGameObj()->setAbsDirection(UP);
		vao->getGameObj()->setGameObject(BULLET);
		addGameObject(vao->getGameObj(), vao, playerTexture, BULLET);

}
//创建敌方子弹
void createEnemyBullet(float x,float y , GameObject* emitter, Texture* texture) {
	if (enemyBullet.size() < MaxEnemyBullet) {
		// 获取敌人的中心
		float x1 = x;
		float y1 = y;

		// 发射点的位置
		float x2 = emitter->getCenter_x();
		float y2 = emitter->getCenter_y();

		// 计算方向向量
		float dx = x2 - x1;
		float dy = y2 - y1;
		float distance = sqrt(dx * dx + dy * dy);

		// 归一化方向向量
		float nx = dx / distance;
		float ny = dy / distance;

		float offsetX = nx;
		float offsetY = ny;
		GameObject* bullet = new GameObject(x1 + offsetX, y1 + offsetY, texture->getWidth(), texture->getHeight(), ENEMY_BULLET);
		// 设置子弹的速度和方向
		bullet->setVector_x(nx);
		bullet->setVector_y(ny);
		RenderObject* vao = new RenderObject(bullet->getVao());
		addGameObject(bullet, vao, texture, ENEMY_BULLET);
	}
}
void createEnemyBullet(std::vector<objectStruct*> enemyCreature, GameObject* emitter, Texture* texture) {
	if (enemyBullet.size() < MaxEnemyBullet) {
		// 假设enemyCreature是一个包含敌人的容器
		GameObject* enemy;
		for (auto obj : enemyCreature) {
			if (obj->gameObject->getGameObject() == ENEMY)
				enemy = obj->gameObject;
		}

		// 获取敌人的中心
		float x1 = enemy->getCenter_x();
		float y1 = enemy->getCenter_y();

		// 发射点的位置
		float x2 = emitter->getCenter_x();
		float y2 = emitter->getCenter_y();

		// 计算方向向量
		float dx = x2 - x1;
		float dy = y2 - y1;
		float distance = sqrt(dx * dx + dy * dy);

		// 归一化方向向量
		float nx = dx / distance;
		float ny = dy / distance;

		float offsetX = nx; 
		float offsetY = ny;
			// 设置子弹的速度和方向
		
			RenderObject* vao = new RenderObject(new GameObject(x1 + offsetX, y1 + offsetY, texture->getWidth(), texture->getHeight(), ENEMY_BULLET));
			vao->getGameObj()->setVector_x(nx);
			vao->getGameObj()->setVector_y(ny);
			addGameObject(vao->getGameObj(), vao, texture, ENEMY_BULLET);
	}
}
//在渲染管线的添加游戏对象
void addGameObject(GameObject* game, RenderObject* vao, Texture* texture, int object) {

	if (object == BULLET&&playerBullet.size()<= MaxPlayerBullet) {
		struct objectStruct* obj = new objectStruct();
		obj->du = -1;
		obj->gameObject = game;
		obj->texture = texture;
		obj->vao = vao;
		playerBullet.push_back(obj);
	}
	else if(object == BULLET){
		delete game;
		delete vao;
	}
	if (object == ENEMY_BULLET&& enemyBullet.size()< MaxEnemyBullet) {
		struct objectStruct* obj = new objectStruct();
		obj->du = -1;
		obj->gameObject = game;
		obj->texture = texture;
		obj->vao = vao;
		enemyBullet.push_back(obj);
	}
	else if(object == ENEMY_BULLET){
		delete game;
		delete vao;
	}
}
void addGameObject(GameObject* game, RenderObject* vao, Texture* texture, bool loop, GameObject* loopObject, float du, bool comtext, int object) {
	if (enemyCreature.size()<100) {
		if (object == ENEMY && texture != nullptr) {
			struct objectStruct* obj = new objectStruct();
			obj->du = du;
			obj->default_du = du;
			obj->gameObject = game;
			obj->texture = texture;
			obj->comtext = comtext;
			obj->loopObject = loopObject;
			obj->vao = vao;
			obj->loop = loop;
			enemyCreature.push_back(obj);
		}
		if (object == ENEMY && texture == nullptr) {
			struct objectStruct* obj = new objectStruct();
			obj->du = du;
			obj->default_du = du;
			obj->gameObject = game;
			obj->texture = air;
			obj->comtext = comtext;
			obj->loopObject = loopObject;
			obj->vao = vao;
			obj->loop = loop;
			enemyCreature.push_back(obj);
		}
	}
	else {
		delete game;
		delete vao;
	}
}
void setActivite(int a) {
	activite = a;
}
int getActivite() {
	return activite;
}