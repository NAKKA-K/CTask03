#include"menu.h"
#include"title.h"
#include"genre_select.h"
#include"mode_select.h"
#include<DxLib.h>

#include"scene_mgr.h"
#include"action_button.h"

//extern int m_font100;

void TitleScene()
{
	Title title;
	
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


