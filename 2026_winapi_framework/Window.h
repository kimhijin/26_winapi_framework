#pragma once
class Window
{
public:
	Window();
	~Window();

public:
	int Run(HINSTANCE hInstance, int nCmdShow);

private:
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	ATOM MyRegisterClass();
	void Create();
	void Show(int nCmdShow);
	int MessageLoop();
public:
	static int ConsumeWheel()
	{
		int deltat = m_wheelDelta;
		m_wheelDelta = 0;
		return deltat;
	}
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	inline static const wchar_t* CLASS_NAME = L"http ³ë»ó";
	inline static int m_wheelDelta = 0;
};

