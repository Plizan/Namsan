#include "stdafx.h"
#include "cLoadScene.h"


cLoadScene::cLoadScene()
{
	//m_BackGround = IMAGE->AddImage("Loading", "./Image/Loading.bmp");

}


cLoadScene::~cLoadScene()
{
}

void cLoadScene::Init()
{
	m_NowLoad = 0;

	//이미지 추가

	//이미지는 여기서 추가시킨다. 순서대로 이름, 경로, 이미지 갯수
	Load("game", "./Image/BackGround/TitleBackGround.bmp");
	Load("game_start", "./Image/BackGround/Title_Bg.bmp");
	Load("game_Info", "./Image/BackGround/main.bmp");
	//Load("GameInfo", "./Image/BackGround/InGame_Bg.bmp");



	//Load("Player", "./Image/Player/(%d).bmp", 2);
	//Load("HHHHH", "./Image/OH.bmp");
	//Load("Button1", "./lmage/Button/ButtonHow.bmp");
	
	//Load("Button2_Nomal", "./Image/Button/ButtonHow2.bmp");
	//Load("Button_start_Nomal","./Image/Button/ButtonPlay.bmp");
	Load("Button_start_Nomal", "./Image/Button/ButtonPlay.bmp");
	Load("Button_start_OnCursor","./Image/Button/ButtonLeave.bmp");
	Load("Button_start_Click", "./Image/Button/ButtonHow.bmp");
	//Load("Button_start_Click","./Image/Button/ButtonHow2.bmp");

	Load("Button_Info_Nomal", "./Image/Button/ButtonPlay.bmp");
	Load("Button_Info_OnCursor", "./Image/Button/ButtonLeave.bmp");
	Load("Button_Info_Click", "./Image/Button/ButtonHow.bmp");


//Load("Button_Info_Nomal","./Image/Button/ButtonHow2.bmp");
//Load("Butto_Info_OnCursor","./Image/Button/ButtonLeave.bmp");
//Load("Button_Info_Click","./Image/Button/ButtonHow2.bmp");
	
	m_MaxLoad = m_Load.size();
}

void cLoadScene::Update()
{
	if (m_NowLoad != m_MaxLoad) {
		IMAGE->AddImage(
			m_Load[m_NowLoad].key,
			m_Load[m_NowLoad].path,
			m_Load[m_NowLoad].count
		);

		m_NowLoad++;
	}
	else {
		//이미지 추가가 다 되었으면 Scene을 변경한다.
		SCENE->ChangeScene("Ingame");
	}
}

void cLoadScene::Render()
{
	Point Pos;
	Pos.x = 0;
	Pos.y = 0;
}

void cLoadScene::Release()
{
}
