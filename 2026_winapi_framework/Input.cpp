#include "pch.h"
#include "Input.h"
#include "Core.h"
#include "Window.h"

void Input::Update()
{

	HWND hWnd = GET_SINGLE(Core)->GetHwnd();
	bool focused = (::GetFocus() == hWnd);

	for (int vk = 1; vk < KEY_COUNT; vk++)
	{					// 0000 8000 8001 0001
		bool pressNow = focused&&(::GetAsyncKeyState(vk) & 0X8000) != 0;
		KeyState& state = m_keys[vk];
		bool pressPrev = (state == KeyState::DOWN 
			|| state == KeyState::PRESS);
		if (pressNow)
			state = pressPrev ? KeyState::PRESS : KeyState::DOWN;
		else
			state = pressPrev ? KeyState::UP : KeyState::NONE;
	}

	POINT pt = {};
	::GetCursorPos(&pt);
	::ScreenToClient(hWnd, &pt);
	m_mousepos = Vector2(pt.x, pt.y);

	//ÈÙ
	m_wheel = Window::ConsumeWheel() / WHEEL_DELTA;
}