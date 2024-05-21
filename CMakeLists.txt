cmake_minimum_required(VERSION 3.24)

project(S24_Game)

set(CMAKE_CXX_MINIMUM 20)
set(CMAKE_CXX_MINIMUM_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)
add_subdirectory(Notreal)
add_subdirectory(S24_Qizong_Liang)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Game)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR})
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)

