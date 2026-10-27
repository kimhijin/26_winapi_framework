#include "pch.h"
#include "Core.h"

bool Core::Init(HWND hWnd)
{
	m_hWnd = hWnd;
	m_hDC = ::GetDC(m_hWnd);
	CreateBackBuffer();
	m_gameScene.Init();
	Time::Init();
	return true;
}

void Core::GameLoop()
{

	MainUpdate();
	MainRender();
}

void Core::CleanUp()
{
	ReleaseBackBuffer();
	::ReleaseDC(m_hWnd, m_hDC);
}


void Core::MainUpdate()
{
	Time::Update();
	Input::Update();
	m_gameScene.Update();



}

void Core::MainRender()
{
	//::Rectangle(m_hBackDC, -1, -1, WINDOW_WIDTH+1, WINDOW_HEIGHT+1);
	::PatBlt(m_hBackDC, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, WHITENESS);
	m_gameScene.Render(m_hBackDC);

	//Vector2 pos = m_obj.GetPos();
	//Vector2 size = m_obj.GetSize();

	//Utils::DrawRect(m_hBackDC, pos, size);

	::BitBlt(m_hDC, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, m_hBackDC, 0, 0, SRCCOPY);
	//::TransparentBlt();//색빼낼때
	//::StretchBlt();//확대 축소
	//::AlphaBlend();
	////::MaskBlt();
	//::PatBlt();//색깔 채울째
	//::PlgBlt();//회전할때
}

void Core::CreateBackBuffer()
{
	m_hBackBit =::CreateCompatibleBitmap(m_hDC, WINDOW_WIDTH, WINDOW_HEIGHT);
	m_hBackDC =::CreateCompatibleDC(m_hDC);

	::SelectObject(m_hBackDC, m_hBackBit);
}
void Core::ReleaseBackBuffer()
{
	::DeleteDC(m_hBackDC);
	::DeleteObject(m_hBackBit);
}
