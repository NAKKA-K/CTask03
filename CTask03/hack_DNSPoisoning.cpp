#include"hack_DNSPoisoning.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>

void HackDNS()
{
	static DNS *dns;
	if (dns->IsCreated() == false) dns = new DNS();	//コンストラクタの内部で自動的にflagをtrueに変更


	dns->DNSGraph();		//自動アニメーションや操作アニメーション
	dns->DNSKey();

	//問題の終了処理
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

	//画像読み込み
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
	//画像消去
	DeleteGraph(m_hackBG);
}

void DNS::DNSGraph()
{
	DrawGraph(0, 0, m_hackBG, FALSE);
	DrawStringToHandle(100, 45, "Network", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, "DNSキャッシュポイズニング", FontList::m_colorGreen1, FontList::m_font100);

/*
SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);//tomフェードイン
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
		//DrawStringToHandle(50, 930, "2人のDNSキャッシュのMACを書き換えて\n通信を盗聴しろ！", FontList::m_colorGreen1, FontList::m_font50);
		SetFontSize(50);
		if (KeyInputSingleCharString(1200, 960, 20, str, FALSE) == 1) {
			if (strcmp(str, "00:00:00:AB:AB:AB") == 0) m_scene = 5;	//正解
			else m_scene = 10;	//不正解
		}
		m_timer = GetNowCount();//時間を初期化
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
