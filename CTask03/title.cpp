#include "title.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include<DxLib.h>

Title::Title()
{
	m_font100 = CreateFontToHandle("���C���I", 100, 3);
	m_menuBG = LoadGraph("SecureBack.jpg");
}
Title::~Title()
{
	DeleteFontToHandle(m_font100);
	DeleteGraph(m_menuBG);
}

//�`��
void Title::TitleGraph()
{
	DrawGraph(0, 0, m_menuBG, FALSE);

	//�^�C�g�����ڐݒ�
	const int TITLE_XY[2] = { 100,200 };

	//�^�C�g���\��
	DrawStringToHandle(TITLE_XY[0],TITLE_XY[1],"TITLE", GetColor(200, 200, 200), m_font100);

	return;
}
//����
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
