#include "OknoWindows.h"
BOOL OknoWindows::ChangeResolution(LONG width, LONG height)
{
	DEVMODE dmScreenSettings;   //struktura trybu wy�wietlania
	memset(&dmScreenSettings, 0, sizeof(dmScreenSettings)); //czyszczenie pami�ci
	dmScreenSettings.dmSize = sizeof(dmScreenSettings);     //rozmiar struktury
	dmScreenSettings.dmPelsWidth = width;        //nowa szeroko�� ekranu
	dmScreenSettings.dmPelsHeight = height;        //nowa wysoko�� ekranu   
	dmScreenSettings.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
	return ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) == DISP_CHANGE_SUCCESSFUL;
}
