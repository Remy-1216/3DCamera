#include "Camera.h"
#include <cmath>

Camera::Camera(): m_cameraAngle(0.0f), m_cameraPos(VGet(0.0f,0.0f,0.0f)), m_cameraTarget(VGet(0.0f,0.0f,0.0f))
{
}

Camera::~Camera()
{
}

void Camera::Init()
{
	//奥行100～5000までをカメラの描画範囲とする
	SetCameraNearFar(10.0f, 8000.0f);
}

void Camera::Update(VECTOR mplayerPos)
{
	m_pad = GetJoypadDirectInputState(DX_INPUT_PAD1, &m_input);

	//カメラを左右に動かす
	//右にスティックを傾けている
	if (m_input.Rx > 0)
	{
		m_cameraAngle +=0.05f;
	}
	//右にスティックを傾けている
		//左にスティックを傾けている
	if (m_input.Rx < 0)
	{
		m_cameraAngle -= 0.05f;
	}

	//カメラを上下に動かす



	// カメラ座標
	//計算内容の解説
	//VTransform
	m_cameraPos = VAdd(mplayerPos, VTransform({ 0.0f,  200.0f,-400.0f }, MGetRotY(m_cameraAngle)));

	// 注視点
	m_cameraTarget = VAdd(mplayerPos, VGet(0.0f, 100.0f, 0.0f));


	//カメラ座標と注視点を設定する
	SetCameraPositionAndTarget_UpVecY(m_cameraPos, m_cameraTarget);
}
