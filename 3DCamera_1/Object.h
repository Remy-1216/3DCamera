#pragma once
#include "DxLib.h"

class Object
{
public:

	Object();

	virtual ~Object();

	//初期化
	void Init();

	//描画
	void Draw();

private:

	//モデルのハンドル　複数個表示刺せます。
	int m_handle[4];

	//座標 数個所に配置します
	VECTOR m_pos[4];

};

