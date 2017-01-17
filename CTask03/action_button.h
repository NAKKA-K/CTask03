#ifndef _ACTION_BUTTON_H
#define _ACTION_BUTTON_H

#include"mouse_status.h"
class ActionButton
{
public:
	ActionButton();

	//strと書かれたボタンを作成。指定したkeyを押されるとtrueを返す
	bool ActionInButton(int x1, int y1, int x2, int y2, const char *buttonStr, const int key = 0);
	//問題の流れの次に進む
	void NextAction(int *routeScene);


	/*Debug*/
	void DebugButton(ActionButton button);

private:
	//m_keyが0ならfalseを返す
	bool CheckKeyStatus();
	//m_keyにデフォルトを設定する(KEY_INPUT_F5)
	void SetDefaultKey();

	int m_key;
};

#endif // !_ACTION_BUTTON_H
