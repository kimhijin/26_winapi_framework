#include "pch.h"
#include "Window.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

    Window game;
	game.Run(hInstance, nCmdShow);
}



BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    //if (!hWnd)
    //{
    //    return FALSE;
    //}


    return TRUE;
}

