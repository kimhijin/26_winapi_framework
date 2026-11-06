#pragma once
template<typename T>
concept Number = std::is_arithmetic_v<T>;
constexpr float PI = std::numbers::pi_v<float>;
constexpr float DegToRad(float deg) { return deg * (PI / 180.f); }
constexpr float RadToDeg(float rad) { return rad * (180.f / PI); }
struct Vec2
{
    Vec2() = default;
    template<Number X, Number Y>
    Vec2(X x, Y y)
        : x((float)x)
        , y((float)y)
    {
    }
    Vec2 operator +(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }
    Vec2 operator -(const Vec2& other) const { return Vec2(x - other.x, y - other.y); }
    //Vec2 operator *(const Vec2& other) const { return Vec2(x * other.x, y * other.y); }
    Vec2 operator*(const Vec2&) const = delete;
    Vec2 operator/(const Vec2&) const = delete;
    Vec2 operator *(float val) const { return Vec2(x * val, y * val); }
    // ³ª´°¼À Ãß°¡
    Vec2 operator/(float val) const
    {
        return (std::fabs(val) > FLT_EPSILON) ? Vec2(x / val, y / val) : Vec2{};
    }
    Vec2 operator-() const { return Vec2(-x, -y); }

    Vec2& operator +=(const Vec2& other) { x += other.x; y += other.y; return *this; }
    Vec2& operator -=(const Vec2& other) { x -= other.x; y -= other.y; return *this; }
    Vec2& operator *=(const Vec2& other) { x *= other.x; y *= other.y; return *this; }
    Vec2& operator*=(float val) { x *= val; y *= val; return *this; }
    // ³ª´°¼À Ãß°¡
    Vec2& operator/=(float val)
    {
        *this = *this / val;
        return *this;
    }
    float LengthSquared() const { return x * x + y * y; }
    float Length() const { return std::sqrt(LengthSquared()); }
    Vec2 Normalized() const
    {
        float len = Length();
        return (len > FLT_EPSILON) ? Vec2(x / len, y / len) : Vec2{};
    }
    float Angle() const { return std::atan2(y, x); }
    static Vec2 FromAngle(float rad) { return Vec2{ std::cos(rad), std::sin(rad) }; }
    static float Distance(const Vec2& a, const Vec2& b) { return (a - b).Length(); }
    float Dot(const Vec2& other) const { return x * other.x + y * other.y; }
    float Cross(const Vec2& other) const { return x * other.y - y * other.x; }
    float x = 0.f;
    float y = 0.f;
};
using Vector2 = Vec2;