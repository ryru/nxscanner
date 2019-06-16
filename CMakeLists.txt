cmake_minimum_required(VERSION 3.5.1)

set(this nxscanner)

project(${this} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -pedantic -Werror -pedantic-errors")


enable_testing()
add_subdirectory(test)

set(
        source
        src/main.cpp
        src/scanner/probe.cpp
        src/scanner/probe_set.cpp src/scanner/preparation.cpp src/nxscan.cpp src/scanner/resolver.cpp src/scanner/scanner.cpp src/validator/display.cpp src/validator/input.cpp)

add_executable(${this} ${source})
target_include_directories(${this} PUBLIC include)
target_link_libraries(${this} boost_system pthread boost_program_options)