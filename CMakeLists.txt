cmake_minimum_required(VERSION 3.17)
project(graphics_engine)

set(CMAKE_CXX_STANDARD 14)


add_executable(graphics_engine src/main.cpp glad.c include/glad.h src/Shader.cpp src/Shader.h)

find_package(glfw3 REQUIRED )
find_package(OpenGL REQUIRED)

target_include_directories(graphics_engine PUBLIC include)
target_link_libraries(graphics_engine glfw ${GLFW_LIBRARIES} dl)