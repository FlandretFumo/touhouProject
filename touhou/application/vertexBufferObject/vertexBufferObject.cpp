#include"vertexVBO.h"

VBO::VBO() {

}
VBO::~VBO() {

}
int VBO::createVBO() {
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_VERTEX_ARRAY, vbo);
	//glBufferData(GL_VERTEX_ARRAY,);
	return  0;
}