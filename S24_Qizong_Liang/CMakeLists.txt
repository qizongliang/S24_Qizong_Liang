add_executable(Game Source.cpp)

include_directories("../Notreal/include")

target_link_libraries(Game Notreal)