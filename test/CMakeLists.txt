cmake_minimum_required(VERSION 3.14)

set(this UnitTests)

set(
        Sources
        probe_test.cpp
        probe_set_test.cpp
)

add_subdirectory(lib/googletest-master)

add_executable(
        ${this}
        ${Sources}
)
target_link_libraries(
        ${this} PUBLIC
        gtest_main
)

add_test(
        NAME ${this}
        COMMAND ${this}
)