#ifndef _LEARN_H
#define _LEARN_H


class Learn {
public:
	Learn();
	~Learn();

	void LearnGraph();
	void LearnKey();
	bool IsCreated();

private:
	static bool m_createdFlg;
	int m_maxScene;
	int m_scene;
	int m_sceneG[32];

	char folderName[56];	//ó·)Learn/BOFçUåÇ/


};

void HackLearn();


#endif // !_LEARN_H