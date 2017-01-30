#include"game_main.h"
#include"genre_select.h"
#include"mode_select.h"
#include"hack_list_io.h"

/*�����������Ă���t�@�C��*/
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
	//�I�������W�������ƃ��[�h�ɂ���ĕ���
	//Program
	if (GenreSelect::GetSelectGenre() == 0) ProgramList();
	//Network
	if (GenreSelect::GetSelectGenre() == 1) NetworkList();
	//Cipher
	if (GenreSelect::GetSelectGenre() == 2) CipherList();

	return;
}

/*
�ȉ���3�֐��ɂ́A�w�K�Ǝ��H�����ꂼ������Ă���
�ꍇ�ɂ���Ă̓��[�h���ɂ��֐��𕪂���\������
*/

void ProgramList()
{
	if (ModeSelect::GetSelectMode() == 0) {
		switch (HackListIO::GetSelectList()) {
		case 1:	/*BOF�U��*/
			HackBOF();
			break;
		case 2:	/*SQL�C���W�F�N�V����*/
			HackSQL();
			break;
		case 3:	/*XSS*/
			//HackXSS();
			break;
		case 4:

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

void NetworkList()
{
	if (ModeSelect::GetSelectMode() == 0) {
		switch (HackListIO::GetSelectList()) {
		case 1:	/*�Z�b�V�����n�C�W���b�N*/
			HackHijack();
			break;
		case 2:	/*ARP�L���b�V���|�C�Y�j���O*/
			HackARP();
			break;
		case 3:	/*SYN�X�L����*/
			HackSYN();
			break;
		case 4:	/*DNS�L���b�V���|�C�Y�j���O*/
			HackDNS();
			break;
		case 5:	/*�W�I�^���[���U��*/
			TargetedMailAttack(1);
			break;
		case 6:
			TargetedMailAttack(2);
			break;
		case 7:
			TargetedMailAttack(3);
			break;
		case 8:	/*�A�C�h���X�L����*/
			HackIdle();
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
		case 1:	/*�����U��*/
			HackDictionary();
			break;
		case 2:	/*BruteForce�U��1(��������)*/
			HackBrute1();
			break;
		case 3:	/*BruteForce�U��2(��������)*/
			HackBrute2();
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
