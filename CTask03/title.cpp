#include "title.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include<DxLib.h>

Title::Title()	//�K�v�ȉ摜�A�F�A����
{
	t_pulse = LoadGraph("pulse.png");
	t_titleG = LoadGraph("Title.png");
	t_bin = LoadGraph("bin.png");
	m_font100 = CreateFontToHandle("���C���I", 100, 3);
	CrBlack = GetColor(0 ,0, 0);
}
Title::~Title()
{
	DeleteFontToHandle(m_font100);
	DeleteGraph(t_pulse);
	DeleteGraph(t_titleG);
	DeleteGraph(t_bin);
}


//�`��
void Title::TitleGraph()
{
	static int a=0, cnt, x, i, bin_y;

	if (x <= 1920) {	//�@�p���X�𑖂点��`��
		DrawGraph(0, 0, t_pulse, TRUE);
		DrawBox(x, 580, 1920, 1080, CrBlack, TRUE);
		DrawBox(0, 0, 1920 - x, 390, CrBlack, TRUE);
		x += 20;
	}else if( i < 7 ){	//�@�^�C�g���̕�����`��
		const int title_x[7] = { 660, 750, 860, 950, 1035 , 1120, 1200};
		DrawGraph(0, 0, t_titleG, TRUE);
		DrawBox(title_x[i], 480, 1200, 610, CrBlack, TRUE);
		DrawGraph(0, 0, t_pulse, TRUE);

		cnt+=1;
		if (cnt % 20 == 0) {
			i++;
		}
	} else if (bin_y <= 1080) {	//01�̔w�i��`��
		DrawGraph(0, 0, t_bin, TRUE);
		DrawBox(0, bin_y, 1920, 1080, CrBlack, TRUE);
		DrawGraph(0, 0, t_pulse, TRUE);
		DrawGraph(0, 0, t_titleG, TRUE);
		bin_y += 23;
		
	} else {	//�@�S�ẴA�j���[�V�����I�����ɌŒ�`��
		DrawGraph(0, 0, t_bin, TRUE);
		DrawGraph(0, 0, t_pulse, TRUE);
		DrawGraph(0, 0, t_titleG, TRUE);
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
