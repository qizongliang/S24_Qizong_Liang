add_executable(Game Source.cpp MyGame.h MyGame.cpp Counter.h Counter.cpp)

include_directories("../Notreal/include")

target_link_libraries(Game Notreal)