set (UnitSentence_src
    UnitSentence.cpp
)
add_executable(UnitSentence ${UnitSentence_src})
set_property(TARGET UnitSentence PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded")
target_link_libraries(UnitSentence gtest.lib)
target_link_libraries(UnitSentence gtest_main.lib)
