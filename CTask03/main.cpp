#include<DxLib.h>
#include"Keyboard.h"
#include"scene_mgr.h"
#include"menu.h"
#include"game_main.h"
#include"font_list.h"

//int font100;

void Init();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrecInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�����ݒ聚
	SetGraphMode(1920, 1080, 16);            	//(�K�{)��ʂ̃T�C�Y�ݒ�
	ChangeWindowMode(TRUE);                	//()FullScreen�ł͂Ȃ�Window�ŊJ��
	if (DxLib_Init() == -1) return -1;            	//(�K�{)DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);    	//(�K�{)�O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetMouseDispFlag(TRUE);						//�}�E�X�J�[�\���̕\��
	
	FontList fontlist;	//�N���X�̃R���X�g���N�^���N�������邽�߂����ɐ錾
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && Keyboard_Get(KEY_INPUT_ESCAPE) == 0) {
		Keyboard_Update();

		switch (SceneMgr::GetScene()) {
		case SCENE_INIT:
			Init();
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

			break;

		//Game
		case SCENE_GAME:
			GameMain();
			break;
		}
	}

	DxLib_End();
	return 0;
}


void Init()
{
	//font100= CreateFontToHandle("���C���I", 100, 3);



	//End init
	SceneMgr::SetScene(SCENE_TITLE);
	return;
}