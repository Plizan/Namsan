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
	//프레임 , 애니메이션을 위한 것이다.
	m_PlayerFrame = new cFrame;

	//SetFrame은 순서대로 시작 프레임, 끝 프레임, 딜레이값을 받는다.
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

	//이미지 출력 방법 : cLoadScene에서 추가한 이미지를 사용한다.
	//IMAGE->FindImage("이름")을 하여 이미지를 찾을 수 있다.
	//IMAGE->Render(이미지, 좌표, true = 이미지의 중심을 중앙으로 설정, 제거할 컬러키);
	IMAGE->Render(IMAGE->FindImage("BackGround"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage("HHHHH")->FindImage(0), Pos, true, RGB(255, 0, 255));
}

void cIngameScene::Release()
{
	//프레임은 꼭 Release에서 제거해야 한다.
	SAFE_DELETE(m_PlayerFrame);
}
