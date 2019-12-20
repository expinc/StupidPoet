set (UnitSentence_src
    UnitSentence.cpp
)
add_executable(UnitSentence ${UnitSentence_src})
target_link_libraries(UnitSentence
    gtest.dll
    gtest_main.dll
    model)


set (UnitPoetry_src
    UnitPoetry.cpp
)
add_executable(UnitPoetry ${UnitPoetry_src})
target_link_libraries(UnitPoetry
    gtest.dll
    gtest_main.dll
    model)
