#include"uv.h"
UV::UV() {
	float uvs[] = {0};
	glGenBuffers(1, &uv);
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
}
UV::UV(bool text) {
	float uvs[] = {
		0
	};
	glGenBuffers(1, &uv);
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
}
UV::~UV() {
	glDeleteBuffers(1, &uv);
}
void UV::bindUV() {
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
}
GLuint UV::getUV() {
	return uv;
}