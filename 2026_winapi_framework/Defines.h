#pragma once

#define DECLARE_SINGLETON(className)                 \
private:                                             \
    className() = default;                           \
public:                                              \
    className(const className&) = delete;            \
    className& operator=(const className&) = delete; \
    static className* GetInst()                      \
    {                                                \
        static className inst;                       \
        return &inst;                                \
    }

#define GET_SINGLE(className) className::GetInst()

#define SAFE_DELETE(ptr)     \
    if (ptr)                 \
    {                        \
        delete ptr;          \
        ptr = nullptr;       \
    }
#define fDT Time::GetDT();
#define GET_KEY(key) Input::GetKey(key)
#define GET_KEYDOWN(key) Input::GetKeyDown(key)
#define GET_KEYUP(key) Input::GetKeyUp(key)
#define GET_MOUSEPOS Input::GetMousePos()

constexpr int WINDOW_WIDTH = 1280; 
constexpr int WINDOW_HEIGHT = 720; 
inline const wchar_t* GAME_TITLE = L"2-2 GAME"; //매우 중요