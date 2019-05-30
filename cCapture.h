#pragma once
#include "singleton.h"

class cCapture : public singleton<cCapture>
{
private:
	HWND m_hwnd;

	BITMAPFILEHEADER fh;

	BITMAPINFOHEADER ih;

	BITMAP bit;

	BITMAPINFO *pih;

	int PalSize;

	HANDLE hFile;

	DWORD dwWritten, Size;

	HDC hdc;

public:
	cCapture();
	virtual ~cCapture();

	bool WindowCapture(HBITMAP, LPWSTR);
	HBITMAP FocusScreenCapture();
	HBITMAP FullScreenCapture();

	void Init(HWND hWnd);

	wchar_t* ConverCtoWC(char* str);
};

#define CAPTURE cCapture::GetInstance()