#ifndef _GENRE_SELECT_H
#define _GENRE_SELECT_H

#define MAX_SELECT_GENRE 3
class GenreSelect {
public:
	GenreSelect();
	~GenreSelect();

	void GenreGraph();
	void GenreKey();
	int GetFont();
	static int GetSelectGenre();

private:
	static int m_selectGenre;
	int m_menuG;	//　genreの選択肢（文字）の画像を保存する変数
	int m_bin;		//　01の背景画像を保存する変数
	int m_pulse;	//　パルスの画像を保存する変数
	int m_font100;	//　文字のサイズを保存する変数
	int CrGreen;	//　緑色の定義を保存する変数
};



#endif // !_GENRE_SELECT_H