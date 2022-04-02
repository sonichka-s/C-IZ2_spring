CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

project(C-IZ2_spring)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic")

add_subdirectory(src)
add_subdirectory(cmd)
add_subdirectory(tests)