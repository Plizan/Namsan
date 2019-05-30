#include "stdafx.h"
#include "cIngameScene.h"

#pragma warning(disable:4996)

cIngameScene::cIngameScene()
{
}


cIngameScene::~cIngameScene()
{
}

void cIngameScene::Init()
{
	Pos.x = 0;
	Pos.y = 0;
	b_Move = false;

	imageNum = 0;
	//������ , �ִϸ��̼��� ���� ���̴�.
	m_PlayerFrame = new cFrame;

	//SetFrame�� ������� ���� ������, �� ������, �����̰��� �޴´�.
	m_PlayerFrame->SetFrame(0, 2, 50);
}

void cIngameScene::Update()
{
	m_PlayerFrame->Frame();

	INPUT->GetMousePos().x;
	INPUT->GetMousePos().y;
	if (INPUT->KeyPress(VK_UP)) {
		Pos.y -= 10;
	}
	if (INPUT->KeyPress(VK_DOWN)) {
		Pos.y += 10;
	}
	if (INPUT->KeyPress(VK_RIGHT)) {
		Pos.x += 10;
	}
	if (INPUT->KeyPress(VK_LEFT)) {
		Pos.x -= 10;
	}
	if (INPUT->KeyDown(VK_SPACE)) {

		DEBUG_LOG("Space");

		imageNum++;

		char temp[30];
		sprintf(temp, "./Capture/%d Model.bmp", imageNum);

		CAPTURE->WindowCapture(CAPTURE->FocusScreenCapture(), CAPTURE->ConverCtoWC(temp));
	}
}

void cIngameScene::Render()
{
	Point m_BackGroundPos;
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;

	//�̹��� ��� ��� : cLoadScene���� �߰��� �̹����� ����Ѵ�.
	//IMAGE->FindImage("�̸�")�� �Ͽ� �̹����� ã�� �� �ִ�.
	//IMAGE->Render(�̹���, ��ǥ, true = �̹����� �߽��� �߾����� ����, ������ �÷�Ű);
	IMAGE->Render(IMAGE->FindImage("BackGround"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage("HHHHH")->FindImage(0), Pos, true, RGB(255, 0, 255));
}

void cIngameScene::Release()
{
	//�������� �� Release���� �����ؾ� �Ѵ�.
	SAFE_DELETE(m_PlayerFrame);
}
