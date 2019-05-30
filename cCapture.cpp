#include "stdafx.h"
#include "cCapture.h"


cCapture::cCapture()
{
	hdc = GetDC(NULL);
}

cCapture::~cCapture()
{
}

bool cCapture::WindowCapture(HBITMAP hBit,LPWSTR Path)
{
	GetObject(hBit, sizeof(BITMAP), &bit);

	ih.biSize = sizeof(BITMAPINFOHEADER);

	ih.biWidth = bit.bmWidth;

	ih.biHeight = bit.bmHeight;

	ih.biPlanes = 1;

	ih.biBitCount = bit.bmPlanes * bit.bmBitsPixel;

	if (ih.biBitCount > 8) ih.biBitCount = 24;

	ih.biCompression = BI_RGB;

	ih.biSizeImage = 0;

	ih.biXPelsPerMeter = 0;

	ih.biYPelsPerMeter = 0;

	ih.biClrUsed = 0;

	ih.biClrImportant = 0;

	PalSize = (ih.biBitCount == 24 ? 0 : 1 << ih.biBitCount) * sizeof(RGBQUAD);

	pih = (BITMAPINFO *)malloc(ih.biSize + PalSize);

	pih->bmiHeader = ih;

	GetDIBits(hdc, hBit, 0, bit.bmHeight, NULL, pih, DIB_RGB_COLORS);
	ih = pih->bmiHeader;

	if (ih.biSizeImage == 0) {

		ih.biSizeImage = ((((ih.biWidth*ih.biBitCount) + 31) & ~31) >> 3) * ih.biHeight;

	}

	Size = ih.biSize + PalSize + ih.biSizeImage;

	pih = (BITMAPINFO *)realloc(pih, Size);

	GetDIBits(hdc, hBit, 0, bit.bmHeight, (PBYTE)pih + ih.biSize + PalSize, pih, DIB_RGB_COLORS);

	fh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + PalSize;

	fh.bfReserved1 = 0;

	fh.bfReserved2 = 0;

	fh.bfSize = Size + sizeof(BITMAPFILEHEADER);

	fh.bfType = 0x4d42;

	hFile = CreateFile(Path, GENERIC_WRITE, 0, NULL,

		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(hFile, &fh, sizeof(fh), &dwWritten, NULL);

	WriteFile(hFile, pih, Size, &dwWritten, NULL);

	ReleaseDC(NULL, hdc);

	CloseHandle(hFile);

	return true;
}

HBITMAP cCapture::FocusScreenCapture()
{

	HDC hScrDC, hMemDC;

	HBITMAP hBitmap;

	RECT rt;

	//포커스를 가진 윈도우의 정보를 얻음.

	//GetWindowRect(m_hwnd, &rt);

	//rt.left = max(0, rt.left);

	//rt.top = max(0, rt.top);

	//rt.right = min(rt.right, GetSystemMetrics(SM_CXSCREEN));

	//rt.bottom = min(rt.bottom, GetSystemMetrics(SM_CYSCREEN));

 	rt.left = 200;
	rt.top = 200;
	rt.right = 480;
	rt.bottom = 720;

	//화면 전체 DC를 얻는다.

	hScrDC = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);

	hMemDC = CreateCompatibleDC(hScrDC);

	hBitmap = CreateCompatibleBitmap(hScrDC, rt.right - rt.left, rt.bottom - rt.top);

	SelectObject(hMemDC, hBitmap);

	//메모리 DC에 화면 DC를 복사 받는다.

	BitBlt(hMemDC, 0, 0, rt.right - rt.left, rt.bottom - rt.top, hScrDC, rt.left, rt.top, SRCCOPY);



	DeleteDC(hMemDC);

	DeleteDC(hScrDC);

	return hBitmap;
}

HBITMAP cCapture::FullScreenCapture()
{

	//전체 화면 크기 구함

	int ScreenWidth = GetSystemMetrics(SM_CXSCREEN);

	int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);



	HDC hScrDC, hMemDC;

	HBITMAP hBitmap;

	//화면 전체 DC를 얻음

	hScrDC = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);

	hMemDC = CreateCompatibleDC(hScrDC);

	hBitmap = CreateCompatibleBitmap(hScrDC, ScreenWidth, ScreenHeight);

	SelectObject(hMemDC, hBitmap);



	//메모리 DC에 화면 DC를 복사 받는다.

	BitBlt(hMemDC, 0, 0, ScreenWidth, ScreenHeight, hScrDC, 0, 0, SRCCOPY);



	DeleteDC(hMemDC);

	DeleteDC(hScrDC);



	return hBitmap;

}

void cCapture::Init(HWND hWnd)
{
}

wchar_t* cCapture::ConverCtoWC(char* str)
{
	//wchar_t형 변수 선언
	wchar_t* pStr;
	//멀티 바이트 크기 계산 길이 반환
	int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);

	//wchar_t 메모리 할당
	pStr = new WCHAR[strSize];
	//형 변환
	MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, pStr, strSize);

	return pStr;
}