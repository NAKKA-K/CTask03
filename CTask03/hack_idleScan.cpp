#include"hack_idleScan.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>


void HackIdle()
{
	static Idle *idle;
	if (idle->IsCreated() == false) idle = new Idle();	//コンストラクタの内部で自動的にflagをtrueに変更


	idle->IdleMain();

	//TODO:問題が終了したときにSetSceneするように変更が必要

	//問題の終了処理
	if (SceneMgr::GetScene() == SCENE_LIST) {
		delete idle;
		idle = nullptr;
	}
	return;
}


bool Idle::m_createdFlag = false;


Idle::Idle() :timer(0), timeFlg(0), animeFlg(0)
{
	m_createdFlag = true;

	//画像読み込み
	backScreen = LoadGraph("Image/Q_gamen.png");
	tom = LoadGraph("Image/tom.png");
	pc = LoadGraph("Image/pc.png");
	vector_Red_R = LoadGraph("Image/矢印赤右.png");
	vector_Red_L = LoadGraph("Image/矢印赤左.png");
	vector_Red_S1 = LoadGraph("Image/矢印赤斜1.png");
	vector_Red_S2 = LoadGraph("Image/矢印赤斜2.png");
	vector_Blue_S1 = LoadGraph("Image/矢印青斜1.png");
	vector_Blue_S2 = LoadGraph("Image/矢印青斜2.png");
	vector_Blue_S3 = LoadGraph("Image/矢印青斜3.png");
	vector_Blue_LB = LoadGraph("Image/矢印青左大.png");
}
Idle::~Idle()
{
	m_createdFlag = false;

	DeleteGraph(backScreen);
	DeleteGraph(tom);
	DeleteGraph(pc);
	DeleteGraph(vector_Red_R);
	DeleteGraph(vector_Red_L);
	DeleteGraph(vector_Red_S1);
	DeleteGraph(vector_Red_S2);
	DeleteGraph(vector_Blue_S1);
	DeleteGraph(vector_Blue_S2);
	DeleteGraph(vector_Blue_S3);
	DeleteGraph(vector_Blue_LB);
}

void Idle::IdleMain()
{
	//static int timer, timeFlg = 0, animeFlg = 0;
	if (timeFlg == 0) {
		timer = GetNowCount();
		if (animeFlg == 14)
			timeFlg = 2;
		else if (animeFlg == 21)
			timeFlg = 3;
		else
			timeFlg = 1;
	}
	IdleGraph(animeFlg);							//アイドルスキャン描画
	IdleKey(&animeFlg, &timeFlg, &timer);//アイドルスキャン処理

	return;
}


void Idle::IdleGraph(int animeFlg)
{
	DrawGraph(0, 0, backScreen, TRUE);
	DrawStringToHandle(140, 60, "Network", FontList::m_colorGreen2, FontList::m_font65);
	DrawStringToHandle(550, 60, "アイドルスキャン", FontList::m_colorGreen2, FontList::m_font70);
	DrawExtendGraph(750, 220, 750 + 412, 220 + 227, pc, TRUE);
	DrawExtendGraph(150, 620, 150 + 412, 620 + 227, pc, TRUE);
	DrawExtendGraph(1450, 610, 1450 + 250, 610 + 250, tom, TRUE);


	if (animeFlg >= 1) {
		DrawExtendGraph(650, 720, 650 + 726, 720 + 53, vector_Blue_LB, TRUE);
		DrawStringToHandle(620, 790, "SYN（送信元をアイドル中のホストにした偽のパケット）", FontList::m_colorBrown, FontList::m_font30);
	}
	if (animeFlg >= 2) {
		DrawExtendGraph(350, 350, 350 + 231, 350 + 188, vector_Red_S1, TRUE);
		DrawStringToHandle(300, 350, "SYN/ACK", FontList::m_colorBrown, FontList::m_font40);
	}
	if (animeFlg >= 3) {
		DrawExtendGraph(450, 400, 450 + 231, 400 + 188, vector_Red_S2, TRUE);
		DrawStringToHandle(600, 550, "RST", FontList::m_colorBrown, FontList::m_font40);
	}
	if (animeFlg >= 4) {
		DrawExtendGraph(1300, 350, 1300 + 231, 350 + 188, vector_Blue_S2, TRUE);
		DrawStringToHandle(1450, 360, "SYN/ACK", FontList::m_colorBrown, FontList::m_font40);
	}
	if (animeFlg >= 5) {
		DrawExtendGraph(1200, 400, 1200 + 231, 400 + 188, vector_Blue_S3, TRUE);
		DrawStringToHandle(1000, 550, "RST(ID ＝ ??)", FontList::m_colorGreen2, FontList::m_font40);
	}
	if (animeFlg == 6) {
		DrawStringToHandle(45, 925, "ターゲットのポートがオープンされている場合、\nTomに返ってきたRSTパケットのIDの数値はいくつか？", FontList::m_colorGreen2, FontList::m_font40);
		DrawStringToHandle(45, 1020, "※アイドル中のホストのIDは6ずつ増えるものとし、最終IDは50とする。", FontList::m_colorGreen2, FontList::m_font30);
	}

	if (animeFlg==7) {
		DrawStringToHandle(95, 950, "正解！", FontList::m_colorGreen2, FontList::m_font50);
	}
	if (animeFlg==8) {
		DrawStringToHandle(95, 950, "不正解……", FontList::m_colorGreen2, FontList::m_font50);
	}

	return;
}
void Idle::IdleKey(int *animeFlg, int *timeFlg, int *timer)
{
	if(*animeFlg<=6){
		if (*timeFlg == 1 && (GetNowCount() - *timer) < 20000) {
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
			else if (12000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 15000)
				*animeFlg = 6;
			else if (15000 <= (GetNowCount() - *timer) && (GetNowCount() - *timer) <= 16000) {
				SetFontSize(80);
				if (KeyInputNumber(1150, 945, 9999, 0, FALSE) == 62) *animeFlg = 7;
				else *animeFlg = 8;

				*timer = GetNowCount();
			}

		}
	}
	else {
		if (GetNowCount() - *timer <= 2 * 1000) {}
		else SceneMgr::SetScene(SCENE_LIST);
	}

	return;
}


bool Idle::IsCreated()
{
	return m_createdFlag;
}
