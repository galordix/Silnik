#include "OknoWindows.h"
BOOL OknoWindows::ChangeResolution(LONG width, LONG height)
{
	DEVMODE dmScreenSettings;   //struktura trybu wyœwietlania
	memset(&dmScreenSettings, 0, sizeof(dmScreenSettings)); //czyszczenie pamiêci
	dmScreenSettings.dmSize = sizeof(dmScreenSettings);     //rozmiar struktury
	dmScreenSettings.dmPelsWidth = width;        //nowa szerokoœæ ekranu
	dmScreenSettings.dmPelsHeight = height;        //nowa wysokoœæ ekranu   
	dmScreenSettings.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
	return ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) == DISP_CHANGE_SUCCESSFUL;
}
