#include "hack_list_io.h"
#include "keyboard.h"
#include"genre_select.h"
#include"mode_select.h"
#include"font_list.h"
#include"action_button.h"
#include<string>
#include<stdio.h>
#include<DxLib.h>

char HackListIO::m_questionTitle[32][64];
int HackListIO::m_questionNum=0;
bool HackListIO::m_readedListFlag = false;
int HackListIO::m_hackListBG = 0;
//int HackList::m_selectList = 0;

HackListIO::HackListIO()
{
}
HackListIO::~HackListIO()
{
	m_readedListFlag = false;
	fclose(fp);
}


bool HackListIO::ReadHackList()
{
	if (m_readedListFlag == false) {
		const char *modeName[2]{
			"_g","_j"
		};
		char fileName[16];


		//ファイル名の決定とファイルオープン
		snprintf(fileName, sizeof(fileName),
			"%s%s.txt", m_genreName[GenreSelect::GetSelectGenre()], modeName[ModeSelect::GetSelectMode()]);
		fopen_s(&fp, fileName, "r");
		if (fp == NULL) {

			return false;
		}

		//listをすべて読み込み。モード選択からhacklistに到達するたびにm_readedListFlagをfalseにする
		for (int i = 0; fscanf_s(fp, "%[^,],%d\n",
			m_questionTitle[i], sizeof(m_questionTitle[0]), &m_questionNum) != EOF; i++) {
		}
		m_readedListFlag = true;
	}
	
	return true;
}

void HackListIO::DrawHackList()
{
	//HACK:この変数たちの値をどうにかしてやらなければいけない
	static int namex = 150, namey = 250;	//一番左上の、問題タイトル座標
	static int dname = 150;
	static int astx = 50, asty = 250;	//アスタリスクの座標
	static int drawIdx=0;	//問題タイトルの配列に使用。[drawIdx~drawIdx+9]をfor文で出力している


	//背景、ジャンル名、選択カーソルの表示
	DrawGraph(0, 0, m_hackListBG, false);	//背景出力
	DrawStringToHandle(110, 120, m_genreName[GenreSelect::GetSelectGenre()], FontList::m_colorGreen, FontList::m_font100);		//ジャンル名出力
	DrawStringToHandle(astx, asty, "*", FontList::m_colorGreen, FontList::m_font100);


	static ActionButton button;
	//Buttonの表示。Buttonをクリック、又は指定したKEYを押すとtrueが戻る(今回はKEY_INPUT_RIGHT)


	//問題タイトルを1ページ分表示(座標をワークスペースに代入)
	//1ページに見える範囲の配列しか表示していない
	for (int i = drawIdx, x = namex, y = namey; i < m_questionNum || i < (drawIdx + 9); i++) {
		DrawStringToHandle(x, y, m_questionTitle[i], FontList::m_colorGreen, FontList::m_font100);
		y += 150;		//1問ずつ改行
		if ((i + 1) % 5 == 0) {	//5問分表示したら2列目(i%5だと、iが0だった時に最初から改行されるため+1)
			x += 960;
			y = 250;
		}
	}

	//HACK:Listの上限を超えて別の領域にアクセスしている。if文などで制御求む(drawIdxを使用せずに、別の方式でも問題ない)
	//HACK:drawIdxとはバグを直すときに取った、救済措置のようなものなのでどこかに穴が潜んでいるかもしれない
	//HACK:現に選択した問題の識別番号をすぐに特定することができない
	if (button.ActionInButton(1700, 850, 1750, 900, "→", KEY_INPUT_RIGHT) == true) {
		if (astx < 960) {//画面左なら右に
			astx += 960;
		}
		else {
			/*dname -= 960;
			namex = dname;
			namey = 250;*/
			drawIdx += 5;
		}
		//namey += 150;								//1問ずつ改行
		//strnum += 1;								//表示した問題数を記憶
	}
	if (button.ActionInButton(1650, 850, 1700, 900, "←",KEY_INPUT_LEFT) == true) {		
		if (astx > 960) {//画面右なら左に
			astx -= 960;
		}
		else if(drawIdx!=0){
			/*dname -= 960;
			namex = dname;
			namey = 250;*/
			drawIdx -= 5;
		}
		//dname -= 960;
		//namex = dname;
		//namey = 250;
	}
	if (button.ActionInButton(1675, 900, 1715, 950, "↓", KEY_INPUT_DOWN) == true) {
		if (asty < 850)
			asty += 150;
	}
	if (button.ActionInButton(1675, 800, 1715, 850, "↑", KEY_INPUT_UP) == true) {
		if (asty > 850)	//HACK:適当にコピーしただけなので修正求む
			asty -= 150;
	}
	//HACK:表示場所が適当なので修正求む
	if (button.ActionInButton(1800, 950, 1900, 1000, "決定", KEY_INPUT_RETURN) == true) {
		//HACK:選択した問題が分かるように、識別番号を静的メンバ変数に保存すべし(m_selectList)
	}
	return;
}

bool HackListIO::GetReadedListFlag()
{
	return m_readedListFlag;
}

void HackListIO::SetReadedListFlag(bool readedListFlag)
{
	m_readedListFlag = readedListFlag;
}

