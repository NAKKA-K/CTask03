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

	if (button.ActionInButton(1700, 850, 1800, 900, "送信") == true) {
		printfDx("\n");
		button.NextAction(&routeScene);
	}
	return;
}



//strと書かれたボタンを作成。指定したkeyを押されるとtrueを返す
bool ActionButton::ActionInButton(int x1, int y1, int x2, int y2, const char *buttonStr, const int key)
{
	//keyに何も設定されていなければ、デフォルト設定にする
	m_key = key;
	if (CheckKeyStatus()==false) SetDefaultKey();

	//Buttonを表示
	DrawBox(x1, y1, x2, y2, FontList::m_colorWhite1, TRUE);
	DrawBox(x1+3, y1+3, x2-3, y2-3, FontList::m_colorWhite, TRUE);
	DrawStringToHandle(x1, y1, buttonStr, FontList::m_colorBlack, FontList::m_font50);

	//Button判定(マウス&キー)
	MouseStatus mouseStatus;
	if (mouseStatus.GetMouseStatus(x1,y1,x2,y2)==true) return true;	//範囲内で左クリックされた場合
	if (Keyboard_Get(m_key)==1) return true;	//keyで確定された場合

	return false;
}

//問題の流れの次に進む
void ActionButton::NextAction(int *routeScene)
{
	(*routeScene)++;
	return;
}


//m_keyが0で初期化されたままならfalseを返す
bool ActionButton::CheckKeyStatus()
{
	if (m_key==0) return false;

	return true;
}
//m_keyにデフォルトを設定する(KEY_INPUT_F5)
void ActionButton::SetDefaultKey()
{
	m_key = KEY_INPUT_F5;
	return;
}

