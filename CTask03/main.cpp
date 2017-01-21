/*
シングルトン
スマートポインタ:メモリリークをなくすためのもの。参照されなくなったメモリがあれば開放する。
	uniquePtr:参照先が1つしか作れない
	sharedPtr:参照先が複数作れる。しかし参照先同士で相互参照が起き、削除されなくなる。そのためにweekPtr
	weekPtr:複数の参照先の1つが削除されれば、他も同じように削除する
インターフェース:全て仮想関数(virtual void A() =0;)。いくらでも継承して大丈夫。
関数:void A();		A()=delete;	A()=0;	A()=default;
GetSet:ゲッターセッター
using
デザインパターン:ゲーム作成？
*/

#include<DxLib.h>
#include"Keyboard.h"
#include"scene_mgr.h"
#include"menu.h"
#include"game_main.h"
#include"font_list.h"
#include"menu_graph_list.h"
#include"mouse_status.h"

/*
action_button.cppにDebugコード
*/


void Init();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrecInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//初期設定★
	SetGraphMode(1920, 1080, 16);            	//(必須)画面のサイズ設定
	//ChangeWindowMode(TRUE);                	//()FullScreenではなくWindowで開く
	if (DxLib_Init() == -1) return -1;            	//(必須)DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);    	//(必須)グラフィックの描画先を裏画面にセット
	SetMouseDispFlag(TRUE);						//マウスカーソルの表示


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
			HackSelectScene();
			break;

		//Game
		case SCENE_GAME:
			//GameMain();
			break;
		}
		MouseStatus::printMousePoint();
	}

	DxLib_End();
	return 0;
}


void Init()
{
	/*クラスのコンストラクタを起動させるためだけに宣言*/
	FontList fontlist;
	MenuGraphList menuGraphList;


	SceneMgr::SetScene(SCENE_TITLE);
	return;
}