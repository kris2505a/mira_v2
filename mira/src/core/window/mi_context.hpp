#pragma once
#include "core/mi_core.hpp"
#include "core/types/mi_error.hpp"
#include "core/types/mi_types.hpp"

#include <vector>

NS_CORE

class Context {
public:
    MI_CORE_API static Expected<void, Error> init();
    MI_CORE_API static void shut_down();
    MI_CORE_API static Expected<std::vector<std::string>, Error> retrieve_extensions();
    MI_CORE_API static void poll_events();

private:
    static std::string s_last_error;
};

NS_CORE_END