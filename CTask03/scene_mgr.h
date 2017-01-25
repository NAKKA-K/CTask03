#ifndef _SCENE_MGR_H
#define _SCENE_MGR_H

enum SCENE {
	SCENE_INIT,			//ゲーム開始時の初期化(又は初期化が必要な時)
	SCENE_TITLE,		//タイトル画面
	SCENE_GENRE,		//ジャンル選択画面
	SCENE_MODE,		//モード選択画面
	SCENE_LIST,			//?問題選択画面

	SCENE_GAME,
	SCENE_DEBUG
};


class SceneMgr {
public:
	static void SetScene(int scene);
	static int GetScene();

private:
	static int m_scene;	//複数作ることはないので共有
};


#endif _SCENE_MGR_H
