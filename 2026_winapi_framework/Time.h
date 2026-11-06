#pragma once
class Time
{
public:
	static void Init();
	static void Update();
private :
	static void UpdateTitle();
public:
	static float GetDT() { return m_dT; }
	static float GetUnscaledDT() { return m_unscaledDT; }
	static void  SetScale(float scale) { m_scale = std::max(scale, 0.f); }
	static float GetScale() { return m_scale; }
	static void  HitStop(float seconds)
	{
		m_hitStopRemain = std::max(m_hitStopRemain, seconds);
	}
	// ¾ÀÀÌ ¹Ù²ð ¶§
	static void  Reset()
	{
		m_scale = 1.f;
		m_hitStopRemain = 0.f;
	}
	static UINT GetFPS() { return m_fps; }
private :
	//deltaTime
	inline static float m_dT = 0.f;
	inline static LARGE_INTEGER m_prevCount = {};
	inline static LARGE_INTEGER m_curCount = {};
	inline static LARGE_INTEGER m_frequency= {};
	inline static const float m_maxdT = 0.1f;
	inline static float            m_unscaledDT = 0.f;
	inline static float            m_scale = 1.f;
	inline static float            m_hitStopRemain = 0.f;

	//FPS
	inline static UINT m_fps = 0;
	inline static UINT m_frameCount = 0;
	inline static float m_fpsTimer = 0.f;
};

