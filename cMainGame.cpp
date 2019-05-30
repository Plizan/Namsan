#include "stdafx.h"
#include "cMainGame.h"
#include "Ingame_game.h"
#include "cLoadScene.h"
#include "cIngameScene.h"
#include "cIngame_start.h"
#include "cIngame_Info.h"
cMainGame::cMainGame()
{
}


cMainGame::~cMainGame()
{
}

void cMainGame::Init(HWND hWnd)
{
	m_hWnd = hWnd;

	m_hDC = GetDC(m_hWnd);

	//m_hBackBuffer = CreateCompatibleDC(m_hDC);
	//m_hBitmap = LoadBitmap(m_hIns, MAKEINTRESOURCE(m_hBackBuffer));//CreateCompatibleBitmap(m_hDC, D_SCREEN_WIDTH, D_SCREEN_HEIGHT);
	//SelectObject(m_hBackBuffer, (HBITMAP)m_hBitmap);
	//ReleaseDC(m_hWnd, m_hDC);

	//SetTimer(m_hWnd, 0, 10, NULL);

	SetTimer(m_hWnd, 0, 1000, NULL);

	IMAGE->Init();

	//Init 에서 Scene을 추가시켜준다 순서대로 이름, Scene 클래스
	SCENE->AddScene("Load", new cLoadScene);
	SCENE->AddScene("Ingame", new cIngameScene);
	SCENE->AddScene("Ingame_start", new cIngame_start);
	SCENE->AddScene("Ingame_Info", new cIngame_Info);
	//처음으로 보여줄 씬으로 바꾼다
	SCENE->ChangeScene("Load");

}

void cMainGame::Update()
{
	SCENE->Update();
	INPUT->Update();
	Count++;
}

void cMainGame::Render()
{
	HDC hdc = GetDC(m_hWnd);
	HDC m_MemDC;
	HBITMAP hBitmap;
	HBITMAP OldBitMap;

	RECT WindowRect;
	GetClientRect(m_hWnd, &WindowRect);

	m_MemDC = CreateCompatibleDC(hdc);
	hBitmap = CreateCompatibleBitmap(hdc, WindowRect.right, WindowRect.bottom);
	OldBitMap = (HBITMAP)SelectObject(m_MemDC, hBitmap);


	IMAGE->InputHDC(m_MemDC);
	SCENE->Render();

	BitBlt(hdc, 0, 0, WindowRect.right, WindowRect.bottom, m_MemDC, 0, 0, SRCCOPY);
	DeleteObject(SelectObject(m_MemDC, OldBitMap));
	DeleteDC(m_MemDC);

}

void cMainGame::Release()
{
	KillTimer(m_hWnd, 0);

	cImageManager::ResetInstance();
	cInputManager::ResetInstance();
	cSceneManager::ResetInstance();
}

void cMainGame::InputHDC(HDC hdc)
{
	m_hDC = hdc;
}

void cMainGame::InputHINSTANCE(HINSTANCE hinstance)
{
	m_hIns = hinstance;
}
