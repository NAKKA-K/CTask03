#include"game_main.h"
#include"genre_select.h"
#include"mode_select.h"
#include"hack_list_io.h"
#include"scene_mgr.h"

/*問題を実装しているファイル*/
//Learn
#include"learn.h"

//Program
#include"hack_BOF.h"
#include"hack_SQLInjec.h"
#include"hack_XSS.h"

//Network
#include"hack_ARPPoisoning.h"
#include"hack_SYNScan.h"
#include"hack_DNSPoisoning.h"
#include"hack_TargetedMailAttack.h"
#include"hack_sessionHijack.h"
#include"hack_idleScan.h"

//Cipher
#include"hack_Dictionary.h"
#include"hack_BruteForce.h"


void GameMain()
{
	//選択したジャンルとモードによって分岐
	if (ModeSelect::GetSelectMode() == 1) HackLearn();
	//Program
	else if (GenreSelect::GetSelectGenre() == 0) ProgramList();
	//Network
	else if (GenreSelect::GetSelectGenre() == 1) NetworkList();
	//Cipher
	else if (GenreSelect::GetSelectGenre() == 2) CipherList();

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
		case 1:	/*BOF攻撃*/
			HackBOF();
			break;
		case 2:	/*SQLインジェクション*/
			HackSQL();
			break;	
		default:
			SceneMgr::SetScene(SCENE_LIST);
			break;
		/*XSS*/ //HackXSS();
		}
	}
	else {
		//HackLearn();
	}
	return;
}

void NetworkList()
{
	if (ModeSelect::GetSelectMode() == 0) {
		switch (HackListIO::GetSelectList()) {
		case 1:	/*セッションハイジャック*/
			HackHijack();
			break;
		case 2:	/*ARPキャッシュポイズニング*/
			HackARP();
			break;
		case 3:	/*SYNスキャン*/
			HackSYN();
			break;
		case 4:	/*DNSキャッシュポイズニング*/
			HackDNS();
			break;
		case 5:	/*標的型メール攻撃*/
			TargetedMailAttack(1);
			break;
		case 6:
			TargetedMailAttack(2);
			break;
		case 7:
			TargetedMailAttack(3);
			break;
		case 8:	/*アイドルスキャン*/
			HackIdle();
			break;
		default:
			SceneMgr::SetScene(SCENE_LIST);
			break;
		}
	}
	else if (ModeSelect::GetSelectMode() == 1) {
		switch (HackListIO::GetSelectList()) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	return;
}

void CipherList()
{
	if (ModeSelect::GetSelectMode() == 0) {
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
		default:
			SceneMgr::SetScene(SCENE_LIST);
			break;
		}
	}
	else if (ModeSelect::GetSelectMode() == 1) {
		switch (HackListIO::GetSelectList()) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	return;
}
