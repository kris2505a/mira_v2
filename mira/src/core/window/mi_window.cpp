#include "mi_window.hpp"
#include <GLFW/glfw3.h>
#include "mi_context.hpp"
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

NS(core)

Window::Window(const WindowCreateInfo& create_info)
    : m_handle(nullptr), m_info(create_info) {

    glfwWindowHint(GLFW_RESIZABLE,  m_info.resizable ? GLFW_TRUE : GLFW_FALSE);
    m_handle = glfwCreateWindow(
        static_cast<int>(m_info.width),
        static_cast<int>(m_info.height),
        m_info.title.c_str(),
        nullptr,
        nullptr
    );


}

std::expected<Scope<Window>, Error> Window::create_new(const WindowCreateInfo& create_info) {
    
    auto window = create_scope<Window>(create_info);
    if (!window->m_handle) {
        return std::unexpected {
            Error {
                ErrorType::FailedToCreateGLFWWindow,
                Context::get_last_error()
            }
        };
    }

    return std::move(window);
}

bool Window::is_open() const {
    return !glfwWindowShouldClose(m_handle);
}

HWND Window::get_native_handle() const {
    return glfwGetWin32Window(m_handle);
}

Window::~Window() {
    if (m_handle)
        glfwDestroyWindow(m_handle);
}



NS_END
