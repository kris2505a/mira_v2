#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <wrl/client.h>
#include "mi_core.hpp"


NS(core)

template <typename T>
using ComScope = Microsoft::WRL::ComPtr<T>;

NS_END