#ifndef _TITLE_H
#define _TITLE_H

class Title
{
public:
	Title();
	~Title();

	void TitleGraph();	//
	void TitleKey();	//
	int GetFont();

private:
	int t_pulse;	//�@�p���X�̉摜��ۑ�����ϐ�
	int t_titleG;	//�@�^�C�g���̕����摜��ۑ�����ϐ�
	int t_bin;	//�@01�̔w�i�摜��ۑ�����ϐ�
	int m_font100;	//�@�����̃T�C�Y��ۑ�����ϐ�
	int CrBlack;	//�@���F�̒�`��ۑ�����ϐ�
};

#endif // !_TITLE_H
