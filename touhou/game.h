#pragma once
#include"golb.h"

#include"math.h"
#define MOVE 0.05
#define LEFT -10000
#define RIGHT 10000
#define UP 20000
#define DOWN 30000
#define QUIT 40000
#define KEEP 47183
#define START 666666
#define VOLUME 111111
#define SETTINGS 999999
#define TARGET 10

#define TITLE 9999
#define SELECT 1111
#define STOP  2222
#define GAME 6666
#define GAME_STOP 3214
#define PLAYER_DEAD 557852

#define MaxEnemyBullet 999999 
#define MaxPlayerBullet 50

#define FILE_HEAT 2314979329822781300

#define FILE_END 2314979329822781300


void setActivite(int a);
int getActivite();
void gameLogic(GLFWwindow* window);
void initializeGame();
void allRenderEvent();
void titleActivite();
void playerEvent(GLFWwindow* window); 
void EnemyEvent();
void rend(Shader* shader, RenderObject* vao, Texture* mTexture);
void keyEvent(int key);
void gameObjectEvent();
void ToSting(int v,int length, std::vector<Texture*>* numberList_s);

void addGameObject(GameObject* game, RenderObject* vao, Texture* texture, bool loop, GameObject* loopObject, float du, bool comtext, int object);
void addGameObject(GameObject* game, RenderObject* vao, Texture* texture, int object);
void loop(std::vector<objectStruct*> gameStruct, bool off);
void barrage(std::vector<objectStruct*> gameStruct);
void createPlayerBullet();
void prepareCamera();
void tice(float ms, std::atomic<bool>* obj);
void prepareOrtho();
bool isRun();
void mouseClick(int x, int y);
void click(bool c,int key);
bool getClick();
void clearGame();