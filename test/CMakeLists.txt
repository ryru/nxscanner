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

add_executable(
        ${this}
        ${sources}
)

target_include_directories(${this} PUBLIC ../include)

target_link_libraries(
        ${this}
        gtest_main
)

add_test(
        NAME ${this}
        COMMAND ${this}
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/${this}
)