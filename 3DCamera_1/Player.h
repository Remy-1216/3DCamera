#pragma once
#include "DxLib.h"

class Player
{
public:

	Player();
	virtual ~Player();

	//������
	void Init();

	//���� �J�����̃A���O�����󂯎��
	void Update(float cameraAngle);

	//�`��
	void Draw();

	//�v���C���[�̈ʒu��n��
	VECTOR GetPos() const { return m_pos; }

private:


	//���f���̃n���h��
	int m_handle;

	//�L�����N�^�[�������Ă������
	float m_characterAngle;

	//���f���̍��W
	VECTOR m_pos;

	// �L�����N�^�[���ǂ��܂œ�������
	VECTOR m_move;

	//�J�����̉�]������ɕϊ������l��ۑ�����
	VECTOR m_movementDirection;

	//�J�����̃}�g���b�N�X
	MATRIX m_rotMatrix;

	// ���f���̉�]�s����쐬
	MATRIX m_modelRotMatrix;
};	

