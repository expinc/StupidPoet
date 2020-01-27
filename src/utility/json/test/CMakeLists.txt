set (UnitJsonDoc_src
    UnitJsonDoc.cpp
)
add_executable(UnitJsonDoc ${UnitJsonDoc_src})
target_link_libraries(UnitJsonDoc
    gtest.lib
    gtest_main.lib
    json)
