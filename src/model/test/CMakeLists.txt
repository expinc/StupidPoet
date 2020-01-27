set (UnitSentence_src
    UnitSentence.cpp
)
add_executable(UnitSentence ${UnitSentence_src})
target_link_libraries(UnitSentence
    gtest.lib
    gtest_main.lib
    model)


set (UnitPoetry_src
    UnitPoetry.cpp
)
add_executable(UnitPoetry ${UnitPoetry_src})
target_link_libraries(UnitPoetry
    gtest.lib
    gtest_main.lib
    model)
