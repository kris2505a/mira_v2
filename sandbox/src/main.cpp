#include <core/log/mi_log.hpp> 
#include  <core/window/mi_context.hpp>


int main() {
    if (auto res = mi::core::Context::init(); !res) {
        const auto& e = res.error();
        MI_LOG_FATAL("Error: {} | File: {} | Line: {}", e.get_message(), e.get_file(), e.get_line());
        return -1;
    }

    MI_LOG_DEBUG("Init Successful");

    mi::core::Context::shut_down();

}
