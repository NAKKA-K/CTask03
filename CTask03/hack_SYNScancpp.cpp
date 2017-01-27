#include"hack_SYNScan.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>


void HackSYN()
{
	static SYN *syn;
	if (syn->IsCreated() == false) syn = new SYN();	//�R���X�g���N�^�̓����Ŏ����I��flag��true�ɕύX


	syn->SYNGraph();		//�����A�j���[�V�����⑀��A�j���[�V����
	syn->SYNKey();

	//���̏I������
	if (SceneMgr::GetScene() == SCENE_LIST) {
		delete syn;
		syn = nullptr;
	}
	return;
}


bool SYN::m_createdFlag = false;


SYN::SYN() :m_scene(0), m_timer(0), m_alpha(0), bright(255)
{
	m_createdFlag = true;


	//�摜�ǂݍ���
	m_hackBG = LoadGraph("Image/Q_gamen.png");
	m_webAppG = LoadGraph("Image/webApp3.png");
	m_pcG = LoadGraph("Image/pc.png");
	m_arrowRedG = LoadGraph("Image/arrowRed.png");
	m_arrowBlueG= LoadGraph("Image/arrowBlue.png");


	SetKeyInputStringColor(FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack);

	m_timer = GetNowCount();
}
SYN::~SYN()
{
	m_createdFlag = false;
	//�摜����
	DeleteGraph(m_hackBG);
	DeleteGraph(m_webAppG);
	DeleteGraph(m_pcG);
	DeleteGraph(m_arrowRedG);
	DeleteGraph(m_arrowBlueG);
}

void SYN::SYNGraph()
{
	const float PI = 3.141592653589793238462643383279;

	DrawGraph(0, 0, m_hackBG, FALSE);
	DrawStringToHandle(100, 45, "Network", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, "SYN�X�L����", FontList::m_colorGreen1, FontList::m_font100);


	DrawExtendGraph(20, 350, 700, 700, m_pcG, TRUE);
	DrawExtendGraph(1250, 350, 1900, 700, m_pcG, TRUE);

	if (m_scene >= 2) {
		DrawRotaGraph(955, 360, 1.6f, PI/180*38, m_arrowRedG, TRUE);
		DrawStringToHandle(900, 300, "SYN", FontList::m_colorGreen1, FontList::m_font50);
	}
	if (m_scene >= 4) {
		DrawGraph(800, 500, m_arrowBlueG, TRUE);
		DrawStringToHandle(850, 450, "SYN/ACK", FontList::m_colorGreen1, FontList::m_font50);
	}
	if (m_scene >= 6) {
		DrawRotaGraph(955, 690, 1.6f, PI / 180 * 38, m_arrowRedG, TRUE);
		DrawBox(810, 600, 1110, 660, FontList::m_colorGreen1, TRUE);
	}
	
	if (m_scene == 0) {}
	else if (m_scene == 1) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);//tom�t�F�[�h�C��
		DrawRotaGraph(955, 360, 1.6f, PI / 180 * 38, m_arrowRedG, TRUE);//��
		DrawStringToHandle(900, 300, "SYN", FontList::m_colorGreen1, FontList::m_font50);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (m_alpha <= 255) m_alpha += 2;
	}
	else if (m_scene==2) m_alpha = 0;
	else if (m_scene == 3) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);//tom�t�F�[�h�C��
		DrawGraph(800, 500, m_arrowBlueG, TRUE);//��
		DrawStringToHandle(850, 450, "SYN/ACK", FontList::m_colorGreen1, FontList::m_font50);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (m_alpha <= 255) m_alpha += 2;
	}
	else if (m_scene == 4) m_alpha = 0;
	else if (m_scene == 5) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);//tom�t�F�[�h�C��
		DrawRotaGraph(955, 690, 1.6f, PI / 180 * 38, m_arrowRedG, TRUE);//��
		DrawBox(810, 600, 1110, 660, FontList::m_colorGreen1, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (m_alpha <= 255) m_alpha += 2;
	}
	else if (m_scene == 6) {
		DrawStringToHandle(50, 930, "�X�e���X�X�L���������邽�߂ɁA\n����T�[�o�ɑ���ׂ��t���O���Z�b�g����I", FontList::m_colorGreen1, FontList::m_font50);
		SetFontSize(50);
		if (KeyInputSingleCharString(870, 610, 7, str, FALSE) == 1) {
			if (strcmp(str, "RST") == 0) m_scene = 7;	//����
			else if (strcmp(str, "ACK") == 0) m_scene = 11;
			else m_scene = 15;	//�s����
		}
		m_timer = GetNowCount();//���Ԃ�������
	}
	else if (m_scene == 7) {
		DrawStringToHandle(20, 930, "����ɋC�Â��ꂸ�Ƀ|�[�g��\n�X�L�����ł����I", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene == 8) {
		DrawStringToHandle(20, 930, "�ʐM���m�����Ă��܂���log�Ɏc��A\n�Ԃ��Ȃ���DoS�U�����Ǝv���Ă��܂��B", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene == 9 || m_scene == 12 || m_scene == 16) {
		SetDrawBright(bright, bright, bright);
		if (bright > 0) bright -= 2;
		else bright = 0;
	}
	else if (m_scene == 10 || m_scene == 13 || m_scene == 17) {
		SceneMgr::SetScene(SCENE_LIST);
		SetDrawBright(255, 255, 255);
	}

	else if (m_scene == 11) {
		DrawStringToHandle(50, 930, "�X�L�����̗�����log�Ɏc���Ă��܂����c�c", FontList::m_colorGreen1, FontList::m_font50);
	}

	else if (m_scene == 15) {
		DrawStringToHandle(50, 930, "�����DoS�U�����ƔF������Ă��܂����c�c", FontList::m_colorGreen1, FontList::m_font50);
	}

	return;
}
void SYN::SYNKey()
{
	if (m_scene <= 6) {
		if (GetNowCount() - m_timer <= 2 * 1000) m_scene = 0;	//2
		else if (GetNowCount() - m_timer <= 4 * 1000) m_scene = 1;	//2
		else if (GetNowCount() - m_timer <= 41 * 100) m_scene = 2;	//0.1
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 3;	//2
		else if (GetNowCount() - m_timer <= 61 * 100) m_scene = 4;	//0.1
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 5;	//2
		else if (GetNowCount() - m_timer <= 9 * 1000) m_scene = 6;	//����
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
			m_alpha = 255;
			m_scene = 6;
		}
	}
	else if (m_scene <= 9) {
		if (GetNowCount() - m_timer <= 2 * 1000) m_scene = 7;//2
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 8;//3
		else if (GetNowCount() - m_timer <= 7 * 1000) m_scene = 9;//2
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 10;//�I������
	}
	else if (m_scene <= 13) {	
		if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 11;//2
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 12;//2
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 13;//m_scene=2
	}
	else if (m_scene <= 17) {
		if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 15;//2
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 16;//2
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 17;//m_scene=2
	}


	return;
}


bool SYN::IsCreated()
{
	return m_createdFlag;
}

