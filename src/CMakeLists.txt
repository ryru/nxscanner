set(
        source
        main.cpp
        scanner/probe.cpp
        scanner/probe_set.cpp scanner/preparation.cpp nxscan.cpp scanner/resolver.cpp scanner/scanner.cpp validator/display.cpp validator/input.cpp)

add_executable(${this} ${source})
target_include_directories(${this} PUBLIC include)
target_link_libraries(${this} boost_system pthread boost_program_options)
