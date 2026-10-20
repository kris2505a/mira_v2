#pragma once
#include "core/mi_core.hpp"
#include <string>
#include <format>

NS_CORE


enum class LogType {
	Info,
	Debug,
	Warn,
	Error,
	Fatal
};


#define MI_LOG_INFO(msg, ...) mi::core::Log::log_message(PRJ_NAME, mi::core::LogType::Info, msg, __VA_ARGS__)
#define MI_LOG_DEBUG(msg, ...) mi::core::Log::log_message(PRJ_NAME, mi::core::LogType::Debug, msg, __VA_ARGS__)
#define MI_LOG_WARN(msg, ...) mi::core::Log::log_message(PRJ_NAME, mi::core::LogType::Warn, msg, __VA_ARGS__)
#define MI_LOG_ERROR(msg, ...) mi::core::Log::log_message(PRJ_NAME, mi::core::LogType::Error, msg, __VA_ARGS__)
#define MI_LOG_FATAL(msg, ...) mi::core::Log::log_message(PRJ_NAME, mi::core::LogType::Fatal, msg, __VA_ARGS__)

class MI_CORE_API Log {

public:
	template <typename... Args>
	inline static void log_message(std::string_view project_name, LogType type, std::string_view msg, Args&&... args) {
		const auto formatted_message = std::vformat(msg, std::make_format_args(args...));
		log_to_console(type_to_string(type), project_name, formatted_message);
	}

private:
	static std::string type_to_string(LogType type);
	static void log_to_console(std::string_view log_type, std::string_view project_name, std::string_view formatted_message);

};

NS_CORE_END
