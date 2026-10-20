#include <core/log/mi_log.hpp> 
#include  <core/window/mi_context.hpp>
#include  <core/window/mi_window.hpp>


int main() {
    if (auto res = mi::core::Context::init(); !res) {
        const auto& e = res.error();
        MI_LOG_FATAL("Error: {} | File: {} | Line: {}", e.get_message(), e.get_file(), e.get_line());
        return -1;
    }
    MI_LOG_DEBUG("Init Successful");


    mi::core::WindowCreateInfo create_info {
        .width = 1280,
        .height = 720,
        .title = "Mira",
        .resizable = false
    };

    auto window_result = mi::core::Window::create_new(create_info);
    if (!window_result) {
        const auto& e = window_result.error();
        MI_LOG_FATAL("Error: {} | File: {} | Line: {}", e.get_message(), e.get_file(), e.get_line());
        mi::core::Context::shut_down();
        return -1;
    }
    //*window_result means window_result.value(). just writing fancy btw. 
    auto window = std::move(*window_result);


    while (window->is_open()) {
        mi::core::Context::poll_events();
    }

    mi::core::Context::shut_down();
}
