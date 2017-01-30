#include"hack_sessionHijack.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>


void HackHijack()
{
	static Hijack *hijack;
	if (hijack->IsCreated() == false) hijack = new Hijack();	//�R���X�g���N�^�̓����Ŏ����I��flag��true�ɕύX


	hijack->HijackMain();

	//TODO:��肪�I�������Ƃ���SetScene����悤�ɕύX���K�v

	//���̏I������
	if (SceneMgr::GetScene() == SCENE_LIST) {
		delete hijack;
		hijack = nullptr;
	}
	return;
}


bool Hijack::m_createdFlag = false;


Hijack::Hijack() :timer(0), timeFlg(0), animeFlg(0), pal(0), mail_X(1030), mail_Y(690)
{
	m_createdFlag = true;

	//�摜�ǂݍ���
	SM = LoadGraph("Image/SM.jpg");
	backScreen = LoadGraph("Image/Q_gamen.png");
	bob = LoadGraph("Image/bob.png");
	cathy = LoadGraph("Image/cathy.png");
	tom = LoadGraph("Image/tom.png");
	pc = LoadGraph("Image/pc.png");
	smartphone_Cathy = LoadGraph("Image/�L���T�z.png");
	receive1 = LoadGraph("Image/�����o���P.png");
	receive2 = LoadGraph("Image/�����o���Q.png");
	receive3 = LoadGraph("Image/�����o���R.png");
	send1 = LoadGraph("Image/�����o���S.png");
	send2 = LoadGraph("Image/�����o���T.png");
	send3 = LoadGraph("Image/�����o���U.png");
	frame = LoadGraph("Image/�g.png");
	mail = LoadGraph("Image/���[���A�C�R���P.png");
	vector_Red_R = LoadGraph("Image/���ԉE.png");
	vector_Red_L = LoadGraph("Image/���ԍ�.png");
	vector_Red_S1 = LoadGraph("Image/���Ԏ�1.png");
	vector_Red_S2 = LoadGraph("Image/���Ԏ�2.png");
	vector_Blue_S1 = LoadGraph("Image/����1.png");
	vector_Blue_S2 = LoadGraph("Image/����2.png");
	vector_Blue_S3 = LoadGraph("Image/����3.png");
	vector_Blue_LB = LoadGraph("Image/������.png");
}
Hijack::~Hijack()
{
	m_createdFlag = false;

	DeleteGraph(SM);
	DeleteGraph(backScreen);
	DeleteGraph(bob);
	DeleteGraph(cathy);
	DeleteGraph(tom);
	DeleteGraph(pc);
	DeleteGraph(smartphone_Cathy);
	DeleteGraph(receive1);
	DeleteGraph(receive2);
	DeleteGraph(receive3);
	DeleteGraph(send1);
	DeleteGraph(send2);
	DeleteGraph(send3);
	DeleteGraph(frame);
	DeleteGraph(mail);
	DeleteGraph(vector_Red_R);
	DeleteGraph(vector_Red_L);
	DeleteGraph(vector_Red_S1);
	DeleteGraph(vector_Red_S2);
	DeleteGraph(vector_Blue_S1);
	DeleteGraph(vector_Blue_S2);
	DeleteGraph(vector_Blue_S3);
	DeleteGraph(vector_Blue_LB);
}

void Hijack::HijackMain()
{
	//static int timer, timeFlg = 0, animeFlg = 0, pal = 0, mail_X = 1030, mail_Y = 690;
	if (timeFlg == 0) {
		timer = GetNowCount();
		if (animeFlg == 14)
			timeFlg = 2;
		else if (animeFlg == 21)
			timeFlg = 3;
		else
			timeFlg = 1;
	}
	HijackGraph(animeFlg, pal, mail_X, mail_Y);									//�Z�b�V�����n�C�W���b�N�`��
	HijackKey(&animeFlg, &timeFlg, &timer, &pal, &mail_X, &mail_Y);			//�Z�b�V�����n�C�W���b�N����

	return;
}


void Hijack::HijackGraph(int animeFlg, int pal, int mail_X, int mail_Y)
{

	DrawGraph(0, 0, backScreen, TRUE);
	DrawExtendGraph(300, 180, 300 + 422, 180 + 690, smartphone_Cathy, TRUE);
	DrawExtendGraph(800, 250, 800 + 267, 250 + 267, bob, TRUE);
	DrawExtendGraph(1450, 250, 1450 + 250, 250 + 250, cathy, TRUE);
	DrawStringToHandle(1535, 510, "Cathy", FontList::m_colorWhite, FontList::m_font30);
	DrawStringToHandle(905, 510, "Bob", FontList::m_colorWhite, FontList::m_font30);
	DrawStringToHandle(140, 60, "Network", FontList::m_colorGreen2, FontList::m_font65);
	DrawStringToHandle(550, 60, "�Z�b�V�����n�C�W���b�N", FontList::m_colorGreen2, FontList::m_font70);
	DrawStringToHandle(500, 250, "Bob", FontList::m_colorBlack, FontList::m_font30);


	if (animeFlg == 1 || animeFlg == 2) {
		DrawExtendGraph(1650, 183, 1650 + 240, 183 + 90, receive3, TRUE);
		DrawStringToHandle(1660, 195, "������Bob�Ƃ̃f�[�g�A\n�҂����킹�̂��ƌ���\n�Ȃ�����I", FontList::m_colorOrange1, FontList::m_font20);
	}
	if (animeFlg >= 2) {
		DrawExtendGraph(455, 300, 455 + 220, 300 + 85, send2, TRUE);
		DrawStringToHandle(460, 308, "����΂�́ABob�B\n�����͂ǂ��ő҂�����\n����H", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg == 3 || animeFlg == 4) {
		DrawExtendGraph(1030, 220, 1030 + 240, 220 + 70, receive3, TRUE);
		DrawStringToHandle(1040, 233, "�����ƁACathy�����\n���[�����B", FontList::m_colorRed, FontList::m_font20);
	}
	if (animeFlg >= 4) {
		DrawExtendGraph(345, 380, 345 + 225, 380 + 85, receive2, TRUE);
		DrawStringToHandle(355, 388, "�₠�ACathy�I\n������12�����炢�ɖl\n���������ɂ�����B", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg >= 5) {
		DrawExtendGraph(440, 460, 440 + 235, 460 + 85, send2, TRUE);
		DrawStringToHandle(445, 468, "���肪�Ƃ�Bob�I\n�����`�����ǁA���s����\n�݂������X������́I", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg >= 6) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
		DrawExtendGraph(800, 600, 800 + 250, 600 + 250, tom, TRUE);
		DrawStringToHandle(905, 860, "Tom", FontList::m_colorWhite, FontList::m_font30);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (animeFlg == 7) {
		DrawExtendGraph(1030, 530, 1030 + 285, 530 + 90, receive3, TRUE);
		DrawStringToHandle(1040, 540, "�������B\nBob�̂�A������Cathy��\n�f�[�g���Ƃ�������Ȃ����B", FontList::m_colorBlue1, FontList::m_font20);
	}
	if (animeFlg == 8) {
		DrawExtendGraph(1030, 520, 1030 + 360, 520 + 110, receive1, TRUE);
		DrawStringToHandle(1050, 585, "Cathy�͖l�ɂ������������񂾁c�c", FontList::m_colorBlue1, FontList::m_font20);
	}
	if (animeFlg == 9) {
		DrawExtendGraph(1030, 480, 1030 + 365, 480 + 150, receive1, TRUE);
		DrawStringToHandle(1055, 562, "�ז����Ă��I�I�I", FontList::m_colorBlue1, FontList::m_font35);
	}
	if (animeFlg >= 10 && animeFlg <= 13) {
		DrawExtendGraph(1230, 190, 1230 + 265, 180 + 145, frame, TRUE);
		DrawStringToHandle(1240, 200, "���M���FBob\n���M��FCathy\n�V�[�P���X�ԍ��F147\n�m�F�����ԍ��F121\n�p�P�b�g���F137(Byte)", FontList::m_colorBrown, FontList::m_font22);
	}
	if (animeFlg >= 10 && animeFlg <= 14 || animeFlg == 21) {
		DrawExtendGraph(1080, 330, 1080 + 350, 330 + 46, vector_Red_R, TRUE);
	}
	if (animeFlg >= 11 && animeFlg <= 13) {
		DrawExtendGraph(990, 435, 990 + 265, 435 + 145, frame, TRUE);
		DrawStringToHandle(1000, 445, "���M���FCathy\n���M��FBob\n�V�[�P���X�ԍ��F121\n�m�F�����ԍ��F284\n�p�P�b�g���F142(Byte)", FontList::m_colorBrown, FontList::m_font22);
	}
	if (animeFlg >= 11 && animeFlg <= 14 || animeFlg == 21) {
		DrawExtendGraph(1080, 380, 1080 + 350, 380 + 46, vector_Red_L, TRUE);
	}
	if (animeFlg >= 12 && animeFlg <= 13) {
		DrawExtendGraph(1350, 640, 1350 + 400, 640 + 200, frame, TRUE);
		DrawStringToHandle(1365, 658, "���M���FBob\n���M��FCathy\n�V�[�P���X�ԍ��F284\n�m�F�����ԍ��F������\n�p�P�b�g���F124(Byte)", FontList::m_colorBrown, FontList::m_font30);
	}
	if (animeFlg >= 12 && animeFlg <= 14 || animeFlg == 21) {
		DrawExtendGraph(1030, 540, 1030 + 396, 540 + 189, vector_Blue_S1, TRUE);
	}
	if (animeFlg >= 13) {
		DrawStringToHandle(40, 925, "Bob���ԐM��������O�ɁA�������m�F����\n�ԍ����Z�b�g���đ��M����I", FontList::m_colorGreen2, FontList::m_font50);
	}
	if (animeFlg == 14)
		DrawExtendGraph(mail_X, mail_Y, mail_X + 339 / 4, mail_Y + 223 / 4, mail, TRUE);

	if (animeFlg >= 15 && animeFlg <= 20) {
		DrawExtendGraph(345, 550, 345 + 330, 550 + 70, receive2, TRUE);
		DrawStringToHandle(350, 560, "���̓D�_�L�I\n����ȏ㎄��Bob�ɋ߂Â��Ȃ��ŁI", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg == 16) {
		DrawExtendGraph(1650, 183, 1650 + 210, 183 + 90, receive3, TRUE);
		DrawStringToHandle(1660, 195, "�D�_�L??\n�N��A���̖��B\n���������ĕ��C!?", FontList::m_colorOrange1, FontList::m_font20);
	}
	if (animeFlg >= 17 && animeFlg <= 20) {
		DrawExtendGraph(390, 620, 390 + 290, 620 + 75, send2, TRUE);
		DrawStringToHandle(395, 635, "�ǂ��������ƁH\n���������ĕ��C���Ă����!?", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg >= 18 && animeFlg <= 20) {
		DrawExtendGraph(1030, 210, 1030 + 220, 210 + 70, receive3, TRUE);
		DrawStringToHandle(1040, 223, "���C!?\n�Ӗ���������Ȃ��I", FontList::m_colorRed, FontList::m_font20);
	}
	if (animeFlg >= 19 && animeFlg <= 20) {
		DrawExtendGraph(345, 700, 345 + 330, 700 + 50, receive2, TRUE);
		DrawStringToHandle(355, 710, "�ˑR���������Ă���񂾁A�N�́H", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg == 20) {
		DrawExtendGraph(1630, 195, 1630 + 280, 195 + 70, receive3, TRUE);
		DrawStringToHandle(1635, 205, "�ȂɁA�Ƃڂ�����Ă����́H\n�������A�����m��Ȃ�!!", FontList::m_colorOrange1, FontList::m_font20);
	}



	if (animeFlg == 21) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
		DrawExtendGraph(mail_X, mail_Y, mail_X + 339 / 4, mail_Y + 223 / 4, mail, TRUE);
	}
	if (animeFlg >= 21) {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawExtendGraph(800, 600, 800 + 250, 600 + 250, tom, TRUE);
		DrawStringToHandle(905, 860, "Tom", FontList::m_colorWhite, FontList::m_font30);

	}
	if (animeFlg == 22) {
		DrawExtendGraph(1030, 520, 1030 + 300, 520 + 120, receive1, TRUE);
		DrawStringToHandle(1050, 580, "����A�����������B\n�Ȃ�ŁA�Ȃ�œ͂��Ȃ��H", FontList::m_colorBlue1, FontList::m_font20);
	}
	if (animeFlg == 23) {
		DrawExtendGraph(1030, 500, 1030 + 365, 500 + 110, receive1, TRUE);
		DrawStringToHandle(1055, 565, "�����A���ꂶ�Ⴀ�l��Cathy���c", FontList::m_colorBlue1, FontList::m_font20);
	}

	return;
}
void Hijack::HijackKey(int *animeFlg, int *timeFlg, int *timer, int *pal, int *mail_X, int *mail_Y)
{
	if (*timeFlg == 1 && (GetNowCount() - *timer) < 31000) {
		if (2000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 4000)
			*animeFlg = 1;
		else if (4000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 6000)
			*animeFlg = 2;
		else if (6000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 8000)
			*animeFlg = 3;
		else if (8000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 10000)
			*animeFlg = 4;
		else if (10000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 12000)
			*animeFlg = 5;
		else if (12000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 15000) {
			*animeFlg = 6;
			if (*pal < 255)
				*pal += 2;
		}
		else if (15000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 18000)
			*animeFlg = 7;
		else if (18000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 20000)
			*animeFlg = 8;
		else if (20000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 22000)
			*animeFlg = 9;
		else if (22000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 24000)
			*animeFlg = 10;
		else if (24000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 26000)
			*animeFlg = 11;
		else if (26000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 28000)
			*animeFlg = 12;
		else if (28000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 29000) {
			*animeFlg = 13;
		}
		else if (29000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 31000) {
			SetFontSize(80);
			if (KeyInputNumber(1150, 945, 9999, 0, FALSE) == 263)
				*animeFlg = 14;
			else
				*animeFlg = 21;
			*timeFlg = 0;
		}
	}
	else if (*timeFlg == 2 && (GetNowCount() - *timer) < 20000) {
		if (1000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 4000) {
			if (*mail_X < 1370)
				*mail_X += 4;
			if (*mail_Y > 520)
				*mail_Y -= 2;
		}
		else if (4000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 6000) {
			*animeFlg = 15;
		}
		else if (6000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 9000) {
			*animeFlg = 16;
		}
		else if (9000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 11000) {
			*animeFlg = 17;
		}
		else if (11000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 13000) {
			*animeFlg = 18;
		}
		else if (13000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 15000) {
			*animeFlg = 19;
		}
		else if (15000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 18000) {
			*animeFlg = 20;
		}
		else if((GetNowCount() - *timer) > 18000){
			*animeFlg = 30;
		}
	}

	else if (*timeFlg == 3 && (GetNowCount() - *timer) < 20000) {
		if (1000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 4000) {
			if (*mail_X < 1370)
				*mail_X += 4;
			if (*mail_Y > 520)
				*mail_Y -= 2;
			if (*pal > 0)
				*pal -= 3;
		}
		else if (4000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 7000)
			*animeFlg = 22;
		else if (6000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 8000)
			*animeFlg = 23;
		else if ((GetNowCount() - *timer) > 10000) {
			*animeFlg = 30;
		}
	}

	if (*animeFlg==30) {
		SceneMgr::SetScene(SCENE_LIST);
	}


	return;
}


bool Hijack::IsCreated()
{
	return m_createdFlag;
}






