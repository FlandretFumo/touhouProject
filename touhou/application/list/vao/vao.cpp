#include"vao.h"
RenderObject::RenderObject(GLuint aVbo) {
	gameobj = false;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, aVbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
	obj = nullptr;
	
	glGenBuffers(1, &uv);
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	float uvs[] = {
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 0.0f};
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
	

	unsigned int indices[] = {
	0, 1, 2,
	2, 1, 3
	};
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindVertexArray(0);
}
RenderObject::RenderObject(GameObject*  obj) {
	gameobj = true;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, obj->getVao());
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

	this->obj = obj;
	glGenBuffers(1, &uv);
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	float uvs[] = {
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 0.0f };
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);


	unsigned int indices[] = {
	0, 1, 2,
	2, 1, 3
	};
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindVertexArray(0);
}
RenderObject::RenderObject(GLuint aVbo, bool text) {
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, aVbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

	GLuint uv;
	glGenBuffers(1, &uv);
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	float uvs[] = {
		1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 0.0f// 第一个顶点的 U 从 0.0f 变为 1.0f，第二个顶点的 U 从 1.0f 变为 0.0f
 // 第三个顶点的 U 从 0.0f 变为 1.0f，第四个顶点的 U 从 1.0f 变为 0.0f
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, GL_ARRAY_BUFFER);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, uv);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBindVertexArray(0);
}

RenderObject::~RenderObject(){
	glDeleteBuffers(1, &uv);
	glDeleteBuffers(1, &ebo);
	glDeleteVertexArrays(1, &vao);
	delete obj;

}
int RenderObject::bind() {
	glBindVertexArray(vao);
	return 0;
}
int RenderObject::unbind() {
	glBindVertexArray(0);
	return 0;
}
GameObject* RenderObject::getGameObj() {
	return obj;
}
