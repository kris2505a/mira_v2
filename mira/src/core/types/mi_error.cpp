#include "mi_error.hpp"


NS_CORE

std::ostream& operator<<(std::ostream& ostr, const Error& err) {
    ostr << err.get_message()
         << "\t in file: " << err.get_file()
         << "\t in line: " << err.get_line();

    return ostr;
}


Error::Error(ErrorType type, std::string_view error, const std::source_location& location)
    : m_type(type), m_error(error), m_line(location.line()), m_file(location.file_name()) {

}

ErrorType Error::get_type() const {
    return m_type;
}

std::string_view Error::get_message() const {
    return m_error;
}

std::string_view Error::get_file() const {
    return m_file;
}

u32 Error::get_line() const {
    return m_line;
}

NS_CORE_END
