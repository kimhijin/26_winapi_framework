#pragma once

// 표준 헤더
#define NOMINMAX

#include "framework.h"
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <type_traits>
#include <format>
#include <numbers>
#include <crtdbg.h>
#include <memory>
#ifdef  _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif //  _DEBUG


// 각종 using
using std::vector;
using std::list;
using std::map;
using std::wstring;

// 99. Headers(My Headers)
#include "Defines.h"
#include "Vec2.h"
#include "Utils.h"
#include "Time.h"
#include "Input.h"
#include "Enums.h"


#pragma comment(lib, "winmm.lib")