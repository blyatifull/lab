cmake_minimum_required(VERSION 3.20)
project(course C)

set(CMAKE_C_STANDARD 11)

add_executable(course main.c libs/data_structures/ordered_array_set/ordered_array_set.c libs/data_structures/ordered_array_set/ordered_array_set.h)


add_subdirectory(libs)
target_link_libraries(course data_structures)
target_link_libraries(course algorithms)