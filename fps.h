// fps.h
#pragma once

#include <DxLib.h>

#define W_FPS			60
#define MicroSecond		1000000.0f
#define MillSecond		1000.0f
#define WaitTimeMill	3000

typedef struct _FPS {
	LONGLONG FirstTakeTime = 0;
	LONGLONG NowTakeTime = 0;
	LONGLONG OldTakeTime = 0;

	float DeltaTime = 0.000001f;
	int FrameCount = 1;
	float Average = 0.0f;
}FPS;

extern FPS fps;

extern VOID FPSInit(VOID);
extern VOID FPSCheck(VOID);
extern VOID FPSDraw(VOID);
extern VOID FPSWait(VOID);

// End
