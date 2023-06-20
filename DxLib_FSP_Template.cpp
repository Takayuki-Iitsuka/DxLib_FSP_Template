//DxLib_FSP_Template.cpp
//
//#include <windows.h>
#include <DxLib.h>
#include "fps.h"
#include <cmath>

// マクロ定義
#define W_Title "DxLib Test..." //　タイトル
#define W_Vsync TRUE // V-Syncを使うならTRUE
#define W_Icon 555 //　アイコン

const double MY_PI = 3.141592653589793238462643;

const int W_Width = 1280; //　画面の幅
const int W_Height = 720; // 画面の高さ
const int W_ColorBit = 32; // 画面の色

// プロトタイプ宣言
int WINAPI WinMain(_In_	HINSTANCE, _In_opt_ HINSTANCE,
				   _In_	LPSTR, _In_	int);

// Windows Main 関数
int WINAPI WinMain(_In_	HINSTANCE hInstance, _In_opt_ HINSTANCE	hPrevInstance,
				   _In_	LPSTR lpCmdLine, // LPSTR or PSTR
				   _In_	int	nCmdShow)
{
	// Log.txtの出力
#ifndef _DEBUG // ifndef or
	SetOutApplicationSystemLogValidFlag(FALSE); // log.txt
#endif
	//

	ChangeWindowMode(TRUE); //ウィンドウモードの設定
	SetGraphMode(W_Width, W_Height, W_ColorBit); //解像度の設定
	SetWindowSizeChangeEnableFlag(TRUE);
	//SetWindowSize(W_Width, W_Height); //ウィンドウの大きさ設定
	SetMainWindowText(W_Title); //ウィンドウのタイトル設定
	SetBackgroundColor(10, 90, 150); //ウィンドウの背景色
	SetWaitVSyncFlag(W_Vsync); //垂直同期の設定
	SetAlwaysRunFlag(TRUE); //非アクティブでも実行する
	SetWindowIconID(W_Icon); // アイコン

	//DxLibの初期化
	if (DxLib_Init() == -1)
	{
		return -1; //DxLib初期化失敗ならソフト終了
		//return EXIT_FAILURE; // 1 or -1
	}

	//裏画面に描画する（ダブルバッファリング）
	SetDrawScreen(DX_SCREEN_BACK);

	//FPSの初期化
	FPSInit();

	//無限ループ（ゲームループ）
	while (TRUE)
	{
		//メッセージ処理をする（マウス操作やキー入力などを受け続ける）
		if (ProcessMessage() != 0)
		{
			break; //無限ループから出る（ゲーム終了）
		}
		//画面を消去する（１ループずつ書き換える）
		if (ClearDrawScreen() != 0)
		{
			break; //無限ループから出る（ゲーム終了）
		}

		// main loop
		//ここに全ての処理動作が入る
		{
			FPSCheck(); //FPS計測
			////////////////////////////

			
			DrawString(50, 50, "Hello...! DxLib.......!", GetColor(250, 190, 255));
			DrawString((W_Width / 2) - 150, (W_Height / 2) - 60, "Takayuki Iitsuka", GetColor(250, 190, 255));
			DrawString((W_Width / 2) - 150, W_Height / 2, "飯塚　隆行　いいつか　たかゆき　ｲｲﾂｶ ﾀｶﾕｷ", GetColor(250, 190, 255));

			DrawPixel(320, 240, GetColor(255, 255, 255));


			////////////////////////////
			FPSDraw(); //FPS描画
			FPSWait(); //FPS待機
		}
		//main loop End
		//ここまで、全ての処理動作が入る

		//裏画面を画面に描画
		ScreenFlip();

	} // main loop

	//WaitKey(); //キー入力待機

	DxLib_End(); //DxLib終了
	
	return EXIT_SUCCESS; // ソフト終了 return 0;
}

// End
