#pragma once
#include"../../golb.h"
#include"texture.h"
#include <windows.h>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring> // for strlen


class TextTexture{
public:
	TextTexture();
	~TextTexture();
	void createText(Texture** mTextTexture, char* text);
	struct BitmapData {
		int width;
		int height;
		std::vector<unsigned char> data;
	};
	char* c;
	int getSize();
	unsigned char *data_c;
	BitmapData* getData(int value);
	BitmapData CreateFontBitmap(const char* fontFace, int fontSize, int charSpacing, const char* text);
	char * getChar();
private:
	std::vector<BitmapData*> textTextureData;
	int size;
	BitmapData* data;
};