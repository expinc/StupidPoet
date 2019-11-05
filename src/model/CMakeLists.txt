set(model_src
    Model.cpp
    NGram.cpp
    Poetry.cpp
    Sentence.cpp
)
add_library(model STATIC ${model_src})
target_link_libraries(model
    infra)

add_subdirectory(test)
