cmake_minimum_required(VERSION 3.14)

set(this UnitTests)

set(
        sources
        ../src/scanner/probe.cpp
        probe_test.cpp
        ../src/scanner/probe_set.cpp
        probe_set_test.cpp
        ../src/scanner/preparation.cpp
        preparation_test.cpp
)

add_subdirectory(lib/googletest-master)

add_executable(
        ${this}
        ${sources}
)
target_include_directories(${this} PUBLIC ../include)
target_link_libraries(
        ${this} PUBLIC
        gtest_main
)

add_test(
        NAME ${this}
        COMMAND ${this}
)