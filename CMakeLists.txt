cmake_minimum_required(VERSION 3.8)
project(RoseEngineC)

set(CMAKE_CXX_STANDARD 20)

# Specify the ImGui directory
set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/include/imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends)

# Add source files, including ImGui
file(GLOB_RECURSE SRC "src/*.cpp" "src/*.c")

file(GLOB_RECURSE LIB "lib/lib-mingw-w64/*.a")

# Include other necessary directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Define the executable
add_executable(RoseEngineC ${SRC})

# Link libraries, including GLFW, OpenGL, and GDI
target_link_libraries(RoseEngineC ${LIB} gdi32 opengl32 kernel32 user32)
