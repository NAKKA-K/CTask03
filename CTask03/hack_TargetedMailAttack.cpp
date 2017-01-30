#include<DxLib.h>
#include"Keyboard.h"
#include"font_list.h"
#include"hack_TargetedMailAttack.h"
#include"scene_mgr.h"
//#include<stdlib.h>
#include<time.h>
#include<stdio.h>

#define MAIL_SIZE 600
#define MAIL_SPACE 50
#define CNTMAX 2

static int mail_scene;

char q_num[3], question[64], choice[11][255], ans1[3];
int ans;


bool MAIL::m_createdFlag = false;

MAIL::MAIL()
{
	MailBG = LoadGraph("Image/Q_gamen.png");
	m_falseG = LoadGraph("Image/false.png");
	m_createdFlag = true;

}
MAIL::~MAIL()
{
	DeleteGraph(MailBG);
	DeleteGraph(m_falseG);
	m_createdFlag = false;
}

/*
��������������������������������������������������������������������������
���֐�����MAIL::Init															��
��������������������������������������������������������������������������
���@  �\��������														��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����E															��
��������������������������������������������������������������������������*/
void MAIL::Init(void)
{
	mail_scene = 0;
}
/*
��������������������������������������������������������������������������
���֐�����MAIL::Putstring														��
��������������������������������������������������������������������������
���@  �\��������̉��s													��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����Ex�F������̐擪��\������X���W								��
���@�@�@���Ey�F������̐擪��\������Y���W								��
���@�@�@���Ekaigyo�F���s�œ������W�iY���W�j								��
���@�@�@���Estr�F���s����O�̕�����										��
���@�@�@���EWordCount�F���̕������ɓ��B����Ɖ��s������s��				��
���@�@�@���EcolorFlg�F�O�̎��͍������A�P�̎��͐����ŕ\������			��
��������������������������������������������������������������������������*/
void MAIL::Putstring(int x, int y, int kaigyo, char str[255], int WordCount, int colorFlg) {
	char work[64];

	int i = 0;
	while (str[i] != '\0') {
		memset(work, '\0', sizeof(work));	//work�̏�����
		int cnt = 0;
		int j = 0;
		for (j = 0; j < WordCount && str[i] != '\0'; i++, j++) {
			if (str[i] == '$') {	//���s�p�R�[�h'$'
				i++;
				break;
			}

			//2Byte�����Ȃ�A2Byte�����Ɋi�[
			if (j == WordCount - 2 && str[i] >= 0x80) {
				if (str[i - 1] >= 0x80) {
					for (cnt = i - 1; str[cnt] >= 0x80; cnt--) {}
					if (i - cnt % 2 == 0) {
						work[j++] = str[i++];
						work[j++] = str[i++];
						break;
					}
					else {
						work[j++] = str[i++];
						break;
					}
				}
				else {
					work[j++] = str[i++];
					work[j++] = str[i++];
					break;
				}
			}
			if (j == WordCount - 2 && str[i] < 0x80) {
				work[j++] = str[i++];
				work[j++] = str[i++];
				break;
			}
			work[j] = str[i];
			//1Byte�����Ȃ�A1Byte�����i�[
			/*else {
			strncat_s(work, sizeof(work), str + i, 1);
			}*/
		}

		//1�s�̎w�蕶�������I�[�o�[������
		/*if (j >= WordCount + 1) {
		i -= 2;
		j -= 2;
		}*/
		work[j] = '\0';

		//1�s�o�͌�A���s
		if (colorFlg == 0) {
			DrawString(x, y, work, FontList::m_colorBlack);
		}
		else {
			DrawString(x, y, work, FontList::m_colorBlue);
		}
		y += kaigyo;
	}
}

/*
��������������������������������������������������������������������������
���֐�����MAIL::MailFrame														��
��������������������������������������������������������������������������
���@  �\�����[���̊O�g�����											��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����Ex�F�\������X���W											��
���@�@�@���Ey�G�\������Y���W											��
��������������������������������������������������������������������������*/
void MAIL::MailFrame(int x, int y)
{
	DrawBox(x, y, x + MAIL_SIZE, y + MAIL_SIZE, FontList::m_colorWhite, 1);
	DrawLine(x, y + MAIL_SPACE, x + MAIL_SIZE, y + MAIL_SPACE, FontList::m_colorBlue);
	DrawString(x + 5, y + 1, "From�F", FontList::m_colorBlack);
	DrawLine(x, y + MAIL_SPACE * 2, x + MAIL_SIZE, y + MAIL_SPACE * 2, FontList::m_colorBlue);
	DrawString(x + 5, y + MAIL_SPACE, "To�F", FontList::m_colorBlack);
	DrawLine(x, y + MAIL_SPACE * 3, x + MAIL_SIZE, y + MAIL_SPACE * 3, FontList::m_colorBlue);
	DrawString(x + 5, y + MAIL_SPACE * 2, "�����F", FontList::m_colorBlack);
	DrawLine(x, y + 550, x + MAIL_SIZE, y + 550, FontList::m_colorBlue);
	DrawBox(x + 1, y + 1, x - 1 + MAIL_SIZE, y - 1 + MAIL_SIZE, FontList::m_colorBlue, 0);
	DrawBox(x, y, x + MAIL_SIZE, y + MAIL_SIZE, FontList::m_colorBlue, 0);

}

/*
��������������������������������������������������������������������������
���֐�����MAIL::DrawMailLeft													��
��������������������������������������������������������������������������
���@  �\�������̃��[����`�悷��										��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����Ex�F�\������X���W											��
���@�@�@���Ey�F�\������Y���W											��
���@�@�@���Eselect�FTRUE�̎��ɑI����ԂɂȂ�							��
��������������������������������������������������������������������������*/
void MAIL::DrawMailLeft(int x, int y, int select)
{
	if (select == FALSE) {	//�ۑI����Ԃ̎��A�P�x��񔼌�
		SetDrawBright(125, 125, 125);
	}

	MAIL::MailFrame(x, y);
	//���[���̍��o�l�ifrom�j
	DrawString(x + 100, y + 1, choice[0], FontList::m_colorBlack);
	//���[���̈���ito�j
	DrawString(x + 100, y + MAIL_SPACE, choice[1], FontList::m_colorBlack);
	//����
	DrawString(x + 100, y + MAIL_SPACE * 2, choice[2], FontList::m_colorBlack);
	//���[���̖{��
	MAIL::Putstring(x + 10, y + 5 + MAIL_SPACE * 3, 40, choice[3], 42, 0);
	//���[���̓Y�t���@���@URL
	MAIL::Putstring(x + 40, y + 5 + MAIL_SPACE * 10 + 15, 40, choice[4], 42, 1);

	if (select == FALSE) {
		SetDrawBright(255, 255, 255);
	}
}
/*
��������������������������������������������������������������������������
���֐�����MAIL::DrawMailRight													��
��������������������������������������������������������������������������
���@  �\���E���̃��[����`�悷��										��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����Ex�F�\������X���W											��
���@�@�@���Ey�F�\������Y���W											��
���@�@�@���Eselect�FTRUE�̎��ɑI����ԂɂȂ�							��
��������������������������������������������������������������������������*/
void MAIL::DrawMailRight(int x, int y, int select)
{
	if (select == FALSE) {	//�ۑI����Ԃ̎��A�P�x��񔼌�
		SetDrawBright(125, 125, 125);
	}

	MAIL::MailFrame(x, y);
	//���[���̍��o�l�ifrom�j
	DrawString(x + 100, y + 1, choice[5], FontList::m_colorBlack);
	//���[���̈���ito�j
	DrawString(x + 100, y + MAIL_SPACE, choice[6], FontList::m_colorBlack);
	//����
	DrawString(x + 100, y + MAIL_SPACE * 2, choice[7], FontList::m_colorBlack);
	//���[���̖{��
	MAIL::Putstring(x + 10, y + 5 + MAIL_SPACE * 3, 40, choice[8], 42, 0);
	//���[���̓Y�t���@���@URL
	MAIL::Putstring(x + 40, y + 5 + MAIL_SPACE * 10 + 15, 40, choice[9], 42, 1);

	if (select == FALSE) {
		SetDrawBright(255, 255, 255);
	}
}

/*
��������������������������������������������������������������������������
���֐�����MAIL::TargetedMailKey												��
��������������������������������������������������������������������������
���@  �\��MAIL::TargetedMail�ł̃L�[����										��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����Eselect1�F�����̃��[���̑I����ԁiTRUE�őI���j				��
���@�@�@���Eselect2�F�E���̃��[���̑I����ԁiTRUE�őI���j				��
��������������������������������������������������������������������������*/
void MAIL::TargetedMailKey(int *select1, int *select2)
{
	int work;

	//���̑I������ς���
	if (Keyboard_Get(KEY_INPUT_LEFT) == 1 || Keyboard_Get(KEY_INPUT_RIGHT) == 1) {
		work = *select1;
		*select1 = *select2;
		*select2 = work;
	}
	//�G���^�[�L�[��������Ă���Ƃ������Ȃ琳���V�[���ցA�ԈႢ�Ȃ�ԈႢ�V�[���Ɉڍs
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
		if (ans == 0 && *select1 == 1 || ans == 1 && *select2 == 1) {
			mail_scene += 2;
		}
		else {
			mail_scene++;
		}
		*select1 = 1; *select2 = 0;
	}
}
/*
��������������������������������������������������������������������������
���֐�����MAIL::TargetedMail													��
��������������������������������������������������������������������������
���@  �\��MAIL::TargetedMail�̖�蕶�����									��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����E															��
��������������������������������������������������������������������������*/
void MAIL::TargetedMail(void)
{
	static int select1 = 1, select2 = 0;
	int work;

	MAIL::TargetedMailKey(&select1, &select2);

	DrawGraph(0, 0, MailBG, FALSE);		//�w�i�̕`��
	MAIL::DrawMailLeft(230, 220, select1);	//���̃��[���`��
	MAIL::DrawMailRight(1100, 220, select2);	//�E�̃��[���`��
	DrawStringToHandle(80, 940, "�����S�ȃ��[����I��", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(100, 45, "Program", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, question, FontList::m_colorGreen1, FontList::m_font100);

}
/*
��������������������������������������������������������������������������
���֐�����MAIL::InputFile														��
��������������������������������������������������������������������������
���@  �\��num�őI�����ꂽ��蕶���t�@�C������ǂݏo��					��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����Enum�F�I�����ꂽ���ԍ�										��
��������������������������������������������������������������������������*/
void MAIL::InputFile(int num)
{
	FILE *fp = NULL;
	int cnt;

	fopen_s(&fp, "(Targeted_Mail.txt", "r");

	if (fp != nullptr) {
		while (fscanf_s(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",	//%[^,]�́u,�v�𕶎���Ƃ��Ĕ��肳���Ȃ�
			q_num, sizeof(q_num),
			question, sizeof(question),
			choice[0], sizeof(choice[0]),
			choice[1], sizeof(choice[1]),
			choice[2], sizeof(choice[2]),
			choice[3], sizeof(choice[3]),
			choice[4], sizeof(choice[4]),
			choice[5], sizeof(choice[5]),
			choice[6], sizeof(choice[6]),
			choice[7], sizeof(choice[7]),
			choice[8], sizeof(choice[8]),
			choice[9], sizeof(choice[9]),
			ans1, sizeof(ans1)) != EOF
			) {
			ans = atoi(ans1);
			if (num == atoi(q_num)) {
				fclose(fp);
				mail_scene++;
				break;
			}
		}
	}
}


/*
��������������������������������������������������������������������������
���֐�����MAIL::False													��
��������������������������������������������������������������������������
���@  �\�������ԈႦ�����ɕ\������									��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����E															��
��������������������������������������������������������������������������*/
void MAIL::False(void)
{

	static int cnt;
	int n,i;

	time_t t;
	time(&t);
	srand(t);

	n = rand();

	cnt++;
	DrawGraph(0, 0, MailBG, FALSE);
	
	for (i = 0; i <= cnt; i++) {
		n = rand();
		if (i == 0) {
			DrawGraph(1960 / 2 - 300, 1080 / 2 - 200, m_falseG, TRUE);
			i += 4;
		}
		else if(cnt<=100){
			DrawGraph(n % 1960, n % 1080, m_falseG, TRUE);
			i += 4;
		}
		else {
			DrawGraph(n % 1960, n % 1080, m_falseG, TRUE);
		}
	}
	DrawStringToHandle(770, 460, "���s", FontList::m_colorGreen1, FontList::m_font100);
	if (cnt >= 200) {
		cnt = 0;
		mail_scene = 4;
	}
}
/*
��������������������������������������������������������������������������
���֐�����True															��
��������������������������������������������������������������������������
���@  �\�����𐳉��������ɕ\������									��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����E															��
��������������������������������������������������������������������������*/
void MAIL::True(void)
{
	static int cnt;
	cnt++;
	DrawGraph(0, 0, MailBG, FALSE);
	DrawStringToHandle(770, 460, "����", FontList::m_colorGreen1, FontList::m_font100);
	if (cnt >= 100) {
		cnt = 0;
		mail_scene = 4;
	}

}


/*
��������������������������������������������������������������������������
���֐�����MAIL::TargetedMailAttack											��
��������������������������������������������������������������������������
���@  �\����ʂ̐��ڊǗ����s��											��
��������������������������������������������������������������������������
���߂�l���Ȃ�															��
��������������������������������������������������������������������������
����  �����Enum�F�I�����ꂽ���ԍ�										��
��������������������������������������������������������������������������*/
bool MAIL::IsCreated()
{
	return m_createdFlag;
}


void TargetedMailAttack(int num)
{
	static MAIL *mail;
	if (mail->IsCreated() == false) mail = new MAIL();	//�R���X�g���N�^�̓����Ŏ����I��flag��true�ɕύX

	switch (mail_scene) {
	case 0:	//�t�@�C���ǂݍ��ݕ���
		SetFontSize(25);
		mail->InputFile(num);
		break;

	case 1:
		mail->TargetedMail();
		break;

	case 2:
		mail->False();
		break;

	case 3:
		mail->True();
		break;
	case 4:
		mail->Init();
		SceneMgr::SetScene(SCENE_LIST);
		break;
	}
	if (SceneMgr::GetScene() == SCENE_LIST) {
		/*delete���Ă�new�Ŏ擾�����t���[�X�g�A���������邾���ŁAbof�̃A�h���X�������������킯�ł͂Ȃ��B
		(�s��l���������Ă���)���̂��߁A���������Anullptr�ŏ��������Ă���B
		�����Ă���2���͊֐���������Ɛ���ɋ@�\���Ȃ����߂��̂܂ܓW�J���Ă���B
		*/
		delete mail;
		mail = nullptr;
	}
}
