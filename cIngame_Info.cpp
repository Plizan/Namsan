#include "stdafx.h"



cIngame_Info::cIngame_Info()
{
}


cIngame_Info::~cIngame_Info()
{
}

void cIngame_Info::Init()
{
	m_Button = new cButton(0, 0, "Button_Info");
	m_Button->Init();
	
}

void cIngame_Info::Update()
{
	if (m_Button->Update())
	{
		DEBUG_LOG("c");
		SCENE->ChangeScene("Ingame");
	}
}

void cIngame_Info::Render()
{
	Pos.x = 0;
	Pos.y = 0;
	IMAGE->Render(IMAGE->FindImage("game_Info"), Pos, false);
	m_Button->Render();
}

void cIngame_Info::Release()
{
	SAFE_DELETE(m_Button);
}
