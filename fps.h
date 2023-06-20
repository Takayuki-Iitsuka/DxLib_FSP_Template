// fps.h
#pragma once

#include <DxLib.h>

//マクロ定義
#define W_FPS			60 //FPSの設定
#define MicroSecond		1000000.0f //1マクロ秒
#define MillSecond		1000.0f //1ミリ秒
#define WaitTimeMill	3000 //最大で待てるミリ秒

//構造体の定義
typedef struct _FPS {
	LONGLONG FirstTakeTime = 0; //１フレーム目の計測時間
	LONGLONG NowTakeTime = 0; //現在の計測時間
	LONGLONG OldTakeTime = 0; //以前の計測時間

	float DeltaTime = 0.000001f; //デルタタイム（経過時間）
	int FrameCount = 1; //現在のフレーム数（１フレーム目～MAXフレーム目まで）
	float Average = 0.0f; //平均FPS値
}FPS;

//外部グローバル変数
extern FPS fps;

//外部プロトタイプ宣言
extern VOID FPSInit(VOID);
extern VOID FPSCheck(VOID);
extern VOID FPSDraw(VOID);
extern VOID FPSWait(VOID);

// End
