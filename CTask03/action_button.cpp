#include "action_button.h"
#include"mouse_status.h"
#include"keyboard.h"
#include<DxLib.h>

#include"font_list.h"


ActionButton::ActionButton() :m_key(0)
{
}

/*Debug*/
void ActionButton::DebugButton(ActionButton button)
{
	int routeScene = 0;
	printfDx("%d", routeScene);

	if (button.ActionInButton(1700, 850, 1800, 900, "���M") == true) {
		printfDx("\n");
		button.NextAction(&routeScene);
	}
	return;
}



//str�Ə����ꂽ�{�^�����쐬�B�w�肵��key����������true��Ԃ�
bool ActionButton::ActionInButton(int x1, int y1, int x2, int y2, const char *buttonStr, const int key)
{
	//key�ɉ����ݒ肳��Ă��Ȃ���΁A�f�t�H���g�ݒ�ɂ���
	m_key = key;
	if (CheckKeyStatus()==false) SetDefaultKey();

	//Button��\��
	DrawBox(x1, y1, x2, y2, FontList::m_colorWhite1, TRUE);
	DrawBox(x1+3, y1+3, x2-3, y2-3, FontList::m_colorWhite, TRUE);
	DrawStringToHandle(x1, y1, buttonStr, FontList::m_colorBlack, FontList::m_font50);

	//Button����(�}�E�X&�L�[)
	MouseStatus mouseStatus;
	if (mouseStatus.GetMouseStatus(x1,y1,x2,y2)==true) return true;	//�͈͓��ō��N���b�N���ꂽ�ꍇ
	if (Keyboard_Get(m_key)==1) return true;	//key�Ŋm�肳�ꂽ�ꍇ

	return false;
}

//���̗���̎��ɐi��
void ActionButton::NextAction(int *routeScene)
{
	(*routeScene)++;
	return;
}


//m_key��0�ŏ��������ꂽ�܂܂Ȃ�false��Ԃ�
bool ActionButton::CheckKeyStatus()
{
	if (m_key==0) return false;

	return true;
}
//m_key�Ƀf�t�H���g��ݒ肷��(KEY_INPUT_F5)
void ActionButton::SetDefaultKey()
{
	m_key = KEY_INPUT_F5;
	return;
}

