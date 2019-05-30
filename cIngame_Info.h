#pragma once
#include "cScene.h"
class cButton;
class cIngame_Info: public cScene
{
private:
	cButton * m_Button;
	Point Pos;
public:
	cIngame_Info();
	virtual~cIngame_Info();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

