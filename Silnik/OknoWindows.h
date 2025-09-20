#pragma once
#include <Windows.h>
class OknoWindows
{
	BOOL ChangeResolution(LONG width, LONG height);

protected:
	HWND hWindow;
	BOOL Initialize(HINSTANCE uchwytAplikacji, POINT polozenieOkna, POINT rozmiarOkna,
		bool fullscreen = false, bool resolutionChange = true);
};

