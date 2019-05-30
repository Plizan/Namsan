#pragma once
#include "cScene.h"
class cButton;
class cIngame_start:public cScene
{
private:
	//cFrame * m_PlayerFrame;
	cButton * m_Button[4];
	Point Pos;
public:
	
	cIngame_start();
	virtual~cIngame_start();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

