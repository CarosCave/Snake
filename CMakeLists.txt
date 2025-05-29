cmake_minimum_required(VERSION 3.28.3)
project(Snake)

set(CMAKE_CXX_STANDARD 20)

add_executable(Snake main.cpp)
# ncurses korrekt linken
target_link_libraries(Snake PRIVATE ncurses)
