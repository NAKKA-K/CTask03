#ifndef _ACTION_BUTTON_H
#define _ACTION_BUTTON_H

#include"mouse_status.h"
class ActionButton
{
public:
	ActionButton();

	//str�Ə����ꂽ�{�^�����쐬�B�w�肵��key����������true��Ԃ�
	bool ActionInButton(int x1, int y1, int x2, int y2, const char *buttonStr, const int key = 0);
	//���̗���̎��ɐi��
	void NextAction(int *routeScene);


	/*Debug*/
	void DebugButton(ActionButton button);

private:
	//m_key��0�Ȃ�false��Ԃ�
	bool CheckKeyStatus();
	//m_key�Ƀf�t�H���g��ݒ肷��(KEY_INPUT_F5)
	void SetDefaultKey();

	int m_key;
};

#endif // !_ACTION_BUTTON_H
