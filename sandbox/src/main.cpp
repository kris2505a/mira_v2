#include <core/log/mi_log.hpp> 

int main() {
    MI_LOG_INFO("yay: {}", 0);
    MI_LOG_DEBUG("yay: {}", 1);
    MI_LOG_WARN("yay: {}", 2);
    MI_LOG_ERROR("yay: {}", 3);
    MI_LOG_FATAL("yay: {}", 4);
}
