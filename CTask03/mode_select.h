#ifndef _MODE_SELECT_H
#define _MODE_SELECT_H


#define MAX_SELECT_MODE 2
class ModeSelect
{
public:
	ModeSelect();
	~ModeSelect();

	void ModeGraph();
	void ModeKey();
	int GetFont();
	static int GetSelectMode();

private:
	static int m_selectMode;
	int m_modeG;	//�@���[�h�I�����i�����j�̉摜��ۑ�����ϐ�
	int m_pulse;	//�@�p���X�̉摜��ۑ�����ϐ�
	int m_bin;		//�@01�̔w�i�摜��ۑ�����ϐ�
	int m_font100;	//�@�����̃T�C�Y��ۑ�����ϐ�
	int CrGreen;	//�@�ΐF�̒�`��ۑ�����ϐ�
};

#endif // !_MODE_SELECT_H
