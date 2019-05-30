#include "stdafx.h"
#include "cButton.h"


cButton::cButton(int x, int y,const string& key)
{

	m_pos.x = x;
	m_pos.y = y;
	m_Nomal = IMAGE->FindImage(key +"_Nomal");
	m_OnCursor = IMAGE->FindImage(key +"_OnCursor");
	m_Click = IMAGE->FindImage(key +"_Click");
}


cButton::~cButton()
{
}

void cButton::Init()
{
	SetRect(&m_rt, m_pos.x, m_pos.y,
		m_pos.x + m_Nomal->m_info->bmWidth,
		m_pos.y + m_Nomal->m_info->bmHeight);
}

bool cButton::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (b_Click) {
		if (INPUT->MouseLUp()) {
			return true;
		}
	}

	if (PtInRect(&m_rt, pt)) {
		b_OnCursor = true;

		if (INPUT->MouseLPress()) {
			b_Click = true;
		}
		else
			b_Click = false;
	}
	else
		b_OnCursor = false;


	return false;
}

void cButton::Render()
{
	if (b_Click)
		IMAGE->Render(m_Click, m_pos, false, RGB(255, 0, 255));
	else if (b_OnCursor)
		IMAGE->Render(m_OnCursor, m_pos, false, RGB(255, 0, 255));
	else
		IMAGE->Render(m_Nomal, m_pos, false, RGB(255, 0, 255));
}

void cButton::Release()
{
}

