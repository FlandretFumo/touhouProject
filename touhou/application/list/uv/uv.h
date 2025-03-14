#pragma once
#include"../../golb.h"
class UV {
public:
	UV();
	UV(bool text);
	~UV();
	void bindUV();
	GLuint getUV();
private:
	GLuint uv;
};