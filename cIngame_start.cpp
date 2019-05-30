#include "stdafx.h"



cIngame_start::cIngame_start()
{
}


cIngame_start::~cIngame_start()
{
}

void cIngame_start::Init()
{
	//m_Button[1] = new cButton(100, 500, "Button_start");
	m_Button[0] = new cButton(0,0, "Button_start");


	m_Button[0]->Init();
}

void cIngame_start::Update()
{
	INPUT->GetMousePos().x;
	INPUT->GetMousePos().y;

	if (m_Button[0]->Update())
	{
		DEBUG_LOG("c");
		SCENE->ChangeScene("Ingame");
	}

}

void cIngame_start::Render()
{
	Pos.x = 0;
	Pos.y = 0;


	IMAGE->Render(IMAGE->FindImage("game_start"), Pos, false);
	m_Button[0]->Render();
}

void cIngame_start::Release()
{
	SAFE_DELETE(m_Button[0]);
}
