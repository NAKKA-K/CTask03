#ifndef _SCENE_MGR_H
#define _SCENE_MGR_H

enum SCENE {
	SCENE_INIT,			//�Q�[���J�n���̏�����(���͏��������K�v�Ȏ�)
	SCENE_TITLE,		//�^�C�g�����
	SCENE_GENRE,		//�W�������I�����
	SCENE_MODE,		//���[�h�I�����
	SCENE_LIST,			//?���I�����

	SCENE_GAME,
	SCENE_DEBUG
};


class SceneMgr {
public:
	static void SetScene(int scene);
	static int GetScene();

private:
	static int m_scene;	//������邱�Ƃ͂Ȃ��̂ŋ��L
};


#endif _SCENE_MGR_H
