cmake_minimum_required(VERSION 3.23.2)

# project name
project(example_project)

# falgs
set(CMAKE_CXX_STANDARD 20)

# include
include_directories(./include ./src ./libs/example_lib_one/include ./libs/example_lib_two/include)

# target
add_executable(example_project ./src/main.cpp ./src/example_project.cpp ./src/project_interface.cpp)

# external library 1
add_subdirectory(./libs/example_lib_one)
target_link_libraries(example_project example_lib_one)

add_library(example_lib_two STATIC IMPORTED)
set_property(TARGET example_lib_two PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/example_lib_two/libexample_lib_two.a)
target_link_libraries( example_project example_lib_two )
