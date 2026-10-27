#pragma once
namespace Utils
{
	inline RECT MakeRect(Vector2 pos, Vector2 size)
	{
		return RECT{ (LONG)(pos.x - size.x / 2),
		(LONG)(pos.y - size.y / 2),
		(LONG)(pos.x + size.x / 2),
		(LONG)(pos.y + size.y / 2) };
	}

	inline void DrawRect(HDC hdc, Vector2 pos, Vector2 size)
	{
		RECT rt = MakeRect(pos, size);
		::Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
	}

	inline void DrawElipse(HDC hdc, Vector2 pos, Vector2 size)
	{
		RECT rt = MakeRect(pos, size);
		::Ellipse(hdc, rt.left, rt.top, rt.right, rt.bottom);
	}
	inline void DrawLine(HDC hdc, Vector2 from, Vector2 to)
	{
		::MoveToEx(hdc, (int)from.x, (int)from.y, nullptr);
		::LineTo(hdc, (int)to.x, (int)to.y);
	}
	inline void DrawTextColor(HDC hdc, Vector2 pos,
		const wstring& text, COLORREF color = RGB(0, 0, 0))
	{
		COLORREF oldtextColor = ::SetTextColor(hdc, color);
		::SetBkMode(hdc, TRANSPARENT);
		::TextOut(hdc, (int)pos.x, (int)pos.y, text.c_str(), text.length());
		::SetTextColor(hdc, oldtextColor);
	}

	inline void DrawTextBox(HDC hdc, Vector2 pos, Vector2 size,
		const wstring& text, COLORREF color = RGB(0, 0, 0)
		, UINT format = DT_CENTER | DT_VCENTER | DT_SINGLELINE)
	{
		RECT rt = MakeRect(pos, size);;
		COLORREF oldTextCoor = ::SetTextColor(hdc, color);
		::SetBkMode(hdc, TRANSPARENT);
		::DrawText(hdc, text.c_str(), text.length(), &rt, format);
		::SetTextColor(hdc, oldTextCoor);
	}
}