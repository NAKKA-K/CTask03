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
	int t_pulse;	//　パルスの画像を保存する変数
	int t_titleG;	//　タイトルの文字画像を保存する変数
	int t_bin;	//　01の背景画像を保存する変数
	int m_font100;	//　文字のサイズを保存する変数
	int CrBlack;	//　黒色の定義を保存する変数
};

#endif // !_TITLE_H
