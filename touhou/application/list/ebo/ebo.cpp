#include"ebo.h"
EBO::EBO() {
	unsigned int indices[] = {
	0, 1, 2,
	2, 1, 3
	};
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}
EBO::~EBO() {
	glDeleteBuffers(1, &ebo);
}
GLuint EBO::bindEBO() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	return ebo;
}
GLuint EBO::getEBO() {
	return ebo;
}