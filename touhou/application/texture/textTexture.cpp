#include"textTexture.h"
TextTexture::TextTexture() {

}
void TextTexture::createText(Texture** mTextTexture, char* text) {
	data = new TextTexture::BitmapData;
	textTextureData.push_back(data);
	c = text;
	*data = CreateFontBitmap("Arial", 24, 5,text);
	//*mTextTexture = new Texture(data->data.data(), data->width, data->height, 0);
}


TextTexture::~TextTexture() {
	textTextureData.clear();
	textTextureData.shrink_to_fit();
	delete[] data;
}
TextTexture::BitmapData* TextTexture::getData(int value) {
	return textTextureData.at(value);
}
int TextTexture::getSize() {
	size = textTextureData.size();
	return size;
}
char* TextTexture::getChar() {
	return c;
}
TextTexture::BitmapData TextTexture::CreateFontBitmap(const char* fontFace, int fontSize, int charSpacing, const char* text) {
	HDC hdc = GetDC(NULL); // 获取屏幕设备上下文
	if (!hdc) {
		// 错误处理
		throw std::runtime_error("Failed to get device context.");
	}
	HFONT hFont = CreateFont(
		fontSize,			// 字体高度
		0,                  // 字体宽度（0表示自动计算）
		0,                  // 字体倾斜角度
		0,                  // 字体加粗
		FW_NORMAL,          // 字体粗细
		FALSE,              // 是否斜体
		FALSE,              // 是否下划线
		FALSE,              // 是否删除线
		DEFAULT_CHARSET,    // 字符集
		OUT_DEFAULT_PRECIS, // 输出精度
		CLIP_DEFAULT_PRECIS,// 剪裁精度
		DEFAULT_QUALITY,    // 输出质量
		DEFAULT_PITCH | FF_SWISS, // 字体间距和族
		(const char*)fontFace // 字体名称
	);

	if (!hFont) {
		// 错误处理
		ReleaseDC(NULL, hdc);
		throw std::runtime_error("Failed to create font.");
	}

	HGDIOBJ oldFont = SelectObject(hdc, hFont);

	SIZE size;
	if (!GetTextExtentPoint32(hdc, text, strlen(text), &size)) {
		// 错误处理
		SelectObject(hdc, oldFont);
		DeleteObject(hFont);
		ReleaseDC(NULL, hdc);
		throw std::runtime_error("Failed to get text extent.");
	}

	int bitmapWidth = size.cx;
	int bitmapHeight = size.cy;

	// 创建一个兼容的内存设备上下文
	HDC hdcMem = CreateCompatibleDC(hdc);
	if (!hdcMem) {
		// 错误处理
		SelectObject(hdc, oldFont);
		DeleteObject(hFont);
		ReleaseDC(NULL, hdc);
		throw std::runtime_error("Failed to create compatible memory DC.");
	}

	HBITMAP hBitmap = CreateCompatibleBitmap(hdc, bitmapWidth, bitmapHeight);
	if (!hBitmap) {
		// 错误处理
		DeleteDC(hdcMem);
		SelectObject(hdc, oldFont);
		DeleteObject(hFont);
		ReleaseDC(NULL, hdc);
		throw std::runtime_error("Failed to create compatible bitmap.");
	}

	HGDIOBJ oldBitmap = SelectObject(hdcMem, hBitmap);

	// 设置文本颜色和背景颜色
	SetTextColor(hdcMem, RGB(255, 255, 255)); // 白色文本
	SetBkColor(hdcMem, RGB(0, 0, 0));         // 黑色背景
	SetBkMode(hdcMem, TRANSPARENT);           // 透明背景模式

	// 将文本绘制到内存设备上下文中
	RECT rect = { 0, 0, bitmapWidth, bitmapHeight };
	if (!DrawText(hdcMem, text, strlen(text), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE)) {
		// 错误处理
		SelectObject(hdcMem, oldBitmap);
		DeleteObject(hBitmap);
		DeleteDC(hdcMem);
		SelectObject(hdc, oldFont);
		DeleteObject(hFont);
		ReleaseDC(NULL, hdc);
		throw std::runtime_error("Failed to draw text.");
	}

	// 获取位图数据
	BITMAPINFOHEADER bi;
	memset(&bi, 0, sizeof(BITMAPINFOHEADER));
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = bitmapWidth;
	bi.biHeight = -bitmapHeight; // 负值表示位图数据是从底部开始的
	bi.biPlanes = 1;
	bi.biBitCount = 32;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;

	std::vector<unsigned char> bitmapData(bitmapWidth * bitmapHeight * 4); // 32位色深，每个像素4字节

	if (!GetDIBits(hdcMem, hBitmap, 0, bitmapHeight, bitmapData.data(), (BITMAPINFO*)&bi, DIB_RGB_COLORS)) {
		// 错误处理
		SelectObject(hdcMem, oldBitmap);
		DeleteObject(hBitmap);
		DeleteDC(hdcMem);
		SelectObject(hdc, oldFont);
		DeleteObject(hFont);
		ReleaseDC(NULL, hdc);
		throw std::runtime_error("Failed to get DIBits.");
	}

	// 清理资源
	SelectObject(hdcMem, oldBitmap);
	DeleteObject(hBitmap);
	DeleteDC(hdcMem);
	SelectObject(hdc, oldFont);
	ReleaseDC(NULL, hdc);
	DeleteObject(hFont);

	TextTexture::BitmapData result = { bitmapWidth, bitmapHeight, bitmapData };
	return result;
}



