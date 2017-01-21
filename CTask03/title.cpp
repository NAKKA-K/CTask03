#include "title.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include<DxLib.h>
#include"font_list.h"
#include"menu_graph_list.h"

Title::Title()	//�K�v�ȉ摜�A�F�A����
{
}
Title::~Title()
{
}


//�`��
void Title::TitleGraph()
{
	static int a=0, cnt, x, i, bin_y;

	if (x <= 1920) {	//�@�p���X�𑖂点��`��
		DrawGraph(0, 0, MenuGraphList::m_pulse, TRUE);
		DrawBox(x, 580, 1920, 1080, FontList::m_colorBlack, TRUE);
		DrawBox(0, 0, 1920 - x, 390, FontList::m_colorBlack, TRUE);
		x += 20;
	}else if( i < 7 ){	//�@�^�C�g���̕�����`��
		const int title_x[7] = { 660, 750, 860, 950, 1035 , 1120, 1200};
		DrawGraph(0, 0, MenuGraphList::m_titleG, TRUE);
		DrawBox(title_x[i], 480, 1200, 610, FontList::m_colorBlack, TRUE);
		DrawGraph(0, 0, MenuGraphList::m_pulse, TRUE);

		cnt+=1;
		if (cnt % 20 == 0) {
			i++;
		}
	} else if (bin_y <= 1080) {	//01�̔w�i��`��
		DrawGraph(0, 0, MenuGraphList::m_bin, TRUE);
		DrawBox(0, bin_y, 1920, 1080, FontList::m_colorBlack, TRUE);
		DrawGraph(0, 0, MenuGraphList::m_pulse, TRUE);
		DrawGraph(0, 0, MenuGraphList::m_titleG, TRUE);
		bin_y += 23;

	} else {	//�@�S�ẴA�j���[�V�����I�����ɌŒ�`��
		DrawGraph(0, 0, MenuGraphList::m_bin, TRUE);
		DrawGraph(0, 0, MenuGraphList::m_pulse, TRUE);
		DrawGraph(0, 0, MenuGraphList::m_titleG, TRUE);
	}
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {	//�@�G���^�[�L�[���͎��ɏ�����
		x = 0;
		i = 0;
		bin_y = 0;
	}


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
