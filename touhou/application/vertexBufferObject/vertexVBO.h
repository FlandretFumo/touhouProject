#pragma once
#include"../../golb.h"
class VBO {
public:
	VBO();
	~VBO();
	int createVBO();
private:
	float* postion;
	GLuint vbo;
};