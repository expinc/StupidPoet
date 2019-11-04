set (UnitSentence_src
    UnitSentence.cpp
)
add_executable(UnitSentence ${UnitSentence_src})
set_property(TARGET UnitSentence PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded")
target_link_libraries(UnitSentence
    gtest.lib
    gtest_main.lib
    model)


set (UnitPoetry_src
    UnitPoetry.cpp
)
add_executable(UnitPoetry ${UnitPoetry_src})
set_property(TARGET UnitPoetry PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded")
target_link_libraries(UnitPoetry
    gtest.lib
    gtest_main.lib
    model)
