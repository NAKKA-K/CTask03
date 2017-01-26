#include"game_main.h"
#include"genre_select.h"
#include"mode_select.h"
#include"hack_list_io.h"

/*�����������Ă���t�@�C��*/
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
		case 1:	/*BOF�U��*/
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
		case 1:	/*�Z�b�V�����n�C�W���b�N*/
			break;
		case 2:	/*ARP�L���b�V���|�C�Y�j���O*/
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
	return;
}
