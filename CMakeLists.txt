cmake_minimum_required(VERSION 3.14)

set(this nxscanner)

project(${this} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -pedantic -Werror -pedantic-errors")

enable_testing()
add_subdirectory(test)


add_executable(${this} src/main.cpp)
target_link_libraries(${this} boost_system pthread boost_program_options)