//
//#include <windows.h>
#include <DxLib.h>
#include "fps.h"
#include <cmath>

//
#define W_Title "DxLib Test..."
#define W_Vsync TRUE // V-Syncを使うならTRUE
#define W_Icon 555

// プロトタイプ宣言
int WINAPI WinMain(_In_	HINSTANCE, _In_opt_ HINSTANCE,
				   _In_	LPSTR, _In_	int);

// Windows Main 関数
int WINAPI WinMain(_In_	HINSTANCE hInstance, _In_opt_ HINSTANCE	hPrevInstance,
				   _In_	LPSTR lpCmdLine, // LPSTR or PSTR
				   _In_	int	nCmdShow)
{
#ifndef _DEBUG // ifndef or
	SetOutApplicationSystemLogValidFlag(FALSE); // log.txt
#endif
	//
	const int W_Width = 1280;
	const int W_Height = 720;
	const int W_ColorBit = 32;
	const double MY_PI = 3.141592653589793238462643;

	ChangeWindowMode(TRUE);
	SetGraphMode(W_Width, W_Height, W_ColorBit);
	SetWindowSizeChangeEnableFlag(TRUE);
	//SetWindowSize(W_Width, W_Height);
	SetMainWindowText(W_Title);
	SetBackgroundColor(10, 90, 150);
	SetWaitVSyncFlag(W_Vsync);
	SetAlwaysRunFlag(TRUE);
	SetWindowIconID(W_Icon); // アイコン

	if (DxLib_Init() == -1)
	{
		return -1;
		//return EXIT_FAILURE; // 1 or -1
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//FPS
	FPSInit();

	while (TRUE)
	{
		if (ProcessMessage() != 0)
		{
			break;
		}
		if (ClearDrawScreen() != 0)
		{
			break;
		}
		// main loop
		{
			FPSCheck();
			FPSDraw();
			FPSWait();

			DrawString(50, 50, "Hello...! DxLib.......!", GetColor(250, 190, 255));
			DrawString((W_Width / 2) - 150, (W_Height / 2) - 60, "Takayuki Iitsuka", GetColor(250, 190, 255));
			DrawString((W_Width / 2) - 150, W_Height / 2, "飯塚　隆行　いいつか　たかゆき　ｲｲﾂｶ ﾀｶﾕｷ", GetColor(250, 190, 255));

			DrawPixel(320, 240, GetColor(255, 255, 255));

		}
		//
		ScreenFlip();

	} // main loop

	//WaitKey();
	DxLib_End();
	//return 0;
	return EXIT_SUCCESS;
}

// End
