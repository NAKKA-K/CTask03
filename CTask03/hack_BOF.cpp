#include"hack_BOF.h"
#include"keyboard.h"
#include"scene_mgr.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include<DxLib.h>

void HackBOF()
{
	/*話に上がっていたので結論を記述する
	  staticで宣言されたBOF* bof;は実行時に静的領域に確保される。
	  その後newにより、フリーストアにBOFClass分の領域を確保する。
	*/
	static BOF *bof;
	if (bof->IsCreated()==false) bof = new BOF();	//コンストラクタの内部で自動的にflagをtrueに変更


	bof->BOFGraph();		//自動アニメーションや操作アニメーション
	bof->BOFKey();

	//問題の終了処理
	if (SceneMgr::GetScene()== SCENE_LIST) {
		/*deleteしてもnewで取得したフリーストアが解放されるだけで、bofのアドレスが初期化されるわけではない。
		  (不定値が代入されていた)そのため、解放した後、nullptrで初期化してある。
		  そしてこの2文は関数分けすると正常に機能しないためそのまま展開してある。
		*/
		delete bof;
		bof = nullptr;
	}
	return;
}


bool BOF::m_createdFlag = false;

BOF::BOF() :m_scene(0),m_timer(0),m_alpha(0),bright(255)
{
	m_createdFlag = true;
	//memset(str, '\0', sizeof(str));

	//座標変数の初期化
	bobP[0] = 1200, bobP[1] = 500;	
	webAppP[0] = 100, webAppP[1] = 300, webAppP[2] = 1000, webAppP[3] = 750;

	//画像読み込み
	m_bobG = LoadGraph("Image/bob.png");
	m_cathyG = LoadGraph("Image/cathy.png");
	m_tomG = LoadGraph("Image/tom.png");
//	m_hackBG = LoadGraph("Image/learn.png");
	m_hackBG = LoadGraph("Image/Q_gamen.png");
	m_balloonG[0] = LoadGraph("Image/balloon2.png");
	m_balloonG[1] = LoadGraph("Image/balloon5.png");
	m_webAppG = LoadGraph("Image/webApp2.png");


	SetKeyInputStringColor(FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack,
		FontList::m_colorBlack, FontList::m_colorBlack, FontList::m_colorBlack);

	m_timer = GetNowCount();
}
BOF::~BOF()
{
	m_createdFlag = false;
	//画像消去
	DeleteGraph(m_bobG);
	DeleteGraph(m_cathyG);
	DeleteGraph(m_tomG);
	DeleteGraph(m_hackBG);
	DeleteGraph(m_balloonG[0]);
	
	DeleteGraph(m_webAppG);
}

void BOF::BOFGraph()
{
	DrawGraph(0, 0, m_hackBG, FALSE);
	DrawStringToHandle(100, 45, "Program", FontList::m_colorGreen1, FontList::m_font75);
	DrawStringToHandle(550, 45, "BOF攻撃", FontList::m_colorGreen1, FontList::m_font100);


	/*第1章開始*/
	//int bobP[2] = { 1200, 500 };	メンバ変数に移動
	//int webAppP[4]={100,300,1000,750};	//メンバ変数に移動
	if (m_scene <= 12) {
		DrawExtendGraph(webAppP[0], webAppP[1], webAppP[2], webAppP[3], m_webAppG, TRUE);	//bobの公開しているサイト(2章は拡大)
		DrawExtendGraph(bobP[0], bobP[1], bobP[0] + 250, bobP[1] + 250, m_bobG, TRUE);	//(2章になると位置が移動)
		if (m_scene <= 8) DrawGraph(1600, 500, m_cathyG, TRUE);	//TODO:フェードアウト(2章になると消える)
		else if (m_scene >= 10) DrawGraph(1600, 650, m_tomG, TRUE);
	}
	else if (m_scene <= 30) {
		DrawExtendGraph(webAppP[0], webAppP[1], webAppP[2], webAppP[3], m_webAppG, TRUE);	//最終位置、(サイト拡大)
		DrawExtendGraph(bobP[0], bobP[1], bobP[0] + 250, bobP[1] + 250, m_bobG, TRUE);//最終位置、1600, 170, +200,+250
		DrawGraph(1600, 650, m_tomG, TRUE);
	}
	if (m_scene >= 15 && m_scene <= 24) {
		for (int i = 1; i <= 5; i++) DrawFormatStringToHandle(webAppP[0] + 90, webAppP[1] + 50 + 120 * i, FontList::m_colorBlack, FontList::m_font50, "%s%s", str, str);
	}
	else if (m_scene >= 25) DrawFormatStringToHandle(webAppP[0] + 500, webAppP[1] + 600, FontList::m_colorBlack, FontList::m_font30, "%s様、いらっしゃいませ。", str);


	const int bobSP1[2] = { 1100,350 };	//bobのコメント表示座標
	const int cathySP1[2] = { 1500,350 };	//cathyのコメント表示座標
	const int bobSP2[2] = { 1500,400 };
	const int tomSP2[2] = { 1500,550 };

	if (m_scene == 0) {
		DrawExtendGraph(cathySP1[0] - 5, cathySP1[1] - 5, cathySP1[0] + 300, cathySP1[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(cathySP1[0], cathySP1[1], "ハローBob！", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 1) {
		DrawExtendGraph(bobSP1[0] - 5, bobSP1[1] - 5, bobSP1[0] + 300, bobSP1[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP1[0], bobSP1[1], "やあ、Cathy！", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 2) {
		DrawExtendGraph(cathySP1[0] - 5, cathySP1[1] - 5, cathySP1[0] + 410, cathySP1[1] + 150, m_balloonG[1], TRUE);
		DrawStringToHandle(cathySP1[0], cathySP1[1], "前に言ってた、\nネットに公開してるサイトの\n調子はどう？", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 3) {
		DrawExtendGraph(bobSP1[0] - 5, bobSP1[1] - 5, bobSP1[0] + 420, bobSP1[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP1[0], bobSP1[1], "ああ、それなりに調子いいよ。", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 4) {
		DrawExtendGraph(bobSP1[0] - 5, bobSP1[1] - 5, bobSP1[0] + 420, bobSP1[1] + 150, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP1[0], bobSP1[1], "初めて公開したサイトだから、\n直さなきゃならない所は\nいっぱいあるけどね。", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 5) {
		DrawExtendGraph(cathySP1[0] - 5, cathySP1[1] - 5, cathySP1[0] + 420, cathySP1[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(cathySP1[0], cathySP1[1], "へえ、やっぱりBobは凄いな。", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 6) {
		DrawExtendGraph(cathySP1[0] - 5, cathySP1[1] - 5, cathySP1[0] + 400, cathySP1[1] + 150, m_balloonG[1], TRUE);
		DrawStringToHandle(cathySP1[0], cathySP1[1], "私にできないことを\n平然とやってのける！\nそこに痺れるし、憧れるよ！", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 7) {
		DrawExtendGraph(cathySP1[0] - 5, cathySP1[1] - 5, cathySP1[0] + 400, cathySP1[1] + 100, m_balloonG[1], TRUE);
		DrawStringToHandle(cathySP1[0], cathySP1[1], "じゃあBob、頑張ってね。\nバイBob！", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 8) {
		DrawExtendGraph(bobSP1[0] - 5, bobSP1[1] - 5, bobSP1[0] + 350, bobSP1[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP1[0], bobSP1[1], "ははw、またねCathy。", FontList::m_colorBlack, FontList::m_font30);
	}
	/*第1章終了　&　第2章開始*/
	else if (m_scene == 9) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);//tomフェードイン
		DrawGraph(1600, 650, m_tomG, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (m_alpha<=255) m_alpha += 2;
	}
	else if (m_scene == 10) {
		DrawExtendGraph(tomSP2[0] - 5, tomSP2[1] - 5, tomSP2[0] + 400, tomSP2[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "BobBobBobBob！！！", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 11) {
		DrawExtendGraph(tomSP2[0] - 10, tomSP2[1] - 5, tomSP2[0] + 420, tomSP2[1] + 100, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0]-5, tomSP2[1], "僕のCathyに\n馴れ馴れしくしやがってぇぇえ！！", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 12) {
		DrawExtendGraph(tomSP2[0] - 5, tomSP2[1] - 5, tomSP2[0] + 420, tomSP2[1] + 100, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "奴のサイトを\nむちゃくちゃにしてやる……", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 13) {
		if (bobP[0] < 1600) bobP[0] += 6;//右上に移動
		if (bobP[1] > 170) bobP[1] -= 4;
		if (webAppP[0]>10) webAppP[0] -= 2;//サイトの拡大
		if (webAppP[1]>160) webAppP[1] -= 2;
		if (webAppP[2]<1500) webAppP[2] += 6;
		if (webAppP[3]<900) webAppP[3] += 4;	
	}
	else if (m_scene == 14) {
		DrawExtendGraph(tomSP2[0]-5, tomSP2[1]-5, tomSP2[0] +400, tomSP2[1] + 100, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "char str[16];\nscanf(\"%s\",str);", FontList::m_colorBlack, FontList::m_font30);
		SetFontSize(50);
		DrawStringToHandle(50,950, "BOF攻撃を仕掛けてサイトをめちゃくちゃにしてやれ！", FontList::m_colorGreen1	, FontList::m_font50);
		if (KeyInputString(460, 640, 22, str, FALSE) == 1) {
			if (strlen(str) >= 17) m_scene = 15;	//正解
			else m_scene = 25;	//不正解
		}
		m_timer = GetNowCount();//時間を初期化
	}
	/*第2章終了　&　第3章開始*/
	else if (m_scene == 15) {
		DrawExtendGraph(tomSP2[0] - 5, tomSP2[1] - 5, tomSP2[0] + 380, tomSP2[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "ハハッ！！成功だ！！", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 16) {
		DrawExtendGraph(bobSP2[0] + 350, bobSP2[1] + 50,bobSP2[0] - 15, bobSP2[1] - 15, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP2[0], bobSP2[1], "な、何だこれ！？", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 17) {
		DrawExtendGraph(bobSP2[0] + 420, bobSP2[1] + 50, bobSP2[0] - 15, bobSP2[1] - 15, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP2[0], bobSP2[1], "とりあえず何とかしなきゃ……", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 18) {
		DrawExtendGraph(tomSP2[0] - 5, tomSP2[1] - 5, tomSP2[0] + 420, tomSP2[1] + 100, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "無様だな、Bob。\nやっぱりCathyは僕が……！", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 19 || m_scene == 27) {
		SetDrawBright(bright, bright, bright);
		if (bright > 0) bright -= 2;
		else bright = 0;
	}
	else if (m_scene == 20 || m_scene == 28) {
		SceneMgr::SetScene(SCENE_LIST);
		SetDrawBright(255, 255, 255);
	}
	//不正解
	else if (m_scene == 25) {
		DrawExtendGraph(tomSP2[0] - 5, tomSP2[1] - 5, tomSP2[0] + 380, tomSP2[1] + 50, m_balloonG[1], TRUE);
		DrawStringToHandle(tomSP2[0], tomSP2[1], "くっ！ダメか……", FontList::m_colorBlack, FontList::m_font30);
	}
	else if (m_scene == 26) {
		DrawExtendGraph(bobSP2[0] + 380, bobSP2[1] + 100, bobSP2[0] - 15, bobSP2[1] - 15, m_balloonG[1], TRUE);
		DrawStringToHandle(bobSP2[0], bobSP2[1], "今日も順調だな。\nよし、頑張ろう。", FontList::m_colorBlack, FontList::m_font30);
	}
	/*
	else if (m_scene == 27) {
		SetDrawBright(bright, bright, bright);
		if (bright>0) bright -= 2;
		else bright = 0;
	}
	else if (m_scene == 28) {
		SceneMgr::SetScene(SCENE_LIST);
		SetDrawBright(255, 255, 255);
	}
	*/
	return;
}
void BOF::BOFKey()
{
	/*第1章開始*/
	if (m_scene <= 14) {
		if (GetNowCount() - m_timer <= 3 * 1000) m_scene = 0;	//3
		else if (GetNowCount() - m_timer <= 5 * 1000) m_scene = 1;//2
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 2;//3
		else if (GetNowCount() - m_timer <= 10 * 1000) m_scene = 3;//2
		else if (GetNowCount() - m_timer <= 14 * 1000) m_scene = 4;//4
		else if (GetNowCount() - m_timer <= 16 * 1000) m_scene = 5;//2
		else if (GetNowCount() - m_timer <= 20 * 1000) m_scene = 6;//4
		else if (GetNowCount() - m_timer <= 22 * 1000) m_scene = 7;//2
		else if (GetNowCount() - m_timer <= 24 * 1000) m_scene = 8;//2
		/*第1章終了　&　第2章開始*/
		else if (GetNowCount() - m_timer <= 28 * 1000) m_scene = 9;
		else if (GetNowCount() - m_timer <= 32 * 1000) m_scene = 10;
		else if (GetNowCount() - m_timer <= 36 * 1000) m_scene = 11;
		else if (GetNowCount() - m_timer <= 38 * 1000) m_scene = 12;
		else if (GetNowCount() - m_timer <= 42 * 1000) m_scene = 13;
		else if (GetNowCount() - m_timer <= 46 * 1000) m_scene = 14;
		if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
			m_scene = 14;	//イベントスキップ
			bobP[0] = 1600, bobP[1] = 170;	//イベントスキップした用
			webAppP[0] = 10, webAppP[1] = 160, webAppP[2] = 1500, webAppP[3] = 900;
		}
	}
	/*第2章終了　&　第3章開始*/
	else if (m_scene <= 21) {	//正解
		if (GetNowCount() - m_timer <= 4 * 1000) m_scene = 15;//2
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 16;//2
		else if (GetNowCount() - m_timer <= 8 * 1000) m_scene = 17;//2
		else if (GetNowCount() - m_timer <= 12 * 1000) m_scene = 18;//4
		else if (GetNowCount() - m_timer <= 16 * 1000) m_scene = 19;//4フェードアウト
		else if (GetNowCount() - m_timer <= 18* 1000) m_scene = 20;
	}
	else if (m_scene<=30) {	//不正解
		if (GetNowCount() - m_timer <= 4 * 1000) m_scene = 25;
		else if (GetNowCount() - m_timer <= 6 * 1000) m_scene = 26;
		else if (GetNowCount() - m_timer <= 10 * 1000) m_scene = 27;
		else if (GetNowCount() - m_timer <= 12 * 1000) m_scene = 28;

	}

	return;
}
bool BOF::IsCreated()
{
	return m_createdFlag;
}
