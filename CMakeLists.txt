cmake_minimum_required(VERSION 3.2)
project(Conway_s_Game_of_Life)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

add_executable(Conway_s_Game_of_Life main.cpp)

target_link_libraries(Conway_s_Game_of_Life raylib)
