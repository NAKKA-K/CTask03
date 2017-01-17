#include "mode_select.h"

#include<DxLib.h>
#include"keyboard.h"
#include"scene_mgr.h"

int ModeSelect::m_selectMode = 0;

ModeSelect::ModeSelect()
{
	m_font100 = CreateFontToHandle("メイリオ", 100, 3);
	m_menuBG = LoadGraph("SecureBack.jpg");

}
ModeSelect::~ModeSelect()
{
	DeleteFontToHandle(m_font100);
	DeleteGraph(m_menuBG);
}

//描写
void ModeSelect::ModeGraph()
{
	DrawGraph(0, 0, m_menuBG, FALSE);

	//モード項目設定
	const int MENU_STRING_P[MAX_SELECT_MODE][2] = { { 500,470 },{ 500,820 } };
	const char* MENU_STRING[MAX_SELECT_MODE] = { "gakusyu","jissen" };	//TODO:名称変更

	//モード項目表示
	for (int i = 0; i < MAX_SELECT_MODE; i++) {
		DrawStringToHandle(MENU_STRING_P[i][0], MENU_STRING_P[i][1],
			MENU_STRING[i], GetColor(200, 200, 200), m_font100);
	}
	DrawStringToHandle(MENU_STRING_P[m_selectMode][0] - 50, MENU_STRING_P[m_selectMode][1] - 10,
		"*", GetColor(200, 200, 200), m_font100);

	return;
}
//操作
void ModeSelect::ModeKey()
{
	if (Keyboard_Get(KEY_INPUT_DOWN) % 15 == 1) {
		m_selectMode = (m_selectMode + MAX_SELECT_MODE + 1) % MAX_SELECT_MODE;
	}
	else if (Keyboard_Get(KEY_INPUT_UP) % 15 == 1) {
		m_selectMode = (m_selectMode + MAX_SELECT_MODE - 1) % MAX_SELECT_MODE;
	}

	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {	//TODO:学習と実践のSCENEに変更する必要あり
		SceneMgr::SetScene(SCENE_LIST);
	}
	else if (Keyboard_Get(KEY_INPUT_BACK) == 1) {
		SceneMgr::SetScene(SCENE_GENRE);
	}

	return;
}

int ModeSelect::GetFont()
{
	return m_font100;
}

int ModeSelect::GetSelectMode()
{
	return m_selectMode;
}
