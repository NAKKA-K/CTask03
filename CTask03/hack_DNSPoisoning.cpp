#include"hack_DNSPoisoning.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>

void HackDNS()
{
	static DNS *dns;
	if (dns->IsCreated() == false) dns = new DNS();	//�R���X�g���N�^�̓����Ŏ����I��flag��true�ɕύX


	dns->DNSGraph();		//�����A�j���[�V�����⑀��A�j���[�V����
	dns->DNSKey();

	//���̏I������
	if (SceneMgr::GetScene() == SCENE_LIST) {
		delete dns;
		dns = nullptr;
	}
	return;
}


bool DNS::m_createdFlag = false;


DNS::DNS() :m_scene(0), m_timer(0), m_alpha(0), bright(255)
{
	m_createdFlag = true;

	//�摜�ǂݍ���
	m_hackBG = LoadGraph("Image/Q_gamen.png");
	m_pcG = LoadGraph("Image/pc.png");
	m_arrowBlueG = LoadGraph("Image/arrowBlue.png");


	SetKeyInputStringColor(FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1,
		FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1,
		FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1,
		FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1);

	m_timer = GetNowCount();
}
DNS::~DNS()
{
	m_createdFlag = false;
	//�摜����
	DeleteGraph(m_hackBG);
	DeleteGraph(m_pcG);
	DeleteGraph(m_arrowBlueG);
}

void DNS::DNSGraph()
{
	DrawGraph(0, 0, m_hackBG, FALSE);
	DrawStringToHandle(100, 45, "Network", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, "DNS�L���b�V���|�C�Y�j���O", FontList::m_colorGreen1, FontList::m_font100);


	//��ʂ̉摜
	DrawExtendGraph(200, 200, 200 + 225, 200 + 125, m_pcG, TRUE);//����
	DrawStringToHandle(475, 190, "����DNS�T�[�o\n(denshi.co.jp)", FontList::m_colorWhite, FontList::m_font25);
	DrawExtendGraph(200, 360, 200 + 225, 360 + 125, m_pcG, TRUE);//�����i
	DrawStringToHandle(160, 500, "����DNS�T�[�o", FontList::m_colorWhite, FontList::m_font25);
	DrawExtendGraph(200, 700, 200 + 225, 700 + 125, m_pcG, TRUE);//�����i
	DrawStringToHandle(155, 650, "�UWeb�T�[�o", FontList::m_colorWhite, FontList::m_font25);
	DrawBox(330, 650-5, 430, 680, FontList::m_colorGreen1, TRUE);
	DrawExtendGraph(1200, 300, 1200 + 225, 300 + 125, m_pcG, TRUE);//�E��i
	DrawStringToHandle(1150, 240, "DNS�T�[�o(�^�[�Q�b�g)", FontList::m_colorWhite, FontList::m_font25);
	DrawExtendGraph(1200, 700, 1200 + 225, 700 + 125, m_pcG, TRUE);//�E���i
	DrawStringToHandle(1470, 730, "�N���C�A���g", FontList::m_colorWhite, FontList::m_font25);


	const float PI = 3.141592653589793238462643383279;	//���̉�]�\���Ɏg�p


	if (m_scene>=1) {
		DrawGraph(500, 280, m_arrowBlueG, TRUE);
		DrawBox(700, 250, 1000, 330, FontList::m_colorWhite, TRUE);
		DrawStringToHandle(700+3, 250+3, "1.�@���O�����v��\n�@www.denshi.co.jp", FontList::m_colorBlack, FontList::m_font25);
	}
	if (m_scene >= 2) {
		DrawTurnGraph(750, 390, m_arrowBlueG, TRUE);
		DrawBox(650, 370, 920, 490, FontList::m_colorWhite, TRUE);
		DrawStringToHandle(650 + 3, 370 + 3, "2.�@�s���ȉ���\n�@10.0.0.5\n�@www.denshi.com��\n�@10.0.0.9", FontList::m_colorBlack, FontList::m_font25);
	}
	if (m_scene >= 3) {
		DrawBox(1500, 300, 1900, 400, FontList::m_colorWhite, TRUE);
		DrawStringToHandle(1500 + 3, 300 + 3, "3.�@�L���b�V���ɓo�^\n�@www.denshi.co.jp�F10.0.0.5\n�@www.denshi.com�F10.0.0.9", FontList::m_colorBlack, FontList::m_font25);
	}
	if (m_scene>=4) {
		DrawRotaGraph(1420, 560, 0.7f, PI / 180 * 90, m_arrowBlueG, TRUE);

		DrawBox(1400, 580, 1650, 650, FontList::m_colorWhite, TRUE);
		DrawStringToHandle(1400+ 3, 580 + 3, "4.�@���O�����v��\n�@www.denshi.com", FontList::m_colorBlack, FontList::m_font25);
	}
	if (m_scene >= 5) {
		DrawRotaGraph(1240, 560, 0.7f, PI / 180 * 270, m_arrowBlueG, TRUE);

		DrawBox(1100, 450, 1300, 515, FontList::m_colorWhite, TRUE);
		DrawStringToHandle(1100 + 3, 450 + 3, "5.�@����\n�@10.0.0.9", FontList::m_colorBlack, FontList::m_font25);
	}
	if (m_scene >= 6) {
		DrawGraph(500, 750, m_arrowBlueG, TRUE);
		DrawBox(650, 720, 1050, 840, FontList::m_colorWhite, TRUE);
		DrawStringToHandle(650 + 3, 720 + 3, "6.�@www.denshi.com��\n�@�A�N�Z�X���Ă�����肾��\n�@�U�̃T�C�g�ɃA�N�Z�X", FontList::m_colorBlack, FontList::m_font25);
	}


	if (m_scene == 7) {
		DrawStringToHandle(50, 930, "�U�̃T�C�g�ɗU�����ꂽ�ꍇ��\n�U�T�C�g��IP�𓚂���", FontList::m_colorGreen1, FontList::m_font50);
		SetFontSize(50);
		if (KeyInputSingleCharString(1200, 960, 20, str, FALSE) == 1) {
			if (strcmp(str, "10.0.0.9") == 0) m_scene = 8;	//����
			else m_scene = 11;	//�s����
		}
		m_timer = GetNowCount();//���Ԃ�������
	}

	else if (m_scene==8) {
		DrawStringToHandle(50, 930, "�������B���̍U���̗\�h�Ƃ���\nDNS�T�[�o�̃Z�L�����e�B�����߂邱�Ƃ�", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene==9||m_scene==12) {
		SetDrawBright(bright, bright, bright);
		if (bright > 0) bright -= 2;
		else bright = 0;
	}
	else if (m_scene == 10 || m_scene == 13) {
		SceneMgr::SetScene(SCENE_LIST);
		SetDrawBright(255, 255, 255);
	}


	else if (m_scene==11) {
		DrawStringToHandle(50, 930, "�s�������c�c�B�U������Ă��܂��\���A\nDNS�T�[�o�̃Z�L�����e�B�΍��Y���ȁB", FontList::m_colorGreen1, FontList::m_font50);
	}
	return;
}
void DNS::DNSKey()
{
	if (m_scene <= 7) {
		if (GetNowCount() - m_timer <= 2 * 1000) m_scene = 0;	//2
		else if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 1;	//1
		else if (GetNowCount() - m_timer <= 4 * 1000) m_scene = 2;	//1
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 3;	//1
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 4;	//1
		else if (GetNowCount() - m_timer <= 7 * 1000) m_scene = 5;	//1
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 6;	//1
		else if (GetNowCount() - m_timer <= 9 * 1000) m_scene = 7;	//����
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) m_scene = 7;
	}
	else if (m_scene<=10) {
		if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 8;	//3
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 9;	//2
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 10;	//�I��
	}
	else if (m_scene <= 13) {
		if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 11;	//3
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 12;	//2
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 13;	//�I��
	}

	return;
}


bool DNS::IsCreated()
{
	return m_createdFlag;
}
