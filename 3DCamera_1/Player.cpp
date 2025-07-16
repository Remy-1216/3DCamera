#include "Player.h"

Player::Player():m_handle(-1),m_pos(VGet(0.0f,0.0f,0.0f)),m_pad(0)
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

void Player::Update()
{
	m_pad = GetJoypadDirectInputState(DX_INPUT_PAD1, &m_input);

	//�X�e�B�b�N��|���������ɐi��
	if (m_input.X < 0)
	{
		m_pos.x -= 10.0f;
	}
	if((m_input.X > 0))
	{
		m_pos.x += 10.0f;
	}

	if (m_input.Y < 0)
	{
		m_pos.z += 10.0f;
	}
    if(m_input.Y > 0)
	{
		m_pos.z -= 10.0f;
	}

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
