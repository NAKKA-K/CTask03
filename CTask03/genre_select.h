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
	int m_font100;
	int m_menuBG;
};



#endif // !_GENRE_SELECT_H