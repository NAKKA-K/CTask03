#include"genre_select.h"
#include<DxLib.h>
#include"keyboard.h"
#include"scene_mgr.h"
#include"title.h"
#include"font_list.h"
#include"menu_graph_list.h"

int GenreSelect::m_selectGenre=0;

GenreSelect::GenreSelect()
{
	FontList fontlist;	//�N���X�̃R���X�g���N�^���N�������邽�߂����ɐ錾
	MenuGraphList menugraphlist;
}
GenreSelect::~GenreSelect()
{
}

//�`��
void GenreSelect::GenreGraph()
{
	DrawGraph(0, 0, MenuGraphList::m_bin, TRUE);
	DrawGraph(0, 0, MenuGraphList::m_menuG, TRUE);
	DrawGraph(0, 0, MenuGraphList::m_pulse, TRUE);

	//�W���������ڐݒ�
	const int GENRE_STRING_XY[MAX_SELECT_GENRE][2] = { { 80,470 },{ 80,610 },{ 80,760 } };
	
	//�@�I���̃A�C�R���i���j�̕\��
	DrawStringToHandle(GENRE_STRING_XY[m_selectGenre][0]-50, GENRE_STRING_XY[m_selectGenre][1]-10,
		"*", FontList::m_colorGreen1, FontList::m_font100);
	
	return;
}
//����
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

int GenreSelect::GetSelectGenre()
{
	return m_selectGenre;
}

void GenreSelect::DebugSetGenre(int genre)
{
	m_selectGenre = genre;
	return;
}