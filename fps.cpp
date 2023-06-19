// fps.cpp
#include "fps.h"

FPS fps;

VOID FPSInit(VOID)
{
	fps.FirstTakeTime = GetNowHiPerformanceCount();
	fps.NowTakeTime = fps.FirstTakeTime;
	fps.OldTakeTime = fps.FirstTakeTime;
	fps.DeltaTime = 0.000001f;
	fps.FrameCount = 1;
	fps.Average = 0.0f;

	return;
}

VOID FPSCheck(VOID)
{
	fps.NowTakeTime = GetNowHiPerformanceCount();
	fps.DeltaTime = (fps.NowTakeTime - fps.OldTakeTime) / MicroSecond;
	fps.OldTakeTime = fps.NowTakeTime;
	if (fps.FrameCount == W_FPS) {
		float TotalFrameTime = fps.NowTakeTime - fps.FirstTakeTime;
		float CalcAveasge = TotalFrameTime / W_FPS;
		fps.Average = MicroSecond / CalcAveasge;
		fps.FirstTakeTime = GetNowHiPerformanceCount();
		fps.FrameCount = 1;
	}
	else {
		fps.FrameCount++;
	}

	return;
}

VOID FPSDraw(VOID)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS:%3.1f", fps.Average);

	return;
}

VOID FPSWait(VOID)
{
	int wait = 0;

	wait =
		MicroSecond / W_FPS * fps.FrameCount
		- (fps.NowTakeTime - fps.FirstTakeTime);

	wait /= MillSecond;

	if (wait > 0 && wait <= WaitTimeMill)
	{
		WaitTimer(wait);
	}

	return;
}

// End
