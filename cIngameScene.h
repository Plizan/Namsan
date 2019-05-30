#pragma once
#include "cScene.h"
class cButton;
class cIngameScene : public cScene
{
private:
	cTexture * m_BackGround;
	cFrame * m_PlayerFrame;
	Point Pos;
	POINT ptmouse;
	bool b_Move;

<<<<<<< HEAD
	cButton* m_Button[4];
	//cButton * m_button;

=======
	int imageNum;
>>>>>>> 2da323efcff4d33a78ab8e13dc778d25bcd24ead
public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};



