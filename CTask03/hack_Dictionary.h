#ifndef _HACK_DICTIONARY_H
#define _HACK_DICTIONARY_H


class Dictionary
{
public:
	Dictionary();
	~Dictionary();

	void DictionaryGraph();
	void DictionaryKey();
	bool IsCreated();

private:
	int m_scene;
	int m_timer;
	int m_alpha;

	int bright;
	char str[8];
	char answer[10][8] = {"admin","root","0120","0000","1234","master","C++","pc","main","intel"};
	int ansNum;	//ìöÇ¶ÇÃäiî[à íu(óêêî)

	static bool m_createdFlag;

	int m_hackBG;
	int m_webAppG;
};

void HackDictionary();


#endif // !_HACK_DICTIONARY_H
