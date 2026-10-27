#include "pch.h"
#include "Object.h"
#include "Scene.h"

Object::Object()
	:m_pos{}
	, m_size{}
{
}

Object::~Object()
{
}

void Object::Render(HDC hdc)
{
	Utils::DrawRect(hdc, m_pos, m_size);
}


