#pragma once
#include"../../golb.h"
#include"../../application/list/uv/uv.h"
#include"../../application/list/vbo/vbo.h"
#include"../../application/list/ebo/ebo.h"
#define NO_VEO ((GLuint)-1)
class RenderObject {
public:
	RenderObject(GLuint aVbo);
	RenderObject::RenderObject(GameObject* obj);
	RenderObject::RenderObject(GameObject* obj,bool main);
	GameObject* getGameObj();
	~RenderObject();
	int bind();
	int unbind();
private:
	bool mainClass = true;
	GLuint vao{0};
	GLuint uv;
	GLuint ebo;
	GameObject* obj = nullptr; 
	bool gameobj = false;
};