#include "title.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include<DxLib.h>

Title::Title()
{
	m_font100 = CreateFontToHandle("メイリオ", 100, 3);
	m_menuBG = LoadGraph("SecureBack.jpg");
}
Title::~Title()
{
	DeleteFontToHandle(m_font100);
	DeleteGraph(m_menuBG);
}

//描写
void Title::TitleGraph()
{
	DrawGraph(0, 0, m_menuBG, FALSE);

	//タイトル項目設定
	const int TITLE_XY[2] = { 100,200 };

	//タイトル表示
	DrawStringToHandle(TITLE_XY[0],TITLE_XY[1],"TITLE", GetColor(200, 200, 200), m_font100);

	return;
}
//操作
void Title::TitleKey()
{
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
		SceneMgr::SetScene(SCENE_GENRE);
	}

	return;
}

int Title::GetFont()
{
	return m_font100;
}
