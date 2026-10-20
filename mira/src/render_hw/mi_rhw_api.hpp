#pragma once

#ifdef RHW_BUILD_DLL
    #define MI_RHW_API __declspec(dllexport)
#else
    #define MI_RHW_API __declspec(dllimport)
#endif

#define NS_RHW namespace mi::rhw {

#define NS_RHW_END }