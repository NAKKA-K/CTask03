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
	//初期設定★
	SetGraphMode(1920, 1080, 16);            	//(必須)画面のサイズ設定
	ChangeWindowMode(TRUE);                	//()FullScreenではなくWindowで開く
	if (DxLib_Init() == -1) return -1;            	//(必須)DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);    	//(必須)グラフィックの描画先を裏画面にセット
	SetMouseDispFlag(TRUE);						//マウスカーソルの表示
	
	FontList fontlist;	//クラスのコンストラクタを起動させるためだけに宣言
	
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
	//font100= CreateFontToHandle("メイリオ", 100, 3);



	//End init
	SceneMgr::SetScene(SCENE_TITLE);
	return;
}