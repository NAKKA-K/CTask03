#include"genre_select.h"
#include<DxLib.h>
#include"keyboard.h"
#include"scene_mgr.h"

int GenreSelect::m_selectGenre=0;

GenreSelect::GenreSelect()
{
	m_font100 = CreateFontToHandle("メイリオ", 100, 3);
	m_menuBG = LoadGraph("SecureBack.jpg");

}
GenreSelect::~GenreSelect()
{
	DeleteFontToHandle(m_font100);
	DeleteGraph(m_menuBG);
}

//描写
void GenreSelect::GenreGraph()
{
	DrawGraph(0, 0, m_menuBG, FALSE);

	//ジャンル項目設定
	const int GENRE_STRING_XY[MAX_SELECT_GENRE][2] = { { 500,120 },{ 500,470 },{ 500,820 } };
	const char* GENRE_STRING[MAX_SELECT_GENRE] = { "Program","NetWork","Cipher" };
	
	//ジャンル項目表示
	for (int i = 0; i < MAX_SELECT_GENRE; i++) {
		DrawStringToHandle(GENRE_STRING_XY[i][0], GENRE_STRING_XY[i][1],
			GENRE_STRING[i], GetColor(200, 200, 200), m_font100);
	}
	DrawStringToHandle(GENRE_STRING_XY[m_selectGenre][0]-50, GENRE_STRING_XY[m_selectGenre][1]-10,
		"*", GetColor(200, 200, 200), m_font100);

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
	return m_selectGenre;
}
