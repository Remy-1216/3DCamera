#include "DxLib.h"
#include "Player.h"
#include <vector>
#include <algorithm>

Player::Player():m_handle(-1), m_characterAngle(0.0f), m_pos(VGet(0.0f, 0.0f, 0.0f)),  m_movementDirection(VGet(0.0f, 0.0f, 0.0f))
{
}

Player::~Player()
{
	//���f���̍폜
	MV1DeleteModel(m_handle);
}

void Player::Init()
{
	//���f�������[�h�A���������f����ۑ����Ă���ʒu�������B
	m_handle = MV1LoadModel("data/Player.mv1");

	
	//���f���̈ʒu��ݒ肷��
	MV1SetPosition(m_handle, m_pos);
}

void Player::Update(float cameraAngle)
{
	//�A�i���O�X�e�B�b�N���g���Ĉړ�
	int analogX = 0;
	int analogZ = 0;

	GetJoypadAnalogInput(&analogX, &analogZ, DX_INPUT_PAD1);

	//�x�N�g���̒������ő��1000�ɂȂ�
	//�v���C���[�̍ő�ړ����x��0.01f / frame
	m_move = VGet(analogX, 0.0f, -analogZ);	//�x�N�g���̒�����0�`1000

	//0.00 ~ 0.01�̒����ɂ���
	//�x�N�g���̒������擾����
	float len = VSize(m_move);

	//�x�N�g���̒�����0.0~1.0�̊����ɕϊ�����
	float rate = len / 1000.0f;

	//���x������ł���̂ňړ��x�N�g���ɔ��f����
	m_move = VNorm(m_move);

	float speed = 10.0f * rate;
	m_move = VScale(m_move, speed);


	// �J�����̉�]����ɕ�����ϊ�
	m_rotMatrix = MGetRotY(cameraAngle);
	m_movementDirection = VTransform(m_move, m_rotMatrix);

	//�ړ������ƃL�����N�^�[�̍��W�𑫂�
	m_pos = VAdd(m_pos,m_movementDirection);

	// �ړ����̂݌������X�V����
	if (VSize(m_movementDirection) > 0.0f)
	{
		m_characterAngle = atan2f(-m_movementDirection.x, -m_movementDirection.z);
	}

	//���f���̉�]�X�V
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_characterAngle, 0.0f));

	//���f���̈ʒu��ݒ肷��
	MV1SetPosition(m_handle, m_pos);
}

void Player::Draw()
{
	//���f���̕\��
	MV1DrawModel(m_handle);

	//�v���C���[�̍��W�ʒu��\������
	DrawFormatString(0, 400, GetColor(255, 255, 255), "player�̍��W(%.2f,%.2f,%.2f)", m_pos.x, m_pos.y, m_pos.z);
}
