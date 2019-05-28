#pragma once
#include "cScene.h"

class PictureScene : public cScene
{
private:


public:
	PictureScene();
	virtual ~PictureScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

