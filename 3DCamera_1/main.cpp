#include "DxLib.h"
#include "Player.h"
#include "Camera.h"


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	//��ʃT�C�Y�̕ύX
	//��1280,�c720�A�J���[�r�b�g��32�Őݒ�
	SetGraphMode(1280, 720, 32);

	// DirectX11���g�p����悤�ɂ���B(DirectX9���A�ꕔ�@�\�s��)
	// Effekseer���g�p����ɂ͕K���ݒ肷��B
	SetUseDirect3DVersion(DX_DIRECT3D_11);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �t���X�N���[���؂�ւ����ɂ��������Ȃ�Ȃ��悤��
	SetChangeScreenModeGraphicsSystemResetFlag(false);

	// Z�o�b�t�@�̐ݒ�
	//Z�o�b�t�@���g�p����
	SetUseZBuffer3D(true);
	
	//Z�o�b�t�@�ɏ������݂��s��
	SetWriteZBuffer3D(true);
	
	//�|���S���̃o�b�N�J�����O���g�p����
	SetUseBackCulling(true);

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);


	//Player�̃|�C���^���쐬
	Player m_player;

	//player�̏�����
	m_player.Init();

	//Camera�̃|�C���^���쐬
	Camera m_camera;

	//Camera�̏�����
	m_camera.Init();
	
	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		//�Q�[����ʂ̍X�V
		//Plyaer�̍X�V
		m_player.Update();

		//Camera�̍X�V
		//Player�̍��W�ʒu���󂯎��
		m_camera.Update(m_player.GetPos());

		//�Q�[����ʂ̕`��
		//Player�̕`��
		m_player.Draw();

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}
	

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}