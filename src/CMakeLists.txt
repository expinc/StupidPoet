cmake_minimum_required(VERSION 3.15)
project(StupidPoet)

set(StupidPoet_version_major 1)
set(StupidPoet_version_minor 0)
set(StupidPoet_version_patch 0)


set(CMAKE_CXX_STANDARD 17)


include_directories(
    ${CMAKE_SOURCE_DIR}
    ../third-party/google-test/include
    ../third-party/rapidjson
)
link_directories(
    ../third-party/google-test/lib
)


set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/gen)
if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
endif (MSVC)


add_subdirectory(driver)
add_subdirectory(infra)
add_subdirectory(model)
add_subdirectory(utility)
