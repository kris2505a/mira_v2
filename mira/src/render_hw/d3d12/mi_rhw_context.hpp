#pragma once
#include "render_hw/mi_rhw_api.hpp"
#include "core/types/mi_win_types.hpp"

#include <dxgi1_6.h>

NS_RHW

class MI_RHW_API Context {
public:

private:
    core::ComScope<IDXGIFactory7> m_native_factory;
};

NS_RHW_END