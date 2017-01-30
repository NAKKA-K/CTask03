#include"hack_sessionHijack.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>


void HackHijack()
{
	static Hijack *hijack;
	if (hijack->IsCreated() == false) hijack = new Hijack();	//コンストラクタの内部で自動的にflagをtrueに変更


	hijack->HijackMain();

	//TODO:問題が終了したときにSetSceneするように変更が必要

	//問題の終了処理
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

	//画像読み込み
	SM = LoadGraph("Image/SM.jpg");
	backScreen = LoadGraph("Image/Q_gamen.png");
	bob = LoadGraph("Image/bob.png");
	cathy = LoadGraph("Image/cathy.png");
	tom = LoadGraph("Image/tom.png");
	pc = LoadGraph("Image/pc.png");
	smartphone_Cathy = LoadGraph("Image/キャサホ.png");
	receive1 = LoadGraph("Image/吹き出し１.png");
	receive2 = LoadGraph("Image/吹き出し２.png");
	receive3 = LoadGraph("Image/吹き出し３.png");
	send1 = LoadGraph("Image/吹き出し４.png");
	send2 = LoadGraph("Image/吹き出し５.png");
	send3 = LoadGraph("Image/吹き出し６.png");
	frame = LoadGraph("Image/枠.png");
	mail = LoadGraph("Image/メールアイコン１.png");
	vector_Red_R = LoadGraph("Image/矢印赤右.png");
	vector_Red_L = LoadGraph("Image/矢印赤左.png");
	vector_Red_S1 = LoadGraph("Image/矢印赤斜1.png");
	vector_Red_S2 = LoadGraph("Image/矢印赤斜2.png");
	vector_Blue_S1 = LoadGraph("Image/矢印青斜1.png");
	vector_Blue_S2 = LoadGraph("Image/矢印青斜2.png");
	vector_Blue_S3 = LoadGraph("Image/矢印青斜3.png");
	vector_Blue_LB = LoadGraph("Image/矢印青左大.png");
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
	HijackGraph(animeFlg, pal, mail_X, mail_Y);									//セッションハイジャック描画
	HijackKey(&animeFlg, &timeFlg, &timer, &pal, &mail_X, &mail_Y);			//セッションハイジャック処理

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
	DrawStringToHandle(550, 60, "セッションハイジャック", FontList::m_colorGreen2, FontList::m_font70);
	DrawStringToHandle(500, 250, "Bob", FontList::m_colorBlack, FontList::m_font30);


	if (animeFlg == 1 || animeFlg == 2) {
		DrawExtendGraph(1650, 183, 1650 + 240, 183 + 90, receive3, TRUE);
		DrawStringToHandle(1660, 195, "明日のBobとのデート、\n待ち合わせのこと決め\nなくちゃ！", FontList::m_colorOrange1, FontList::m_font20);
	}
	if (animeFlg >= 2) {
		DrawExtendGraph(455, 300, 455 + 220, 300 + 85, send2, TRUE);
		DrawStringToHandle(460, 308, "こんばんは、Bob。\n明日はどこで待ち合わ\nせる？", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg == 3 || animeFlg == 4) {
		DrawExtendGraph(1030, 220, 1030 + 240, 220 + 70, receive3, TRUE);
		DrawStringToHandle(1040, 233, "おっと、Cathyからの\nメールだ。", FontList::m_colorRed, FontList::m_font20);
	}
	if (animeFlg >= 4) {
		DrawExtendGraph(345, 380, 345 + 225, 380 + 85, receive2, TRUE);
		DrawStringToHandle(355, 388, "やあ、Cathy！\n明日は12時ぐらいに僕\nが向かえにいくよ。", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg >= 5) {
		DrawExtendGraph(440, 460, 440 + 235, 460 + 85, send2, TRUE);
		DrawStringToHandle(445, 468, "ありがとうBob！\nランチだけど、私行って\nみたいお店があるの！", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg >= 6) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
		DrawExtendGraph(800, 600, 800 + 250, 600 + 250, tom, TRUE);
		DrawStringToHandle(905, 860, "Tom", FontList::m_colorWhite, FontList::m_font30);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (animeFlg == 7) {
		DrawExtendGraph(1030, 530, 1030 + 285, 530 + 90, receive3, TRUE);
		DrawStringToHandle(1040, 540, "くそぅ。\nBobのやつ、明日はCathyと\nデートだというじゃないか。", FontList::m_colorBlue1, FontList::m_font20);
	}
	if (animeFlg == 8) {
		DrawExtendGraph(1030, 520, 1030 + 360, 520 + 110, receive1, TRUE);
		DrawStringToHandle(1050, 585, "Cathyは僕にこそ相応しいんだ……", FontList::m_colorBlue1, FontList::m_font20);
	}
	if (animeFlg == 9) {
		DrawExtendGraph(1030, 480, 1030 + 365, 480 + 150, receive1, TRUE);
		DrawStringToHandle(1055, 562, "邪魔してやる！！！", FontList::m_colorBlue1, FontList::m_font35);
	}
	if (animeFlg >= 10 && animeFlg <= 13) {
		DrawExtendGraph(1230, 190, 1230 + 265, 180 + 145, frame, TRUE);
		DrawStringToHandle(1240, 200, "送信元：Bob\n送信先：Cathy\nシーケンス番号：147\n確認応答番号：121\nパケット長：137(Byte)", FontList::m_colorBrown, FontList::m_font22);
	}
	if (animeFlg >= 10 && animeFlg <= 14 || animeFlg == 21) {
		DrawExtendGraph(1080, 330, 1080 + 350, 330 + 46, vector_Red_R, TRUE);
	}
	if (animeFlg >= 11 && animeFlg <= 13) {
		DrawExtendGraph(990, 435, 990 + 265, 435 + 145, frame, TRUE);
		DrawStringToHandle(1000, 445, "送信元：Cathy\n送信先：Bob\nシーケンス番号：121\n確認応答番号：284\nパケット長：142(Byte)", FontList::m_colorBrown, FontList::m_font22);
	}
	if (animeFlg >= 11 && animeFlg <= 14 || animeFlg == 21) {
		DrawExtendGraph(1080, 380, 1080 + 350, 380 + 46, vector_Red_L, TRUE);
	}
	if (animeFlg >= 12 && animeFlg <= 13) {
		DrawExtendGraph(1350, 640, 1350 + 400, 640 + 200, frame, TRUE);
		DrawStringToHandle(1365, 658, "送信元：Bob\n送信先：Cathy\nシーケンス番号：284\n確認応答番号：□□□\nパケット長：124(Byte)", FontList::m_colorBrown, FontList::m_font30);
	}
	if (animeFlg >= 12 && animeFlg <= 14 || animeFlg == 21) {
		DrawExtendGraph(1030, 540, 1030 + 396, 540 + 189, vector_Blue_S1, TRUE);
	}
	if (animeFlg >= 13) {
		DrawStringToHandle(40, 925, "Bobが返信するよりも前に、正しい確認応答\n番号をセットして送信せよ！", FontList::m_colorGreen2, FontList::m_font50);
	}
	if (animeFlg == 14)
		DrawExtendGraph(mail_X, mail_Y, mail_X + 339 / 4, mail_Y + 223 / 4, mail, TRUE);

	if (animeFlg >= 15 && animeFlg <= 20) {
		DrawExtendGraph(345, 550, 345 + 330, 550 + 70, receive2, TRUE);
		DrawStringToHandle(350, 560, "この泥棒猫！\nこれ以上私のBobに近づかないで！", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg == 16) {
		DrawExtendGraph(1650, 183, 1650 + 210, 183 + 90, receive3, TRUE);
		DrawStringToHandle(1660, 195, "泥棒猫??\n誰よ、この娘。\nもしかして浮気!?", FontList::m_colorOrange1, FontList::m_font20);
	}
	if (animeFlg >= 17 && animeFlg <= 20) {
		DrawExtendGraph(390, 620, 390 + 290, 620 + 75, send2, TRUE);
		DrawStringToHandle(395, 635, "どういうこと？\nもしかして浮気しているの!?", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg >= 18 && animeFlg <= 20) {
		DrawExtendGraph(1030, 210, 1030 + 220, 210 + 70, receive3, TRUE);
		DrawStringToHandle(1040, 223, "浮気!?\n意味が分からない！", FontList::m_colorRed, FontList::m_font20);
	}
	if (animeFlg >= 19 && animeFlg <= 20) {
		DrawExtendGraph(345, 700, 345 + 330, 700 + 50, receive2, TRUE);
		DrawStringToHandle(355, 710, "突然何を言っているんだ、君は？", FontList::m_colorBlack, FontList::m_font20);
	}
	if (animeFlg == 20) {
		DrawExtendGraph(1630, 195, 1630 + 280, 195 + 70, receive3, TRUE);
		DrawStringToHandle(1635, 205, "なに、とぼけるっていうの？\nいいわよ、もう知らない!!", FontList::m_colorOrange1, FontList::m_font20);
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
		DrawStringToHandle(1050, 580, "あれ、おかしいぞ。\nなんで、なんで届かない？", FontList::m_colorBlue1, FontList::m_font20);
	}
	if (animeFlg == 23) {
		DrawExtendGraph(1030, 500, 1030 + 365, 500 + 110, receive1, TRUE);
		DrawStringToHandle(1055, 565, "ああ、これじゃあ僕のCathyが…", FontList::m_colorBlue1, FontList::m_font20);
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






