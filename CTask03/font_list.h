#ifndef _FONT_LIST_H
#define _FONT_LIST_H
//使用するフォントを一括でまとめたClass

class FontList
{
public:
	FontList();
	~FontList();

	static int m_colorWhite;//白
	static int m_colorWhite1;//灰色
	static int m_colorBlack;//黒
	static int m_colorGreen;//緑
	static int m_colorGreen1;//薄緑(ジャンル選択等で使用)
	static int m_colorBlue;
	static int m_font30;
	static int m_font50;//size50メイリオ
	static int m_font75;//size75メイリオ
	static int m_font100;//size100メイリオ
	static int m_loadFlag;//2重読み込みを制限するFlag
};

#endif // !_FONT_LIST_H
