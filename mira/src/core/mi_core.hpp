#pragma once

#ifdef CORE_BUILD_DLL
    #define MI_CORE_API __declspec(dllexport)
#else
    #define MI_CORE_API __declspec(dllimport)
#endif


#define NS_CORE namespace mi::core {


#define NS_CORE_END }