#include"hack_ARPPoisoning.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>


void HackARP()
{
	/*�b�ɏオ���Ă����̂Ō��_���L�q����
	static�Ő錾���ꂽARP* bof;�͎��s���ɐÓI�̈�Ɋm�ۂ����B
	���̌�new�ɂ��A�t���[�X�g�A��ARPClass���̗̈���m�ۂ���B
	*/
	static ARP *arp;
	if (arp->IsCreated() == false) arp = new ARP();	//�R���X�g���N�^�̓����Ŏ����I��flag��true�ɕύX


	arp->ARPGraph();		//�����A�j���[�V�����⑀��A�j���[�V����
	arp->ARPKey();

	//���̏I������
	if (SceneMgr::GetScene() == SCENE_LIST) {
		delete arp;
		arp = nullptr;
	}
	return;
}

bool ARP::m_createdFlag = false;


ARP::ARP() :m_scene(0), m_timer(0), m_alpha(0), bright(255)
{
	m_createdFlag = true;

	//���W�ϐ��̏�����

	//�摜�ǂݍ���
	//	m_hackBG = LoadGraph("Image/learn.png");
	m_hackBG = LoadGraph("Image/Q_gamen.png");
	m_bobG = LoadGraph("Image/bob.png");
	m_cathyG = LoadGraph("Image/cathy.png");
	m_tomG = LoadGraph("Image/tom.png");


	SetKeyInputStringColor(FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1,
		FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1,
		FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1,
		FontList::m_colorGreen1, FontList::m_colorGreen1, FontList::m_colorGreen1);

	m_timer = GetNowCount();
}
ARP::~ARP()
{
	m_createdFlag = false;
	//�摜����
	DeleteGraph(m_hackBG);
}

void ARP::ARPGraph()
{
	DrawGraph(0, 0, m_hackBG, FALSE);
	DrawStringToHandle(100, 45, "Network", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, "ARP�L���b�V���|�C�Y�j���O", FontList::m_colorGreen1, FontList::m_font100);



	DrawExtendGraph(100, 300, 300, 500, m_bobG, TRUE);
	DrawGraph(1600, 300, m_cathyG, TRUE);

	if (m_scene>=0) {
		DrawBox(300, 200, 750, 500, FontList::m_colorWhite, TRUE);
		DrawBox(300+2, 300, 750-2, 500-2, FontList::m_colorBlue, TRUE);//White1
		DrawStringToHandle(300 + 5, 200 + 5, "Bob", FontList::m_colorBlue, FontList::m_font30);
		DrawStringToHandle(300 + 5, 200 + 35, "IP: 192.168.0.100", FontList::m_colorBlue, FontList::m_font30);
		DrawStringToHandle(300 + 5, 200 + 65, "MAC: 00:00:00:AA:AA:AA", FontList::m_colorBlue, FontList::m_font30);

		DrawStringToHandle(300 + 5, 320 + 5, "������ARP�L���b�V��", FontList::m_colorWhite, FontList::m_font30);
		DrawStringToHandle(300 + 5, 320 + 55, "IP: 192.168.0.200=", FontList::m_colorWhite, FontList::m_font30);
		if(m_scene<=1) DrawStringToHandle(300 + 5, 320 + 105, "MAC: 00:00:00:BB:BB:BB", FontList::m_colorWhite, FontList::m_font30);


		DrawBox(1150, 200, 1600, 500, FontList::m_colorWhite, TRUE);
		DrawBox(1150 + 2, 300, 1600 - 2, 500 - 2, FontList::m_colorBlue, TRUE);//white1
		DrawStringToHandle(1150 + 5, 200 + 5, "Cathy", FontList::m_colorBlue, FontList::m_font30);
		DrawStringToHandle(1150 + 5, 200 + 35, "IP: 192.168.0.200", FontList::m_colorBlue, FontList::m_font30);
		DrawStringToHandle(1150 + 5, 200 + 65, "MAC: 00:00:00:BB:BB:BB", FontList::m_colorBlue, FontList::m_font30);

		DrawStringToHandle(1150 + 5, 320 + 5, "������ARP�L���b�V��", FontList::m_colorWhite, FontList::m_font30);
		DrawStringToHandle(1150 + 5, 320 + 55, "IP: 192.168.0.100=", FontList::m_colorWhite, FontList::m_font30);
		if (m_scene <= 1) DrawStringToHandle(1150 + 5, 320 + 105, "MAC: 00:00:00:AA:AA:AA", FontList::m_colorWhite, FontList::m_font30);

	}
	if (m_scene>=2) {
		DrawBox(800, 600, 1250, 900, FontList::m_colorWhite, TRUE);
		DrawBox(800 + 2, 700, 1250 - 2, 900 - 2, FontList::m_colorBlue, TRUE);//white1
		DrawStringToHandle(800 + 5, 600 + 5, "Tom(������)", FontList::m_colorBlue, FontList::m_font30);
		DrawStringToHandle(800 + 5, 600 + 35, "IP: 192.168.0.300", FontList::m_colorBlue, FontList::m_font30);
		DrawStringToHandle(800 + 5, 600 + 65, "MAC: 00:00:00:AB:AB:AB", FontList::m_colorBlue, FontList::m_font30);

		DrawStringToHandle(800 + 5, 700 + 5, "������ARP�L���b�V��", FontList::m_colorWhite, FontList::m_font30);
		DrawStringToHandle(800 + 5, 700 + 35, "IP: 192.168.0.100=", FontList::m_colorWhite, FontList::m_font30);
		DrawStringToHandle(800 + 5, 700 + 65, "MAC: 00:00:00:AA:AA:AA", FontList::m_colorWhite, FontList::m_font30);
		DrawStringToHandle(800 + 5, 700 + 125, "IP: 192.168.0.200=", FontList::m_colorWhite, FontList::m_font30);
		DrawStringToHandle(800 + 5, 700 + 155, "MAC: 00:00:00:BB:BB:BB", FontList::m_colorWhite, FontList::m_font30);
		DrawGraph(1300, 650, m_tomG, TRUE);
	}

	if (m_scene == 0) {}
	else if (m_scene==1) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);//tom�t�F�[�h�C��
		DrawBox(800, 600, 1250, 900, FontList::m_colorWhite, TRUE);
		DrawBox(800 + 2, 700, 1250 - 2, 900 - 2, FontList::m_colorBlue, TRUE);//white1
		DrawStringToHandle(800 + 5, 600 + 5, "Tom(������)", FontList::m_colorBlue, FontList::m_font30);
		DrawStringToHandle(800 + 5, 600 + 35, "IP: 192.168.0.300", FontList::m_colorBlue, FontList::m_font30);
		DrawStringToHandle(800 + 5, 600 + 65, "MAC: 00:00:00:AB:AB:AB", FontList::m_colorBlue, FontList::m_font30);

		DrawStringToHandle(800 + 5, 700 + 5, "������ARP�L���b�V��", FontList::m_colorWhite, FontList::m_font30);
		DrawStringToHandle(800 + 5, 700 + 35, "IP: 192.168.0.100=", FontList::m_colorWhite, FontList::m_font30);
		DrawStringToHandle(800 + 5, 700 + 65, "MAC: 00:00:00:AA:AA:AA", FontList::m_colorWhite, FontList::m_font30);
		DrawStringToHandle(800 + 5, 700 + 125, "IP: 192.168.0.200=", FontList::m_colorWhite, FontList::m_font30);
		DrawStringToHandle(800 + 5, 700 + 155, "MAC: 00:00:00:BB:BB:BB", FontList::m_colorWhite, FontList::m_font30);
		DrawGraph(1300, 650, m_tomG, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (m_alpha <= 255) m_alpha += 2;
	}
	else if (m_scene == 2) {}
	else if (m_scene == 3) {
		DrawBox(300 + 4, 425, 750 - 50, 425+30, FontList::m_colorWhite, TRUE);
		DrawBox(1150 + 4, 425, 1600 - 50, 425+30, FontList::m_colorWhite, TRUE);
		DrawStringToHandle(300 + 5, 320 + 105, "MAC: ", FontList::m_colorBlue, FontList::m_font30);
		DrawStringToHandle(1150 + 5, 320 + 105, "MAC: ", FontList::m_colorBlue, FontList::m_font30);

		DrawStringToHandle(50, 930, "2�l��ARP�L���b�V����MAC������������\n�ʐM�𓐒�����I", FontList::m_colorGreen1, FontList::m_font50);
		SetFontSize(50);
		if (KeyInputSingleCharString(1200, 960, 20, str, FALSE) == 1) {
			if (strcmp(str, "00:00:00:AB:AB:AB") == 0) m_scene = 5;	//����
			else m_scene = 10;	//�s����
		}
		m_timer = GetNowCount();//���Ԃ�������
	}
	else if (m_scene==5) {
		DrawStringToHandle(50, 930, "�ʐM�̓����ɐ�������!�����Ă���f�[�^��\n���ł����邱�Ƃ��ł��邼�B", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene == 6 || m_scene == 11) {
		SetDrawBright(bright, bright, bright);
		if (bright > 0) bright -= 2;
		else bright = 0;
	}
	else if (m_scene == 7 || m_scene == 12) {
		SceneMgr::SetScene(SCENE_LIST);
		SetDrawBright(255, 255, 255);
	}

	else if (m_scene == 10) {
		DrawStringToHandle(50, 950, "�ʐM�̓����Ɏ��s�����B", FontList::m_colorGreen1, FontList::m_font50);
	}

	return;
}
void ARP::ARPKey()
{
	if (m_scene <= 4) {
		if (GetNowCount() - m_timer <= 2 * 1000) m_scene = 0;	//2
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 1;//4
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 2;//4
		else if (GetNowCount() - m_timer <= 10 * 1000) m_scene = 3;//���
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) m_scene = 3;
	}
	else if (m_scene <= 9) {//����
		if (GetNowCount() - m_timer <= 4 * 1000) m_scene = 5;	//4
		else if (GetNowCount() - m_timer <= 7 * 1000) m_scene = 6;//3
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 7;//3
	}
	else if (m_scene <= 20) {//�s����
		if (GetNowCount() - m_timer <= 4 * 1000) m_scene = 10;	//4
		else if (GetNowCount() - m_timer <= 7 * 1000) m_scene = 11;//3
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 12;//3
	}

	return;
}


bool ARP::IsCreated()
{
	return m_createdFlag;
}
