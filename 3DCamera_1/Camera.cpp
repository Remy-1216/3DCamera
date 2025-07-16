#include "Camera.h"
#include <cmath>

Camera::Camera(): m_cameraAngleX(0.0f), m_cameraAngleY(0.0f), m_cameraPos(VGet(0.0f,0.0f, 0.0f)), m_cameraTarget(VGet(0.0f, 0.0f, 0.0f))
{
}

Camera::~Camera()
{
}

void Camera::Init()
{
	//奥行100～5000までをカメラの描画範囲とする
	SetCameraNearFar(10.0f, 8000.0f);

	//カメラ位置の初期位置
	m_cameraPos = VGet(0.0f, 0.0f, 0.0f);

	//注視点の初期位置
	m_cameraTarget = VGet(0.0f, 0.0f, 0.0f);
}

void Camera::Update(VECTOR playerPos)
{
	m_pad = GetJoypadDirectInputState(DX_INPUT_PAD1, &m_input);

	//カメラを左右に動かす
	//右にスティックを傾けている
	if (m_input.Rx > 0)
	{
		m_cameraAngleX +=0.09f;
	}
	
	//左にスティックを傾けている
	if (m_input.Rx < 0)
	{
		m_cameraAngleX -= 0.09f;
	}

	//カメラを上下に動かす
	//上にスティックを傾ける
	if (m_input.Ry < 0)
	{
		m_cameraAngleY += 0.05f;
		if (m_cameraAngleY > 1.0f)
		{
			m_cameraAngleY = 1.0f;
		}
	}

	//左にスティックを傾けている
	if (m_input.Ry > 0)
	{
		m_cameraAngleY -= 0.05f;
		if (m_cameraAngleY < 0.0f)
		{
			m_cameraAngleY = 0.0f;
		}
	}


	// カメラ座標
	//計算内容の解説
	//VTransformを行い行列を使った座標変換を行います。MGetRotYを使用しＹ軸回転行列を取得します。
	//playerの座標と足しているのは、プレイヤーが移動した場合も一定の位置からカメラを映し出すためです
	m_cameraPos = VAdd(playerPos,VTransform({ 0.0f,  200.0f,-400.0f }, MGetRotY(m_cameraAngleX)));

	m_cameraTarget = VAdd(playerPos, { 0.0f, 100.0f, 0.0f });

	//カメラ座標と注視点を設定する
	SetCameraPositionAndTarget_UpVecY(m_cameraPos, m_cameraTarget);
}
