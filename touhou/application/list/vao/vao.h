#pragma once
#include"../../golb.h"
#include"../../application/list/uv/uv.h"
#include"../../application/list/vbo/vbo.h"
#include"../../application/list/ebo/ebo.h"
#define NO_VEO ((GLuint)-1)
class RenderObject {
public:
	RenderObject(GLuint aVbo);
	RenderObject(GLuint aVbo,bool text);
	RenderObject::RenderObject(GameObject* obj);
	GameObject* getGameObj();
	~RenderObject();
	int bind();
	int unbind();
private:
	GLuint vao{0};
	GLuint uv;
	GLuint ebo;
	GameObject* obj = nullptr; 
	bool gameobj = false;
};