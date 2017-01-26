#include"game_main.h"
#include"genre_select.h"
#include"mode_select.h"
#include"hack_list_io.h"

/*問題を実装しているファイル*/
//Program
#include"hack_BOF.h"

//Network
#include"hack_ARPPoisoning.h"
#include"hack_SYNScan.h"

//Cipher
#include"hack_Dictionary.h"
#include"hack_BruteForce.h"


void GameMain()
{
	//選択したジャンルとモードによって分岐
	//Program
	if (GenreSelect::GetSelectGenre() == 0) ProgramList();
	//Network
	if (GenreSelect::GetSelectGenre() == 1) NetworkList();
	//Cipher
	if (GenreSelect::GetSelectGenre() == 2) CipherList();

	return;
}

/*
以下の3関数には、学習と実践がそれぞれ入っている
場合によってはモード毎にも関数を分ける可能性あり
*/

void ProgramList()
{
	if (ModeSelect::GetSelectMode() == 0) {
		switch (HackListIO::GetSelectList()) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	else if (ModeSelect::GetSelectMode() == 1) {
		switch (HackListIO::GetSelectList()) {
		case 1:	/*BOF攻撃*/
			HackBOF();
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	return;
}

void NetworkList()
{
	if (ModeSelect::GetSelectMode() == 0) {
		switch (HackListIO::GetSelectList()) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	else if (ModeSelect::GetSelectMode() == 1) {
		switch (HackListIO::GetSelectList()) {
		case 1:	/*セッションハイジャック*/
			break;
		case 2:	/*ARPキャッシュポイズニング*/
			HackARP();
			break;
		case 3:
			HackSYN();
			break;
		}
	}
	return;
}

void CipherList()
{
	if (ModeSelect::GetSelectMode() == 0) {
		switch (HackListIO::GetSelectList()) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	else if (ModeSelect::GetSelectMode() == 1) {
		switch (HackListIO::GetSelectList()) {
		case 1:	/*辞書攻撃*/
			HackDictionary();
			break;
		case 2:	/*BruteForce攻撃1(総当たり)*/
			HackBrute1();
			break;
		case 3:	/*BruteForce攻撃2(総当たり)*/
			HackBrute2();
			break;
		}
	}
	return;
}
