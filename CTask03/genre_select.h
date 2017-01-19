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
	int m_menuG;	//�@genre�̑I�����i�����j�̉摜��ۑ�����ϐ�
	int m_bin;		//�@01�̔w�i�摜��ۑ�����ϐ�
	int m_pulse;	//�@�p���X�̉摜��ۑ�����ϐ�
	int m_font100;	//�@�����̃T�C�Y��ۑ�����ϐ�
	int CrGreen;	//�@�ΐF�̒�`��ۑ�����ϐ�
};



#endif // !_GENRE_SELECT_H