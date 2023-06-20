//DxLib_FSP_Template.cpp
//
//#include <windows.h>
#include <DxLib.h>
#include "fps.h"
#include <cmath>

// �}�N����`
#define W_Title "DxLib Test..." //�@�^�C�g��
#define W_Vsync TRUE // V-Sync���g���Ȃ�TRUE
#define W_Icon 555 //�@�A�C�R��

const double MY_PI = 3.141592653589793238462643;

const int W_Width = 1280; //�@��ʂ̕�
const int W_Height = 720; // ��ʂ̍���
const int W_ColorBit = 32; // ��ʂ̐F

// �v���g�^�C�v�錾
int WINAPI WinMain(_In_	HINSTANCE, _In_opt_ HINSTANCE,
				   _In_	LPSTR, _In_	int);

// Windows Main �֐�
int WINAPI WinMain(_In_	HINSTANCE hInstance, _In_opt_ HINSTANCE	hPrevInstance,
				   _In_	LPSTR lpCmdLine, // LPSTR or PSTR
				   _In_	int	nCmdShow)
{
	// Log.txt�̏o��
#ifndef _DEBUG // ifndef or
	SetOutApplicationSystemLogValidFlag(FALSE); // log.txt
#endif
	//

	ChangeWindowMode(TRUE); //�E�B���h�E���[�h�̐ݒ�
	SetGraphMode(W_Width, W_Height, W_ColorBit); //�𑜓x�̐ݒ�
	SetWindowSizeChangeEnableFlag(TRUE);
	//SetWindowSize(W_Width, W_Height); //�E�B���h�E�̑傫���ݒ�
	SetMainWindowText(W_Title); //�E�B���h�E�̃^�C�g���ݒ�
	SetBackgroundColor(10, 90, 150); //�E�B���h�E�̔w�i�F
	SetWaitVSyncFlag(W_Vsync); //���������̐ݒ�
	SetAlwaysRunFlag(TRUE); //��A�N�e�B�u�ł����s����
	SetWindowIconID(W_Icon); // �A�C�R��

	//DxLib�̏�����
	if (DxLib_Init() == -1)
	{
		return -1; //DxLib���������s�Ȃ�\�t�g�I��
		//return EXIT_FAILURE; // 1 or -1
	}

	//����ʂɕ`�悷��i�_�u���o�b�t�@�����O�j
	SetDrawScreen(DX_SCREEN_BACK);

	//FPS�̏�����
	FPSInit();

	//�������[�v�i�Q�[�����[�v�j
	while (TRUE)
	{
		//���b�Z�[�W����������i�}�E�X�����L�[���͂Ȃǂ��󂯑�����j
		if (ProcessMessage() != 0)
		{
			break; //�������[�v����o��i�Q�[���I���j
		}
		//��ʂ���������i�P���[�v������������j
		if (ClearDrawScreen() != 0)
		{
			break; //�������[�v����o��i�Q�[���I���j
		}

		// main loop
		//�����ɑS�Ă̏������삪����
		{
			FPSCheck(); //FPS�v��
			////////////////////////////

			
			DrawString(50, 50, "Hello...! DxLib.......!", GetColor(250, 190, 255));
			DrawString((W_Width / 2) - 150, (W_Height / 2) - 60, "Takayuki Iitsuka", GetColor(250, 190, 255));
			DrawString((W_Width / 2) - 150, W_Height / 2, "�ђˁ@���s�@�������@�����䂫�@��¶ ��շ", GetColor(250, 190, 255));

			DrawPixel(320, 240, GetColor(255, 255, 255));


			////////////////////////////
			FPSDraw(); //FPS�`��
			FPSWait(); //FPS�ҋ@
		}
		//main loop End
		//�����܂ŁA�S�Ă̏������삪����

		//����ʂ���ʂɕ`��
		ScreenFlip();

	} // main loop

	//WaitKey(); //�L�[���͑ҋ@

	DxLib_End(); //DxLib�I��
	
	return EXIT_SUCCESS; // �\�t�g�I�� return 0;
}

// End
