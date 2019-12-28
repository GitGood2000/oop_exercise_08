cmake_minimum_required(VERSION 3.10)
project(lab8)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)
add_executable(lab8
  ./main.cpp
  ./square.cpp
  ./rectangle.cpp
  ./trapezoid.cpp)

target_link_libraries(lab8 Threads::Threads)
