#pragma once
class Object
{
public:
	Object();
	virtual ~Object(); // °¡»ó ¼Ò¸êÀÚ
public:
	virtual void Update() {};
	virtual void Render(HDC hdc) {};
public:
	Vector2 GetPos() const { return m_pos; }
	void SetPos(Vector2 pos) { m_pos = pos; }

	Vector2 GetSize() const { return m_size; }
	void SetSize(Vector2 size) { m_size = size; }
public:
	void Translate(Vector2 delta)
	{
		m_pos += delta;
	}
	void Scale(float factor)
	{
		m_size *= factor;
	}
	bool IsActive() const { return m_active; }
	void SetActive(bool active) { m_active = active; }
public:
	bool m_active;
	Vector2 m_pos;
	Vector2 m_size;
};

