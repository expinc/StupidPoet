set(learn_src
    Learn.cpp)
add_executable(learn ${learn_src})
target_link_libraries(learn
    infra
    model)
