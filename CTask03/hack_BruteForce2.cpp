#include"hack_BruteForce.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>

void HackBrute2()
{
	static Brute2 *brute;
	if (brute->IsCreated() == false) brute = new Brute2();	//�R���X�g���N�^�̓����Ŏ����I��flag��true�ɕύX


	brute->BruteGraph();		//�����A�j���[�V�����⑀��A�j���[�V����
	brute->BruteKey();

	//���̏I������
	if (SceneMgr::GetScene() == SCENE_LIST) {
		delete brute;
		brute = nullptr;
	}
	return;
}


bool Brute2::m_createdFlag = false;


Brute2::Brute2() :m_scene(0), m_timer(0), m_alpha(0), bright(255)
{
	m_createdFlag = true;

	//ansNum�̌���
	ansNum = GetRand(7);//0~9


						//�摜�ǂݍ���
	m_hackBG = LoadGraph("Image/Q_gamen.png");
	m_webAppG = LoadGraph("Image/webApp3.png");


	SetKeyInputStringColor(FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack);

	m_timer = GetNowCount();
}
Brute2::~Brute2()
{
	m_createdFlag = false;
	//�摜����
	DeleteGraph(m_hackBG);
}

void Brute2::BruteGraph()
{
	DrawGraph(0, 0, m_hackBG, FALSE);
	DrawStringToHandle(100, 45, "Cipher", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, "BruteForce�U���U", FontList::m_colorGreen1, FontList::m_font100);


	DrawExtendGraph(10, 160, 1500, 900, m_webAppG, TRUE);

	if (m_scene >= 1) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);//tom�t�F�[�h�C��
													  //�����\��
		DrawBox(1500, 170, 1850, 850, FontList::m_colorWhite, TRUE);
		DrawStringToHandle(1510, 175, "PASS��ab����3����\n�\������Ă���", FontList::m_colorBlack, FontList::m_font30);
		for (int i = 0; i < 8; i++) {
			DrawFormatStringToHandle(1510, 300 + (i * 60), FontList::m_colorBlack, FontList::m_font50, "%s", answer[i]);
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (m_alpha <= 255) m_alpha += 2;
	}

	if (m_scene == 0) {}
	else if (m_scene == 1) {}
	else if (m_scene == 2) {
		DrawStringToHandle(50, 930, "BruteForce�U�����d�|���āA\nPASS�F�؂�ʉ߂���I", FontList::m_colorGreen1, FontList::m_font50);
		SetFontSize(50);
		if (KeyInputSingleCharString(690, 640, 3, str, FALSE) == 1) {
			if (strcmp(str, answer[ansNum]) == 0) m_scene = 3;	//����
			else m_scene = 7;	//�s����
		}
		m_timer = GetNowCount();//���Ԃ�������
	}
	else if (m_scene == 3) {
		DrawStringToHandle(10 + 500, 160 + 600, "PASS��F�؂��܂����B\n��������Ⴂ�܂��B", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 4) {
		DrawStringToHandle(20, 930, "�K����PASS�ݒ肾�Ƃ����ɓ��肳���B\n���ɓ������������ō\������Ă���Ȃ�c�c", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene == 5) {
		SetDrawBright(bright, bright, bright);
		if (bright > 0) bright -= 2;
		else bright = 0;
	}
	else if (m_scene == 6) {
		SceneMgr::SetScene(SCENE_LIST);
		SetDrawBright(255, 255, 255);
	}

	else if (m_scene == 7) {
		DrawStringToHandle(10 + 500, 160 + 600, "PASS�̔F�؂Ɏ��s���܂����B\n�ēx���͂��Ă��������B", FontList::m_colorBlack, FontList::m_font30);
		DrawStringToHandle(50, 930, "�S�Ă̑g�ݍ��킹����͂��Ă�����\n�ǂꂩ�ʂ邩������Ȃ��B", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene == 8) {
		m_scene = 2;//���͂ɖ߂�
	}

	return;
}
void Brute2::BruteKey()
{
	if (m_scene <= 2) {
		if (GetNowCount() - m_timer <= 4 * 100) m_scene = 0;	//2
		else if (GetNowCount() - m_timer <= 24 * 100) m_scene = 1;	//2
		else if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 2;	//����
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
			m_alpha = 255;
			m_scene = 2;
		}
	}
	else if (m_scene <= 6) {
		if (GetNowCount() - m_timer <= 2 * 1000) m_scene = 3;	//3
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 4;	//3
		else if (GetNowCount() - m_timer <= 7 * 1000) m_scene = 5;	//2
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 6;	//�I������
	}
	else if (m_scene <= 8) {
		if (GetNowCount() - m_timer <= 2 * 1000) m_scene = 7;	//3
		else if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 8;	//m_scene=2
	}

	return;
}


bool Brute2::IsCreated()
{
	return m_createdFlag;
}

