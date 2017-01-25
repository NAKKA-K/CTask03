#include "mode_select.h"

#include<DxLib.h>
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"

int ModeSelect::m_selectMode = 0;

ModeSelect::ModeSelect()
{
	FontList fontlist;	//�N���X�̃R���X�g���N�^���N�������邽�߂����ɐ錾
	MenuGraphList menugraphlist;
}

ModeSelect::~ModeSelect()
{
}


//�`��
void ModeSelect::ModeGraph()
{
	//�摜�\��
	DrawGraph(0, 0, MenuGraphList::m_bin, TRUE);
	DrawGraph(0, 0, MenuGraphList::m_modeG, TRUE);
	DrawGraph(0, 0, MenuGraphList::m_pulse, TRUE);

	//���[�h���ڐݒ�
	const int MENU_STRING_P[MAX_SELECT_MODE][2] = { { 80,470 },{ 80,720 } };
	
	//�I���̃A�C�R���i���j�̕\��
	DrawStringToHandle(MENU_STRING_P[m_selectMode][0] - 50, MENU_STRING_P[m_selectMode][1] - 10,
		"*", FontList::m_colorGreen1, FontList::m_font100);
	
	return;
}
//����
void ModeSelect::ModeKey()
{
	if (Keyboard_Get(KEY_INPUT_DOWN) % 15 == 1) {
		m_selectMode = (m_selectMode + MAX_SELECT_MODE + 1) % MAX_SELECT_MODE;
	}
	else if (Keyboard_Get(KEY_INPUT_UP) % 15 == 1) {
		m_selectMode = (m_selectMode + MAX_SELECT_MODE - 1) % MAX_SELECT_MODE;
	}

	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {	//TODO:�w�K�Ǝ��H��SCENE�ɕύX����K�v����
		SceneMgr::SetScene(SCENE_LIST);
	}
	else if (Keyboard_Get(KEY_INPUT_BACK) == 1) {
		SceneMgr::SetScene(SCENE_GENRE);
	}

	return;
}

int ModeSelect::GetSelectMode()
{
	return m_selectMode;
}

void ModeSelect::DebugSetMode(int mode)
{
	m_selectMode = mode;
	return;
}