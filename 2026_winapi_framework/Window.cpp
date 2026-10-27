#include "pch.h"
#include "Window.h"
#include "Resource.h"
#include "Core.h"
#include "Time.h"

Window::Window() 
    : m_hInst(nullptr)
    , m_hWnd(nullptr)
{
	
}

Window::~Window()
{
}

int Window::Run(HINSTANCE hInstance, int nCmdShow)
{
    m_hInst = hInstance;
    MyRegisterClass();
    Create();
    Show(nCmdShow);
    if (!GET_SINGLE(Core)->Init(m_hWnd))
    {
        MessageBox(m_hWnd, L"초기화 실패", L"ERROR", MB_OK);
    }
    return MessageLoop();
}

ATOM Window::MyRegisterClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc; //객체가 없기에 클래스에 종속해서 쓸 수 있게
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_MY2026WINAPIFRAMEWORK));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = CLASS_NAME; //todo
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return ::RegisterClassExW(&wcex);
}

LRESULT Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_MOUSEHWHEEL:
        m_wheelDelta += GET_WHEEL_DELTA_WPARAM(wParam);
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        break;
    default:
        return ::DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void Window::Create()
{
	//AdjustWindowRect();
    RECT windowRt = { 0,0,WINDOW_WIDTH, WINDOW_HEIGHT };

    //todo
    DWORD style = WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_THICKFRAME;
    ::AdjustWindowRect(&windowRt, WS_OVERLAPPEDWINDOW, false);
    int winW = windowRt.right - windowRt.left;
    int winH = windowRt.bottom - windowRt.top;
    // 정중앙 띄우는거 까지
    int posX = (::GetSystemMetrics(SM_CXSCREEN) - winW)/2;
    int posY = (::GetSystemMetrics(SM_CXSCREEN) - winH)/2;
    m_hWnd = ::CreateWindowW(CLASS_NAME, GAME_TITLE, WS_OVERLAPPEDWINDOW,
        posX, posY, winW, winH
        , nullptr, nullptr, m_hInst, nullptr);
}

void Window::Show(int nCmdShow)
{
    ::ShowWindow(m_hWnd, nCmdShow);
}


int Window::MessageLoop()
{
    MSG msg = {};

    while (true)
    {
        if (WM_QUIT == msg.message)
            break;

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }
        else {
            GET_SINGLE(Core)->GameLoop();
        }
    }

    GET_SINGLE(Core)->CleanUp();
    return (int)msg.wParam;
}
