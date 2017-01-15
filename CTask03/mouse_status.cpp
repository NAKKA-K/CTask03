#include "mouse_status.h"
#include<DxLib.h>

MouseStatus::MouseStatus() :m_mouseButton(0), m_mouseX(0), m_mouseY(0)
{
}

//指定範囲内で左クリックされたらtrue
bool MouseStatus::GetMouseStatus(int x1, int y1, int x2, int y2)
{
	//Button,X,Yの情報を保存
	GetMouseInputLog(&m_mouseButton, &m_mouseX, &m_mouseY);

	//左クリック以外？
	if ((m_mouseButton&=MOUSE_INPUT_LEFT) == 0) return false;

	//否定の条件を付けるのが面倒だったので、else判定で楽をしました
	if (m_mouseX >= x1&&m_mouseX < x2&&m_mouseY >= y1&&m_mouseY < y2) { }
	else return false;


	return true;
}

int MouseStatus::GetMouseButton()
{
	return GetMouseInput()&MOUSE_INPUT_LEFT;
}
