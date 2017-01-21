#ifndef _GENRE_SELECT_H
#define _GENRE_SELECT_H
//ジャンル画面の表示


#define MAX_SELECT_GENRE 3
class GenreSelect {
public:
	GenreSelect();
	~GenreSelect();

	void GenreGraph();
	void GenreKey();
	static int GetSelectGenre();

private:
	static int m_selectGenre;
};



#endif // !_GENRE_SELECT_H