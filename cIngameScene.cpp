#include "stdafx.h"
#include "cIngameScene.h"


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

	//������ , �ִϸ��̼��� ���� ���̴�.
	m_PlayerFrame = new cFrame;

	//SetFrame�� ������� ���� ������, �� ������, �����̰��� �޴´�.
	m_PlayerFrame->SetFrame(0, 2, 50);

	m_Button[0] = new cButton(100,200,"Button_start");
	m_Button[1] = new cButton(100,500,"Button_Info");

	m_Button[0]->Init();
	m_Button[1]->Init();
	
}

void cIngameScene::Update()
{

	//Game_main = game;
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

		
	
		
	



}


void cIngameScene::Render()
{

	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;
	//game = Game_main;
	//Point 
	//�̹��� ��� ��� : cLoadScene���� �߰��� �̹����� ����Ѵ�.
	//IMAGE->FindImage("�̸�")�� �Ͽ� �̹����� ã�� �� �ִ�.
	//IMAGE->Render(�̹���, ��ǥ, true = �̹����� �߽��� �߾����� ����, ������ �÷�Ű);
	
			IMAGE->Render(IMAGE->FindImage("game"), m_BackGroundPos, false);
		m_Button[0]->Render();
		m_Button[1]->Render();

	
}

void cIngameScene::Release()
{
	//�������� �� Release���� �����ؾ� �Ѵ�.
	SAFE_DELETE(m_PlayerFrame);
	SAFE_DELETE(m_Button[0]);
	SAFE_DELETE(m_Button[1]);

}



