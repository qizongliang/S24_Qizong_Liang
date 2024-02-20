cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_MINIMUM 20)
set(CMAKE_CXX_MINIMUM_REQUIRED True)

add_definitions(-DNOTREAL_DEBUG=2)

add_subdirectory(Notreal)
add_subdirectory(S24_Qizong_Liang)
