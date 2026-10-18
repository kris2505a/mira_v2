cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME core)

project(${PROJECT_NAME} LANGUAGES C CXX)

# =========================
# Source Files
# =========================

file(GLOB_RECURSE PROJECT_SOURCES
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# =========================
# Library
# =========================

add_library(${PROJECT_NAME} SHARED
    ${PROJECT_SOURCES}
)

# =========================
# Include Directories
# =========================

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/mira/src

    PRIVATE
        ${CMAKE_SOURCE_DIR}/mira/thirdparty/glfw/include
)

target_compile_features(${PROJECT_NAME}
    PUBLIC
        cxx_std_23
)

# =========================
# Compile Definitions
# =========================

target_compile_definitions(${PROJECT_NAME} PRIVATE
    CORE_BUILD_DLL
)

target_compile_definitions(core PRIVATE PRJ_NAME="core")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        MI_DEBUG
    )
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        MI_RELEASE
    )
endif()

# =========================
# Link Libraries
# =========================

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
)
