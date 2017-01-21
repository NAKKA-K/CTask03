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
		hackList.SetReadedListFlag(false);	//����hackList�ɖ߂������Alist��ǂݍ��ݒ����悤��flag��false��
		SceneMgr::SetScene(SCENE_MODE);
	}

	hackList.ReadHackList();	//readedFlag��true�̎��͓ǂݍ��܂Ȃ�
	hackList.DrawHackList();//�`�ʁAke����y�Amouse����

	return;
}
