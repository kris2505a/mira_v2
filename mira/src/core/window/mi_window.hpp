#pragma once
#include "core/mi_core.hpp"
#include "core/types/mi_types.hpp"
#include "core/types/mi_error.hpp"

#include <string>
#include <Windows.h>

struct GLFWwindow;

NS_CORE

struct WindowCreateInfo {
    u32 width;
    u32 height;
    std::string title;
    bool resizable;
};


class MI_CORE_API Window {
public:
    Window(const WindowCreateInfo& create_info);
    ~Window();
    static Expected<Scope<Window>, Error> create_new(const WindowCreateInfo& create_info);
    bool is_open() const;
    HWND get_native_handle() const;

private:
    GLFWwindow* m_handle;
    WindowCreateInfo m_info;
};

NS_CORE_END