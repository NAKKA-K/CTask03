#ifndef _FONT_LIST_H
#define _FONT_LIST_H
//使用するフォントを一括でまとめたClass

class FontList
{
public:
	FontList();
	~FontList();

	static int m_loadFlag;

	static int m_colorWhite;//白
	static int m_colorWhite1;//灰色
	static int m_colorBlack;//黒
	static int m_colorOrange;//暗いオレンジ
	static int m_colorGreen;//緑
	static int m_colorGreen1;//薄緑(ジャンル選択等で使用)
	static int m_colorBlue;

	static int m_colorRed;
	static int m_colorBrown;
	static int m_colorGreen2;
	static int m_colorOrange1;
	static int m_colorBlue1;


	static int m_font20;
	static int m_font22;
	static int m_font25;
	static int m_font30;
	static int m_font35;
	static int m_font40;
	static int m_font50;//size50メイリオ
	static int m_font65;
	static int m_font70;
	static int m_font75;//size75メイリオ
	static int m_font80;
	static int m_font100;//size100メイリオ

};

#endif // !_FONT_LIST_H
