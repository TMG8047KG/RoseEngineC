cmake_minimum_required(VERSION 3.29.6)
project(RoseEngineC)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp glad.c
        Shader.h
)

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/include/lib-mingw-w64)
link_directories(${PROJECT_SOURCE_DIR}/include/glad)
link_libraries(${PROJECT_SOURCE_DIR}/include/stb_image.h)

add_executable(RoseEngineC ${SOURCE_FILES})

target_link_libraries(RoseEngineC glfw3 gdi32 opengl32)