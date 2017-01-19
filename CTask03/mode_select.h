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
	int m_modeG;	//　モード選択肢（文字）の画像を保存する変数
	int m_pulse;	//　パルスの画像を保存する変数
	int m_bin;		//　01の背景画像を保存する変数
	int m_font100;	//　文字のサイズを保存する変数
	int CrGreen;	//　緑色の定義を保存する変数
};

#endif // !_MODE_SELECT_H
