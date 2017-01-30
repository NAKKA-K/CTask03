#include"hack_BOF.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>

void HackBOF()
{
	/*�b�ɏオ���Ă����̂Ō��_���L�q����
	  static�Ő錾���ꂽBOF* bof;�͎��s���ɐÓI�̈�Ɋm�ۂ����B
	  ���̌�new�ɂ��A�t���[�X�g�A��BOFClass���̗̈���m�ۂ���B
	*/
	static BOF *bof;
	if (bof->IsCreated()==false) bof = new BOF();	//�R���X�g���N�^�̓����Ŏ����I��flag��true�ɕύX


	bof->BOFGraph();		//�����A�j���[�V�����⑀��A�j���[�V����
	bof->BOFKey();

	//���̏I������
	if (SceneMgr::GetScene()== SCENE_LIST) {
		/*delete���Ă�new�Ŏ擾�����t���[�X�g�A���������邾���ŁAbof�̃A�h���X�������������킯�ł͂Ȃ��B
		  (�s��l���������Ă���)���̂��߁A���������Anullptr�ŏ��������Ă���B
		  �����Ă���2���͊֐���������Ɛ���ɋ@�\���Ȃ����߂��̂܂ܓW�J���Ă���B
		*/
		delete bof;
		bof = nullptr;
	}
	return;
}


bool BOF::m_createdFlag = false;

BOF::BOF() :m_scene(0),m_timer(0),m_alpha(0),bright(255)
{
	m_createdFlag = true;
	//memset(str, '\0', sizeof(str));

	//���W�ϐ��̏�����
	bobP[0] = 1200, bobP[1] = 500;	
	webAppP[0] = 100, webAppP[1] = 300, webAppP[2] = 1000, webAppP[3] = 750;

	//�摜�ǂݍ���
	m_bobG = LoadGraph("Image/bob.png");
	m_cathyG = LoadGraph("Image/cathy.png");
	m_tomG = LoadGraph("Image/tom.png");
//	m_hackBG = LoadGraph("Image/learn.png");
	m_hackBG = LoadGraph("Image/Q_gamen.png");
	m_balloonG[0] = LoadGraph("Image/balloon2.png");
	m_balloonG[1] = LoadGraph("Image/balloon5.png");
	m_webAppG = LoadGraph("Image/webApp2.png");


	SetKeyInputStringColor(FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack);

	m_timer = GetNowCount();
}
BOF::~BOF()
{
	m_createdFlag = false;
	//�摜����
	DeleteGraph(m_bobG);
	DeleteGraph(m_cathyG);
	DeleteGraph(m_tomG);
	DeleteGraph(m_hackBG);
	DeleteGraph(m_balloonG[0]);
	
	DeleteGraph(m_webAppG);
}

void BOF::BOFGraph()
{
	DrawGraph(0, 0, m_hackBG, FALSE);
	DrawStringToHandle(100, 45, "Program", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, "BOF�U��", FontList::m_colorGreen1, FontList::m_font100);


	/*��1�͊J�n*/
	//int bobP[2] = { 1200, 500 };	�����o�ϐ��Ɉړ�
	//int webAppP[4]={100,300,1000,750};	//�����o�ϐ��Ɉړ�
	if (m_scene <= 12) {
		DrawExtendGraph(webAppP[0], webAppP[1], webAppP[2], webAppP[3], m_webAppG, TRUE);	//bob�̌��J���Ă���T�C�g(2�͂͊g��)
		DrawExtendGraph(bobP[0], bobP[1], bobP[0] + 250, bobP[1] + 250, m_bobG, TRUE);	//(2�͂ɂȂ�ƈʒu���ړ�)
		if (m_scene <= 8) DrawGraph(1600, 500, m_cathyG, TRUE);	//TODO:�t�F�[�h�A�E�g(2�͂ɂȂ�Ə�����)
		else if (m_scene >= 10) DrawGraph(1600, 650, m_tomG, TRUE);
	}
	else if (m_scene <= 30) {
		DrawExtendGraph(webAppP[0], webAppP[1], webAppP[2], webAppP[3], m_webAppG, TRUE);	//�ŏI�ʒu�A(�T�C�g�g��)
		DrawExtendGraph(bobP[0], bobP[1], bobP[0] + 250, bobP[1] + 250, m_bobG, TRUE);//�ŏI�ʒu�A1600, 170, +200,+250
		DrawGraph(1600, 650, m_tomG, TRUE);
	}
	if (m_scene >= 15 && m_scene <= 24) {
		for (int i = 1; i <= 5; i++) DrawFormatStringToHandle(webAppP[0] + 90, webAppP[1] + 50 + 120 * i, FontList::m_colorBlack, FontList::m_font50, "%s%s", str, str);
	}
	else if (m_scene >= 25) DrawFormatStringToHandle(webAppP[0] + 500, webAppP[1] + 600, FontList::m_colorBlack, FontList::m_font30, "%s�l�A��������Ⴂ�܂��B", str);


	const int bobSP1[2] = { 1100,350 };	//bob�̃R�����g�\�����W
	const int cathySP1[2] = { 1500,350 };	//cathy�̃R�����g�\�����W
	const int bobSP2[2] = { 1500,400 };
	const int tomSP2[2] = { 1500,550 };

	if (m_scene == 0) {
		DrawExtendGraph(cathySP1[0] - 5, cathySP1[1] - 5, cathySP1[0] + 300, cathySP1[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(cathySP1[0], cathySP1[1], "�n���[Bob�I", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 1) {
		DrawExtendGraph(bobSP1[0] - 5, bobSP1[1] - 5, bobSP1[0] + 300, bobSP1[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP1[0], bobSP1[1], "�₠�ACathy�I", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 2) {
		DrawExtendGraph(cathySP1[0] - 5, cathySP1[1] - 5, cathySP1[0] + 410, cathySP1[1] + 150, m_balloonG[1], TRUE);
		DrawStringToHandle(cathySP1[0], cathySP1[1], "�O�Ɍ����Ă��A\n�l�b�g�Ɍ��J���Ă�T�C�g��\n���q�͂ǂ��H", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 3) {
		DrawExtendGraph(bobSP1[0] - 5, bobSP1[1] - 5, bobSP1[0] + 420, bobSP1[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP1[0], bobSP1[1], "�����A����Ȃ�ɒ��q������B", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 4) {
		DrawExtendGraph(bobSP1[0] - 5, bobSP1[1] - 5, bobSP1[0] + 420, bobSP1[1] + 150, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP1[0], bobSP1[1], "���߂Č��J�����T�C�g������A\n�����Ȃ���Ȃ�Ȃ�����\n�����ς����邯�ǂˁB", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 5) {
		DrawExtendGraph(cathySP1[0] - 5, cathySP1[1] - 5, cathySP1[0] + 420, cathySP1[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(cathySP1[0], cathySP1[1], "�ւ��A����ς�Bob�͐����ȁB", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 6) {
		DrawExtendGraph(cathySP1[0] - 5, cathySP1[1] - 5, cathySP1[0] + 400, cathySP1[1] + 150, m_balloonG[1], TRUE);
		DrawStringToHandle(cathySP1[0], cathySP1[1], "���ɂł��Ȃ����Ƃ�\n���R�Ƃ���Ă̂���I\n������Ⴢ�邵�A������I", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 7) {
		DrawExtendGraph(cathySP1[0] - 5, cathySP1[1] - 5, cathySP1[0] + 400, cathySP1[1] + 100, m_balloonG[1], TRUE);
		DrawStringToHandle(cathySP1[0], cathySP1[1], "���ႠBob�A�撣���ĂˁB\n�o�CBob�I", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 8) {
		DrawExtendGraph(bobSP1[0] - 5, bobSP1[1] - 5, bobSP1[0] + 350, bobSP1[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP1[0], bobSP1[1], "�͂�w�A�܂���Cathy�B", FontList::m_colorBlack, FontList::m_font30);
	}
	/*��1�͏I���@&�@��2�͊J�n*/
	else if (m_scene == 9) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);//tom�t�F�[�h�C��
		DrawGraph(1600, 650, m_tomG, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (m_alpha<=255) m_alpha += 2;
	}
	else if (m_scene == 10) {
		DrawExtendGraph(tomSP2[0] - 5, tomSP2[1] - 5, tomSP2[0] + 400, tomSP2[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "BobBobBobBob�I�I�I", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 11) {
		DrawExtendGraph(tomSP2[0] - 10, tomSP2[1] - 5, tomSP2[0] + 420, tomSP2[1] + 100, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0]-5, tomSP2[1], "�l��Cathy��\n����ꂵ�����₪���Ă������I�I", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 12) {
		DrawExtendGraph(tomSP2[0] - 5, tomSP2[1] - 5, tomSP2[0] + 420, tomSP2[1] + 100, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "�z�̃T�C�g��\n�ނ��Ⴍ����ɂ��Ă��c�c", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 13) {
		if (bobP[0] < 1600) bobP[0] += 6;//�E��Ɉړ�
		if (bobP[1] > 170) bobP[1] -= 4;
		if (webAppP[0]>10) webAppP[0] -= 2;//�T�C�g�̊g��
		if (webAppP[1]>160) webAppP[1] -= 2;
		if (webAppP[2]<1500) webAppP[2] += 6;
		if (webAppP[3]<900) webAppP[3] += 4;	
	}
	else if (m_scene == 14) {
		DrawExtendGraph(tomSP2[0]-5, tomSP2[1]-5, tomSP2[0] +400, tomSP2[1] + 100, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "char str[16];\nscanf(\"%s\",str);", FontList::m_colorBlack, FontList::m_font30);
		SetFontSize(50);
		DrawStringToHandle(50,950, "BOF�U�����d�|���ăT�C�g���߂��Ⴍ����ɂ��Ă��I", FontList::m_colorGreen1	, FontList::m_font50);
		if (KeyInputString(460, 640, 22, str, FALSE) == 1) {
			if (strlen(str) >= 17) m_scene = 15;	//����
			else m_scene = 25;	//�s����
		}
		m_timer = GetNowCount();//���Ԃ�������
	}
	/*��2�͏I���@&�@��3�͊J�n*/
	else if (m_scene == 15) {
		DrawExtendGraph(tomSP2[0] - 5, tomSP2[1] - 5, tomSP2[0] + 380, tomSP2[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "�n�n�b�I�I�������I�I", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 16) {
		DrawExtendGraph(bobSP2[0] + 350, bobSP2[1] + 50,bobSP2[0] - 15, bobSP2[1] - 15, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP2[0], bobSP2[1], "�ȁA��������I�H", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 17) {
		DrawExtendGraph(bobSP2[0] + 420, bobSP2[1] + 50, bobSP2[0] - 15, bobSP2[1] - 15, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP2[0], bobSP2[1], "�Ƃ肠�������Ƃ����Ȃ���c�c", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 18) {
		DrawExtendGraph(tomSP2[0] - 5, tomSP2[1] - 5, tomSP2[0] + 420, tomSP2[1] + 100, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "���l���ȁABob�B\n����ς�Cathy�͖l���c�c�I", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 19 || m_scene == 27) {
		SetDrawBright(bright, bright, bright);
		if (bright > 0) bright -= 2;
		else bright = 0;
	}
	else if (m_scene == 20 || m_scene == 28) {
		SceneMgr::SetScene(SCENE_LIST);
		SetDrawBright(255, 255, 255);
	}
	//�s����
	else if (m_scene == 25) {
		DrawExtendGraph(tomSP2[0] - 5, tomSP2[1] - 5, tomSP2[0] + 380, tomSP2[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "�����I�_�����c�c", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 26) {
		DrawExtendGraph(bobSP2[0] + 380, bobSP2[1] + 100, bobSP2[0] - 15, bobSP2[1] - 15, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP2[0], bobSP2[1], "�������������ȁB\n�悵�A�撣�낤�B", FontList::m_colorBlack, FontList::m_font30);
	}
	/*
	else if (m_scene == 27) {
		SetDrawBright(bright, bright, bright);
		if (bright>0) bright -= 2;
		else bright = 0;
	}
	else if (m_scene == 28) {
		SceneMgr::SetScene(SCENE_LIST);
		SetDrawBright(255, 255, 255);
	}
	*/
	return;
}
void BOF::BOFKey()
{
	/*��1�͊J�n*/
	if (m_scene <= 14) {
		if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 0;	//3
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 1;//2
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 2;//3
		else if (GetNowCount() - m_timer <= 10 * 1000) m_scene = 3;//2
		else if (GetNowCount() - m_timer <= 14 * 1000) m_scene = 4;//4
		else if (GetNowCount() - m_timer <= 16 * 1000) m_scene = 5;//2
		else if (GetNowCount() - m_timer <= 20 * 1000) m_scene = 6;//4
		else if (GetNowCount() - m_timer <= 22 * 1000) m_scene = 7;//2
		else if (GetNowCount() - m_timer <= 24 * 1000) m_scene = 8;//2
		/*��1�͏I���@&�@��2�͊J�n*/
		else if (GetNowCount() - m_timer <= 28 * 1000) m_scene = 9;
		else if (GetNowCount() - m_timer <= 32 * 1000) m_scene = 10;
		else if (GetNowCount() - m_timer <= 36 * 1000) m_scene = 11;
		else if (GetNowCount() - m_timer <= 38 * 1000) m_scene = 12;
		else if (GetNowCount() - m_timer <= 42 * 1000) m_scene = 13;
		else if (GetNowCount() - m_timer <= 46 * 1000) m_scene = 14;
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
			m_scene = 14;	//�C�x���g�X�L�b�v
			bobP[0] = 1600, bobP[1] = 170;	//�C�x���g�X�L�b�v�����p
			webAppP[0] = 10, webAppP[1] = 160, webAppP[2] = 1500, webAppP[3] = 900;
		}
	}
	/*��2�͏I���@&�@��3�͊J�n*/
	else if (m_scene <= 21) {	//����
		if (GetNowCount() - m_timer <= 4 * 1000) m_scene = 15;//2
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 16;//2
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 17;//2
		else if (GetNowCount() - m_timer <= 12 * 1000) m_scene = 18;//4
		else if (GetNowCount() - m_timer <= 16 * 1000) m_scene = 19;//4�t�F�[�h�A�E�g
		else if (GetNowCount() - m_timer <= 18* 1000) m_scene = 20;
	}
	else if (m_scene<=30) {	//�s����
		if (GetNowCount() - m_timer <= 4 * 1000) m_scene = 25;
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 26;
		else if (GetNowCount() - m_timer <= 10 * 1000) m_scene = 27;
		else if (GetNowCount() - m_timer <= 12 * 1000) m_scene = 28;

	}

	return;
}
bool BOF::IsCreated()
{
	return m_createdFlag;
}
