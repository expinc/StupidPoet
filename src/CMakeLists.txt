cmake_minimum_required(VERSION 3.15)
project(StupidPoet)

set(StupidPoet_version_major 1)
set(StupidPoet_version_minor 0)
set(StupidPoet_version_patch 0)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ../third-party/google-test/include
    ../third-party/rapidjson
)
link_directories(../third-party/google-test/lib)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(driver)
add_subdirectory(infra)
add_subdirectory(model)
