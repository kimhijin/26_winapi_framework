#pragma once
template<typename T>
concept Number = std::is_arithmetic_v<T>;
struct Vector2
{
	Vector2() = default;
	template<Number X, Number Y>
	Vector2(X x, Y y)
		:x((float)x)
		,y((float)y)
	{ }
    Vector2 operator +(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
    Vector2 operator -(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
    Vector2 operator *(const Vector2& other) const { return Vector2(x * other.x, y * other.y); }
    Vector2 operator /(const Vector2& other) const { return Vector2(x / other.x, y / other.y); }
    Vector2 operator *(float val) const { return Vector2(x * val, y * val); }
    Vector2 operator /(float val) const { return Vector2(x / val, y / val); }
    // ³ª´°¼À Ãß°¡

    Vector2 operator-() const { return Vector2(-x, -y); }

    Vector2 operator +=(const Vector2& other) { x += other.x; y += other.y; return *this; }
    Vector2 operator -=(const Vector2& other) { x -= other.x; y -= other.y; return *this; }
    Vector2 operator *=(const Vector2& other) { x *= other.x; y *= other.y; return *this; }
    Vector2& operator*=(float val) { x *= val; y *= val; return *this; }
    // ³ª´°¼À Ãß°¡
    FLT_EPSILON;
    float LengthSquared() const { return x * x + y * y; }     // ±æÀÌÀÇ Á¦°ö 
    float Length() const { return std::sqrt(LengthSquared()); }
    Vector2 Normalized() const
    {
        float len = Length();
        return (len > 0.f) ? *this / len : Vec2{};
    }
    float Angle() const { return std::atan2(y, x); }
	float x = 0.f;
	float y = 0.f;
};
using Vec2 = Vector2;