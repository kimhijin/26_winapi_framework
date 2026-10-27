#pragma once
class Time
{
public:
	static void Init();
	static void Update();
public:
	static float GetDT() { return m_dT; }
	static UINT GetFPS() { return m_fps; }
private :
	static void UpdateTitle();
private :
	//deltaTime
	inline static float m_dT = 0.f;
	inline static LARGE_INTEGER m_prevCount = {};
	inline static LARGE_INTEGER m_curCount = {};
	inline static LARGE_INTEGER m_frequency= {};
	inline static const float m_maxdT = 0.1f;

	//FPS
	inline static UINT m_fps = 0;
	inline static UINT m_frameCount = 0;
	inline static float m_fpsTimer = 0.f;
};

