#include "mi_device.hpp"

NS(rhw)

std::expected<std::unique_ptr<Device>, core::Error> Device::create_new() {

    std::unique_ptr<Device> device = std::make_unique<Device>();
    HRESULT hr;
#ifdef MI_DEBUG
    D3D12GetDebugInterface(IID_PPV_ARGS(&device->debug_controller_));
    if (FAILED(hr)) {
        return std::unexpected {
            core::Error {
                core::Error::get_error_from_hresult(hr)
            }
        };
    }
#endif
    
}

NS_END
