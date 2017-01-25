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
}

void DNS::DNSGraph()
{
	DrawGraph(0, 0, m_hackBG, FALSE);
	DrawStringToHandle(100, 45, "Network", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, "DNS�L���b�V���|�C�Y�j���O", FontList::m_colorGreen1, FontList::m_font100);

/*
SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);//tom�t�F�[�h�C��
SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
if (m_alpha <= 255) m_alpha += 2;
*/


/*
SetDrawBright(bright, bright, bright);
if (bright > 0) bright -= 2;
else bright = 0;
*/
/*
SceneMgr::SetScene(SCENE_LIST);
SetDrawBright(255, 255, 255);
*/

	if (m_scene == 0) {}
	else if (m_scene == 1) {}
	else if (m_scene == 3) {
		//DrawStringToHandle(50, 930, "2�l��DNS�L���b�V����MAC������������\n�ʐM�𓐒�����I", FontList::m_colorGreen1, FontList::m_font50);
		SetFontSize(50);
		if (KeyInputSingleCharString(1200, 960, 20, str, FALSE) == 1) {
			if (strcmp(str, "00:00:00:AB:AB:AB") == 0) m_scene = 5;	//����
			else m_scene = 10;	//�s����
		}
		m_timer = GetNowCount();//���Ԃ�������
	}
	else if (m_scene == 0) {
	}
	else if (m_scene == 1) {
	}

	return;
}
void DNS::DNSKey()
{
	if (m_scene <= 4) {
		if (GetNowCount() - m_timer <= 2 * 1000) m_scene = 0;	//2
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) m_scene = 3;
	}

	return;
}


bool DNS::IsCreated()
{
	return m_createdFlag;
}
