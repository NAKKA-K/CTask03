#include"genre_select.h"
#include<DxLib.h>
#include"keyboard.h"
#include"scene_mgr.h"
#include"title.h"

int GenreSelect::m_selectGenre=0;


GenreSelect::GenreSelect()	//必要な画像、色、文字
{
	CrGreen = GetColor(50, 200, 80);
	m_font100 = CreateFontToHandle("メイリオ", 100, 3);
	m_bin = LoadGraph("bin.png");
	m_menuG = LoadGraph("pnc.png");
	m_pulse = LoadGraph("pulse.png");

}
GenreSelect::~GenreSelect()
{
	DeleteFontToHandle(m_font100);
	DeleteGraph(m_menuG);
	DeleteGraph(m_pulse);
	DeleteGraph(m_bin);
}

//描写
void GenreSelect::GenreGraph()
{
	DrawGraph(0, 0, m_bin, TRUE);
	DrawGraph(0, 0, m_menuG, TRUE);
	DrawGraph(0, 0, m_pulse, TRUE);

	//ジャンル項目設定
	const int GENRE_STRING_XY[MAX_SELECT_GENRE][2] = { { 80,470 },{ 80,610 },{ 80,760 } };
	
	//　選択のアイコン（＊）の表示
	DrawStringToHandle(GENRE_STRING_XY[m_selectGenre][0]-50, GENRE_STRING_XY[m_selectGenre][1]-10,
		"*", CrGreen, m_font100);
	
	return;
}
//操作
void GenreSelect::GenreKey()
{
	if (Keyboard_Get(KEY_INPUT_DOWN) % 15 == 1) {
		m_selectGenre = (m_selectGenre + MAX_SELECT_GENRE + 1) % MAX_SELECT_GENRE;
	}
	else if (Keyboard_Get(KEY_INPUT_UP) % 15 == 1) {
		m_selectGenre = (m_selectGenre + MAX_SELECT_GENRE - 1) % MAX_SELECT_GENRE;
	}

	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
		SceneMgr::SetScene(SCENE_MODE);
	}
	return;
}

int GenreSelect::GetFont()
{
	return m_font100;
}

int GenreSelect::GetSelectGenre()
{
	if (m_selectGenre == 0) {
		return SCENE_PROGRAM;
	}
	else if (m_selectGenre == 1) {
		return SCENE_NETWORK;
	}
	else if (m_selectGenre == 2) {
		return SCENE_CIPHER;
	}
}
