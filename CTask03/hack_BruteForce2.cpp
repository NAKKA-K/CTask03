#include"hack_BruteForce.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>

void HackBrute2()
{
	static Brute2 *brute;
	if (brute->IsCreated() == false) brute = new Brute2();	//コンストラクタの内部で自動的にflagをtrueに変更


	brute->BruteGraph();		//自動アニメーションや操作アニメーション
	brute->BruteKey();

	//問題の終了処理
	if (SceneMgr::GetScene() == SCENE_LIST) {
		delete brute;
		brute = nullptr;
	}
	return;
}


bool Brute2::m_createdFlag = false;


Brute2::Brute2() :m_scene(0), m_timer(0), m_alpha(0), bright(255)
{
	m_createdFlag = true;

	//ansNumの決定
	ansNum = GetRand(7);//0~9


						//画像読み込み
	m_hackBG = LoadGraph("Image/Q_gamen.png");
	m_webAppG = LoadGraph("Image/webApp3.png");


	SetKeyInputStringColor(FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack);

	m_timer = GetNowCount();
}
Brute2::~Brute2()
{
	m_createdFlag = false;
	//画像消去
	DeleteGraph(m_hackBG);
}

void Brute2::BruteGraph()
{
	DrawGraph(0, 0, m_hackBG, FALSE);
	DrawStringToHandle(100, 45, "Cipher", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, "BruteForce攻撃Ⅱ", FontList::m_colorGreen1, FontList::m_font100);


	DrawExtendGraph(10, 160, 1500, 900, m_webAppG, TRUE);

	if (m_scene >= 1) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);//tomフェードイン
													  //辞書表示
		DrawBox(1500, 170, 1850, 850, FontList::m_colorWhite, TRUE);
		DrawStringToHandle(1510, 175, "PASSはab文字3桁で\n構成されている", FontList::m_colorBlack, FontList::m_font30);
		for (int i = 0; i < 8; i++) {
			DrawFormatStringToHandle(1510, 300 + (i * 60), FontList::m_colorBlack, FontList::m_font50, "%s", answer[i]);
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (m_alpha <= 255) m_alpha += 2;
	}

	if (m_scene == 0) {}
	else if (m_scene == 1) {}
	else if (m_scene == 2) {
		DrawStringToHandle(50, 930, "BruteForce攻撃を仕掛けて、\nPASS認証を通過しろ！", FontList::m_colorGreen1, FontList::m_font50);
		SetFontSize(50);
		if (KeyInputSingleCharString(690, 640, 3, str, FALSE) == 1) {
			if (strcmp(str, answer[ansNum]) == 0) m_scene = 3;	//正解
			else m_scene = 7;	//不正解
		}
		m_timer = GetNowCount();//時間を初期化
	}
	else if (m_scene == 3) {
		DrawStringToHandle(10 + 500, 160 + 600, "PASSを認証しました。\nいらっしゃいませ。", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 4) {
		DrawStringToHandle(20, 930, "適当なPASS設定だとすぐに特定される。\n特に同じ文字だけで構成されているなら……", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene == 5) {
		SetDrawBright(bright, bright, bright);
		if (bright > 0) bright -= 2;
		else bright = 0;
	}
	else if (m_scene == 6) {
		SceneMgr::SetScene(SCENE_LIST);
		SetDrawBright(255, 255, 255);
	}

	else if (m_scene == 7) {
		DrawStringToHandle(10 + 500, 160 + 600, "PASSの認証に失敗しました。\n再度入力してください。", FontList::m_colorBlack, FontList::m_font30);
		DrawStringToHandle(50, 930, "全ての組み合わせを入力していけば\nどれか通るかもしれない。", FontList::m_colorGreen1, FontList::m_font50);
	}
	else if (m_scene == 8) {
		m_scene = 2;//入力に戻る
	}

	return;
}
void Brute2::BruteKey()
{
	if (m_scene <= 2) {
		if (GetNowCount() - m_timer <= 4 * 100) m_scene = 0;	//2
		else if (GetNowCount() - m_timer <= 24 * 100) m_scene = 1;	//2
		else if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 2;	//入力
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
			m_alpha = 255;
			m_scene = 2;
		}
	}
	else if (m_scene <= 6) {
		if (GetNowCount() - m_timer <= 2 * 1000) m_scene = 3;	//3
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 4;	//3
		else if (GetNowCount() - m_timer <= 7 * 1000) m_scene = 5;	//2
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 6;	//終了処理
	}
	else if (m_scene <= 8) {
		if (GetNowCount() - m_timer <= 2 * 1000) m_scene = 7;	//3
		else if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 8;	//m_scene=2
	}

	return;
}


bool Brute2::IsCreated()
{
	return m_createdFlag;
}

