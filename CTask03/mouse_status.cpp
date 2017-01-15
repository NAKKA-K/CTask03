#include "mouse_status.h"
#include<DxLib.h>

MouseStatus::MouseStatus() :m_mouseButton(0), m_mouseX(0), m_mouseY(0)
{
}

//�w��͈͓��ō��N���b�N���ꂽ��true
bool MouseStatus::GetMouseStatus(int x1, int y1, int x2, int y2)
{
	//Button,X,Y�̏���ۑ�
	GetMouseInputLog(&m_mouseButton, &m_mouseX, &m_mouseY);

	//���N���b�N�ȊO�H
	if ((m_mouseButton&=MOUSE_INPUT_LEFT) == 0) return false;

	//�ے�̏�����t����̂��ʓ|�������̂ŁAelse����Ŋy�����܂���
	if (m_mouseX >= x1&&m_mouseX < x2&&m_mouseY >= y1&&m_mouseY < y2) { }
	else return false;


	return true;
}

int MouseStatus::GetMouseButton()
{
	return GetMouseInput()&MOUSE_INPUT_LEFT;
}
