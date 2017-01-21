#ifndef _MENU_GRAPH_LIST_H
#define _MENU_GRAPH_LIST_H
//メニューに使用する画像を一括でまとめたClass

class MenuGraphList
{
public:
	MenuGraphList();
	~MenuGraphList();

	static int m_bin;	//01の背景画像を保存する変数
	static int m_pulse;//パルスの画像を保存する変数
	static int m_menuG;	//genreの選択肢（文字）の画像を保存する変数
	static int m_titleG;	//タイトル画像
	static int m_modeG;	//モード画像
	static int m_hackListBG;	//HackList背景
};

#endif // !_MENU_GRAPH_LIST_H
