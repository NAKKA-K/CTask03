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
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃MAIL::Init															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃初期化														┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・															┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void MAIL::Init(void)
{
	mail_scene = 0;
}
/*
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃MAIL::Putstring														┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃文字列の改行													┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・x：文字列の先頭を表示するX座標								┃
┃　　　┃・y：文字列の先頭を表示するY座標								┃
┃　　　┃・kaigyo：改行で動く座標（Y座標）								┃
┃　　　┃・str：改行する前の文字列										┃
┃　　　┃・WordCount：この文字数に到達すると改行操作を行う				┃
┃　　　┃・colorFlg：０の時は黒文字、１の時は青文字で表示する			┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void MAIL::Putstring(int x, int y, int kaigyo, char str[255], int WordCount, int colorFlg) {
	char work[64];

	int i = 0;
	while (str[i] != '\0') {
		memset(work, '\0', sizeof(work));	//workの初期化
		int cnt = 0;
		int j = 0;
		for (j = 0; j < WordCount && str[i] != '\0'; i++, j++) {
			if (str[i] == '$') {	//改行用コード'$'
				i++;
				break;
			}

			//2Byte文字なら、2Byte同時に格納
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
			//1Byte文字なら、1Byteだけ格納
			/*else {
			strncat_s(work, sizeof(work), str + i, 1);
			}*/
		}

		//1行の指定文字数をオーバーした時
		/*if (j >= WordCount + 1) {
		i -= 2;
		j -= 2;
		}*/
		work[j] = '\0';

		//1行出力後、改行
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
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃MAIL::MailFrame														┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃メールの外枠を作る											┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・x：表示するX座標											┃
┃　　　┃・y；表示するY座標											┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void MAIL::MailFrame(int x, int y)
{
	DrawBox(x, y, x + MAIL_SIZE, y + MAIL_SIZE, FontList::m_colorWhite, 1);
	DrawLine(x, y + MAIL_SPACE, x + MAIL_SIZE, y + MAIL_SPACE, FontList::m_colorBlue);
	DrawString(x + 5, y + 1, "From：", FontList::m_colorBlack);
	DrawLine(x, y + MAIL_SPACE * 2, x + MAIL_SIZE, y + MAIL_SPACE * 2, FontList::m_colorBlue);
	DrawString(x + 5, y + MAIL_SPACE, "To：", FontList::m_colorBlack);
	DrawLine(x, y + MAIL_SPACE * 3, x + MAIL_SIZE, y + MAIL_SPACE * 3, FontList::m_colorBlue);
	DrawString(x + 5, y + MAIL_SPACE * 2, "件名：", FontList::m_colorBlack);
	DrawLine(x, y + 550, x + MAIL_SIZE, y + 550, FontList::m_colorBlue);
	DrawBox(x + 1, y + 1, x - 1 + MAIL_SIZE, y - 1 + MAIL_SIZE, FontList::m_colorBlue, 0);
	DrawBox(x, y, x + MAIL_SIZE, y + MAIL_SIZE, FontList::m_colorBlue, 0);

}

/*
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃MAIL::DrawMailLeft													┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃左側のメールを描画する										┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・x：表示するX座標											┃
┃　　　┃・y：表示するY座標											┃
┃　　　┃・select：TRUEの時に選択状態になる							┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void MAIL::DrawMailLeft(int x, int y, int select)
{
	if (select == FALSE) {	//否選択状態の時、輝度を約半減
		SetDrawBright(125, 125, 125);
	}

	MAIL::MailFrame(x, y);
	//メールの差出人（from）
	DrawString(x + 100, y + 1, choice[0], FontList::m_colorBlack);
	//メールの宛先（to）
	DrawString(x + 100, y + MAIL_SPACE, choice[1], FontList::m_colorBlack);
	//件名
	DrawString(x + 100, y + MAIL_SPACE * 2, choice[2], FontList::m_colorBlack);
	//メールの本文
	MAIL::Putstring(x + 10, y + 5 + MAIL_SPACE * 3, 40, choice[3], 42, 0);
	//メールの添付物　＆　URL
	MAIL::Putstring(x + 40, y + 5 + MAIL_SPACE * 10 + 15, 40, choice[4], 42, 1);

	if (select == FALSE) {
		SetDrawBright(255, 255, 255);
	}
}
/*
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃MAIL::DrawMailRight													┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃右側のメールを描画する										┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・x：表示するX座標											┃
┃　　　┃・y：表示するY座標											┃
┃　　　┃・select：TRUEの時に選択状態になる							┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void MAIL::DrawMailRight(int x, int y, int select)
{
	if (select == FALSE) {	//否選択状態の時、輝度を約半減
		SetDrawBright(125, 125, 125);
	}

	MAIL::MailFrame(x, y);
	//メールの差出人（from）
	DrawString(x + 100, y + 1, choice[5], FontList::m_colorBlack);
	//メールの宛先（to）
	DrawString(x + 100, y + MAIL_SPACE, choice[6], FontList::m_colorBlack);
	//件名
	DrawString(x + 100, y + MAIL_SPACE * 2, choice[7], FontList::m_colorBlack);
	//メールの本文
	MAIL::Putstring(x + 10, y + 5 + MAIL_SPACE * 3, 40, choice[8], 42, 0);
	//メールの添付物　＆　URL
	MAIL::Putstring(x + 40, y + 5 + MAIL_SPACE * 10 + 15, 40, choice[9], 42, 1);

	if (select == FALSE) {
		SetDrawBright(255, 255, 255);
	}
}

/*
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃MAIL::TargetedMailKey												┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃MAIL::TargetedMailでのキー操作										┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・select1：左側のメールの選択状態（TRUEで選択）				┃
┃　　　┃・select2：右側のメールの選択状態（TRUEで選択）				┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void MAIL::TargetedMailKey(int *select1, int *select2)
{
	int work;

	//問題の選択肢を変える
	if (Keyboard_Get(KEY_INPUT_LEFT) == 1 || Keyboard_Get(KEY_INPUT_RIGHT) == 1) {
		work = *select1;
		*select1 = *select2;
		*select2 = work;
	}
	//エンターキーが押されているとき正解なら正解シーンへ、間違いなら間違いシーンに移行
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
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃MAIL::TargetedMail													┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃MAIL::TargetedMailの問題文を作る									┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・															┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void MAIL::TargetedMail(void)
{
	static int select1 = 1, select2 = 0;
	int work;

	MAIL::TargetedMailKey(&select1, &select2);

	DrawGraph(0, 0, MailBG, FALSE);		//背景の描画
	MAIL::DrawMailLeft(230, 220, select1);	//左のメール描画
	MAIL::DrawMailRight(1100, 220, select2);	//右のメール描画
	DrawStringToHandle(80, 940, "より安全なメールを選べ", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(100, 45, "Program", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, question, FontList::m_colorGreen1, FontList::m_font100);

}
/*
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃MAIL::InputFile														┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃numで選択された問題文をファイルから読み出す					┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・num：選択された問題番号										┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void MAIL::InputFile(int num)
{
	FILE *fp = NULL;
	int cnt;

	fopen_s(&fp, "(Targeted_Mail.txt", "r");

	if (fp != nullptr) {
		while (fscanf_s(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",	//%[^,]は「,」を文字列として判定させない
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
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃MAIL::False													┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃問題を間違えた時に表示する									┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・															┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
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
	DrawStringToHandle(770, 460, "失敗", FontList::m_colorGreen1, FontList::m_font100);
	if (cnt >= 200) {
		cnt = 0;
		mail_scene = 4;
	}
}
/*
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃True															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃問題を正解した時に表示する									┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・															┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void MAIL::True(void)
{
	static int cnt;
	cnt++;
	DrawGraph(0, 0, MailBG, FALSE);
	DrawStringToHandle(770, 460, "正解", FontList::m_colorGreen1, FontList::m_font100);
	if (cnt >= 100) {
		cnt = 0;
		mail_scene = 4;
	}

}


/*
┏━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃関数名┃MAIL::TargetedMailAttack											┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃機  能┃画面の推移管理を行う											┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃戻り値┃なし															┃
┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃引  数┃・num：選択された問題番号										┃
┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
bool MAIL::IsCreated()
{
	return m_createdFlag;
}


void TargetedMailAttack(int num)
{
	static MAIL *mail;
	if (mail->IsCreated() == false) mail = new MAIL();	//コンストラクタの内部で自動的にflagをtrueに変更

	switch (mail_scene) {
	case 0:	//ファイル読み込み分岐
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
		/*deleteしてもnewで取得したフリーストアが解放されるだけで、bofのアドレスが初期化されるわけではない。
		(不定値が代入されていた)そのため、解放した後、nullptrで初期化してある。
		そしてこの2文は関数分けすると正常に機能しないためそのまま展開してある。
		*/
		delete mail;
		mail = nullptr;
	}
}
