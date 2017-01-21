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

	/*Debug*/
	ActionButton button;
	button.DebugButton(button);

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
	if (Keyboard_Get(KEY_INPUT_BACK) == 1) {
		hackList.SetReadedListFlag(false);	//Ÿ‚ÉhackList‚É–ß‚Á‚½Alist‚ğ“Ç‚İ‚İ’¼‚·‚æ‚¤‚Éflag‚ğfalse‚É
		SceneMgr::SetScene(SCENE_MODE);
	}

	hackList.ReadHackList();	//readedFlag‚ªtrue‚Ì‚Í“Ç‚İ‚Ü‚È‚¢
	hackList.DrawHackList();//•`ÊAke”»’èyAmouse”»’è

	return;
}
