cmake_minimum_required(VERSION 3.29.6)
project(RoseEngineC)

set(CMAKE_CXX_STANDARD 20)

# ImGui
set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/include/imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends)

# Sources
set(SOURCE_FILES
        main.cpp
        glad.c
        Shader.h
        Camera.h
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(RoseEngineC ${SOURCE_FILES})

# =========================
# PLATFORM-SPECIFIC LINKING
# =========================

if (WIN32)
    message(STATUS "Building for Windows")

    link_directories(${PROJECT_SOURCE_DIR}/include/lib-mingw-w64)

    target_link_libraries(RoseEngineC
            glfw3
            gdi32
            opengl32
            kernel32
            user32
    )

elseif(UNIX)
    message(STATUS "Building for Linux")

    find_package(OpenGL REQUIRED)

    target_link_libraries(RoseEngineC
            glfw
            OpenGL::GL
            X11
            pthread
            dl
    )
endif()
