#pragma once

#ifdef TIE_PLATFORM_WINDOWS
#ifdef TIE_BUILD_DLL
#define TIE_API __declspec(dllexport)
#else
#define TIE_API __declspec(dllimport)
#endif
#else
#error Only windows now
#endif