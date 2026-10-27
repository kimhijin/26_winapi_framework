#include "pch.h"
#include "Time.h"
#include "Core.h"
void Time::Init()
{
	//time();
	//GetTickCount64();
	//counter : 지금이 눈금이 몇이야?
	::QueryPerformanceCounter(&m_prevCount);
	//frequency : 1초에 눈금이 몇개가 올라가?
	// 10000000이라는 틱을 셀 수 있는 시계가 나타난다.
	::QueryPerformanceFrequency(&m_frequency);
}

void Time::Update()
{
	::QueryPerformanceCounter(&m_curCount);
	m_dT = (float)(m_curCount.QuadPart - m_prevCount.QuadPart)
		/(float)m_frequency.QuadPart;
	m_prevCount = m_curCount;
	if (m_dT > m_maxdT)
		m_dT = m_maxdT;

	//fps
	++m_frameCount;
	m_fpsTimer += m_dT;
	if (m_fpsTimer >= 1.f)
	{
		m_fps = (UINT)(m_frameCount / m_fpsTimer);
		m_fpsTimer = 0.f;
		m_frameCount = 0;
		UpdateTitle();
	}

}

void Time::UpdateTitle()
{
	//wstring strDT = std::to_wstring(m_dT);
	//wstring strFPS = std::to_wstring(m_fps);
	//wstring strTitle = L"FPS: " + strFPS +
	//	L" DT: " + strDT;
	wstring strTitle = 
		std::format(L"FPS: {0}, DT: {1:.6f} Mouse: {2}, {3}"
			, m_fps, m_dT, GET_MOUSEPOS.x, GET_MOUSEPOS.y);
	::SetWindowText(GET_SINGLE(Core)->GetHwnd(),
		strTitle.c_str());
}
