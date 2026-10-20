#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <wrl/client.h>
#include "core/mi_core.hpp"


NS_CORE

template <typename T>
using ComScope = Microsoft::WRL::ComPtr<T>;

NS_CORE_END