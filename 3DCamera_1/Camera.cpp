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
	//���s100�`5000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(10.0f, 8000.0f);
}

void Camera::Update(VECTOR mplayerPos)
{
	m_pad = GetJoypadDirectInputState(DX_INPUT_PAD1, &m_input);

	//�J���������E�ɓ�����
	//�E�ɃX�e�B�b�N���X���Ă���
	if (m_input.Rx > 0)
	{
		m_cameraAngle +=0.05f;
	}
	//�E�ɃX�e�B�b�N���X���Ă���
		//���ɃX�e�B�b�N���X���Ă���
	if (m_input.Rx < 0)
	{
		m_cameraAngle -= 0.05f;
	}

	//�J�������㉺�ɓ�����



	// �J�������W
	//�v�Z���e�̉��
	//VTransform
	m_cameraPos = VAdd(mplayerPos, VTransform({ 0.0f,  200.0f,-400.0f }, MGetRotY(m_cameraAngle)));

	// �����_
	m_cameraTarget = VAdd(mplayerPos, VGet(0.0f, 100.0f, 0.0f));


	//�J�������W�ƒ����_��ݒ肷��
	SetCameraPositionAndTarget_UpVecY(m_cameraPos, m_cameraTarget);
}
