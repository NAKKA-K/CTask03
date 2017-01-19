#include "mode_select.h"

#include<DxLib.h>
#include"keyboard.h"
#include"scene_mgr.h"

int ModeSelect::m_selectMode = 0;

ModeSelect::ModeSelect()	//�K�v�ȉ摜�A�F�A����
{
	CrGreen = GetColor(50, 200, 80);
	m_font100 = CreateFontToHandle("���C���I", 100, 3);
	m_modeG = LoadGraph("tl.png");
	m_pulse = LoadGraph("pulse.png");
	m_bin = LoadGraph("bin.png");
}

ModeSelect::~ModeSelect()
{
	DeleteFontToHandle(m_font100);
	DeleteGraph(m_modeG);
	DeleteGraph(m_pulse);
	DeleteGraph(m_bin);
}

//�`��
void ModeSelect::ModeGraph()
{
	//�摜�\��
	DrawGraph(0, 0, m_bin, TRUE);
	DrawGraph(0, 0, m_modeG, TRUE);
	DrawGraph(0, 0, m_pulse, TRUE);

	//���[�h���ڐݒ�
	const int MENU_STRING_P[MAX_SELECT_MODE][2] = { { 80,470 },{ 80,720 } };
	
	//�I���̃A�C�R���i���j�̕\��
	DrawStringToHandle(MENU_STRING_P[m_selectMode][0] - 50, MENU_STRING_P[m_selectMode][1] - 10,
		"*", CrGreen, m_font100);
	
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

int ModeSelect::GetFont()
{
	return m_font100;
}

int ModeSelect::GetSelectMode()
{
	return m_selectMode;
}
