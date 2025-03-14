#pragma once
#include"texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"
Texture::Texture() {
};
Texture::Texture(std::string path,int unit_S) {
	getImage(path);
	unit = unit_S;
	if (imageData!=nullptr) {
		glCreateTextures(GL_TEXTURE_2D, 1, &aTexture);
		glBindTexture(GL_TEXTURE_2D, aTexture);
		//glActiveTexture(GL_TEXTURE0 + unit);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        stbi_image_free(imageData);
	}
}
Texture::Texture(const char* text_c,int size, int R,int G,int B,int unit_S) {
    imageData = nullptr;
		unit = unit_S;
        this->R = R * (1.0 / 255);
        this->G = G * (1.0 / 255);
        this->B = B * (1.0 / 255);
        type = TEXT;
		struct Texture::BitmapData textImageData = CreateFontBitmap("Arial", size, text_c,255,255,255);
		width = textImageData.width;
		height = textImageData.height;
		
		glCreateTextures(GL_TEXTURE_2D, 1, &aTexture);
		glBindTexture(GL_TEXTURE_2D, aTexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textImageData.width, textImageData.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textImageData.data.data());

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
Texture::~Texture() {
	glDeleteTextures(1, &aTexture);

}
int Texture::getImage(std::string path) {
	imageData = nullptr;
	std::filesystem::path file = path.c_str();
	if (std::filesystem::exists(file)) {
		stbi_set_flip_vertically_on_load(true);
		imageData = stbi_load(path.c_str(), &width, &height, &channels, STBI_rgb_alpha);
	}
	else {
		std::cout << path.c_str()<<"文件不存在" << std::endl;
		stbi_set_flip_vertically_on_load(true);
		imageData = stbi_load("assets/textures/default.png", &width, &height, &channels, STBI_rgb_alpha);
	}
	return 0;
}
int Texture::getWidth() {
	return width;
}
int  Texture::getHeight() {
	return height;
}
unsigned char* Texture::getData() {
	return imageData;
}

int Texture::getUnit() {
	return unit;
}
int Texture::bind() {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, aTexture);
	return aTexture;
}
float Texture::getR() {
    return R;

}
float Texture::getG() {
    return G;

}
float Texture::getB() {
    return B;
}
int Texture::getType() {
    return type;
}
Texture::BitmapData Texture::CreateFontBitmap(const char* fontFace, int fontSizePixels, const char* text, int R, int G, int B) {
    HDC hdc = GetDC(NULL);
    if (!hdc) {
        throw std::runtime_error("Failed to get device context.");
    }

    // 获取设备的DPI设置
    int dpiX = GetDeviceCaps(hdc, LOGPIXELSX);
    int dpiY = GetDeviceCaps(hdc, LOGPIXELSY);

    // 计算逻辑单位字体大小
    int fontSizeLogical = MulDiv(fontSizePixels, 72, dpiY);

    HFONT hFont = CreateFont(
        fontSizeLogical, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, fontFace
    );
    if (!hFont) {
        ReleaseDC(NULL, hdc);
        throw std::runtime_error("Failed to create font.");
    }

    // 创建一个兼容的内存DC
    HDC hdcMem = CreateCompatibleDC(hdc);
    if (!hdcMem) {
        DeleteObject(hFont);
        ReleaseDC(NULL, hdc);
        throw std::runtime_error("Failed to create compatible memory DC.");
    }

    // 设置字体到内存DC
    SelectObject(hdcMem, hFont);

    // 计算文本大小
    SIZE textSize;
    if (!GetTextExtentPoint32(hdcMem, text, strlen(text), &textSize)) {
        DeleteObject(hdcMem);
        DeleteObject(hFont);
        ReleaseDC(NULL, hdc);
        throw std::runtime_error("Failed to get text extent.");
    }

    // 创建位图
    int bitmapWidth = textSize.cx + 16; // 加一些边距
    int bitmapHeight = textSize.cy + 16;
    HBITMAP hBitmap = CreateCompatibleBitmap(hdc, bitmapWidth, bitmapHeight);
    if (!hBitmap) {
        DeleteObject(hdcMem);
        DeleteObject(hFont);
        ReleaseDC(NULL, hdc);
        throw std::runtime_error("Failed to create bitmap.");
    }

    // 选择位图到内存DC
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, hBitmap);

    // 设置背景色为黑色
    RECT rect = { 0, 0, bitmapWidth, bitmapHeight };
    FillRect(hdcMem, &rect, (HBRUSH)(COLOR_BTNFACE + 1)); // COLOR_BTNFACE + 1 通常是白色，但这里我们直接使用黑色RGB(0,0,0)的HBRUSH
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
    FillRect(hdcMem, &rect, hBrush);
    DeleteObject(hBrush);

    // 设置文本颜色
    COLORREF textColor = RGB(R, G, B);
    SetTextColor(hdcMem, textColor);

    // 绘制文本
    SetBkMode(hdcMem, TRANSPARENT);
    TextOut(hdcMem, 8, 8, text, strlen(text));

    // 获取位图数据
    BITMAPINFOHEADER bi;
    ZeroMemory(&bi, sizeof(bi));
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = bitmapWidth;
    bi.biHeight = bitmapHeight; // 正值表示顶部为原点
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = dpiX;
    bi.biYPelsPerMeter = dpiY;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    std::vector<BYTE> bitmapData(bitmapWidth * bitmapHeight * 4); // 32位位图，每个像素4字节
    if (!GetDIBits(hdcMem, hBitmap, 0, bitmapHeight, bitmapData.data(), (BITMAPINFO*)&bi, DIB_RGB_COLORS)) {
        throw std::runtime_error("Failed to get bitmap data.");
    }

    // 恢复原始对象
    SelectObject(hdcMem, hOldBitmap);
    DeleteObject(hBitmap);
    DeleteObject(hdcMem);
    DeleteObject(hFont);
    ReleaseDC(NULL, hdc);

    BitmapData result = { bitmapWidth, bitmapHeight, bitmapData };
    return result;
}