#include"game_main.h"
#include"genre_select.h"
#include"mode_select.h"

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
		switch (0/*hacklist�őI�񂾎��ʔԍ�*/) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	else if (ModeSelect::GetSelectMode() == 1) {
		switch (0/*hacklist�őI�񂾎��ʔԍ�*/) {
		case 0:
			break;
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
		switch (0/*hacklist�őI�񂾎��ʔԍ�*/) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	else if (ModeSelect::GetSelectMode() == 1) {
		switch (0/*hacklist�őI�񂾎��ʔԍ�*/) {
		case 0:	/*�Z�b�V�����n�C�W���b�N*/

			break;
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
		switch (0/*hacklist�őI�񂾎��ʔԍ�*/) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	else if (ModeSelect::GetSelectMode() == 1) {
		switch (0/*hacklist�őI�񂾎��ʔԍ�*/) {
		case 0:
			break;
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
