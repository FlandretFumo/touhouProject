#pragma once
#include"../../golb.h"
class EBO {
public:
	EBO();
	~EBO();
	GLuint bindEBO();
	GLuint getEBO();
private:
	GLuint ebo;
};