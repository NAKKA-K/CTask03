#ifndef _MENU_GRAPH_LIST_H
#define _MENU_GRAPH_LIST_H
//���j���[�Ɏg�p����摜���ꊇ�ł܂Ƃ߂�Class

class MenuGraphList
{
public:
	MenuGraphList();
	~MenuGraphList();

	static int m_bin;	//01�̔w�i�摜��ۑ�����ϐ�
	static int m_pulse;//�p���X�̉摜��ۑ�����ϐ�
	static int m_menuG;	//genre�̑I�����i�����j�̉摜��ۑ�����ϐ�
	static int m_titleG;	//�^�C�g���摜
	static int m_modeG;	//���[�h�摜
	static int m_hackListBG;	//HackList�w�i
};

#endif // !_MENU_GRAPH_LIST_H
