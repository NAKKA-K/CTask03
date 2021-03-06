#include"menu.h"
#include"title.h"
#include"genre_select.h"
#include"mode_select.h"
#include"hack_list_io.h"
#include"keyboard.h"
#include<DxLib.h>

#include"font_list.h"
#include"scene_mgr.h"
#include"action_button.h"

//extern int m_font100;

void TitleScene()
{	
	static Title title;
	
	title.TitleGraph();
	title.TitleKey();

	return;
}

void GenreSelectScene()
{
	static GenreSelect genreSelect;

	genreSelect.GenreKey();
	genreSelect.GenreGraph();
	return;
}

void ModeSelectScene()
{
	static ModeSelect modeSelect;

	modeSelect.ModeGraph();
	modeSelect.ModeKey();
	return;
}

void HackSelectScene()
{
	static HackListIO hackList;

	hackList.ReadHackList();	//readedFlagがtrueの時は読み込まない
	hackList.DrawHackList();//描写、ke判定y、mouse判定

	if (Keyboard_Get(KEY_INPUT_BACK) == 1) {
		hackList.SetReadedListFlag(false);	//次にhackListに戻った時、listを読み込み直すようにflagをfalseに
		SceneMgr::SetScene(SCENE_MODE);
	}
	return;
}
