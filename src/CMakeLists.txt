cmake_minimum_required(VERSION 3.15)
project(StupidPoet)

set(StupidPoet_version_major 1)
set(StupidPoet_version_minor 0)
set(StupidPoet_version_patch 0)

include_directories(../third-party/google-test/include)
link_directories(../third-party/google-test/lib)

add_subdirectory(infra)
