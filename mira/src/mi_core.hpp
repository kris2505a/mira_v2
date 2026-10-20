#pragma once

#ifdef MIRA_BUILD_DLL
    #define MIRA_API __declspec(dllexport)
#else
    #define MIRA_API __declspec(dllimport)
#endif


#define NS(x) namespace mi::x {


#define NS_END }