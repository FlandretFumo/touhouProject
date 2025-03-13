#pragma once
#include"../../golb.h"
class Texture {
public:
	Texture();
	Texture(std::string path, int unit);
	Texture(const char* text_c, int size, int R, int G, int B, int unit_S);
	~Texture();
	float getR();
	float getG();
	float getB();
	int getType();
	int getImage(std::string path);
	int getWidth();
	int getHeight();
	unsigned char* getData();
	int getUnit();
	int bind();
	struct BitmapData {
		int width;
		int height;
		std::vector<unsigned char> data;
	};
	BitmapData CreateFontBitmap(const char* fontFace, int fontSize, const char* text, int R, int G, int B);
private:
	int width{0};
	int height{0};
	int channels{0};
	GLuint aTexture;
	unsigned char* imageData =nullptr;
	int unit;
	float R;
	float G;
	float B;
	int type;
};