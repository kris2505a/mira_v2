#include "mi_log.hpp"
#include <iostream>


NS_CORE

std::string Log::type_to_string(LogType type) {
    switch (type) {
    case LogType::Info:
        return "info ";

    case LogType::Debug:
        return "debug";

    case LogType::Warn:
        return "warn ";

    case LogType::Error:
        return "error";

    case LogType::Fatal:
        return "fatal";
    }

    return "unknown level";
}
void Log::log_to_console(std::string_view log_type, std::string_view project_name, std::string_view formatted_message) {
    std::cout << "$(" << log_type << ") : [" << project_name << "]" << " -> " << formatted_message << "\n";
}

NS_CORE_END