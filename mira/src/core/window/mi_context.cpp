#include "mi_context.hpp"
#include "core/log/mi_log.hpp"

#include <GLFW/glfw3.h>

NS_CORE

std::string Context::s_last_error = "None";

Expected<void, Error> Context::init() {
    glfwSetErrorCallback([](int error, const char* description) {
        s_last_error = std::string(description);
    });

    if (glfwInit()) {
        return {};
    }

    return Unexpected {
        Error {
            ErrorType::FailedToInitGLFW,
            s_last_error
        }
    };
}

void Context::shut_down() {
    glfwTerminate();
}

Expected<std::vector<std::string>, Error> Context::retrieve_extensions() {
    u32 count;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&count);

    if (0 == count) {
        return Unexpected {
            Error {
                ErrorType::ExtensionsNotFound,
                "No extensions found for platform"
            }
        };
    }

    if (!glfwExtensions) {
        return Unexpected {
            Error {
                ErrorType::FailedToRetrieveExtensions,
                "Failed to retrieve extensions from glfw"
            }
        };
    }

    std::vector<std::string> extensions;
    for (u32 i = 0; i < count; i++) {
        extensions.emplace_back(glfwExtensions[i]);
    }
    return extensions;
}

void Context::poll_events() {
    glfwPollEvents();
}

NS_CORE_END
