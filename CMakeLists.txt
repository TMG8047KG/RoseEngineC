cmake_minimum_required(VERSION 3.29.6)
project(RoseEngineC)

set(CMAKE_CXX_STANDARD 20)

# Specify the ImGui directory
set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/include/imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends)

# Add source files, including ImGui
set(SOURCE_FILES
        main.cpp
        glad.c
        Shader.h
        Camera.h
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
)

# Include other necessary directories
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/include/lib-mingw-w64)
link_directories(${PROJECT_SOURCE_DIR}/include/glad)

# Define the executable
add_executable(RoseEngineC ${SOURCE_FILES})

target_sources(RoseEngineC PRIVATE
        ${CMAKE_SOURCE_DIR}/include/imgui/imgui.cpp
        ${CMAKE_SOURCE_DIR}/include/imgui/imgui_draw.cpp
        ${CMAKE_SOURCE_DIR}/include/imgui/imgui_widgets.cpp
        ${CMAKE_SOURCE_DIR}/include/imgui/imgui_tables.cpp
        ${CMAKE_SOURCE_DIR}/include/imgui/imgui_demo.cpp  # Add this line
        ${CMAKE_SOURCE_DIR}/include/imgui/backends/imgui_impl_opengl3.cpp
        ${CMAKE_SOURCE_DIR}/include/imgui/backends/imgui_impl_glfw.cpp
)

# Link libraries, including GLFW, OpenGL, and GDI
target_link_libraries(RoseEngineC glfw3 gdi32 opengl32 kernel32 user32)
