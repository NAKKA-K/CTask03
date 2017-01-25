#include<DxLib.h>
#include"Keyboard.h"
#include"scene_mgr.h"
#include"menu.h"
#include"game_main.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include"mouse_status.h"

#include"genre_select.h"
#include"mode_select.h"
#include"hack_list_io.h"
/*
action_button.cpp��Debug�R�[�h
*/


void Init();
void Debug();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrecInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�����ݒ聚
	SetGraphMode(1920, 1080, 16);            	//(�K�{)��ʂ̃T�C�Y�ݒ�
	//ChangeWindowMode(TRUE);                	//()FullScreen�ł͂Ȃ�Window�ŊJ��
	if (DxLib_Init() == -1) return -1;            	//(�K�{)DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);    	//(�K�{)�O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetMouseDispFlag(TRUE);						//�}�E�X�J�[�\���̕\��


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && Keyboard_Get(KEY_INPUT_ESCAPE) == 0) {
		Keyboard_Update();

		switch (SceneMgr::GetScene()) {
		case SCENE_INIT:
			Init();
			//SceneMgr::SetScene(SCENE_DEBUG);
			break;

		//Menu
		case SCENE_TITLE:
			TitleScene();
			break;
		case SCENE_GENRE:
			GenreSelectScene();
			break;
		case SCENE_MODE:
			ModeSelectScene();
			break;
		case SCENE_LIST:
			HackSelectScene();
			break;

		//Game
		case SCENE_GAME:
			GameMain();
			break;
		case SCENE_DEBUG:
			Debug();
			break;
		}
		MouseStatus::printMousePoint();
	}

	DxLib_End();
	return 0;
}


void Init()
{
	/*�N���X�̃R���X�g���N�^���N�������邽�߂����ɐ錾*/
	FontList fontlist;
	MenuGraphList menuGraphList;


	SceneMgr::SetScene(SCENE_TITLE);
	return;
}

void Debug()
{
	GenreSelect::DebugSetGenre(1);//Network
	ModeSelect::DebugSetMode(1);//Learn

	SceneMgr::SetScene(SCENE_LIST);
	return;
}