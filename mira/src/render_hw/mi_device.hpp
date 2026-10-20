#pragma once
#include "mi_core.hpp"
#include "core/types/mi_win_types.hpp"
#include "core/types/mi_error.hpp"

#include <dxgi1_6.h>
#include <d3d12.h>


NS(rhw) 

class MIRA_API Device {
public:
    Device() = default;
    ~Device() = default;
    static std::expected<std::unique_ptr<Device>, core::Error> create_new();

private:
    core::ComScope<IDXGIFactory7> factory_;
    core::ComScope<ID3D12Device> device_;
    core::ComScope<ID3D12Debug> debug_controller_;
};

NS_END
