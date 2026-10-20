#pragma once
#include "mi_core.hpp"
#include "core/types/mi_error.hpp"
#include "core/types/mi_types.hpp"

#include <vector>

NS(core)

class Context {
public:
    MIRA_API static std::expected<void, Error> init();
    MIRA_API static void shut_down();
    MIRA_API static std::expected<std::vector<std::string>, Error> retrieve_extensions();
    MIRA_API static void poll_events();
    MIRA_API static std::string_view get_last_error();

private:
    static std::string s_last_error;
};

NS_END