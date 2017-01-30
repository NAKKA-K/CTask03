#include"hack_SQLInjec.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>


void HackSQL()
{
	static SQL *sql;
	if (sql->IsCreated() == false) sql = new SQL();	//�R���X�g���N�^�̓����Ŏ����I��flag��true�ɕύX


	sql->SQLGraph();		//�����A�j���[�V�����⑀��A�j���[�V����
	sql->SQLKey();

	//���̏I������
	if (SceneMgr::GetScene() == SCENE_LIST) {
		delete sql;
		sql = nullptr;
	}
	return;
}


bool SQL::m_createdFlag = false;


SQL::SQL() :m_scene(0), m_timer(0), m_alpha(0), bright(255)
{
	m_createdFlag = true;


	//�摜�ǂݍ���
	m_hackBG = LoadGraph("Image/Q_gamen.png");
	m_webAppG = LoadGraph("Image/webApp3.png");
	m_pcG = LoadGraph("Image/pc.png");
	m_tomG = LoadGraph("Image/tom.png");

	SetKeyInputStringColor(FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack);

	m_timer = GetNowCount();
}
SQL::~SQL()
{
	m_createdFlag = false;
	//�摜����
	DeleteGraph(m_hackBG);
	DeleteGraph(m_webAppG);
	DeleteGraph(m_pcG);
	DeleteGraph(m_tomG);
}

void SQL::SQLGraph()
{

	DrawGraph(0, 0, m_hackBG, FALSE);
	DrawStringToHandle(100, 45, "Program", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, "SQL�C���W�F�N�V����", FontList::m_colorGreen1, FontList::m_font100);


	DrawExtendGraph(10, 160, 1500, 900, m_webAppG, TRUE);
	DrawGraph(1600, 700, m_tomG, TRUE);
	if (m_scene>=1) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
		//SQL��
		DrawStringToHandle(1580, 300, "PASS=='[���͒l]';", FontList::m_colorGreen1, FontList::m_font30);
		DrawStringToHandle(450, 850, "'     OR     '1'='1     ;     AND", FontList::m_colorBlack, FontList::m_font30);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (m_alpha <= 255) m_alpha += 2;
	}

	if (m_scene == 0) {}
	else if (m_scene == 1) {}
	else if (m_scene == 2) {
		DrawStringToHandle(50, 930, "�p�ӂ��ꂽ���[�h��1�x�������p���āA\nSQL�C���W�F�N�V�����𐬌�������I", FontList::m_colorGreen1, FontList::m_font50);
		SetFontSize(50);
		if (KeyInputSingleCharString(610, 610, 22, str, FALSE) == 1) {
			if (strcmp(str, "' OR '1'='1") == 0) m_scene = 3;	//����
			else m_scene = 7;
		}
		m_timer = GetNowCount();//���Ԃ�������
	}
	else if (m_scene==3) {
		DrawStringToHandle(625,770, "���O�C���F�؂��܂����B", FontList::m_colorBlack, FontList::m_font30);
		DrawStringToHandle(50, 930, "�s���ȃp�X���[�h�Ń��O�C���ɐ��������I", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene==4) {
		DrawStringToHandle(50, 930, "���̂悤�ȕs���������Ȃ����߂ɁA\n���͒l������������g�����B", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene == 5 ) {
		SetDrawBright(bright, bright, bright);
		if (bright > 0) bright -= 2;
		else bright = 0;
	}
	else if (m_scene == 6) {
		SceneMgr::SetScene(SCENE_LIST);
		SetDrawBright(255, 255, 255);
	}

	else if (m_scene==7) {
		DrawStringToHandle(630, 780, "PASS���Ԉ���Ă��܂��B", FontList::m_colorBlack, FontList::m_font30);
		DrawStringToHandle(50, 930, "SQL���̍\�����Ⴄ�悤���B", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene==8) {
		m_scene = 2;
	}

	return;
}
void SQL::SQLKey()
{
	if (m_scene <= 2) {
		if (GetNowCount() - m_timer <= 1 * 1000) m_scene = 0;	//2
		else if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 1;	//2
		else if (GetNowCount() - m_timer <= 4* 1000) m_scene = 2;	//0.1
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
			m_alpha = 255;
			m_scene = 2;
		}
	}
	else if (m_scene<=6) {
		if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 3;	//2
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 4;	//2
		else if (GetNowCount() - m_timer <= 7 * 1000) m_scene = 5;	//2
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 6;	//�I��
	}
	else if (m_scene<=10) {
		if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 7;	//2
		else if (GetNowCount() - m_timer <= 4 * 1000) m_scene = 8;	//2
	}

	return;
}


bool SQL::IsCreated()
{
	return m_createdFlag;
}





