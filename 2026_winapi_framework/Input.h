#pragma once
enum class Key : BYTE
{
    LBUTTON = VK_LBUTTON, RBUTTON = VK_RBUTTON, MBUTTON = VK_MBUTTON,
    LEFT = VK_LEFT, RIGHT = VK_RIGHT, UP = VK_UP, DOWN = VK_DOWN,
    SPACE = VK_SPACE, ENTER = VK_RETURN, ESC = VK_ESCAPE, TAB = VK_TAB,
    LSHIFT = VK_LSHIFT, LCTRL = VK_LCONTROL, LALT = VK_LMENU,
    A = 'A', B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    NUM0 = '0', NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,
    F1 = VK_F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
};
enum class KeyState
{
    NONE, DOWN, PRESS,UP
};
class Input
{
public:
    static void Update();
    static KeyState GetState(Key key)
    {
        return m_keys[(UINT)key];
    }
    static bool GetKeyDown(Key key)
    {
        return GetState(key) == KeyState::DOWN;
    }
    static bool GetKey(Key key)
    {
        return GetState(key) == KeyState::DOWN ||
            GetState(key) == KeyState::PRESS;
    }
    static bool GetKeyUp(Key key)
    {
        return GetState(key) == KeyState::UP;
    }
    static Vector2 GetMousePos() { return m_mousepos; }
    inline static int GetWheel() { return m_wheel; }
private:
    static constexpr UINT   KEY_COUNT = 256;
    inline static KeyState  m_keys[KEY_COUNT] = {};
    inline static Vector2   m_mousepos = {};
    inline static int       m_wheel = 0;
};

