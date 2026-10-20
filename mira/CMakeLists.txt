
cmake_minimum_required(VERSION 3.25)

project(mira
    VERSION 0.1.0
    LANGUAGES CXX
)


# ==========================================
# C++ Configuration
# ==========================================

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ==========================================
# Dependencies
# ==========================================

add_subdirectory(thirdparty/glfw)

# ==========================================
# Mira Engine DLL
# ==========================================

file(GLOB_RECURSE MIRA_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

add_library(mira SHARED
    ${MIRA_SOURCES}
)

target_include_directories(mira
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_compile_definitions(mira
    PRIVATE
        MIRA_BUILD_DLL
)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(mira PRIVATE
        MI_DEBUG
    )
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(mira PRIVATE
        MI_RELEASE
    )
endif()


target_compile_definitions(mira PRIVATE PRJ_NAME="mira")


target_link_libraries(mira
    PRIVATE
        glfw
        d3d12
        dxgi
        dxguid
)

# ==========================================
# Output Directories
# ==========================================

set_target_properties(mira PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>"
)
