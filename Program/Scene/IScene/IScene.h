#pragma once
#include <Novice.h>
#include "Program/InputManager/InputManager.h"

//シーン名を列挙型(Enum)で定義
enum SCENE { TITLE, STAGE, CLEAR };

/// <summary>
/// シーンの元になるクラス
/// </summary>
class IScene
{

protected: // 静的メンバ変数

	// シーン番号
	static int sceneNo;

	// 入力マネージャー
	static InputManager* inputManager_;

public: // メンバ関数

	/// <summary>
	/// 静的初期化
	/// </summary>
	void StaticInit();

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init() = 0;

	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw() = 0;

	//デストラクタ
	virtual ~IScene();

	// シーン番号のゲッター
	int GetSceneNo();

};

