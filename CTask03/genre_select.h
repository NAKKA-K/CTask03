#ifndef _GENRE_SELECT_H
#define _GENRE_SELECT_H
//�W��������ʂ̕\��


#define MAX_SELECT_GENRE 3
class GenreSelect {
public:
	GenreSelect();
	~GenreSelect();

	void GenreGraph();
	void GenreKey();
	static int GetSelectGenre();

	static void DebugSetGenre(int genre);

private:
	static int m_selectGenre;
};



#endif // !_GENRE_SELECT_H