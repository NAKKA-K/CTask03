#ifndef _FONT_LIST_H
#define _FONT_LIST_H
//�g�p����t�H���g���ꊇ�ł܂Ƃ߂�Class

class FontList
{
public:
	FontList();
	~FontList();

	static int m_colorWhite;//��
	static int m_colorWhite1;//�D�F
	static int m_colorBlack;//��
	static int m_colorGreen;//��
	static int m_colorGreen1;//����(�W�������I�𓙂Ŏg�p)
	static int m_colorBlue;
	static int m_font30;
	static int m_font50;//size50���C���I
	static int m_font75;//size75���C���I
	static int m_font100;//size100���C���I
	static int m_loadFlag;//2�d�ǂݍ��݂𐧌�����Flag
};

#endif // !_FONT_LIST_H
