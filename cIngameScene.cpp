#include "stdafx.h"
#include "cIngameScene.h"

#pragma warning(disable:4996)

Point m_BackGroundPos;

INT game = 10002;

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

	m_Button[0] = new cButton(100,200,"Button_start");
	m_Button[1] = new cButton(100,500,"Button_Info");

	m_Button[0]->Init();
	m_Button[1]->Init();
	
}

void cIngameScene::Update()
{
<<<<<<< HEAD

	//Game_main = game;
=======
	m_PlayerFrame->Frame();

>>>>>>> 2da323efcff4d33a78ab8e13dc778d25bcd24ead
	INPUT->GetMousePos().x;
	INPUT->GetMousePos().y;

	
	if (m_Button[0]->Update())
	{	
		DEBUG_LOG("c");
		SCENE->ChangeScene("Ingame_start");
	}
	if (m_Button[1]->Update())
	{
		DEBUG_LOG("c");
		SCENE->ChangeScene("Ingame_Info");
	}
<<<<<<< HEAD

		
	
		
	



=======
	if (INPUT->KeyDown(VK_SPACE)) {

		DEBUG_LOG("Space");

		imageNum++;

		char temp[30];
		sprintf(temp, "./Capture/%d Model.bmp", imageNum);

		CAPTURE->WindowCapture(CAPTURE->FocusScreenCapture(), CAPTURE->ConverCtoWC(temp));
	}
>>>>>>> 2da323efcff4d33a78ab8e13dc778d25bcd24ead
}


void cIngameScene::Render()
{

	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;
	//game = Game_main;
	//Point 
	//이미지 출력 방법 : cLoadScene에서 추가한 이미지를 사용한다.
	//IMAGE->FindImage("이름")을 하여 이미지를 찾을 수 있다.
	//IMAGE->Render(이미지, 좌표, true = 이미지의 중심을 중앙으로 설정, 제거할 컬러키);
<<<<<<< HEAD
	
			IMAGE->Render(IMAGE->FindImage("game"), m_BackGroundPos, false);
		m_Button[0]->Render();
		m_Button[1]->Render();

	
=======
	IMAGE->Render(IMAGE->FindImage("BackGround"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage("HHHHH")->FindImage(0), Pos, true, RGB(255, 0, 255));
>>>>>>> 2da323efcff4d33a78ab8e13dc778d25bcd24ead
}

void cIngameScene::Release()
{
	//프레임은 꼭 Release에서 제거해야 한다.
	SAFE_DELETE(m_PlayerFrame);
	SAFE_DELETE(m_Button[0]);
	SAFE_DELETE(m_Button[1]);

}



