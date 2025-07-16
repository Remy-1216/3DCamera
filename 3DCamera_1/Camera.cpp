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
	//���s100�`5000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(10.0f, 8000.0f);

	//�J�����ʒu�̏����ʒu
	m_cameraPos = VGet(0.0f, 0.0f, 0.0f);

	//�����_�̏����ʒu
	m_cameraTarget = VGet(0.0f, 0.0f, 0.0f);
}

void Camera::Update(VECTOR playerPos)
{
	m_pad = GetJoypadDirectInputState(DX_INPUT_PAD1, &m_input);

	//�J���������E�ɓ�����
	//�E�ɃX�e�B�b�N���X���Ă���
	if (m_input.Rx > 0)
	{
		m_cameraAngleX +=0.09f;
	}
	
	//���ɃX�e�B�b�N���X���Ă���
	if (m_input.Rx < 0)
	{
		m_cameraAngleX -= 0.09f;
	}

	//�J�������㉺�ɓ�����
	//��ɃX�e�B�b�N���X����
	if (m_input.Ry < 0)
	{
		m_cameraAngleY += 0.05f;
		if (m_cameraAngleY > 1.0f)
		{
			m_cameraAngleY = 1.0f;
		}
	}

	//���ɃX�e�B�b�N���X���Ă���
	if (m_input.Ry > 0)
	{
		m_cameraAngleY -= 0.05f;
		if (m_cameraAngleY < 0.0f)
		{
			m_cameraAngleY = 0.0f;
		}
	}


	// �J�������W
	//�v�Z���e�̉��
	//VTransform���s���s����g�������W�ϊ����s���܂��BMGetRotY���g�p���x����]�s����擾���܂��B
	//player�̍��W�Ƒ����Ă���̂́A�v���C���[���ړ������ꍇ�����̈ʒu����J�������f���o�����߂ł�
	m_cameraPos = VAdd(playerPos,VTransform({ 0.0f,  200.0f,-400.0f }, MGetRotY(m_cameraAngleX)));

	m_cameraTarget = VAdd(playerPos, { 0.0f, 100.0f, 0.0f });

	//�J�������W�ƒ����_��ݒ肷��
	SetCameraPositionAndTarget_UpVecY(m_cameraPos, m_cameraTarget);
}
