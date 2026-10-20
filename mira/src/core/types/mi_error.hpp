#pragma once
#include "core/mi_core.hpp"
#include "mi_types.hpp"
#include <string>
#include <iostream>

#include <source_location>

NS_CORE

enum class ErrorType {
    None = 0,
    FailedToInitGLFW,
    ExtensionsNotFound,
    FailedToRetrieveExtensions,
    FailedToCreateGLFWWindow
};

class MI_CORE_API Error {
    friend std::ostream& operator<< (std::ostream& ostr, const Error& err);

public:
    Error(ErrorType type, std::string_view error, const std::source_location& location = std::source_location::current());
    ~Error() = default;

    [[nodiscard]] ErrorType get_type() const;
    [[nodiscard]] std::string_view get_message() const;
    [[nodiscard]] std::string_view get_file() const;
    [[nodiscard]] u32 get_line() const;

private:
    ErrorType m_type;
    std::string m_error;
    u32 m_line;
    std::string m_file;
};

NS_CORE_END